const std = @import("std");
const Pkg = std.build.Pkg;

const arocc = Pkg{};

const pkgs = struct {
    const arocc_deps = Pkg{
        .name = "zig",
        .source = .{ .path = "arocc/deps/zig/lib.zig" },
        .dependencies = &[_]std.build.Pkg{},
    };

    const arocc = Pkg{
        .name = "arocc",
        .source = .{ .path = "arocc/src/lib.zig" },
        .dependencies = &[_]std.build.Pkg{arocc_deps},
    };
};

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("e2v", "src/main.zig");
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.addPackage(pkgs.arocc);
    exe.install();
    exe.strip = true;
    exe.single_threaded = true;
}
