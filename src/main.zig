const std = @import("std");
const arocc = @import("arocc");

const EnumField = struct {
    nameBuffer: [256]u8,
    name: []u8,
    value: u64,
};

pub fn log_ib(v: u64, b: u64) u64 {
    var log: u64 = 0;
    var vv = v;

    while(vv != 0) {
        vv /= b;
        log += 1;
    }

    return log;
}

pub fn main() !void {
    var arena_instance = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena_instance.deinit();
    const arena = arena_instance.allocator();

    if(std.os.argv.len != 3) {
        std.log.warn("usage: {s} <header path> <enum name>", .{ std.os.argv[0] });
        return;
    }

    const path = std.mem.span(std.os.argv[1]);
    const searchEnumName = std.mem.span(std.os.argv[2]);

    var comp = arocc.Compilation.init(arena);
    defer comp.deinit();
    try comp.addDefaultPragmaHandlers();
    const builtin = try comp.generateBuiltinMacros();
    try comp.include_dirs.append("/usr/include");
    // try comp.defineSystemIncludes();
    var file = try comp.addSourceFromPath(path);

    var pp = arocc.Preprocessor.init(&comp);
    defer pp.deinit();
    try pp.addBuiltinMacros();
    _ = try pp.preprocess(builtin);
    const eof = pp.preprocess(file) catch |err| {
        if (!std.unicode.utf8ValidateSlice(file.buf)) {
            if (comp.diag.list.items.len > 0 and comp.diag.list.items[comp.diag.list.items.len - 1].tag == .invalid_utf8) {
                return;
            }
        }
        return err;
    };
    try pp.tokens.append(arena, eof);

    var tree = try arocc.Parser.parse(&pp);
    defer tree.deinit();

    var enumTypeNode: ?arocc.Tree.NodeIndex = null;
    for (tree.root_decls) |decl| {
        const ndata = tree.nodes.items(.data)[@enumToInt(decl)];
        const ntag = tree.nodes.items(.tag)[@enumToInt(decl)];
        const ntype = tree.nodes.items(.ty)[@enumToInt(decl)];
        if (ntag == .enum_decl) {
            const mapper = tree.comp.string_interner.getFastTypeMapper(tree.comp.gpa) catch tree.comp.string_interner.getSlowTypeMapper();
            defer mapper.deinit(tree.comp.gpa);
            const enumType = ntype.data.@"enum";
            const enumName = mapper.lookup(enumType.name);

            if (std.mem.eql(u8, searchEnumName, enumName)) {
                enumTypeNode = decl;
            }
        } else if (ntag == .typedef) {
            if (std.mem.eql(u8, searchEnumName, tree.tokSlice(ndata.decl.name))) {
                if(ntype.specifier == .@"enum") {
                    enumTypeNode = decl;
                }
            }
        }
    }

    if(enumTypeNode == null) {
        std.log.warn("Enum [{s}] not found or enum has only two values!", .{ searchEnumName });
        return;
    }

    const ntype = tree.nodes.items(.ty)[@enumToInt(enumTypeNode.?)];
    var enumFields = try arena.alloc(EnumField, ntype.data.@"enum".fields.len);
    const mapper = tree.comp.string_interner.getFastTypeMapper(tree.comp.gpa) catch tree.comp.string_interner.getSlowTypeMapper();
    defer mapper.deinit(tree.comp.gpa);

    // TODO(radomski): can be that it's not found
    var enumValue: u64 = 0;
    for(ntype.data.@"enum".fields) | field, i | {
        const enumFieldName = mapper.lookup(field.name);

        if (field.node != .none) {
            const value = tree.value_map.get(field.node) orelse unreachable;
            enumValue = value.data.int;
        } else {
            enumValue += 1;
        }
        
        enumFields[i].name = enumFields[i].nameBuffer[0..enumFieldName.len];
        enumFields[i].value = enumValue;
        std.mem.copy(u8, enumFields[i].name, enumFieldName);
    }

    const columns = [_][]const u8{ "Enum Name", "Enum value DEC", "Enum value HEX" };
    var maxWidths = std.mem.zeroes([columns.len]u64); 
    for(columns) |c, i| {
        maxWidths[i] = c.len;
    }

    for(enumFields) |f| {
        maxWidths[0] = std.math.max(maxWidths[0], f.name.len);
        maxWidths[1] = std.math.max(maxWidths[1], log_ib(f.value, 10));
        maxWidths[2] = std.math.max(maxWidths[2], log_ib(f.value, 16) + 2);
    }

    const stdout = std.io.getStdOut();
    var bufStdout = std.io.bufferedWriter(stdout.writer());
    var cout = bufStdout.writer();

    try cout.print("| {s: >[3]} | {s: >[4]} | {s: >[5]} |\n", .{ columns[0], columns[1], columns[2], maxWidths[0], maxWidths[1], maxWidths[2] });
    for(enumFields) |f| {
        var hexBuffer = std.mem.zeroes([16]u8);
        const hex = try std.fmt.bufPrint(hexBuffer[0..], "0x{x}", .{ f.value });
        try cout.print("| {s: <[3]} | {d: >[4]} | {s: >[5]} |\n", .{ f.name, f.value, hex, maxWidths[0], maxWidths[1], maxWidths[2] });
    }
    try bufStdout.flush();
}
