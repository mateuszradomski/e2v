/*****************************************************************************
*
*                            Copyright Nokia, 2014
*                             All Rights Reserved
*
*                              Nokia Confidential 
*
*****************************************************************************/
/*! \addtogroup History
<PRE> 
  Functional Area:   C Types 
  File Name:         phy_ctypes.h
  Change History:
  mm/dd/yyyy  CR Num Description of Change                          Engineer
  ---------- ------- --------------------------------------------- -----------
  10/03/2007  970802 Original version.                              J. Drouet
  01/14/2008 1012673 Added BB to list of sources/detectors          M. Johns
  02/25/2008 1022031 Modified enum for WI4DSP_BB to avoid confict  Bartkiewicz
  03/03/2008 1028955 Moved FA enumeration to common dir            Bartkiewicz 
  03/12/2008 1034346 EDMA redesign                                 S. Van Gheem
  04/09/2008 1044472 Added UINT32_MAX                              A. Slonneger
  08/25/2009         Modified to support Freescale 8156            M. Morriss
  
</PRE>
*****************************************************************************/
#ifndef PHY_CTYPES_H
#define PHY_CTYPES_H

#include <stdint.h>


/******************************************************************************
** Dependencies
******************************************************************************/

/*****************************************************************************
* Constants
*****************************************************************************/         

/*****************************************************************************
* DSPGS C-Type Definitions
*****************************************************************************/
typedef uint64_t       UINT64_T;
typedef uint64_t       UINT40_T; /* * */
typedef uint32_t       UINT32_T;
typedef uint16_t       UINT16_T;
typedef uint8_t        UINT8_T;
typedef char           CHAR_T;

typedef int64_t        INT64_T;
typedef int64_t        INT40_T; /* * */
typedef int32_t        INT32_T;
typedef int16_t        INT16_T;
typedef int8_t         INT8_T;

 
typedef volatile INT32_T    VINT32_T;
typedef volatile INT16_T    VINT16_T;
typedef volatile INT8_T     VINT8_T;

typedef volatile UINT32_T   VUINT32_T;
typedef volatile UINT16_T   VUINT16_T;
typedef volatile UINT8_T    VUINT8_T;

typedef float               FLOAT32_T;
typedef double              FLOAT64_T;

typedef int                 BOOLEAN_T;

#undef TRUE
#undef FALSE

#define TRUE  (!0)
#define FALSE (!TRUE)

typedef unsigned int        UINT32_MIN_T;
typedef unsigned int        UINT16_MIN_T;
typedef unsigned int        UINT8_MIN_T;

typedef int                 INT32_MIN_T;
typedef int                 INT16_MIN_T;
typedef int                 INT8_MIN_T;

typedef INT32_T     FIXQ31_T;
typedef INT16_T     FIXQ15_T;
typedef UINT32_T    UFIXQ31_T;
typedef UINT32_T    UFIXQ32_T;
typedef UINT16_T    UFIXQ15_T;
typedef UINT32_T    CMPLXQ15_T;
typedef UINT64_T    CMPLXQ31_T;

#define CMPLXQ15_T_RE(c) _ext((c),  0, 16)
#define CMPLXQ15_T_IM(c) _ext((c), 16, 16)
#define CMPLXQ31_T_RE(c) ((FIXQ31_T)_hill(c))
#define CMPLXQ31_T_IM(c) ((FIXQ31_T)_loll(c))





// Normalized mantissa <0.5...1> exponent representation of float point value equal to m*2^e
typedef struct NORM_MANTISSA_EXP_T
{
    FIXQ31_T m;     // mantissa
    int      e;     // exponent
} NORM_MANTISSA_EXP_T;

#endif /* PHY_CTYPES_H */
