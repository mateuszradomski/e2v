/*****************************************************************************
*
*                           Copyright Nokia, 2014
*
*****************************************************************************/

/*! \addtogroup History
<PRE>
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Functional Area:   LTE Modem Common Parameters Definition
  File Name:         phy_eis.h

  Change History:

  mm/dd/yyyy  CR Num Description of Change                          Engineer
  ---------- ------- --------------------------------------------- ---------
  09/21/2010         Original version (based on prelim PHY EIS).   J. Partyka
</PRE>
****************************************************************************/

#ifndef PHY_EIS_H
#define PHY_EIS_H

/******************************************************************************
** KEEP THIS FILE SELF-CONTAINED, INCLUDING AT MOST BASIC STANDARD HEADERS.
******************************************************************************/

#include <stdint.h>
#include <L2ProxyDatabase.h>

/*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
** Documentation Related
******************************************************************************/
/*! \file
 * The definitions in this file shall be shared among all PHY applications
 * and MAC layers. And so , we can ad
 * \warning
 * - Bit Fields structures defined in this header file are compiler &
 *   architecture dependent. Consult with device & compiler documentation
 *   as necessary.
 *
 *  \addtogroup phy_param_field Common PHY Fields & Parameters
 * \ingroup lte_cmn
 */

/******************************************************************************
** Dependencies
******************************************************************************/
#include "phy_ctypes.h"

/* Treat implicit padding in structures as an error */
#pragma GCC diagnostic error "-Wpadded"

/******************************************************************************
** Type Definitions (Literals)
******************************************************************************/

/*!
 * \anchor PHY_LTE_EIS_VERSION
 *
 *  LTE PHY EIS version. This tracks directly to the PHY EIS document
 *  version, with each of the 8 bit values corresponding to one of the four release
 *  numbers. For example, the version 0x02000104 corresponds to EIS version 2.0-1.4
 *
 *  The major and minor portions of the release ID (the first 2 values) will
 *  track the major and minor versions of the PHY firmware versions.
 *  The example above would correspond to PHY firmware version WBTS-PHY_R2.0_REL-1.4.00
 *
 *  The major field will only be updated on major system releases (i.e. R1, R2, etc), while
 *  the minor field will only be updated on minor system releases (i.e. R1.1, R1.2, etc).
 *
 */
#define PHY_LTE_API_VERSION 0x01000000


/*!
 * \anchor PHY_MAX_CELLS
 *
 * This literal defines the maximum number of cells (sectors) supported by RTG
 * \ingroup phy_param_field
 */
#define PHY_MAX_CELLS (2)

/*!
 * \anchor PHY_CELL_CONTAINERS_NUM
 *
 * This literal defines the number of Cell containers
 * available on a single PHY instance (ie. single SoC)
 * \ingroup phy_param_field
 */
#define PHY_CELL_CONTAINERS_NUM (12)

/*!
 * \anchor MAX_NB_CELLS
 *
 * This literal defines the maximum number of narrowband cells (sectors) supported by RTG
 * \ingroup phy_param_field
 */
#define MAX_NB_CELLS (1)

/*!
 * \anchor PHY_MAX_CELL_UE
 *
 * This literal defines the maximum number of UE per Cell and allows the PHY to size its
 * per-UE indexing data storage.
 * \ingroup phy_param_field
 */
#define PHY_MAX_CELL_UE (600)

/*!
 * \anchor PHY_MAX_TX_ANTENNAS
 *
 * This literal defines the maximum number of transmit antennas supported by modem.
 * \ingroup phy_param_field
 */
#define PHY_MAX_TX_ANTENNAS (4)

/*!
 * \anchor PHY_MAX_RX_ANTENNAS
 *
 * This literal defines the maximum number of receive antennas supported by modem.
 * \ingroup phy_param_field
 */
#define PHY_MAX_RX_ANTENNAS (8)

/*!
 * \anchor PHY_CELL_DONT_CARE
 *
 * This literal is used to indicate 'don't care' value for Sector index in message header.
 */
#define PHY_CELL_DONT_CARE (0xFF)

/*!
 * \anchor PHY_HYPERFRAME_DONT_CARE
 *
 * This literal is used to indicate 'don't care' value for LTE HyperFrame number in message header.
 */
#define PHY_HYPERFRAME_DONT_CARE (0xFFFF)

/*!
 * \anchor PHY_FRAME_DONT_CARE
 *
 * This literal is used to indicate 'don't care' value for LTE Frame number in message header.
 */
#define PHY_FRAME_DONT_CARE (0xFFFF)

/*!
 * \anchor PHY_SUBFRAME_DONT_CARE
 *
 * This literal is used to indicate 'don't care' value for LTE Subrame number in message header.
 */
#define PHY_SUBFRAME_DONT_CARE (0xFF)

/*!
 * \anchor PHY_CELL_IDENT_INVALID
 *
 * This literal is used to indicate invalid value for Cell ID in a given Group.
 * When used, cell PCI search will be performed on the PHY layer
 */
#define PHY_CELL_IDENT_INVALID (0xFF)

/*!
 * \anchor PHY_CELL_GROUP_INVALID
 *
 * This literal is used to indicate invalid value for Cell Group.
 * When used, cell PCI search will be performed on the PHY layer.
 */
#define PHY_CELL_GROUP_INVALID (0xFF)

/*!
 * \anchor PHY_MAX_ANTENNAS
 *
 * This literal defines the greater of the maximum number of transmit antennas
 * and receive antennas supported by modem. This is used for structure allocations
 * that are common to transmit and receive.
 * \ingroup phy_param_field
 */
#define PHY_MAX_ANTENNAS (8)

/*!
 * \anchor PHY_MAX_AXC_NUM
 *
 * This literal defines the maximum number of Antenna Streams supported for CPRI
 * \ingroup phy_param_field
 */
#define PHY_MAX_AXC_NUM (PHY_MAX_ANTENNAS)

/*!
 * \anchor PHY_MAX_TX_EAXC_PRACH
 *
 * This literal defines the maximum number of supported PRACH TX Antenna Streams for eCPRI
 * \ingroup phy_param_field
 */
#define PHY_MAX_TX_EAXC_PRACH (4)

/*!
 * \anchor PHY_MAX_TX_EAXC_UPLANE
 *
 * This literal defines the maximum number of supported Uplane (PUXCH & SRS) TX Antenna Streams for eCPRI
 * \ingroup phy_param_field
 */
#define PHY_MAX_TX_EAXC_UPLANE (8)

/*!
 * \anchor PHY_MAX_RX_EAXC_NUM
 *
 * This literal defines the maximum number of RX eCPRI Antenna Streams
 * \ingroup phy_param_field
 */
#define PHY_MAX_RX_EAXC_NUM (8)

/*!
 * \anchor PHY_MAX_TX_EAXC_NUM
 *
 * This literal defines the maximum number of TX eCPRI Antenna Streams
 * \ingroup phy_param_field
 */
#define PHY_MAX_TX_EAXC_NUM (PHY_MAX_TX_EAXC_UPLANE + PHY_MAX_TX_EAXC_PRACH)

/*!
 * \anchor PHY_MAX_PATH
 * This literal defines the number of D4+ BCU <-> RRU endpoint pairs supported by
 * the system.
 * \ingroup phy_param_field
 */
#define PHY_MAX_PATH (4)

/*!
 * \anchor PHY_PUSCH_MAX_CQI_PAYLOAD_LEN
 *
 * This literal defines maximum CQI payload length in PUSCH transmission
 * \ingroup phy4s_param_field
 */
#define PHY_PUSCH_MAX_CQI_PAYLOAD_LEN (17)

/*!
 * \anchor PHY_PUSCH_MAX_ACK_PAYLOAD_LEN
 *
 * This literal defines maximum HARQ-ACK payload length in PUSCH transmission
 */
#define PHY_PUSCH_MAX_ACK_PAYLOAD_LEN (4)

/*!
 * \anchor PHY_PUSCH_GAIN_ATTENUATION_MAX_DB
 *
 * This literal defines max attenuation in dB in PUSCH transmission.
 * The transmitted power range is <-PHY_PUSCH_GAIN_ATTENUATION_MAX_DB..0>dB
 * \ingroup phy4s_param_field
 */
#define PHY_PUSCH_GAIN_ATTENUATION_MAX_DB (80)


/*!
 * \anchor RTG_UL_PUSCH_CLUSTER_MAX
 *
 * This literal defines number of continuous clusters in PUSCH allocation
 */

#define PHY_PUSCH_CLUSTER_MAX (2)


/*!
 * \anchor PHY_UL_DCI_LEN
 *
 * Length in bytes of ul_dci field in PHY_PDCCH_DEC_IND_SUB_T
 */
#define PHY_UL_DCI_LEN (8)

/*!
 * \anchor PHY_MAX_NUM_RB
 *
 * This literal defines number available resource blocks
 * Number of available RBs depends on the system bandwidth
 * Currently fixed to 20MHz bandwidth
 * \ingroup phy4s_param_field
 */
#define PHY_MAX_NUM_RB       (100)


/*!
 * \anchor PHY_RB_BITMAP_LEN
 *
 * This literal defines bytes for RB bitmap representing allocation
 * The order is MSB represents first RB index.
 * \ingroup phy4s_param_field
 */
#define PHY_RB_BITMAP_LEN (uint32_t)((PHY_MAX_NUM_RB + sizeof(uint32_t) * 8 - 1) / (sizeof(uint32_t)* 8))


/*!
 * \anchor PHY_SRS_LOSSES_LEN
 *
 * This literal defines granularity of losses array representing radio channel conditions
 * \ingroup phy4s_param_field
 */
#define PHY_SRS_LOSSES_LEN (14)

/*!
 * \anchor PHY_TTI_READY_MARKING
 *
 * This literal is used to inform L2 that given TTI is about to end.
 * It shall be used to initialize 'cookie' in PHY_PDSCH_DEC_IND_T.
 */
#define PHY_TTI_READY_MARKING   (0xDEADBEEF)

/*!
 * Maximum PRS symbols in TTI
 */
#define PHY_MAX_PRS_SYMBOLS  (8)
#define PHY_MAX_PRS_ANTENNAS (4)

/*!
 * Number of NB SIBs excluding SIB2 in SIB-Type-NB-r13 (36.331)
 */
#define PHY_MAX_NSIB_SCHEDULING_INFO (5)

/*!
* Number of MSIBs: maxSI-Message (36.331)
*/
#define PHY_MAX_MSIB_SCHEDULING_INFO (32)


/*!
 * Number of max NPRACH resources in a cell
 */
#define PHY_MAX_NPRACH_RESOURCES (3)

/*!
 * Number of max NB resource blocks in a cell
 */
#define PHY_MAX_NB_CARRIERS (4)

/*!
 * Number of max CarrierAggregated LTE-U cells
 */
#define PHY_MAX_NUM_OF_ECSAT_SCELLS     (8)

/*!
 * Number of max RTG units chained as a single SCell
 * NOTE: Make sure it's multiple of 4 in order to keep proper structure fields alignment
 */
#define PHY_MAX_NUMBER_OF_SCELL_UNITS   (4)

/*!
 *  CPID for a non-realtime configuration messages.
 *  Note: Common address is shared among all cells on a given SoC.
 *
 *  This address shall receive:
 *   - PHY_CELL_CONFIG_REQ
 *   - PHY_CELL_DECONFIG_REQ
 *   - PHY_ADDRESS_CONFIG_REQ
 *   - PHY_TTI_START_CONFIG_REQ
 *   - PHY_TTI_READY_CONFIG_REQ
 */
#define PHY_CPID_COMMON_CONFIG (0x0F51)

/******************************************************************************
** Type Definitions (Enumerations)
******************************************************************************/

/*!
 * \anchor PHY_MSG_TYPE_T
 * Enumeration defining all PHYSAP message types
 *
 * \ingroup phy_param_field
 */
typedef enum
{

   /* Range 0x0000 - 0x9875 are reserved */

   /* 0x9A00-0x9AFF are for Request Message types (App to DSP) */

   /* 0x9A51 - 0x9A85 are for UL requests*/
   PHY_MIN_UL_ENC_REQ               = 0x9A51,
   PHY_PUSCH_ENC_REQ                = 0x9A51,
   PHY_PUSCH_ACK_REQ                = 0x9A52,
   PHY_PUCCH_ENC_REQ                = 0x9A53,
   PHY_PRACH_ENC_REQ                = 0x9A54,
   PHY_TDD_UL_CFG_REQ               = 0x9A55,
   PHY_SRS_CFG_REQ                  = 0x9A56,
   PHY_SRS_ENC_REQ                  = 0x9A57,
   PHY_PUSCH_RS_AND_HOPPING_CFG_REQ = 0x9A58,
   PHY_NPRACH_CFG_REQ               = 0x9A59,
   PHY_NPUSCH_ENC_REQ               = 0x9A5A,
   PHY_NPRACH_ENC_REQ               = 0x9A5B,
   PHY_NPUSCH_RS_CFG_REQ            = 0x9A5C,
   PHY_MPUSCH_ENC_REQ               = 0x9A5D,
   PHY_MPUCCH_ENC_REQ               = 0x9A5E,
   PHY_MF_PRACH_ENC_REQ             = 0x9A5F,
   PHY_MF_PUSCH_ENC_REQ             = 0x9A90,
   PHY_MF_PUSCH_RS_CFG_REQ          = 0x9A61,
   PHY_MF_PUCCH_ENC_REQ             = 0x9A62,
   PHY_MF_UL_CFG_REQ                = 0x9A63,
   PHY_UL_FADING_CFG_REQ            = 0x9A64,
   PHY_FAKE_NACK                    = 0x9A6F, /* it is NOT sent to PHY for now */
   PHY_MAX_UL_ENC_REQ               = 0x9A70,
   PHY_PUSCH_PDU_FLUSH_REQ          = 0x9A91,

   /* 0x9A71 - 0x9A70 are for DL requests*/
   PHY_MIN_DL_DEC_REQ               = 0x9A71,
   PHY_PHICH_DEC_REQ                = 0x9A71,
   PHY_PDSCH_BUFF_ALLOC_REQ         = 0x9A72, /* Request goes from DSP to APP. */
   PHY_PDSCH_BUFF_ALLOC_RESP        = 0x9A73,
   PHY_PDSCH_DEC_REQ                = 0x9A74,
   PHY_PDCCH_CFG_REQ                = 0x9A75,
   PHY_PHICH_CFG_REQ                = 0x9A76,
   PHY_TDD_CFG_REQ                  = 0x9A77,
   PHY_PDSCH_CFG_REQ                = 0x9A78,
   PHY_SI_CFG_REQ                   = 0x9A79,
   PHY_NB_CFG_REQ                   = 0x9A7A,
   PHY_NPDCCH_CFG_REQ               = 0x9A7B,
   PHY_NB_SIB1_CFG_REQ              = 0x9A7C,
   PHY_NB_SI_CFG_REQ                = 0x9A7D,
   PHY_MPDCCH_CFG_REQ               = 0x9A7E,
   PHY_CATM_SIB1_CFG_REQ            = 0x9A7F,
   PHY_CATM_SI_CFG_REQ              = 0x9A80,
   PHY_BB_DATA_REQ                  = 0x9A81,
   PHY_CSI_CFG_REQ                  = 0x9A82,
   PHY_PRS_CFG_REQ                  = 0x9A83,
   PHY_PMCH_DEC_REQ                 = 0x9A84,
   PHY_MAX_DL_DEC_REQ               = 0x9A85,

   /* 0x9B00-0x9BFF are for Indication Message types (DSP to App) */
   PHY_MIN_IND                      = 0x9B51,
   PHY_PBCH_DEC_IND                 = 0x9B51,
   PHY_PHICH_DEC_IND                = 0x9B52,
   PHY_PDSCH_DEC_IND                = 0x9B53,
   PHY_PDSCH_DEC_PAR_IND            = 0x9B54,
   PHY_PDCCH_DEC_IND                = 0x9B55,
   PHY_SYNC_LOST_IND                = 0x9B56, /*!< Synchronization lost based on PCFICH monitoring. */
   PHY_PRS_DEC_IND                  = 0x9B57,
   PHY_PMCH_DEC_IND                 = 0x9B58,
   PHY_SYNC_ACQUIRED_IND            = 0x9B59,
   PHY_DCI1C_CC_RNTI_DEC_IND        = 0x9B60,
   PHY_MAX_IND                      = 0x9B61,
   PHY_TIME_OFFSET_IND              = 0x9B62,

   /* Range 0x9C00 - 0x9CFF are for cell level init & config messaging (including RACH) */
   PHY_REMOTE_UNIT_CONFIG_REQ       = 0x9C00,
   PHY_CELL_CONFIG_REQ              = 0x9C01, /*!< Notification of prelminary cell configuration */
   PHY_CELL_CONFIG_RSP              = 0x9C02, /*!< Acknowledgement that cell configuration has been processed */
   PHY_ADDRESS_CONFIG_REQ           = 0x9C03,
   PHY_ADDRESS_CONFIG_RSP           = 0x9C04,
   PHY_CELL_DECONFIG_REQ            = 0x9C05, /*!< Cell Deconfiguration request for a cell */
   PHY_CELL_DECONFIG_RSP            = 0x9C06, /*!< Acknowledgement that cell deconfiguration has been processed  */
   PHY_CELL_ANT_RECONFIG_REQ        = 0x9C07, /*!< Cell Antenna Reconfiguration request (recent change) for a cell */
   PHY_CELL_ANT_RECONFIG_RSP        = 0x9C08, /*!< Acknowledgement that cell antenna reconfiguration request has been processed  */
   PHY_TIME_CONFIG_REQ              = 0x9C09, /*!< Frame and subframe config*/
   PHY_NB_TIME_CONFIG_REQ           = 0x9C0A, /*!< HYPER frame configuration */
   PHY_UL_TIME_ALIGN_REQ            = 0x9C10, /*!< UL CPRI/OBSAI time alignment*/
   PHY_TTI_START_CONFIG_REQ         = 0x9C11, /*!< Configuration of TTI start subscribers */
   PHY_TTI_READY_CONFIG_REQ         = 0x9C12, /*!< Configuration of TTI ready subscribers */
   PHY_TTI_START_CONFIG_RSP         = 0x9C13, /*!< Acknowledge of TTI start subscribers configuration */
   PHY_TTI_READY_CONFIG_RSP         = 0x9C14, /*!< Acknowledge of TTI ready subscribers configuration*/
   PHY_FSM4_WIRESHARK_CONFIG_REQ    = 0x9C15,

   /* Range 0x9D00 - 0x9DFF are for unsolicited messages from PHY to Host */
   PHY_TTI_READY_IND                = 0x9D00, /*!< TTI Ready Inidication */
   PHY_TTI_START_IND                = 0x9D01, /*!< TTI Start Indication */
   PHY_RP3_CTRL_RECV_IND            = 0x9D10, /*!< RP3 control/ethernet message reception */
   PHY_RP3_CTRL_SEND_REQ            = 0x9D11, /*!< RP3 control/ethernet message transmission request */
   PHY_RP3_CTRL_CONFIG_REQ          = 0x9D12, /*!< Configuration of generic control transport over RP3 link */
   PHY_ECSAT_CONFIG_REQ             = 0x9D20, /*!< LTE-U/LAA CCA measurement simulation config */
   PHY_ECSAT_AIF_CONFIG_REQ         = 0x9D21, /*!< LTE-U/LAA RP3 addresses config */

   /* Range 0x9E00 - 0x9EFF are for general purpose messages from PHY to Host */
   PHY_GENERIC_NAK_IND              = 0x9E01, /*!< Generic Nack Indication (sent as an indication that PHY did not process a request) */

   /* Ranges 0x9900 - 0x99FF and 0x9F00 - 9FFF are reserved */

   /* Range 0x9876 - 0x98FF are for L1 internal messaging */
   PHY_IQ_DATA_AVAILABLE_IND        = 0x9876, /*!< IQ data available */
   PHY_CELL_CONFIG_IND              = 0x9877, /*!< Indicate cell config */
   PHY_CELL_DECONFIG_IND            = 0x9878, /*!< Indicate cell deconfiguration */
   PHY_TX_BURST_IND                 = 0x9879, /*!< Indicate TX burst */
   PHY_MF_FRAME_CFG                 = 0x987A  /*!< Indicate Multefire frame config */

} PHY_MSG_TYPE_T;

/*!
 * \anchor PHY_PARAM_BW_T
 *
 * This enumeration is used to configure a cell channel bandwidth.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_PARAM_BW_1_4MHZ = 0, /*!< 1.4 MHz bandwidth  */
   PHY_PARAM_BW_3MHZ = 1,   /*!<   3 MHz bandwidth  */
   PHY_PARAM_BW_5MHZ = 2,   /*!<   5 MHz bandwidth  */
   PHY_PARAM_BW_10MHZ = 3,  /*!<  10 MHz bandwidth  */
   PHY_PARAM_BW_15MHZ = 4,  /*!<  15 MHz bandwidth  */
   PHY_PARAM_BW_20MHZ = 5   /*!<  20 MHz bandwidth  */
                        /* 6-255 RESERVED*/
} PHY_PARAM_BW_T;

/*!
 * \anchor PHY_PARAM_CP_T
 * This enumeration is used to configure the cyclic prefix mode.  The cyclic prefix is a
 * repeat of the end of the symbol at the beginning.
 *
 * \ingroup phy_param_field
 */
typedef enum PHY_PARAM_CP_T
{
   PHY_PARAM_CP_NORMAL  = 0, /*!< Normal Cyclic Prefix  */
   PHY_PARAM_CP_EXTEND  = 1  /*!< Extended Cyclic Prefix (<b>Not supported in R1, R2</b>) */
                          /* 2-255 RESERVED*/
}PHY_PARAM_CP_T;


/*!
 * \anchor PHY_PARAM_FM_CFG_T
 * This enumeration is used to configure the Frame Structure as either FDD, TDD or LAA mode.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_PARAM_FDD = 0,  /*!< Frame Type 1 (FDD Mode)  */
   PHY_PARAM_TDD = 1,  /*!< Frame Type 2 (TDD Mode)  */
   PHY_PARAM_LAA = 2,  /*!< Frame Type 3 (LTE-U, LAA or Multefire Mode)  */
   PHY_PARAM_UNDEF = 255 /*!< Undefined */
                   /* 3-254 RESERVED*/
} PHY_PARAM_FM_CFG_T;

/*!
 * \anchor PHY_PARAM_BAND_TYPE_T
 * This enumeration is used to distinguish configuration between LTE and LTE-U bands
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_PARAM_BAND_LTE   = 0,  /*!< Licensed LTE band  */
   PHY_PARAM_BAND_LTE_U = 1   /*!< Unlicensed band  */
                   /* 2-255 RESERVED*/
} PHY_PARAM_BAND_TYPE_T;

/*!
 * \anchor PHY_PARAM_BAND_TYPE_T
 * This enumeration indicates UE capability to operate on LTE-U/LAA/MulteFire SCells
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_UE_BAND_CAP_LTE_L  = 0, /*!< LTE-L only capable */
   PHY_UE_BAND_CAP_LTE_U  = 1, /*!< LTE-U capable */
   PHY_UE_BAND_CAP_LAA    = 2, /*!< LAA capable  */
   PHY_UE_BAND_CAP_MF     = 3 /*!< MulteFire capable  */
                   /* 4-255 RESERVED*/
} PHY_UE_BAND_CAPABILITY_T;

/*!
 * \anchor PHY_PARAM_DOMAIN_TYPE_T
 * This enumeration is used to configure baseband transport method.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_PARAM_DOMAIN_CPRI  = 0, /*!< CPRI time domain link  */
   PHY_PARAM_DOMAIN_eCPRI = 1  /*!< eCPRI frequency domain link */
                          /* 2-255 RESERVED*/
} PHY_PARAM_DOMAIN_TYPE_T;

/*!
 * \anchor PHY_PARAM_PHICH_T
 * This enumeration is used to configure the PHICH Duration per table 6.9.3-1 of 36.211.
 * This is used by PHY (in conjunction with other settings) to define whether PHICH symbols span
 * 1, 2 or 3 symbols.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_PARAM_PHICH_NORMAL  = 0, /*!< Normal Duration  */
   PHY_PARAM_PHICH_EXTEND  = 1  /*!< Extended Duration (<b>Not supported in R1</b>) */
                             /* 2-255 RESERVED*/
} PHY_PARAM_PHICH_T;

/*!
 * \anchor PHY_NPUSCH_FORMAT_T
 * This enumeration indicates the format of NPUSCH encode request (36.211 10.1.3)
 * NPUSCH format 1 - UL-SCH data,
 * NPUSCH format 2 - ACK/NACK.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
    PHY_NPUSCH_FORMAT_1 = 0,
    PHY_NPUSCH_FORMAT_2 = 1,
    PHY_NPUSCH_INVALID = 2
} PHY_NPUSCH_FORMAT_T;

/*!
 * \anchor PHY_MF_PUCCH_FORMAT_T
 * This enumeration indicates the format of Multefire PUCCH encode request
 *
 * \ingroup phy_param_field
 */
typedef enum
{
    PHY_SPUCCH_FORMAT_0 = 0,
    PHY_SPUCCH_FORMAT_1 = 1,
    PHY_SPUCCH_FORMAT_2 = 2,
    PHY_SPUCCH_FORMAT_3 = 3,
    PHY_EPUCCH_FORMAT_1 = 4
} PHY_MF_PUCCH_FORMAT_T;

/*!
 * \anchor LTE_NUM_SLOTS_PER_SF
 * Number of slots per a subframe
 *
 * \ingroup phy_param_field
 */

#define PHY_NUM_SLOT_SUBF           2

/*!
 * \anchor PHY_SRS_TRIGGER_TYPE_T
 * This enumeration is used to indicate whether UE is configured with SRS parameters trigger type 0,
 * type 1 or both on each serving cell.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_SRS_TRIGGER_TYPE0       = 0, /*!< SRS trigger type 0 */
   PHY_SRS_TRIGGER_TYPE1       = 1, /*!< SRS trigger type 1 */
   PHY_SRS_TRIGGER_TYPE0_TYPE1 = 2  /*!< SRS trigger type 0 and type 1 */
} PHY_SRS_TRIGGER_TYPE_T;


/*!
 * \anchor PHY_UE_CELL_CFG_T
 * This enumeration is used to indicate whether UE is configured with one or multiple cells
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_UE_SINGLE_CELL_CFG = 0, /*!< UE configured with one cell */
   PHY_UE_MULTI_CELL_CFG  = 1  /*!< UE configured with multiple cells */
} PHY_UE_CELL_CFG_T;



/*!
 * \anchor PHY_ANT_CFG_ENA_T
 * This enumeration indicates whether or not to use the antenna configuration
 * data or to use the default configuration (as determined by PHY).
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_ANT_CFG_DISABLE  = 0, /*!< Indicates to PHY to use the default mapping.  */
   PHY_ANT_CFG_ENABLE  = 1   /*!< Indicates to PHY to use the app-provided mapping */
                         /* 2-255 RESERVED*/
} PHY_ANT_CFG_ENA_T;

/*!
 * \anchor PHY_MOD_TYPE_T
 * This enumeration indicates the type of modulation (constellation mapping)
 * to apply to the encoded data.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_MOD_TYPE_QPSK = 0,
   PHY_MOD_TYPE_QAM16 = 1,
   PHY_MOD_TYPE_QAM64 = 2,
   PHY_MOD_TYPE_QAM256 = 3,
   PHY_MOD_TYPE_BPSK = 4
} PHY_MOD_TYPE_T;

/*!
 * \anchor PHY_HI_T
 * This enumeration indicates the HARQ indication to send to the UE.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_HI_NAK = 0,    /*!< Negative Acknowledgement.  */
   PHY_HI_DTX = 0,    /*!< PHICH not present (keep it the same as PHY_HI_NAK until Scheduler support) */
   PHY_HI_ACK = 1     /*!< Positive Acknowledgement.  */
} PHY_HI_T;


/*!
 * \anchor PHY_RANK_IND_T
 * This enumeration indicates the rank indication for this particular transmission.
 * This will determine how layering and precoding are performed. Note: If the modem is configured with
 * only one transmit antennas, then this parameter is ignored.  However, if the modem is configured with
 * more than one transmit antenna, then this parameter can contain any of the possible values in the
 * enumeration (i.e. it is possible to specify a Rank 1 transmission even if 2 transmit antennas
 * have been configured).
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_RANK_1 = 1,   /*!< Indicates 1 Transmission Layer */
   PHY_RANK_2 = 2,   /*!< Indicates 2 Transmission Layers */
   PHY_RANK_3 = 3,   /*!< Indicates 3 Transmission Layers (<b>Not supported in R1, R2</b>) */
   PHY_RANK_4 = 4,   /*!< Indicates 4 Transmission Layers (<b>Not supported in R1, R2</b>) */
   PHY_RANK_5 = 5,   /*!< Indicates 5 Transmission Layers */
   PHY_RANK_6 = 6,   /*!< Indicates 6 Transmission Layers */
   PHY_RANK_7 = 7,   /*!< Indicates 7 Transmission Layers */
   PHY_RANK_8 = 8    /*!< Indicates 8 Transmission Layers */
} PHY_RANK_IND_T;

/*!
 * \anchor PHY_CELL_CONFIG_RESULT_T
 * This enumeration defines the valid set of return codes for the PHY_CELL_CONFIG_RSP message.
 *
 * \ingroup phy_param_field
 */
typedef enum
{
   PHY_CELL_CONFIG_SUCCESS = 0,         /* Success */
   /* Non-zero - Failure */
   PHY_CELL_CONFIG_BAD_PARAM = 1,       /* Parameter failure */
   PHY_CELL_CONFIG_EIS_MISMATCH = 2,    /* EIS version mismatch */
   PHY_CELL_CONFIG_RTD_FAILURE = 3,     /* AxC Delay Measurement Failure */
   PHY_CELL_CONFIG_RSP_FAIL = 4,        /* Internal Communication Failure */
   PHY_CELL_CONFIG_FPGA_ACCESS_ERR = 5, /* FPGA Access Error */
   PHY_CELL_CONFIG_WRONG_STATE = 6,     /* Invalid State */
   PHY_CELL_CONFIG_NO_CAPACITY = 7,     /* Cell Capacity Exceeded */
   PHY_CELL_CONFIG_SYNC_FAIL = 8,       /* Internal Synchronization Failure */
   PHY_CELL_CONFIG_INT_PHY_FAIL = 9,    /* Unspecified Config Failure */
   PHY_CELL_CONFIG_BAD_TEST_MODE = 10   /* Invalid test mode  */
} PHY_CELL_CONFIG_RESULT_T;

/* Enumeration of the various ACK/NACK feedback modes carried in an_mode field in PHY_PUSCH_ENC_REQ_T message when TDD configuration
   Once FDD configuration fixed to ACK_NACK_MULTIPLEXING */
typedef enum
{
    /* 1-4 bits of data. */
    ACK_NACK_MULTIPLEXING = 0,
    /* 1-2 bits of data */
    ACK_NACK_BUNDLING
} PHY_ACK_NACK_MULTIPLEXING_MODE_T;

/*!
 * \anchor PHY_IOT_MODE_T
 * Enumeration used in iot_mode field
 */

typedef enum
{
   PHY_LEGACY_LTE         = 0,
   PHY_CAT_M              = 1,
   PHY_NARROWBAND         = 2
} PHY_IOT_MODE_T;


/*!
 * \anchor PHY_RNTI_T
 * Enumeration used in rnti_type field
 */

typedef enum
{
   PHY_C_RNTI             = 0,
   PHY_P_RNTI             = 1,
   PHY_RA_RNTI            = 2,
   PHY_SI_RNTI            = 3,
   PHY_SPS_C_RNTI         = 4,
   PHY_T_C_RNTI           = 5,
   PHY_TPC_PUSCH_RNTI     = 6,
   PHY_TPC_PUCCH_RNTI     = 7,
   PHY_M_RNTI             = 8,
   PHY_NB_RNTI            = 9,
   PHY_CC_RNTI            = 10,
   PHY_NUM_OF_RNTI_TYPES  = 11
} PHY_RNTI_T;


/*!
 * \anchor PHY_SPS_INTERVAL_T
 * This enumeration defines the valid set of Semi Persistent Scheduling Intervals for DL/UL (as described by 36.331, section 6.3.2).
 * Value in number of subframes. Value PHY_SF10 corresponds to 10 subframes, PHY_SF20 corresponds to 20 subframes and so on.
 * For TDD, the UE shall round this parameter down to the nearest integer (of 10 subframes), e.g. PHY_SF10 corresponds to 10 subframes,
 * PHY_SF32 corresponds to 30 subframes, PHY_SF128 corresponds to 120 subframes.
 */
typedef enum
{
   PHY_SF10                 = 0,
   PHY_SF20                 = 1,
   PHY_SF32                 = 2,
   PHY_SF40                 = 3,
   PHY_SF64                 = 4,
   PHY_SF80                 = 5,
   PHY_SF128                = 6,
   PHY_SF160                = 7,
   PHY_SF320                = 8,
   PHY_SF640                = 9,
   PHY_INVALID_INTERVAL     = 10, /*!< When Semi Persistent Scheduling Interval is not defined */
   PHY_NUM_OF_SPS_INTERVALS = 11
} PHY_SPS_INTERVAL_T;



/*!
 * \anchor PHY_SPS_IND_T
 *  This enumeration is used in PHY_PDCCH_DEC_IND_SUB_T/PHY_PDSCH_DEC_PAR_IND_SUB_T to indicate
 *  whether DCI was received for SPS-RNTI, non SPS-RNTI or resources were allocated semi-persistently.
 *  Additionally for SPS-RNTI indicates SPS activation/release/retransmission.
 */
typedef enum
{
    PHY_NON_SPS        = 0, /*!< DCI received for non-SPS-RNTI */
    PHY_SPS_ACTIVATION = 1, /*!< DCI received for SPS-RNTI with SPS activation */
    PHY_SPS_RELEASE    = 2, /*!< DCI received for SPS-RNTI with SPS release */
    PHY_SPS_RETX       = 3, /*!< DCI received for SPS-RNTI as retransmission */
    PHY_SPS_FAKE       = 4  /*!< No DCI received, resources allocated semi-persistently */
} PHY_SPS_IND_T;


/*!
 * \anchor PHY_SRS_SYMBOL_MODE_T
 * Enumeration used in symbol_type field
 */
typedef enum
{
   PHY_SRS_SYMBOL_NORMAL             = 0,
   PHY_SRS_SYMBOL_SPECIAL_SF_FIRST   = 1,
   PHY_SRS_SYMBOL_SPECIAL_SF_SECOND  = 2
} PHY_SRS_SYMBOL_MODE_T;


/*!
 * \anchor PHY_ANTENNA_PORT_COUNT_T
 * Enumeration used in CSI_CFG message
 */
typedef enum
{
  PHY_ANTENNA_PORT_COUNT_1 = 1,
  PHY_ANTENNA_PORT_COUNT_2 = 2,
  PHY_ANTENNA_PORT_COUNT_4 = 4,
  PHY_ANTENNA_PORT_COUNT_8 = 8
} PHY_ANTENNA_PORT_COUNT_T;

/*!
 * \anchor PHY_NARROWBAND_OPMODE
 * Enumeration used in PHY_NB_CFG_REQ message
 */
typedef enum
{
  PHY_NB_INBAND_SAME_PCI      = 0,
  PHY_NB_INBAND_DIFFERENT_PCI = 1,
  PHY_NB_GUARDBAND            = 2,
  PHY_NB_STANDALONE           = 3
} PHY_NARROWBAND_OPMODE_T;

/*!
 * \anchor PHY_SUBCARRIER_SPACING_T
 * Enumeration used in NB_CFG message
 */
typedef enum
{
  PHY_SPACING_3750_HZ = 0,
  PHY_SPACING_15000_HZ = 1
} PHY_SUBCARRIER_SPACING_T;

/*!
 * \anchor PHY_ADDRESS_T
 * Type of data field containing communication endpoint's adress,
 * (ie. Syscom sicad or EventMachine queue).
 */
typedef uint32_t PHY_ADDRESS_T;

/*!
 * \anchor PHY_ADDRESS_BITMAP_T
 * Type of data field containing bitmap of addresses
 */
typedef uint8_t PHY_ADDRESS_BITMAP_T;

/*!
 * \anchor PHY_PDCCH_DEC_IND_SUB_T
 * Enumeration for DCI formats received on the PDCCH
 */
typedef enum
{
    PHY_DCI_FORMAT_0            = 0x00,
    PHY_DCI_FORMAT_0A,
    PHY_DCI_FORMAT_0B,

    PHY_DCI_FORMAT_1            = 0x10,
    PHY_DCI_FORMAT_1A,
    PHY_DCI_FORMAT_1B,
    PHY_DCI_FORMAT_1C,
    PHY_DCI_FORMAT_1D,
    PHY_DCI_FORMAT_1A_RACH_ORDER,
    PHY_DCI_FORMAT_1C_MCCH_NOTIFY,
    PHY_DCI_FORMAT_1C_LAA,

    PHY_DCI_FORMAT_2            = 0x20,
    PHY_DCI_FORMAT_2A,
    PHY_DCI_FORMAT_2B,
    PHY_DCI_FORMAT_2C,

    PHY_DCI_FORMAT_3_3A         = 0x30,

    PHY_DCI_FORMAT_4            = 0x40,
    PHY_DCI_FORMAT_4A,
    PHY_DCI_FORMAT_4B,

    PHY_DCI_FORMAT_5            = 0x50,
    PHY_DCI_FORMAT_5A,

    PHY_DCI_FORMAT_60A          = 0x60,
    PHY_DCI_FORMAT_60B,
    PHY_DCI_FORMAT_61A,
    PHY_DCI_FORMAT_61B,
    PHY_DCI_FORMAT_62,
    PHY_DCI_FORMAT_62_DI,

    PHY_DCI_FORMAT_61A_RACH_ORDER,
    PHY_DCI_FORMAT_61B_RACH_ORDER,

    PHY_NB_DCI_FORMAT_N0        = 0x70,
    PHY_NB_DCI_FORMAT_N1,
    PHY_NB_DCI_FORMAT_N2,

    PHY_DCI_DL_SPS_FORMATS      = 0x80,

    PHY_DCI_INVALID_FORMAT      = 0xFF
} PHY_DCI_FORMAT_T;

/*
 * \anchor PHY_RNTI_ACTION
 * Action for RNTI in PDCCH_CFG_REQ message
 */
typedef enum
{
    PHY_ADD_MODIFY_RNTI = 0,
    PHY_DELETE_RNTI     = 1
} PHY_RNTI_ACTION;

/*
 * \anchor PHY_CATM_CE_MODE
 * Enumeration for ce_mode in PHY_MPDCCH_CFG_REQ_T message
 */
typedef enum
{
    PHY_CE_MODE_A = 1,
    PHY_CE_MODE_B = 2
} PHY_CATM_CE_MODE;

/******************************************************************************
** Type Definitions (Structures)
******************************************************************************/


/*---------------------------------------------------------------------------*
 *
 *                      Message Header Structures
 *
 *---------------------------------------------------------------------------*/

/*!
 * \anchor PHY_MSG_HDR_T
 * The PHY_MSG_HDR_T is used on all messages exchanged between the Host and PHY
 * software regardless of application domain.
 *
 */
typedef struct
{
   /*!
    * Message ID classifying the message. The application is responsible for
    * populating this field based on the enumeration PHY_MSG_TYPE_T.
    */
   uint16_t msg_type;

   /*!
    * Length of the message including this header in bytes
    *
    * Valid range: 12 (header only) - 65535
    */
   uint16_t length;

   /*!
    * Hyperframe number associated with the PHY request / indicator.
    *
    * Note a value of "don't care" signifies that no hyperframe number validation should be made on the message.
    *
    * Valid Range: 0 - 1023 (HFN is 10 bits), 0xFFFF for "don't care".
    */
   uint16_t hyperframe_num;

   /*!
    * Frame number associated with the PHY request / indicator.
    *
    * Note a value of "don't care" signifies that no frame number validation should be made on the message.
    *
    * Valid Range: 0 - 1023 (SFN is 10 bits), 0xFFFF for "don't care".
    */
   uint16_t frame_num;

   uint16_t reserved;

   /*!
    * Subframe number associated with the PHY request / indicator.
    *
    * Note that a value of "don't care" signifies that no subframe number validation should be made on the message.
    *
    * Valid Range: 0 - 9, 0xFF for "don't care".
    */
   uint8_t subframe_num;

   /*!
    * Target sector that the packet is to be transmitted on.
    *
    * Valid Range: 0 - 2
    */
   uint8_t   cell_index;

   uint32_t padding;

}  PHY_MSG_HDR_T;


/*---------------------------------------------------------------------------*
 *
 *                      Initialization Message Structures
 *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TTI_START_CONFIG_REQ_T
 * This message configure the list of a PHY_TTI_START_IND message subscribers.
 * Each recipient will receive notification on the beginning of every TTI.
 * Note: Repeated adresses will be removed.
 * Note: This message has to be sent one time only, right after system startup.
 */
typedef struct
{
    PHY_MSG_HDR_T msg_hdr;

    /*! Number of subscribers to be regsitered (number of elements in a subsequent array) */
    uint32_t num_of_subscribers;

    /*! Open array of subscribers */
    PHY_ADDRESS_T address_list[1];

} PHY_TTI_START_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TTI_READY_CONFIG_REQ_T
 * This message configure the list of a PHY_TTI_READY_IND message subscribers.
 * Each recipient will receive notification on the very end of every TTI.
 * Note: Repeated adresses will be removed.
 * Note: This message has to be sent one time only, right after system startup.
 */
typedef struct
{
    PHY_MSG_HDR_T msg_hdr;

    /*! Number of subscribers to be regsitered (number of elements in a subsequent array) */
    uint32_t num_of_subscribers;

    /*! Open array of subscribers */
    PHY_ADDRESS_T address_list[1];

} PHY_TTI_READY_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TTI_START_CONFIG_RSP_T
 * This message acknowledge that the list of a PHY_TTI_START_IND message subscribers,
 * delivered in PHY_TTI_START_CONFIG_REQ message was added to the subscriber list.
 * Note: This message will be sent one time, in response to the PHY_TTI_START_CONFIG_REQ.
 */
typedef struct
{
    PHY_MSG_HDR_T msg_hdr;

    /*! Length of received subscribers list. */
    uint32_t num_of_subscribers_received;

    /*!
     * Number of subscribers actually registered.
     * Value different from 'num_of_subscribers_received' indicate an error.
     */
    uint32_t num_of_subscribers_registered;

} PHY_TTI_START_CONFIG_RSP_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TTI_READY_CONFIG_RSP_T
 * This message acknowledge, that the list of a PHY_TTI_READY_IND message subscribers,
 * delivered in PHY_TTI_READY_CONFIG_REQ message, was added to the subscriber list.
 * Note: This message will be sent one time, in response to the PHY_TTI_READY_CONFIG_REQ.
 */
typedef struct
{
    PHY_MSG_HDR_T msg_hdr;

    /*! Length of received subscribers list. */
    uint32_t num_of_subscribers_received;

    /*!
     * Number of subscribers actually registered.
     * Value different from 'num_of_subscribers_received' indicate an error.
     */
    uint32_t num_of_subscribers_registered;

} PHY_TTI_READY_CONFIG_RSP_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TTI_READY_IND_T
 * This message indicates to MAC that it should prepare for the next TTI event.
 * This message is sent to the HOST0 endpoint 100 usec before the start of the next TTI.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    *
    * The msg_hdr::frame and msg_hdr::subframe fields correspond to the upcoming frame / subframe.
    */
   PHY_MSG_HDR_T msg_hdr;

} PHY_TTI_READY_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TTI_START_IND_T
 * This message indicates the start of new subframe processing to the Host. One instance of
 * this message is sent for each cell.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Status of cell subframe timing.
    *
    *  0 - Normal - Frame / Subframe has updated normally
    *  1 - Initial Update - This is the first timing report for this cell.
    *  2 - Time Adjustment - This cell has undergone a time adjustment. One or more subframes
    *      has been skipped.
    */
   uint32_t status;

   uint32_t padding[1];

} PHY_TTI_START_IND_T;

/*---------------------------------------------------------------------------*
 *
 *                      Cell/RACH Configuration Message Structures
 *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_ANT_CONFIG_T
 * Structure that describes the antenna configuration parameters (either Tx or Rx)
 * for a single cell.  This structure exists for each transmit and receive
 * antenna in the cell.
 */
typedef struct
{

  /*!
   * Physical AIF/RP3 link number
   */
   uint8_t link_id;

  /*!
   * Reserved for future use
   */
   uint8_t reserved;

  /*!
   * OBSAI message address (13-bit) for this antenna carrier
   */
   uint16_t obsai_adress;

  /*!
   * Antena carried index.
   * AxC index is used only internally by platform
   */
   uint16_t axc_id;

  /*!
   * Reserved for future use
   */
   uint16_t reserved2;

   /*!
   * Antenna carrier offset
   * Advance/delay in 307.2MHz clock ticks
   */
   int32_t axc_offset;


} PHY_ANT_CONFIG_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PATH_DELAY_CONFIG_T
 * This structure defines the delay characteristics of each D4 Path for the cell.
 */
typedef struct
{
   /*!
   * This field specifies an integer path identifier to be associated with the
   * RTD and non-RTD delays found in this record. This value will be found in the
   * PHY_ANT_CONFIG_T structure and used to refer to these delay values.
   *
   * Valid Range: 0 - 0xFFFF
   */
   uint32_t   path_id;

   /*!
   * This field represents the full round trip delay for the path in nanoseconds.
   * In order to determine one-way delay this value need to be divided in half to
   * determine the Tx and Rx delay components.
   *
   * A value of "0xFFFF FFFF" represents an unknown RTD that must be measured by
   * the PHY (specified by the PHY_ANT_RTD_MEASUREMENT_CONFIG_T structure).
   */
   uint32_t   path_rtd;


} PHY_PATH_DELAY_CONFIG_T;


typedef struct
{
    uint8_t cpri_link;
    uint8_t format;
    uint8_t padding[6];

    uint32_t samples_in_container;
    uint32_t word_position;
    uint32_t bit_position;

    uint32_t ctrl_vector_number;

} PHY_AXC_CONTAINER_CONFIG_T;

typedef struct
{
    uint16_t eaxc_id;
    uint8_t ecpri_link;
    uint8_t format;
    uint32_t padding;

} PHY_EAXC_CONTAINER_CONFIG_T;

typedef struct
{
    uint32_t t2aMaxCpUl;
    uint32_t t2aMinCpUl;
    uint32_t nTaOffset;
    uint32_t fftSamplingOffset;
    uint32_t ta3Simul;
    uint32_t ta3PrachSimul;

} ulEcpriTimingInfo;

typedef struct
{
    /*! Early reception point the RU could receive a U-Plane message,
     * relative to a symbol DL Air Interface transmission.
     * Units: UTU
     */
    uint32_t t2aMaxUp;

    /*! Latest reception point the RU could receive a U-Plane message,
     * relative to a symbol DL Air Interface transmission.
     * Units: UTU
     */
    uint32_t t2aMinUp;

    /*! Early reception point the RU could receive a C-Plane message,
     * relative to a symbol DL Air Interface transmission.
     * Units: UTU
     */
    uint32_t t2aMaxCpDl;

    /*! Latest reception point the RU could receive a C-Plane message,
     * relative to a symbol DL Air Interface transmission.
     * Units: UTU
     */
    uint32_t t2aMinCpDl;

} dlEcpriTimingInfo;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_ANT_CONFIG_T
 * This structure defines the antenna configuration for the cell. Included in
 * this configuration are parameters for RTD measurement collection procedures
 * as well as parameters for configuring the path to Tx and Rx antennas.
 */
typedef struct
{
   uint8_t tx_axc_num;
   uint8_t rx_axc_num;

   uint8_t rx_eaxc_num;
   uint8_t tx_eaxc_num;

   uint32_t padding;

   PHY_AXC_CONTAINER_CONFIG_T tx_axc_config[PHY_MAX_AXC_NUM];
   PHY_AXC_CONTAINER_CONFIG_T rx_axc_config[PHY_MAX_AXC_NUM];

   PHY_EAXC_CONTAINER_CONFIG_T tx_eaxc_config[PHY_MAX_TX_EAXC_NUM];
   PHY_EAXC_CONTAINER_CONFIG_T rx_eaxc_config[PHY_MAX_RX_EAXC_NUM];

   ulEcpriTimingInfo ul_timing_info;
   dlEcpriTimingInfo dl_timing_info;

} PHY_CELL_ANT_CONFIG_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_CONFIG_REQ_T
 * This message sends the configuration for the specified cell.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */

   PHY_MSG_HDR_T msg_hdr;
   /*!
    * 32-bit integer expression of Host / PHY interface version. This is used to verify message
    * compatibility at init time. Note this is not the DSP software version. This value should
    * only change when the interface definition between Host and PHY is updated.
    *
    * The interface version maps directly to the version number of this document and is of the
    * form:
    *
    * <LTE Major Release>.<LTE Minor Release>-<Document Release Major>.<Document Release Minor>
    * with each element mapping to one byte of the version integer.
    *
    */
   uint32_t eis_version;

   /*!
    * Cell ID within a Cell Group as defined by 36.211.
    * This value is combined with the Cell Group to define the overall cell ID (which
    * is used for sync channel sequences, scrambling seeds, and REG mapping).
    *
    * Valid Range: 0 - 2 or PHY_CELL_IDENT_INVALID
    *
    */
   uint8_t  cell_ident;

   /*!
    * Cell Group ID as defined by 36.211.
    * This value is combined with the Cell ID within the group to define the overall
    * cell ID (which is used for sync channel sequences, scrambling seeds and REG mapping).
    *
    * Valid Range: 0 - 167 or PHY_CELL_GROUP_INVALID
    *
    */
   uint8_t  cell_grp_id;

   /*!
    * Frame Structure type (as described by 36.211, section 4). Values defined in PHY_PARAM_FM_CFG_T.

      0 : Type 1 (FDD)
      1 : Type 2 (TDD)
      2 : Type 3 (LTE-U/LAA/MF)

      All other values: Invalid
    */
   uint8_t  frame_structure;


   /*!
    * This field indicates type of baseband transport method. Values defined in PHY_PARAM_DOMAIN_TYPE_T.
    *
    *  0: CPRI
    *  1: eCPRI
    *
    *  All other values: Invalid
    */
   uint8_t baseband_type;


   /*!
    * Cell Bandwidth. Values defined in PHY_PARAM_BW_T.

     Supported range:

      0 : 1.4 MHz
      1 : 3 MHz
      2 : 5 MHz
      3 : 10 MHz
      4 : 15 MHz
      5 : 20 MHz

      All other values : Invalid
    */
   uint8_t   dl_bandwidth;
   uint8_t   ul_bandwidth;

   /*!
    * Cyclic Prefix Length for the cell. Values defined in PHY_PARAM_CP_T.

      0 : Normal
      1 : Extended

      All other values: Invalid
    */
   uint8_t  ul_cyclic_prefix;
   uint8_t  dl_cyclic_prefix;


   /*!
    *  Level of power of the physical signal on cell
    *
    *  Valid Range: 0-4096
    */
   uint16_t  signal_level;

   /*!
    *  Level of power of the AWGN on cell
    *
    *  Valid Range: 0-4096
    */
   uint16_t  noise_level;

   /*!
    * Index of internal PHY Cell container,
    * on which cell will be configured
    *
    * Valid Range: 0 - (PHY_CELL_CONTAINERS_NUM-1)
    */
   uint8_t cell_container_index;

   uint8_t padding[7];

   /*!
    * Antenna configuration of the cell (see PHY_CELL_ANT_CONFIG_T Struct Reference).
    */
   PHY_CELL_ANT_CONFIG_T antenna_config;


} PHY_CELL_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_ADDRESS_CONFIG_RSP_T
 * This message configures set of PHY cell adresses for L2/SCH.
 * Message will be sent as a respons for PHY_ADDRESS_CONFIG_REQ_T.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */

    PHY_MSG_HDR_T msg_hdr;

    /*!
     * Communication endpoint for a non-realtime configuration messages,
     * or messages that are not dedicated for a specific cell.
     */
    PHY_ADDRESS_T config_msg_address;

    /*!
     * Communication endpoint for a realtime downlink control messagess.
     * This adress will receive:
     *
     *  PHY_PHICH_CFG_REQ
     *  PHY_TIME_CFG_REQ
     *  PHY_PDSCH_CFG_REQ
     *  PHY_PDCCH_CFG_REQ
     *  PHY_TDD_CFG_REQ
     *  PHY_SI_CFG_REQ
     *  PHY_CSI_CFG_REQ
     *  PHY_PRS_CFG_REQ
     *  PHY_PHICH_DEC_REQ
     *  PHY_PMCH_DEC_REQ
     *  PHY_MPDCCH_CFG_REQ
     */
    PHY_ADDRESS_T downlink_control;

    /*!
     * Communication endpoint for a realtime uplink control and data messages.
     * This adress will receive:
     *
     *  PHY_TDD_CFG_REQ
     *  PHY_PUSCH_RS_AND_HOPPING_CFG_REQ
     *  PHY_SRS_CFG_REQ
     *  PHY_PUSCH_ENC_REQ
     *  PHY_PUSCH_ACK_REQ
     *  PHY_PUSCH_PDU_FLUSH_REQ
     *  PHY_PUCCH_ENC_REQ
     *  PHY_SRS_ENC_REQ
     *  PHY_PRACH_ENC_REQ
     */
    PHY_ADDRESS_T uplink_control_and_data;

    uint32_t padding[1];

} PHY_ADDRESS_CONFIG_RSP_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_ADDRESS_CONFIG_REQ_T
 * This message configures set of L2/SCH adresses for given cell on PHY.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */

    PHY_MSG_HDR_T msg_hdr;

    /*!
     * Communication endpoint where Master Information Block will be sent.
     * This address will receive:
     *
     * PHY_PBCH_DEC_IND
     */
    PHY_ADDRESS_T mib_sch;

    /*!
     * Communication endpoint where synchronization status updates will be sent.
     * This address will receive:
     *
     * PHY_SYNC_ACQUIRED_IND
     * PHY_SYNC_LOST_IND
     */
    PHY_ADDRESS_T sync_sch;

} PHY_ADDRESS_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_UL_TIME_ALIGN_REQ_T
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   int16_t    samples;
   uint16_t   reserved1;

} PHY_UL_TIME_ALIGN_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_CONFIG_RSP_T
 * This message indicates the result status of the prior configuration request.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Result of configuration operation.
    * For values see PHY_CELL_CONFIG_RESULT_T
    */
   uint32_t   config_result;

   uint8_t    reason_string[256];

} PHY_CELL_CONFIG_RSP_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_DECONFIG_REQ_T
 * This message instructs the PHY to cease operations on the specified cell. This message
 * carries no information outside of the header.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Index of internal PHY Cell container,
    * on which cell will be deconfigured
    *
    * Valid Range: 0 - (PHY_CELL_CONTAINERS_NUM-1)
    */
   uint8_t cell_container_index;

   uint8_t padding[7];

} PHY_CELL_DECONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_DECONFIG_RSP_T
 * This message indicates the result of the prior Deconfig operation on the PHY. If
 * deconfiguration is not possible for some reason a non-success code is returned with a
 * text string detailing the problem. A deconfig failure will likely result in escalation
 * to a PHY reset.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Result of configuration operation.

      Values:
         0       - Success
        Non-zero - Failure (specific result codes TBS)
    */
   uint32_t result;

   /*!
    * ASCII string containing a failure reason description. String is terminated by a
    * NULL character if less than 256 bytes long.
    */
   uint8_t reason_string[256];

} PHY_CELL_DECONFIG_RSP_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_ANT_RECONFIG_REQ_T
 * This message instructs the PHY to reconfigure per the set of contained parameters. This
 * message is used during fault management driven antenna reconfiguration events.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * New cell antenna measurement and tx/rx configuration associated with this request.
    */
   PHY_CELL_ANT_CONFIG_T   ant_config;

} PHY_CELL_ANT_RECONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TIME_CONFIG_REQ_T
 * This message instructs the PHY to configure frame and subframe.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Detected difference between actual and reported LTE time in 10ms frames
    */
    int32_t   frame_delta;

} PHY_TIME_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NB_TIME_CONFIG_REQ_T
 * This message instructs the PHY to configure hyperframe.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   uint16_t hyperSFN;

   uint16_t reserved;

} PHY_NB_TIME_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_ANT_RECONFIG_RSP_T
 * This message indicates the result of the prior reconfiguration operation on the PHY. If
 * reconfiguration is not possible for some reason a non-success code is returned with a
 * text string detailing the problem. A reconfiguration failure will likely result in escalation
 * to a PHY reset.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Result of configuration operation.

      Values:
         0       - Success
        Non-zero - Failure (specific result codes TBD)
    */
   uint32_t result;

   /*!
    * ASCII string containing a failure reason description. String is terminated by a
    * NULL character if less than 256 bytes long.
    */
   uint8_t reason_string[256];

} PHY_CELL_ANT_RECONFIG_RSP_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TDD_CFG_REQ_T
 * The structure describes TDD UL/DL/Special subframe configuration for a sector.
 * If TDD frame type was configured with PHY_SECTOR_CFG_T - DL decoding
 * goes in subframes 0 and 5 only until this message received
 *
 */
typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory. For PHY_PHICH_CFG_T the frame / subframe fields are ignored
      and the configuration is applied instantly.
    */
    PHY_MSG_HDR_T msg_hdr;

    /*!
    * TDD Uplink / Downlink configuration (36.211, Table 4.2-2)
    * Note this field is only valid for TDD frame structure.
    * Valid Range - 0 - 6. For R2 only configuration 1 and 2 are supported.
    */
    uint8_t   ul_dl_config_type;

    /*!
    * Special Subframe Configuration (36.211, Table 4.2-1)
    * Note this field is only valid for TDD frame structure.
    * Valid Range - 0 - 8. For R2 only configuration 5 and 7 are supported
    */
    uint8_t   sp_sf_config;

    uint16_t  reserved;

    uint32_t padding[1];
} PHY_TDD_CFG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_MF_CFG_REQ_T
 * The structure describes timing relations in MF special subframe.
 */
 typedef struct
 {
     /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
       definitions. This header occupies 8 bytes of memory. For PHY_PHICH_CFG_T the frame / subframe fields are ignored
       and the configuration is applied instantly.
     */
     PHY_MSG_HDR_T msg_hdr;

     /*!
     * Special subframe timing (36.211, Table 8.1-1)
     * Valid Range - 0 - 13.
     */
     uint8_t   timing_advance_offset;

     /*!
     * This parameter indicates whether UE performs type 2 channel sensing before transmission on sPUCCH resources.
     * Valid values (may change due to spec): 0x01 - enabled, 0x00 - disabled.
     */
     uint8_t   sPUCCH_LBT;

     uint16_t  reserved;

 } PHY_MF_CFG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PHICH_CFG_REQ_T
 * The structure describes PHICH configuration for a sector. PHICH configuration
 * is expected before any of the following:
 * PHY_PHICH_DEC_REQ_T, PHY_PDCCH_CFG_REQ_T
 * Despithe the name, this message also does contain p-b parameter;
 *
 */
typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory. For PHY_PHICH_CFG_T the frame / subframe fields are ignored
      and the configuration is applied instantly.
    */
    PHY_MSG_HDR_T msg_hdr;

     /*!
      * PHICH Duration defined in PHY_PARAM_PHICH_T
      *
     */
    uint8_t   phich_duration;

    /*!
     * Number of PHICH groups as determined by section 6.9 of 36.211 (8.4.0).
     * Valid Range: 1-25
    */
    uint8_t   num_phich_groups;

    uint16_t  reserved;

} PHY_PHICH_CFG_REQ_T;



/*!
 * \anchor PHY_MBSFN_SUBFRAME_CONF_SUB_T
 *  These fields are used for MBSFN frame and subframe configuration, in Unicast MBSFN Subframe mode
 *  Based on SystemInformationBlockType2.MBSFN-SubframeConfigList
 */
typedef struct PHY_MBSFN_SUBFRAME_CONF_SUB_T
{
    uint8_t  radioframeAllocationPeriod;    /* n: (1, 2, 4, 8, 16, 32) */
    uint8_t  radioframeAllocationOffset;    /* (0..7) */
    uint16_t frames_set_size;               /* number of consecutive radio frames: (1, 4) */
    uint32_t subframeAllocation;            /* starting from the first radioframe and from the first/leftmost bit */
} PHY_MBSFN_SUBFRAME_CONF_SUB_T;


typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory. For PHY_PDSCH_CFG_T the frame / subframe fields are ignored
      and the configuration is applied instantly.
    */
    PHY_MSG_HDR_T msg_hdr;

   /*!
    * This is the parameter P<SUB>B</SUB> in section 5.2 of 36.213 that is used by PHY to determine the ratio of PDSCH EPRE
      to cell-specific RS EPRE.  This is used in conjunction with the UE-specific ratio P<SUB>A</SUB> to determine the PDSCH power for
      a specific UE. The values are also specified in "PDSCH-Configuration" section of 36.331

      Valid Range: 0-3

    */
    uint8_t   pdsch_power_index_b;

    uint8_t num_sf_conf;
    uint16_t reserved;
    PHY_MBSFN_SUBFRAME_CONF_SUB_T sf_conf[8];
} PHY_PDSCH_CFG_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NB_SIB1_CFG_REQ_T
 * The structure describes contains extract from MasterInformationBlock-NB 36.331, 6.7.2
 *
 */
typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory. For PHY_PDSCH_CFG_T the frame / subframe fields are ignored
      and the configuration is applied instantly.
    */
    PHY_MSG_HDR_T msg_hdr;

    uint8_t   opMode;             /* 0:Inband, 1:DiffPCI, 2:Guardband, 3:Standalone */
    uint8_t   schedulingInfoSIB1; /* 0...15 */
    uint8_t   eutra_NumCRS_Ports; /* 0: same, 1: four */

    uint8_t   reserved;
} PHY_NB_SIB1_CFG_REQ_T;


/*!
 * \anchor NSIB_SCHEDULING_INFO_T
 * Extract from 36.331, 6.7.2, SchedulingInfo-NB-r13
 */
typedef struct
{
    uint16_t si_Periodicity;       /* One of: 64,128,256,512,1024,4096 */
    uint8_t  si_RepetitionPattern; /* One of: 2,4,8,16 */
    uint8_t  reserved1;
    uint16_t si_TB;                /* One of: 56, 120, 208, 256, 328, 440, 552, 680 */
    uint16_t reserved2;
} NSIB_SCHEDULING_INFO_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NB_SI_CFG_REQ_T
 * The structure describes contains extract from SystemInformationBlockType1-NB 36.331, 6.7.2
 *
 */
typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory. For PHY_PDSCH_CFG_T the frame / subframe fields are ignored
      and the configuration is applied instantly.
    */
    PHY_MSG_HDR_T msg_hdr;

    uint16_t   si_WindowLength; /* One of: 160, 320, 480, 640, 960, 1280, 1600 */
    uint8_t    eutraControlRegionSize; /* One of: n1, n2, n3 */
    uint8_t    si_RadioFrameOffset; /* 0...15 */
    uint8_t    num_sibs; /* Number of elements in schedulingInfoList-r13 */
    uint8_t    reserved1;
    uint16_t   reserved2;
    NSIB_SCHEDULING_INFO_T scheduling_info[PHY_MAX_NSIB_SCHEDULING_INFO];

} PHY_NB_SI_CFG_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
* \anchor PHY_CATM_SIB1_CFG_REQ_T
* The structure have extract from MasterInformationBlock 36.331, 6.7.2
*
*/
typedef struct
{
    PHY_MSG_HDR_T msg_hdr;

    uint8_t   schedulingInfoSIB1_BR;             /* 0...31 */
    uint8_t   reserved0;
    uint8_t   reserved1;
    uint8_t   reserved2;
} PHY_CATM_SIB1_CFG_REQ_T;


/*!
* \anchor MSIB_SCHEDULING_INFO_T
* Extract from 36.331, SchedulingInfoList-BR
*/
typedef struct
{
    uint16_t  si_Periodicity;/* One of: 8, 16, 32, 64, 128, 256, 512 */
    uint16_t si_TBS;         /* One of: 152, 208, 256, 328, 408, 504, 600, 712, 808, 936 */
    uint8_t  si_Narrowband;  /* One of: 1...16 (maxAvailNarrowBands-r13) */
    uint8_t  reserved1;
    uint16_t  reserved2;
} MSIB_SCHEDULING_INFO_T;

/*---------------------------------------------------------------------------*/
/*!
* \anchor PHY_CATM_SI_CFG_REQ_T
* The structure describes contains extract from bandwidthReducedAccessRelatedInfo-r13, SystemInformationBlockType11, 36.331, 6.2.2
*
*/
typedef struct
{
    PHY_MSG_HDR_T msg_hdr;

    uint8_t si_WindowLength;      /* One of: 20, 40, 60, 80, 120, 160, 200 */
    uint8_t si_RepetitionPattern; /* One of: 1,2,4,8 */
    uint8_t startSymbolBR;        /* One of: n1, n2, n3, n4 */
    uint8_t subframeBitmapLength; /* One of: 10, 40 */
    uint8_t subframeBitmapBR[5];  /* Bitmap: either 10 or 40 bits, starting from oldest bit of first index */
    uint8_t num_sibs;             /* Number of elements in schedulingInfoList-BR-r13 */
    uint8_t padding[6];

    MSIB_SCHEDULING_INFO_T scheduling_info[PHY_MAX_MSIB_SCHEDULING_INFO];
} PHY_CATM_SI_CFG_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_SI_CFG_REQ_T
 * The structure describes window length for System Information Scheduling as per 36.331, 5.2
 *
 */
typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory. For PHY_PDSCH_CFG_T the frame / subframe fields are ignored
      and the configuration is applied instantly.
    */
    PHY_MSG_HDR_T msg_hdr;

    uint32_t si_window_len;
    uint32_t padding;
} PHY_SI_CFG_REQ_T;





/*---------------------------------------------------------------------------*
 *
 *                      User Plane Message Structures
 *
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*!
 * \anchor CALL_ID_UE_INDEX_T
 * This structure defines the bitfield definition for breaking RNTI into a
 * UE Index and RNTI Count field.
 *
 * Note: The order is based on the desire to have the reserved bit as the MSB
 * of the union.
 *
 */
typedef struct
{
   /*!
    * Value of the call_id usable as the UE Index. The system guarantees that there
    * will only be one UE instance with this value active in the cell at any given time.
    *
    * Range: 0 - 599.
    *
    */
   uint16_t  ue_index    : 10;

   /*!
    * This value will be assigned to:
    * 1 for core2 and core3
    * 2 for core4 and core5
    * 3 for core6 and core7
    *
    * Range: 1 - 3
    *
    */
   uint16_t  proc_id  : 5;

   /*!
    * This bit should be ignored by the PHY.
    */
   uint16_t  reserved    : 1;
} CALL_ID_UE_INDEX_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor CALL_ID_UNION_T
 * This union allows for access of RNTI as a UE Index bitfield representation or
 * as a 16 bit unsigned integer.
 *
 */
typedef union
{
   /*!
    * The index_rnti member is used in cases where the UE Index within the RNTI is desired.
    */
   CALL_ID_UE_INDEX_T   index_rnti;

   /*!
    * The full_rnti member is used for the full 16-bit representation of the RNTI.
    */
   uint16_t          full_rnti;
} CALL_ID_UNION_T;



/*---------------------------------------------------------------------------*/
/*!
 * \anchor PUSCH_HOPPING_CONFIG_T
 * This struct carries PUSCH hopping config dynamic parameters
 *
 */
typedef struct
{
   /* frequency hopping enabler flag 0-hopping disabled, 1-hopping enabled */
   uint8_t     freq_hopping;
   /* Data carried by the resource allocation field in DCI. It determines among others hopping type.
     Domain {[0],[1] } for 6-49 N_UL_RB or {[0,0]...[1,1]} for 50..110 N_UL_RB */
   uint8_t     hopping_bits;
   /* transmission number for the transport block trasmitted in slot ns as defined in 3GPP TS36.133. Domain 0:maxHARQ-Tx
     PUSCH domain 1-8, 10, 12, 16, 20, Msg3 1-8 */
   uint8_t     CURRENT_TX_NB;
   /* alignment */
   uint8_t     reserved;
} PHY_PUSCH_HOPPING_DYN_CONFIG_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor RTG_UL_PUSCH_HOPPING_STATIC_CONFIG_T
 * This struct carries PUSCH hopping cell specific parameters
 *
 */
typedef struct
{
    /* PUSCH hopping params
       0-interSubFrame; 1-intraAndInterSubFrame */
    uint8_t     hopping_mode;
    /* pusch-HoppingOffset provided by higher layers. Domain 0..98 */
    uint8_t     N_HO_RB;
    /* number of sub-bands  1..4 */
    uint8_t     N_sb;
    /* alignment */
    uint8_t     reserved;
} RTG_UL_PUSCH_HOPPING_STATIC_CONFIG_T;

typedef struct
{
   /*!
    * Physical RB Offset.  The offset from RB#0 to the first RB of the PUSCH allotment.
    */
   uint8_t prb_offset[PHY_NUM_SLOT_SUBF];

   /*!
    * Number of RBs alloted to this UE
    * CAUTION: when the cluster is not allocated the num_rb shall be zero.
    */
   uint16_t  num_rb;
} PHY_PUSCH_PRB_CLUSTER_LIST_T;

typedef struct
{
  /*!
  * Interferred cell index matching the indexing schema as cell_index field in PHY_MSG_HDR_T of the PHY_PUSCH_ENC_REQ_T
  */
  uint8_t cell_index;
  /*!
   * value represents negative level in dB of intracell interference in reference to the cell the PUSCH request is issued;
   * The intercell interference is disabled upon gain set to PHY_PUSCH_GAIN_ATTENUATION_MAX_DB
   * Caution: The sum of gain + losses[k] for given RB must not exceed 0 dB, which represent signal with maximum strength
   */

  int8_t gain;

  /*!
   * Warning! moving field below to PHY_CELL_INTERFERENCE_T below will broke eis!
   *          Freescale compiler seems to pad tables to 32-bit boundary!
   */
  uint16_t                reserved;
} PHY_CELL_INTERFERENCE_T;

typedef struct
{
    /*!
    *  Array size of neighbouring cells quantity
    *  The list is interpretted till the first entity with gain field set to PHY_PUSCH_GAIN_ATTENUATION_MAX_DB
    */
    PHY_CELL_INTERFERENCE_T cell[PHY_MAX_CELLS-1];
} PHY_INTRACELLS_INTERFERENCES_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PBCH_DEC_IND_T
 * Structure that describes the decoding indication for data transmitted on
 * the Physical Broadcast Channel.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 16 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Size of the formatted MIB data in bits.
   */
  uint8_t data_size;

  /*!
   *   PSCH/SCCH detected Detected frame structure.
   *   0 :  Type 1  (FDD)
   *   1 :  Type 2  (TDD)
   *   255: Unknown (yet)
   *   All other values: Invalid
   */
  uint8_t frame_structure;

  /*!
   * Number of antennas detected by PBCH.
   */
  uint8_t pbch_antennas;

  uint8_t reserved1;

  /*!
   *   PSCH/SCCH detected physicall cell identity, range 0..503; set to 0xffff when not known
   */
  uint16_t pci;

  uint16_t reserved2;

  /*!
   * The MIB data starts at this location. Though only a single word is allocated in the message
   * type. the actual buffer allocation for the message should accomodate enough memory to hold the number
   * of bits specified by the data_size field.
   */
  uint8_t   data[8];

} PHY_PBCH_DEC_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PHICH_DEC_REQ_SUB_T
 * Structure that describes decode request specific to a single UE.
 *
 */
typedef struct
{
   /*!
     * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
     * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
     * a UE by the RRC, and is sometimes called the UE ID.
     *
     * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
     *
  */
  CALL_ID_UNION_T call_id;

  uint16_t crnti;

  /*!
   * PHICH Group ID. The range of this value is dependent on the sector configuration (whichspecifies the number of PHICH groups,
   * which is a funciton of bandwidth and the system level N<SUB>g</SUB> parameter.
   */
  uint8_t grp_id;

  /*!
   * The Orthogonal Sequence index as defined by 36.211 (Table 6.9.1-2)
   *
   * Valid Range: 0-7
   *
   */
  uint8_t sequence_idx;

  uint16_t reserved;

} PHY_PHICH_DEC_REQ_SUB_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PHICH_DEC_REQ_T
 * Structure that describes the decoding request for data to be transmitted on
 * the Physical HARQ Indication Channel.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Address on which corresponding PHY_PHICH_DEC_IND resposne has to be sent.
   */
  PHY_ADDRESS_T response_address;


  /*!
   * Number of individual UE following the header.
   */
  uint32_t num_ue;

  /*!
   * Data structure containing the PHICH decode requests.
   * Though only a single instance of the data structure is shown below, there will be one instance
   * for each UE in the indication (per the num_ue parameter).
   */
  PHY_PHICH_DEC_REQ_SUB_T phich_sub[1];

} PHY_PHICH_DEC_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PHICH_DEC_IND_SUB_T
 * Structure that describes ACK/NACK specific to a single UE.
 *
 */
typedef struct
{
   /*!
     * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
     * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
     * a UE by the RRC, and is sometimes called the UE ID.
     *
     * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
     *
  */
  CALL_ID_UNION_T call_id;

  /*!
    * The Ack/Nack response to be transmitted to the UE (according to section 5.3.5.1 of 36.212).
    *
    * Refer to PHY_HI_T for possible values.
    */
   uint8_t ack_nack;

   /*! PHICH group index. Value copied from corresponding PHY_PHICH_DEC_REQ_SUB_T */
   uint8_t grp_id;

  /*!
   * Serving cell id field.
   */
   uint8_t serv_cell_idx;

  /*! PHICH orthogonal sequence index. Value copied from corresponding PHY_PHICH_DEC_REQ_SUB_T */
   uint8_t sequence_idx;

   uint16_t reserved2;

} PHY_PHICH_DEC_IND_SUB_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PHICH_DEC_IND_T
 * Structure that describes the PHICH decoded data.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Number of individual UE following the header.
   */
  uint32_t num_ue;

  uint32_t padding[1];

  /*!
   * Data structure containing the PHICH decoded data.
   * Though only a single instance of the data structure is shown below, there will be one instance
   * for each UE in the indication (per the num_ue parameter).
   */
  PHY_PHICH_DEC_IND_SUB_T phich_sub[1];

} PHY_PHICH_DEC_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_SYNC_LOST_IND_T
 * Structure that indicates that synchronization is lost based on monitoring of PCFICH channel
 * It is send 5 seconds after last PCFICH was received, and after it sync SM will re-enter signal acquistion mode.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

} PHY_SYNC_LOST_IND_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_SYNC_ACQUIRED_IND_T
 * Structure that indicates that synchronization is acquired and PCI is detected from PSCH/SSCH
 * It is used for Frame Structure Type 3 (LAA) due to absence of MIB, thus lack of PBCH_DEC_INDs
 */
typedef struct
{
    /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
    */
    PHY_MSG_HDR_T msg_hdr;

     /*!
    * Cell ID within a Cell Group as defined by 36.211.
    * This value is combined with the Cell Group to define the overall cell ID (which
    * is used for sync channel sequences, scrambling seeds, and REG mapping).

      Valid Range: 0-2

    */
    uint8_t  cell_id;

    /*!
    * Cell ID decoded from MF-PSS. Have to be the same as cell_id

    Valid Range: 0-2

    */
    uint8_t  mf_cell_id;

    /*!
    * Cell Group ID as defined by 36.211.
    * This value is combined with the Cell ID within the group to define the overall
    * cell ID (which is used for sync channel sequences, scrambling seeds and REG mapping).

      Valid Range: 0-167
    *
    */
    uint8_t  cell_grp_id;

    /*!
    * Cell Group ID decoded form MF-SSS.

      Valid Range: 0-167
    */
    uint8_t  mf_cell_grp_id;

    /*!
    * Physical Cell ID as defined by 36.211, 6.11
    *
    * pci = 3 * cell_grp_id + cell_id
    *
    */

    uint16_t pci;

    uint16_t reserved;

} PHY_SYNC_ACQUIRED_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUSCH_ENC_REQ_SUB_T
 * Structure that describes a subrequest of PUSCH_ENC_REQ, responsible for carrying
 * information about the parameters of one Transport Block.
 *
 * If necessary, corresponding PDU data shall be attached after PHY_PUSCH_ENC_REQ,
 * 'pdu_offset' and 'pdu_size' shall be updated accordingly.
 */
typedef struct
{
    /*!
     * Harq process id.
     * Used for HARQ PDU identification on PHY.
     */
    uint8_t hpid;

    /*!
     * Modulation Type
     */
    uint8_t mod_type;

    /*!
     * HARQ Incremental Redundancy Version
     * Used for HARQ PDU identification on PHY.
     */
    uint8_t harq_rv;

    /*!
     * Flag to help distinguish new transmissions from retransmissions
     *
     * 0 - retransmission
     * 1 - normal, first-time, new transmission
     */
    uint8_t new_tx;

    /*!
     *
     * This field is used for BER simulation.
     * The packet transport block CRC will not be calculated properly,
     * thus eNB will not be able to assume a packet correctly decoded.
     *
     *  0 - normal CRC calculation
     *  1 - transport block CRC will be broken
     */
    uint8_t broken_tb_crc;

    uint8_t padding0[3];
    uint32_t padding1;

    /*!
     * Transport Block Size associated with current PDU.
     * Used for HARQ PDU identification on PHY.
     */
    uint32_t tbs_size;

    /*!
     * Size of the raw data to be encoded.
     * Size is expressed in bytes.
     * Note: size shall be zero, if PDU is not attached after the message (ie. during re-TX)
     */
    uint32_t pdu_size;

    /*!
     * Raw data start position, relative to the PHY_PUSCH_ENC_REQ beginning.
     * Ofset is expressed in bytes.
     * Note: offseet shall be zero, if PDU is not attached after the message (ie. during re-TX)
     */
    uint32_t pdu_offset;

} PHY_PUSCH_ENC_REQ_SUB_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUSCH_ENC_REQ_T
 * The PUSCH Encode Request specifies a single PUSCH/MPUSCH encoding event for the PHY.
 * In this form of the message the data to be transmitted is expressed in terms of
 * a list of message descriptors ultimately containing addresses in the sRIO memory
 * space. This is used by the PHY to read the necessary bytes out of memory for
 * constructing the Transport Block.
 *
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * The RNTI value (which could be C-RNTI, sometimes called the UE ID) applicable to this encode request.
    * Used for HARQ PDU identification on PHY
    */
   CALL_ID_UNION_T  call_id;

   /*!
    * The RNTI identifier, associated with given PUSCH.
    * Used for HARQ PDU identification on PHY
    */
   uint16_t  crnti;

   /*!
   * PUSCH cluster parameters: a starting offset and a cluster length represented in # physical RB
   * CAUTION: Exclusively either cluster or prb_cluster configuration is used.
   * The actual configuration selection is checked based on judgement which of cluster[0].num_rb or prb_cluster[0].num_rb is set to non-zero.
   */
   PHY_PUSCH_PRB_CLUSTER_LIST_T prb_cluster[PHY_PUSCH_CLUSTER_MAX];

   /*!
    * PUSCH dynamic hopping params
    */
   PHY_PUSCH_HOPPING_DYN_CONFIG_T hopp_dyn_config;

   /*!
    * PUSCH INTRA CELLS INTERFERENCES data
    */
   PHY_INTRACELLS_INTERFERENCES_T interferences;

   /*!
    * The least significant nibble - represents n(2) demodulation reference signal. Domain 0..11.
    * The most significant nibble - represents delta_ss_rt applied per PUSCH request. Domain 0..16.
    * The parameter delta_ss_rt is delta_ss offset set real time, used for testing purposes, thus it shall be always 0 but when testing                                                              .
    * Setting this param to nonzero value leads to generation an interferring allocation.                                                                                                                                                                                               .
    * todo future: when changing interfaces consider extending the field to fit delta_ss_rt 0..29 domain.                                                                                            .
    */
   uint8_t   n2drs;

   /*!
    * Harq process id, DEBUG ONLY FIELD for MAC layer usage
    * NOTE: THIS FIELD IS DEPRECATED! DO NOT USE!
    */
   uint8_t   hpid;

   /*!
    * Modulation Type
    *
    * <BR>0 - QPSK
    * <BR>1 - 16-QAM
    * <BR>2 - 64-QAM (not supported in R1)
    *
    * NOTE: THIS FIELD IS DEPRECATED! DO NOT USE!
    */
   uint8_t   mod_type;

   /*!
    * HARQ Incremental Redundancy Version
    * NOTE: THIS FIELD IS DEPRECATED! DO NOT USE!
    */
   uint8_t   harq_rv;

   /*!
    * PUCCH RI LEN.  The number of uncoded bits used for RI.
    The data is MSB alligned
    */

   uint8_t   ri_len;

   /*!
    * PUCCH CQI LEN.  The number of CQI bits. Max 136 bits.
    */
   uint8_t   cqi_len;

   /*!
    * Number of CQI bits when rank equals to 1.
    * This field carries the data only for PUSCH without UL-SCH data,
    * i.e. tb_size is eq 0
    */
   uint8_t   o_cqi_min;

   /*!
    * PUCCH ACK LEN
    * It indicates number of bits in ack_data_sd
    * Value reflects also further number of pucch_ack_data bits provided in subsequent PHY_PUSCH_ACK_REQ message.
    * Caution: pucch_ack contained in PHY_PUSCH_ENC_REQ_T may-never be higher than pucch_ack_len PHY_PUSCH_ACK_REQ_T
    */
   uint8_t   ack_len;

  /*!
   * PUCCH ACK DATA EXPECTED
   * value when sunny-day scenario, i.e. no transmission errors occur
   * data (0..20 bits),  data coding is (o0|o1|o3|...|019|x20|...|x31)
   */

   uint32_t   ack_data_expected;

   /*!
    * PUCCH RI DATA. The RI data.
    * data coding is (o0|o1|o3|...|015|x16|...|x31)
    */
   uint32_t   ri_data;

   /*!
    * PUCCH CQI DATA. The CQI/PMI PDU.
    The data is MSB alligned
    Domain <0..20>
    */

   uint8_t cqi_data[PHY_PUSCH_MAX_CQI_PAYLOAD_LEN];

  /*!
   *dataMcsCodeRateOffset_ack.  The index into the table to give
   *deltaHARQ-ACK offset.
   *
   */
   uint8_t   dataMcsCodeRateOffset_ack;

  /*!
   * dataMcsCodeRateOffset_ack.  The index into the table to give
   * deltaRIoffset offset.
   */
   uint8_t   dataMcsCodeRateOffset_rankind;

  /*!
   * dataMcsCodeRateOffset_ack.  The index into the table to give
   * deltacqi offset.
   */
   uint8_t   dataMcsCodeRateOffset_cqi;

  /*!
   * Transport Block Size.  The size of the TB for this UE.
   * NOTE: THIS FIELD IS DEPRECATED! DO NOT USE!
   */
   uint16_t  tbs_size;

   /*!
    * PDCCH transport block size (obtained from the initial PDCCH for the current PUSCH).
    */
   uint16_t  PDCCH_TBS;

   /*!
    * losses table (bw_losses and pusch_gain) [dB]
    */
   uint8_t  losses[PHY_SRS_LOSSES_LEN];

   /*!
    * This field specifies the ack/nack mode
    * Value domain: PHY_ACK_NACK_MULTIPLEXING_MODE_T
    */
   uint8_t   an_mode;

   /*!
    *  N_bundled used for TDD bundling. 3GPP 36.212 5.2.2.6
    *   NOTE: this parameter is to be overriden by PUSCH_ACK_REQ message
    *   NOTE2: parameter is used internally in DSP code, please do not remove it.
    */
   uint8_t   N_bundled;

  /*!
   * debug only
   * cqi_type
   */
   uint16_t  cqi_type;

    /*!
    * This field indicates that the current subframe is configured to be SRS-subframe,
    * according to tables: TS 36.211 5.5.3.3-1,2
    * Additionally informs us if SRS is send by this UE
    *
    * <BR>0 - not SRS-subframe
    * <BR>1 - SRS-subframe, but this UE does not send SRS
    * <BR>2 - SRS-subframe and this UE send SRS
    */
    uint8_t  srs_info;

   uint8_t  padding;

   /*!
    * Precomputed cinit value. For CatM (BL/CE) usage.
    * Ignored if set to 0.
    */
   uint32_t cinit;

   uint16_t reserved;
   /*!
    * Number of transport block in a given PUSCH transmission.
    * Note: for now only a single TB PUSCH is being supported.
    */
   uint16_t  num_subs;

   /*!
    * List of transport block to be transmitted in given PUSCH transmission.
    * Note: for now only a single TB PUSCH is being supported.
    */
   PHY_PUSCH_ENC_REQ_SUB_T sub[1];

} PHY_PUSCH_ENC_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUSCH_PDU_FLUSH_REQ_T
 * Structure that describes request from L2 side to proactively remove PUSCH PDU
 * from HARQ PDU database, as PHY is unable to determine by its own, when given
 * PDU is no longer needed.
 *
 * Message shall contain all information that is required to unambiguously
 * determine which specific PDU has to be removed.
 *
 */
typedef struct
{
    /*!
     * Message header that contains fields that are common to all message types.
     * Refer to PHY_MSG_HDR_T for field definitions.
     */
    PHY_MSG_HDR_T msg_hdr;

    /*! Call Identifier associated with PDU */
    uint16_t call_id;

    /*! UE RNTI associated with PDU */
    uint16_t rnti;

    /*! Global UE identifier, TBD*/
    uint32_t global_ueid;

    /*! Transport block size - for debugging and cross-checking */
    uint32_t tbs;

    /*! HARQ process identifier */
    uint32_t hpid;

} PHY_PUSCH_PDU_FLUSH_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NPUSCH_FORMAT_1_PAR_T
 * Structure that describes NPUSCH format 1 specific parameters.
 *
 */
typedef struct
{
   /*!
    * Number of resource units. 3GPP 36.213 Table 16.5.1.1-2 (Iru)
    */
   uint8_t I_RU;

   /*!
    * Group hopping may be disabled for UE, even it is enabled in cell. 36.211 10.1.4.1.3
    */
   uint8_t group_hopping_disabled;

   /*!
    * Redundancy version field from DCI.
    */
   uint8_t rv_dci;

   /*!
    *
    * This field is used for BER simulation; the packet transport block CRC will not be calculated properly,
    * thus eNB will not be able to assume a packet correctly decoded.
    *
    *  0 - normal CRC calculation
    *  1 - transport block CRC will be broken
    *
    */
   uint8_t broken_tb_crc;

   /*!
    * Transport Block Size. The size of the TB for this UE.
    */
   uint16_t tbs_size;

} PHY_NPUSCH_FORMAT_1_PAR_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NPUSCH_ENC_REQ_T
 * Structure that describes encode request for NPUSCH
 *
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * The RNTI value (which could be C-RNTI, sometimes called the UE ID) applicable to this encode request.
    *
    */
   CALL_ID_UNION_T  call_id;

   /*!
    * Crnti DEBUG ONLY FIELD
    */
   uint16_t  crnti;

   /*!
    * NPUSCH format
    */
   uint8_t format;

   /*!
    * Subcarrier spacing. Parameter obtained from 36.213 16.3.3 apply for all transmisions of that UE.
    */
   uint8_t sc_spacing;

   /*!
    * Indicates, if all symbols are transmitted (regarding to SRS symbols). 36.211 10.1.3.6
    */
   uint8_t all_symbols;

   /*!
    * Modulation Type
    *
    * <BR>0 - BPSK
    * <BR>1 - QPSK
    */
   uint8_t mod_type;

   /*!
    * Subcarrier Indication Field. Format 1: 3GPP 36.213 Table 16.5.1.1-1 (Isc)
                                   Format 2: 3GPP 36.213 Table 16.4.2-1/2-2 (ACK/NACK subcarrier)
    */
   uint8_t I_sc;

   /*!
    * Number of repetitions. Format 1: 3GPP 36.213 Table 16.5.1.1-3 (Irep)
    *                        Format 2: 3GPP 36.213 16.4.2 (ack-NACK-NumRepetitions)
    */
   uint8_t I_Rep;

   /*!
    * Format 1 specific parameters.
    */
   PHY_NPUSCH_FORMAT_1_PAR_T format_1_par;

   /*!
    * losses table (bw_losses and npusch_gain) [dB]
    */
   uint8_t losses[PHY_SRS_LOSSES_LEN];

   /*!
    * Resource Block number, necessary information when using non-anchor carrier
    */
   int8_t rb_number;

   /*!
    * Data used by Wireshark to ttiTrace adapter. MSB order.
    * I_mcs -> 4 bits
    * hpid  -> 3 bits
    * ndi   -> 1 bit
    */
   uint8_t ttiTraceData;

   /*!
    * NPUSCH INTRA CELLS INTERFERENCES data
    */
   PHY_INTRACELLS_INTERFERENCES_T interferences;

   /*!
    * Structure containing the parameters specific to user data (transport block) or control data (bit).
    */
   //PHY_PUSCH_DATA_ELEMENT_T data_element; //TBD

} PHY_NPUSCH_ENC_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUSCH_ACK_REQ_SUB_T
 * Structure that describes decode request specific to a single UE.
 *
 */
typedef struct
{
   /*!
    *
    * UE's call_id
    *
    */
   CALL_ID_UNION_T  call_id;

   /*!
    *  N_bundled used for TDD bundling. 3GPP 36.212 5.2.2.6
    */
   uint8_t   N_bundled;

   /*!
    * The number of uncoded bits used for ACK.
    */
   uint8_t   pucch_ack_len;

   /*!
    * ACK/NACK data (1 or 2 bits).
    * data coding is (o0|o1|x|x|x|x|x|x)
    */
   uint32_t   pucch_ack_data;

} PHY_PUSCH_ACK_REQ_SUB_T;



/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUSCH_ACK_REQ_T
 * The PUSCH Ack bits Encode Request specifies a ack bits to overwritten in PUSCH encodes
.* This allows late correction of PUSCH punctured ack bits, while leaving enought time
 * for turbo encoder to properly process the data transmitted.
 *
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;


   uint16_t reserved1;
   uint8_t  reserved2;

  /*!
   * Number of individual UE following the header.
   */
   uint8_t num_ue;


  /*!
   * Data structure containing the PUSCH ACK BITS;
   * Though only a single instance of the data structure is shown below, there will be one instance
   * for each UE in the indication (per the num_ue parameter).
   */
   PHY_PUSCH_ACK_REQ_SUB_T pusch_ack_sub[1];

} PHY_PUSCH_ACK_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUCCH_ENC_REQ_SUB_T
 * Structure that describes encode request specific to a single UE.
 *
 */
typedef struct
{
   /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  CALL_ID_UNION_T  call_id;

  /*!
   * Delta_PUCCH-shift.
   */
  uint8_t   delta_pucch_shift;

  /*!
   * N^{1}_{cs} - Number of cyclic shifts used for PUCCH formats 1/1a/1b in a resource block with
   * a mix of formats 1/1a/1b and 2/2a/2b.
   */
  uint8_t   num_cs;

  /*!
   * Number of type2 resource blocks allocated to PUCCH.
   */
  uint8_t   num_rb_type2;

  /*!
   * Indicates the PUCCH format for this UE. Formats 1b & 2b are not supported for R1.
   *
   * <BR>0: PUCCH type 1
   * <BR>1: PUCCH type 1a
   * <BR>2: PUCCH type 1b
   * <BR>3: PUCCH type 1+1a
   * <BR>4: PUCCH type 1+1b
   * <BR>5: PUCCH type 2
   * <BR>6: PUCCH type 2a
   * <BR>7: PUCCH type 2b
   * <BR>8: PUCCH type 3 (ACK)
   * <BR>9: PUCCH type 3 (ACK + SR)
   *
   */
  uint8_t   pucch_format;

  /*!
   * Resource index for all formats
   */
  uint16_t  n12_pucch_res;

  /*!
   * The number of CQI/PMI/RI bits.
   */
  uint8_t   pucch_uci_len;

  /*!
  * losses table (bw_losses and pucch_gain) [dB]
  */
  uint8_t   losses[PHY_SRS_LOSSES_LEN];

   /*!
   * debug only
   */
  uint8_t uci_type;

  uint16_t  crnti;
  /*!
   * The CQI/PMI/RI PDU.
   */
  uint16_t  pucch_uci_data;

  uint16_t  reserved0;
  uint8_t   reserved1;

  /*!
   * The number of uncoded bits used for ACK.
   */
  uint8_t   pucch_ack_len;

  /*!
   * ACK/NACK and SR data (1 to 21 bits).
   * data coding is (o0|o1|...   .../o19/SR/x|x|x|x|x|x|x|x|x|x|x)
   */
  uint32_t   pucch_ack_data;

} PHY_PUCCH_ENC_REQ_SUB_T;

/*!
* \anchor PHY_MF_SR_TYPE_T
* This enumeration indicates the sr type of Multefire PUCCH encode request
*
 * \ingroup phy_param_field
*/
typedef enum
{
   SR_NON_NOMIMAL = 0,
   SR_NOMINAL_SR_ONLY,
   SR_NOMINAL_MULTIPLEX
}PHY_MF_SR_TYPE_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_MF_PUCCH_ENC_REQ_SUB_T
 * Structure that describes encode request specific to a single UE.
 *
 */
typedef struct
{
  /*!
  * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
  * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
  * a UE by the RRC, and is sometimes called the UE ID.
  *
  * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
  *
  */
  CALL_ID_UNION_T  call_id;


  uint16_t crnti;

  /*!
  * Indicates the MF-PUCCH format for this UE.
  */
  uint8_t   format;

  /*
  * Number of allocated interlaces.
  */
  uint8_t   num_interlaces;

  /*!
  * Resource index
  */
  uint16_t  resource_idx;

  /*!
  * losses table (bw_losses and pucch_gain) [dB]
  */
  uint8_t   losses[PHY_SRS_LOSSES_LEN];

  /*!
   * see PHY_MF_SR_TYPE_T
   */
  uint16_t non_nominal_sr;
  /*!
  * The number of uncoded bits used for HARQ-ACK.
  */
  uint32_t   uci_len;

  /*!
  * UCI bits (ACK/NACK + SR bit + periodic CSI reports) or (SR bit + periodic CSI reports) + optional CRC
  * Can be extended if needed.
  */
  uint8_t   uci_data[20];

} PHY_MF_PUCCH_ENC_REQ_SUB_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUCCH_ENC_REQ_T
 * Structure that describes the encode requests for data to be transmitted on
 * the Physical Uplink Control Channel.
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Number of consecutive absolute subframes over which PUCCH or PUSCH stays at the same
   * narrowband before hopping to another narrowband, expressed as a number of absolute subframes.
   *
   * This field is equal 0 for normal PUCCH (for non BL/CE UE)
  */
  uint16_t   num_ch_ul_nb;

  /*!
   * If the sector is configured to support the transmission of ACK/NACK on PUCCH and SRS in one subframe,
   * then in the cell specific SRS-subframes (36.211 tables: 5.5.3.3-1,2) UE shall transmit ACK/NACK
   * or the SR using the shortened PUCCH format
   * See 36.213, 8.2
   *
   * For CatM it describes also guard period.
   * 0 - none
   * 1 - shortened format                 - remove last symbol
   * 2 - guard period                     - remove last symbol
   * 3 - guard period + shortened format  - remove first and last symbol
   * 4 - guard period                     - remove first and last symbol
   */
  uint8_t use_shortened_format;

  /*!
   * Number of individual UE following the header.
   */
  uint8_t num_ue;

  /*!
   * Data structure containing the PUCCH encode requests.
   * Though only a single instance of the data structure is shown below, there will be one instance
   * for each UE in the indication (per the num_ue parameter).
   */
  PHY_PUCCH_ENC_REQ_SUB_T pucch_sub[1];

} PHY_PUCCH_ENC_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_MF_PUCCH_ENC_REQ_T
 * Structure that describes the encode requests for data to be transmitted on
 * the Multefire Physical Uplink Control Channel.
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
  * Symbol omiiting configuration according to LBT or SRS existence
  *
  * 0 - none
  * 1 - remove first symbol (LBT)
  * 2 - remove last symbol (SRS)
  * 3 - remove first and last symbol (LBT+SRS)
  */
  uint8_t shortened_format;

  /*!
  * Number of individual UE following the header.
  */
  uint8_t num_ue;

  /*!
  * reserved.
  */
  uint16_t reserved;

  /*!
  * Data structure containing the MF PUCCH encode requests.
  * Though only a single instance of the data structure is shown below, there will be one instance
  * for each UE in the indication (per the num_ue parameter).
  */
  PHY_MF_PUCCH_ENC_REQ_SUB_T pucch_sub[1];

} PHY_MF_PUCCH_ENC_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_SRS_CFG_REQ_T
 * Structure that describes a configuration of the sounding reference signal
 * for a single sector
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * srs-SubframeConfig 36.211 5.5.3.3-2. For NPUSCH - information in which subframe SRS is encoded.
   *
   */
  uint16_t srs_SC;

  /*!
  * SRS bandwidth configuration.
  * see TS 36.211, Tables 5.5.3.2-1 to 5.5.3.2-4
  */
  uint8_t C_SRS;

  /*!
   * If 'true', for the special frame UpPts, m_SRS_0 shall be reconfigured
   * to m_max_SRS_0 = max{m_C_SRS_0}<=(N_UL_RB-6*N_RA).
   * Note this field is only valid for TDD frame structure.
   * see TS 36.211, 5.5.3.2
   *
   * PRACH and SRS in the same UpPTS frame is not supported now, so it can be removed
   */
  uint8_t srs_MaxUpPts;

} PHY_SRS_CFG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_SRS_ENC_REQ_SUB_T
 * Structure that describes the SRS request specific to a single UE.
 *
 */
typedef struct
{
   /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  uint16_t  call_id;

  /*!
   * losses table (bw_losses and srs_gain) [dB]
   */
  uint8_t  losses[PHY_SRS_LOSSES_LEN];

  /*!
  * The cyclic shift (referred often as phase rotations) of the sounding reference signals,
  * where alpha=2*pi*n_cs_SRS/8, n_cs_SRS=(0..7)
  */
  uint8_t n_cs_SRS;

  /*!
  * The transmission comb - used to calculate frequency-domain starting position.
  * k_tc=(0,1), SRS ocupies every second subcarriers.
  */
  uint8_t k_TC;

  /*!
  * Frequency-domain position - points to block of SRS
  * n_RRC=(0..23)
  */
  uint8_t n_RRC;

  /*!
  * SRS-Bandwidth
  * b_SRS=(0..3)
  */
  uint8_t b_SRS;

  /*!
  * SRS-Hopping Bandwidth
  * b_hop=(0..3)
  */
  uint8_t b_hop;

  /*!
  *  PHY_SRS_SYMBOL_MODE_T
  *  0 - normal, 1 - special (upts) subframe first, 2 - special subframe second
  */
  uint8_t symbol_type;

  /*!
  * Counter of SRS transmissions
  */
  uint16_t n_SRS;

} PHY_SRS_ENC_REQ_SUB_T;




/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_SRS_ENC_REQ_T
 * Structure that describes the encode requests for sounding reference signals
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  uint16_t reserved;
  uint8_t reserved1;

  /*!
   * Number of individual UE following the header.
   */
  uint8_t num_ue;

  /*!
   * Data structure containing the SRS encode requests.
   * Though only a single instance of the data structure is shown below, there will be one instance
   * for each UE in the indication (per the num_ue parameter).
   */
  PHY_SRS_ENC_REQ_SUB_T srs_sub[1];

} PHY_SRS_ENC_REQ_T;




/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PUSCH_RS_CFG_REQ_T
 * Structure that describes configuration of UL RS hopping
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;


  /*!
   * groupHoppingEnabled from PUSCH-Config
   */
  uint8_t group_hopping_enabled;

  /*!
   * sequenceHoppingEnabled from PUSCH-Config
   */
  uint8_t sequence_hopping_enabled;

  /*!
   * groupAssignmentPUSCH from PUSCH-Config
   */
  uint8_t delta_ss;

  /*!
   * n(1) demodulation reference signal
   */
  uint8_t   n1drs;

  uint32_t  pci;

  RTG_UL_PUSCH_HOPPING_STATIC_CONFIG_T data;


} PHY_PUSCH_RS_AND_HOPPING_CFG_REQ_T;


/*!
 * \anchor PHY_NPUSCH_RS_CFG_REQ_T
 * Structure that describes configuration of NB-UL RS hopping and optional base sequences and cyclic shifts.
 * If optional parameter is not signaled, should be set to 0xF.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * groupHoppingEnabled from NPUSCH-Config
   */
  uint8_t group_hopping_enabled;

  /*!
   * groupAssignmentNPUSCH from NPUSCH-Config
   */
  uint8_t delta_ss;

  /*!
   * threeTone-BaseSequence from NPUSCH-Config (optional)
   */
  uint8_t threeTone_bs;

  /*!
   * threeTone-CyclicShift from NPUSCH-Config  (optional)
   */
  uint8_t threeTone_cs;

  /*!
   * sixTone-BaseSequence from NPUSCH-Config  (optional)
   */
  uint8_t sixTone_bs;

  /*!
   * sixTone-CyclicShift from NPUSCH-Config  (optional)
   */
  uint8_t sixTone_cs;

  /*!
   * twelveTone-BaseSequence from NPUSCH-Config  (optional)
   */
  uint8_t twelveTone_bs;

  uint8_t reserved;

  uint32_t  pci;

} PHY_NPUSCH_RS_CFG_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor FADING_MODEL_TAP_T
 * Describes delay and gain of single finger of fading model
 *
 */
typedef struct
{
  /*!
   * Delay in nanoseconds.
   * In implementation this will be rounded to nearest multiple of sampling rate
   */
  uint16_t delay_ns;

  /*!
   * Attenuation in centi Bells, thus greater values mean weaker signal.
   */
  uint16_t attenuation_cB;

}FADING_MODEL_TAP_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_UL_FADING_CFG_REQ_T
 * Structure that describes configuration of fading model
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Boolean flag - if ON there will be no channel model applied
   *
   */
  uint8_t bypass;

  uint8_t reserved0;

  /*!
   * Doppler frequency for Classical Doppler Spectrum in Hz
   * Maximum supported 1.25kHz. If bypass is ON this field is ignored.
   *
   */
  uint16_t doppler_freq_Hz;

  uint16_t reserved1;
  uint8_t  reserved2;

  /*!
   * Number of taps in the model
   * Currently supported: 1 tap with fixed delay = 0, 8 taps with flexible delay.
   */
  uint8_t  num_taps;

  /*!
   * Taps in order of growing delay.
   */
  FADING_MODEL_TAP_T taps;

} PHY_UL_FADING_CFG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PDSCH_DEC_IND_SUB_T
 * Structure that describes the PDSCH decoding results for a single Transport Block.
 */
typedef struct
{
   /*!
    * The RNTI value (which could be C-RNTI, sometimes called the UE ID)
    * applicable to this decode indication.
    *
    */
   CALL_ID_UNION_T  call_id;

   /*! C-RNTI */
   uint16_t crnti;

   /*!
    * CRC status field.
    *
    * <BR>0 - Fail
    * <BR>1 - Pass
    */
   uint8_t  crc_status;

   /*! Codeword number - 0-based */
   uint8_t codeword_num;

   /*! * HARQ process id */
   uint16_t hpid;

   /*!
    * Size of the raw decoded data in bytes (excluding the CRC)
    * Note: shall be set to zero, when CRC had failed.
    */
   uint32_t pdu_size;

   /*!
    * Raw data start position, relative to the PHY_PDSCH_DEC_IND beginning.
    * Ofset is expressed in bytes.
    * Note: shall be set to zero, when CRC had failed.
    */
   uint32_t pdu_offset;

   /*! Transport block CRC-24A, as received */
   uint32_t tb_crc;

   uint32_t padding[1];

} PHY_PDSCH_DEC_IND_SUB_T;

/*!
 * \anchor PHY_PDSCH_DEC_IND_T
 * This message carries the PDSCH decoding results for a single UE and corresponding PDUs to the L2.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
    PHY_MSG_HDR_T msg_hdr;

    /*! This field contains additional MAC-specific information */
    uint32_t cookie;

    /*! L2 Virtual cell identifier */
    uint32_t virtual_cell_id;

    /*! This field indicates number of Transport Blocks and 'subs' carried. */
    uint32_t  num_tb;

    /*! Serving cell index */
    uint32_t serv_cell_idx;

    /*! List of PDSCH decode indication results */
    PHY_PDSCH_DEC_IND_SUB_T pdsch_ind_sub[1];

} PHY_PDSCH_DEC_IND_T;

/*!
 * \anchor PHY_PDSCH_DEC_PAR_IND_SUB_T
 * Structure that describes the PDSCH decode parametric results for a single UE.
 */
typedef struct
{
  /*!
    * The RNTI value (which could be C-RNTI, sometimes called the UE ID)
    * applicable to this decode indication.
    *
    */
   CALL_ID_UNION_T  call_id;

   /*!
    * UL HARQ Channel ID
    *
    * The HARQ channel associated with the PDSCH CRC.
    */
   uint8_t   dl_harq_chan_id;

   /*
    * Codeword number - 1 or 2 codewords
    */
   uint8_t codeword_num;

   /*!
    * CRC field, bitmap, CW1 at LSB
    *
    * <BR>0 - Fail
    * <BR>1 - Pass CW1
    * <BR>2 - Pass CW2, fail CW1
    * <BR>3 - Pass CW1 and CW2
    */
   uint8_t  CRC;

   /*!
    * <BR> PHY_NON_SPS        - 0
    * <BR> PHY_SPS_ACTIVATION - 1
    * <BR> PHY_SPS_RELEASE    - 2
    * <BR> PHY_SPS_RETX       - 3
    * <BR> PHY_SPS_FAKE       - 4
    */
   uint8_t   sps_ind;

   /*!
    * Mode differentiation
    * PHY_LEGACY_LTE - 0
    * PHY_CAT_M - 1
    * PHY_NARROWBAND - 2
    *
    */
   uint8_t iot_mode;

   /*!
    * Narrowband Resource Block number, necessary information when using Narrowband non-anchor carrier
    * Or Serving cell ID, for legacy LTE
    */
   int8_t nb_rb_number;

   /*!
   * CatM HARQ-ACK delay - 3 bits as defined in section 7.3 of 36.213.
   */
  uint8_t mpdcch_harq_ack_delay;

  /*!
   * CatM Transport blocks in a bundle - 2 bits as defined in section 7.3 of 36.213.
   */
  uint8_t tb_in_a_bundle;

  /*!
   * CatM HARQ-ACK bundling flag - 1 bit as defined in section 7.3 of 36.213.
   */
  uint8_t harq_ack_bundling_flag;

  uint8_t reserved;

}PHY_PDSCH_DEC_PAR_IND_SUB_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PDSCH_DEC_PAR_IND_T
 * This message delivers the PDSCH decode parametric results to the UeSch.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Number of UE in pdsch_par_sub. Bundling of parametric results are limited to 5
    * results per message.
    */
   uint8_t num_ue;

   /*!
    * Serving cell id field. NOT USED, moved to PHY_PDSCH_DEC_PAR_IND_SUB_T
    */
   uint8_t serv_cell_idx;

  /*!
   * Reserved/debug field.
   */
   uint16_t reserved1;

   /*!
    * List of PDSCH parametric indication messages.
    */
   PHY_PDSCH_DEC_PAR_IND_SUB_T pdsch_par_sub[1];

} PHY_PDSCH_DEC_PAR_IND_T;

/*!
 * \anchor PHY_MBMS_SESSION_SUB_T
 * Structure that describes expected data from PMCH in given MBSFN subframe
 */
typedef struct
{
  /*! (1..255) owned by uesim & mapped to TMGI-r9  */
  uint16_t local_session_id;
  /*! MAC logical channel id (0..28)*/
  uint16_t logicalChannelIdentity;

} PHY_MBMS_SESSION_SUB_T;
/*!
 * \anchor PHY_PMCH_DEC_REQ_SUB_T
 * Structure that describes decode request for PMCH in given MBSFN subframe
 */
typedef struct
{
  /*! MBSFN area index */
  uint16_t n_mbsfn_id;

   /*! Modulation and Coding Scheme index for PMCH codeword. Range 0 to 28. Refer to 36.213 section 7.1.7 for reference. */
  uint8_t  imcs;

  /*!
    * Subframe number associated with the request / indicator.
    *
    * Note that a value of "don't care" signifies that no subframe number validation should be made on the message.
    *
    * Valid Range: 0 - 9, 0xFF for "don't care".
    */
   uint8_t subframe_num;
   /*! additional session information
    * pmch_num (0..maxPMCH-PerMBSFN(15))
    * num_session 0..maxSessionPerPMCH(29)
    * PHY_MBMS_SESSION_SUB_T session_elem[29];
    */
   uint16_t            pmch_num;        /* (0..maxPMCH-PerMBSFN(15)) */
   uint16_t            num_session;    /* (0..maxSessionPerPMCH(29)) */
   PHY_MBMS_SESSION_SUB_T session_elem[29];

} PHY_PMCH_DEC_REQ_SUB_T;


/*!
 * \anchor PHY_PMCH_DEC_REQ_T
 * Structure that contain decode requests for all PMCHs within specified LTE radio frame
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;
   uint32_t num_subf_req;
   PHY_PMCH_DEC_REQ_SUB_T pmch[1];

} PHY_PMCH_DEC_REQ_T;


/*!
 * \anchor PHY_PMCH_DEC_IND_T
 * This message carries the PMCH reception notification to the Host. Transmission of this
 * message indicates the PHY has finished delivery of the PMCH payload to the host.
 *
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * CRC field.
    *
    * <BR>0 - Fail
    * <BR>1 - Pass
    */
   uint16_t  CRC;

  /*! MBSFN area index */
   uint16_t n_mbsfn_id;

  /*! additional session information
    * pmch_num (0..maxPMCH-PerMBSFN(15))
    * num_session 0..maxSessionPerPMCH(29)
    * PHY_MBMS_SESSION_SUB_T session_elem[29];
    */
   uint16_t            pmch_num;       /* (0..maxPMCH-PerMBSFN(15)) */
   uint16_t            num_session;    /* (0..maxSessionPerPMCH(29)) */
   PHY_MBMS_SESSION_SUB_T session_elem[29];

   /*!
    * Size of the raw decoded data in bytes (excluding the CRC).
    *
    */
   uint32_t  data_size;

   /*!
    * The raw decoded data starts at this location offset in memory.
    */
   uint32_t memory_offset;

} PHY_PMCH_DEC_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PDCCH_DEC_IND_SUB_T
 * Structure that describes the decode indication for data transmitted
 * on the Physical Downlink Control Channel Channel.
 *
 */
typedef struct
{
  /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  CALL_ID_UNION_T  call_id;

  /*!
   * RNTI this PDCCH was addressed to.
   */
  uint16_t rnti;

  /*!
   * PDCCH DCI format
   * Refer to PHY_DCI_FORMAT_T for field definitions.
   */
  uint8_t format;

  /*!
   * Number of the first CCE used for transmission of the DCI
   */
  uint8_t start_res;

  /*
   * Number of codewords - 1-based
   */
  uint8_t num_of_codewords;

  /*!
   * preamble_index, prach_mask_index are used for random access
   * procedure initiated by a PDCCH order (36.212, 5.3.3.1.3)
   * Fields are reserved otherwise.
   */
  uint8_t  preamble_index;

  uint8_t  prach_mask_index;
  uint8_t  starting_ce_level;
  uint8_t  tpc;
  uint8_t  is_ue_specific_search_space;

  /*!
   * HARQ-ACK resource - 4 bits as defined in section 16.4.2 of 36.213.
   */
  uint8_t npdcch_harq_resource;

  /*!
   * CatM HARQ-ACK delay - 3 bits as defined in section 7.3 of 36.213.
   */
  uint8_t mpdcch_harq_ack_delay;

  /*!
   * CatM Transport blocks in a bundle - 2 bits as defined in section 7.3 of 36.213.
   */
  uint8_t tb_in_a_bundle;

  /*!
   * CatM HARQ-ACK bundling flag - 1 bit as defined in section 7.3 of 36.213.
   */
  uint8_t harq_ack_bundling_flag;

  /*!
   *  Bitmap for representing physical RB allocation. One bit corresponds to single RB, with MSB representing RB 0.
   *  Reserving 128 bits to cover 20 MHz. Both maps for suitably even and odd slots carry the same contents for localized VRB.
   */
  uint32_t prb_bitmap[PHY_NUM_SLOT_SUBF][PHY_RB_BITMAP_LEN];

  /*! Transport Block size (in bits) */
  uint32_t  tb_size_cw1;

  /*! Transport Block size (in bits) */
  uint32_t  tb_size_cw2;

  /*! Modulation and Coding Scheme index for codeword 0. Range 0 to 31. Refer to 36.213 section 7.1.7 for reference. */
  uint8_t  imcs_cw1;

  /*! Modulation and Coding Scheme index for codeword 1. Range 0 to 31. Refer to 36.213 section 7.1.7 for reference. */
  uint8_t  imcs_cw2;

  /*! Transport block to CW swap Indication */
  uint8_t tb_swap;

  /*! Downlink Assignment Index */
  uint8_t  dai;

  /*!
   * DCI 0 or 3/3A raw data - MSB alligned bitstream
   * or reserved
   */
  uint8_t  ul_dci[PHY_UL_DCI_LEN];

  /*Downlink Harq process Id*/
  uint8_t   hpid;

  /*!
   * Downlink Tx flag - codeword 1
   * <BR>1 - new Tx transmission
   * <BR>0 - rtx
   */
  uint8_t   new_tx_cw1;

  /*!
   *Downlink Tx flag - codeword 2
   * <BR>1 - new Tx transmission
   * <BR>0 - rtx
   */
  uint8_t   new_tx_cw2;

  /*!
   * <BR> PHY_NON_SPS        - 0
   * <BR> PHY_SPS_ACTIVATION - 1
   * <BR> PHY_SPS_RELEASE    - 2
   * <BR> PHY_SPS_RETX       - 3
   * <BR> PHY_SPS_FAKE       - 4
   */
  uint8_t   sps_ind;

  /*!
   * Serving cell id field.
   */
  uint8_t serv_cell_idx;

  /*!
   * Subframe num of the last PDSCH repetition
   */
  uint8_t pdschSubframe;

  /*!
   * Frame num of the last PDSCH repetition
   */
  uint16_t pdschFrame;

  /*!
   * Reserved for debugs
   */
  uint8_t reserved1; /* Used by Wireshark to ttiTrace adapter. Field: resource allocation type */
  uint8_t reserved2;
  uint16_t reserved3;

} PHY_PDCCH_DEC_IND_SUB_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PDCCH_DEC_IND_T
 * Structure that describes the decode indication for data transmitted
 * on the Physical Downlink Control Channel Channel.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Reserved/Debug field.
   */
  uint16_t  reserved;
  /*!
   * Size of control region in this subframe
   */
  uint8_t   cfi;

  /*!
   * Number of individual UE following the header.
   */
  uint8_t   num_ue;

  PHY_PDCCH_DEC_IND_SUB_T  pdcch_dci[1];

} PHY_PDCCH_DEC_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PRS_DEC_IND_T
 * Structure that describes the decode indication for data transmitted
 * on the Physical Downlink Control Channel Channel.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Number of individual UE following the header.
   */
  uint8_t   num_syms;
  uint8_t   padding1;
  uint16_t  padding2;

  /*!
   * Raport per antenna/per PRS in centiBells.
   */
  int16_t  c2i_cB[PHY_MAX_PRS_ANTENNAS][PHY_MAX_PRS_SYMBOLS];

} PHY_PRS_DEC_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PDCCH_CFG_REQ_T
 * Structure that describes the PDCCH configuration for mobile.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  CALL_ID_UNION_T  call_id;

  uint16_t  rnti;

  /*!
   * Action to take (add/modify/delete). See PHY_RNTI_ACTION enum.
   */
  uint8_t action;

  /*!
   * C-RNTI Type (refer to PHY_RNTI_T enum):
   * <BR>0  - C-RNTI
   * <BR>1  - P_RNTI
   * <BR>2  - RA_RNTI
   * <BR>3  - SI_RNTI
   * <BR>4  - SPS_C_RNTI
   * <BR>5  - T_C_RNTI
   * <BR>6  - TPC_PUSCH_RNTI
   * <BR>7  - TPC_PUCCH_RNTI
   * <BR>8  - M_RNTI
   * <BR>9  - NB_RNTI
   * <BR>10 - CC_RNTI
   */
  uint8_t rnti_type;

  /*!
   * Transmission Mode:
   * <BR>1 - Single-antenna port; port 0
   * <BR>2 - Transmit diversity
   * <BR>3 - Open-loop spatial multiplexing
   * <BR>4 - Closed-loop spatial multiplexing
   * <BR>5 - Multi-user MIMO
   * <BR>6 - Closed-loop Rank=1 precoding
   * <BR>7 - Single-antenna port; port 5
   *
   */
  uint8_t transmission_mode;

  /*!
   * PMI used when no PMI assigned on PDCCH. Used only for transmission mode 4,6:
   *
   */
  uint8_t current_pmi;

  /*!
   * UE Category (36.306)
   *
   */
  uint8_t ue_category;

  uint8_t last_rank_reported;

  /*! This value corresponds to a total power adjust (relative to RS power) for PDSCH REs in all OFDM symbols
   *  not containing Cell-Specific RS (according to section 5.2 of 36.213) as represented by the UE-specific
   *  semi-static parameter P<SUB>A</SUB>. This parameter ranges from -6 dB to +3 dB (the specific values shown below are
   *  defined in the "PDSCH-Configuration" section of 36.331).
   *  Each value will map to a net gain adjust according to the following:
   *  <BR> 0 - -6 dB
   *  <BR> 1 - -4.77 dB
   *  <BR> 2 - -3 dB
   *  <BR> 3 - -1.77 dB
   *  <BR> 4 - 0 dB
   *  <BR> 5 - +1 dB
   *  <BR> 6 - +2 dB
   *  <BR> 7 - +3 dB
   *
   *  <BR> All other values are invalid.
   *  <BR> NOTE: Since MU MIMO is not supported in R1 and R2, there is no need to account for the additional power offset
   *  related to this transmission mode.  When this feature is reported, this interface will be adjusted to include
   *  a power_offset parameter.
   *  <BR>NOTE: relative gain for PDSCH REs in all OFDM symbols containing Cell-Specific RS is based on a value that
   *  is derived from the P<SUB>B</SUB> parameter (see pdsch_power_index_b in PHY_CELL_CONFIG_REQ_T), this value and
   *  the number of antennas.
   */
  uint8_t  ue_power_index;

  /*!
   *  Semi Persistent Scheduling Interval:
   *  <BR> PHY_SF10  - 0
   *  <BR> PHY_SF20  - 1
   *  <BR> PHY_SF32  - 2
   *  <BR> PHY_SF40  - 3
   *  <BR> PHY_SF64  - 4
   *  <BR> PHY_SF80  - 5
   *  <BR> PHY_SF128 - 6
   *  <BR> PHY_SF160 - 7
   *  <BR> PHY_SF320 - 8
   *  <BR> PHY_SF640 - 9
   */
  uint8_t dl_sps_interval;

  /* Number of confgured SPS-Processes (range 1..8, as described by 36.331, section 6.3.2) */
  uint8_t num_of_conf_sps_proc;

  /*!
   * Carrier Indication Flag mode:
   *  <BR> 0  - disabled,
   *  <BR> 1  - CIF enabled,
   *  <BR> 2  - virtual UE in secondary cell
   */
  uint8_t cif_enabled;

  /* ServCell index, valid range: 0-7 */
  uint8_t serv_cell_idx;

   /*!
    * UE cell configuration:
    *  <BR> 0  - UE configured with one cell,
    *  <BR> 1  - UE configured with multiple cells
    */
   uint8_t  multi_cell_flag;

   /*!
    * SRS trigger type:
    *  <BR> 0  - SRS trigger type 0,
    *  <BR> 1  - SRS trigger type 1,
    *  <BR> 2  - SRS trigger type 0 and type 1
    */
  uint8_t  srs_trigger_type;

   /*!
    * Enable QAM256 modulation
    *  <BR> 0  - QAM256 disabled
    *  <BR> 1  - QAM256 enabled
    */
  uint8_t  qam256_enable;

  /*!
   * 3GPP parameters, that allow UE to use alternative I_TBS values (such as 33A or 33B) during TBS determination
   */
  uint8_t tbsIndexAlt;
  uint8_t tbsIndexAlt2;

  /*!
   * Maximum number of spatial multiplexing layers supported
   */
  uint8_t  max_lays_supported;

  /*!
   * Specifies UE unlicensed band capability.
   * Refer to PHY_UE_BAND_CAPABILITY_T enum.
   *
   * <BR>0: LTE-L only capable
   * <BR>1: LTE-U capable
   * <BR>2: LAA capable
   * <BR>3: MulteFire capable
   */
  uint8_t ue_band_capability;

  /*!
   *   Frame type of primary cell, value of PHY_PARAM_FM_CFG_T.
   */
  uint8_t pcell_frame_structure;

  /*!
   * DL-reference UL/DL Configuration (values: 0-6)
   */
  uint8_t dl_ref_ul_dl_config;

  /*!
   * Communication endpoints adresses for data and signalling.
   */
  PHY_ADDRESS_T dest_address_data;
  PHY_ADDRESS_T dest_address_sig;

  /*!
   * To perform load-balancig, L2 has to know mapping between UE and Virtual Cell to which UE is assigned to.
   */
  uint32_t virtual_cell_id;

} PHY_PDCCH_CFG_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NPDCCH_CFG_REQ_T
 * Structure that describes the NPDCCH configuration for mobile.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  CALL_ID_UNION_T  call_id;

  uint16_t  rnti;

  /*!
   * Action to take (add/modify/delete). See PHY_RNTI_ACTION enum.
   */
  uint8_t action;

  /*!
   * C-RNTI Type (refer to PHY_RNTI_T enum):
   * <BR>0  - C-RNTI
   * <BR>1  - P_RNTI
   * <BR>2  - RA_RNTI
   * <BR>3  - SI_RNTI
   * <BR>4  - SPS_C_RNTI
   * <BR>5  - T_C_RNTI
   * <BR>6  - TPC_PUSCH_RNTI
   * <BR>7  - TPC_PUCCH_RNTI
   * <BR>8  - M_RNTI
   * <BR>9  - NB_RNTI
   * <BR>10 - CC_RNTI
   */
  uint8_t rnti_type;

  /*! This value corresponds to a total power adjust (relative to RS power) for PDSCH REs in all OFDM symbols
   *  not containing Cell-Specific RS (according to section 5.2 of 36.213) as represented by the UE-specific
   *  semi-static parameter P<SUB>A</SUB>. This parameter ranges from -6 dB to +3 dB (the specific values shown below are
   *  defined in the "PDSCH-Configuration" section of 36.331).
   *  Each value will map to a net gain adjust according to the following:
   *  <BR> 0 - -6 dB
   *  <BR> 1 - -4.77 dB
   *  <BR> 2 - -3 dB
   *  <BR> 3 - -1.77 dB
   *  <BR> 4 - 0 dB
   *  <BR> 5 - +1 dB
   *  <BR> 6 - +2 dB
   *  <BR> 7 - +3 dB
   *
   *  <BR> All other values are invalid.
   *  <BR> NOTE: Since MU MIMO is not supported in R1 and R2, there is no need to account for the additional power offset
   *  related to this transmission mode.  When this feature is reported, this interface will be adjusted to include
   *  a power_offset parameter.
   *  <BR>NOTE: relative gain for PDSCH REs in all OFDM symbols containing Cell-Specific RS is based on a value that
   *  is derived from the P<SUB>B</SUB> parameter (see pdsch_power_index_b in PHY_CELL_CONFIG_REQ_T), this value and
   *  the number of antennas.
   */
  uint8_t  ue_power_index;

   /*!
    *    twoHARQ-Processes - Does UE support 2 HARQ processes operation in DL and UL
    */
  uint8_t  twoHarqEnabled;

  uint16_t reserved2;

   /*!
    *    npdcch-NumRepetitions-r13           ENUMERATED {r1, r2, r4, r8, r16, r32, r64, r128,
                                                         r256, r512, r1024, r2048,
                                                         spare4, spare3, spare2, spare1},
    */
  uint16_t num_repetitions;

   /*!
    *    npdcch-StartSF-USS-r13              ENUMERATED {v1dot5, v2, v4, v8, v16, v32, v48, v64},
    */
  uint8_t start_sf;
   /*!
    *    npdcch-Offset-USS-r13               ENUMERATED {zero, oneEighth, oneFourth, threeEighth}
    */
  uint8_t offset;

  uint16_t  reserved;

  /*!
   * Communication endpoints adresses for data and signalling.
   */
  PHY_ADDRESS_T dest_address_data;
  PHY_ADDRESS_T dest_address_sig;

  /* To perform load-balancig, L2 has to know mapping between UE and Virtual Cell to which UE is assigned to.
   */
  uint32_t virtual_cell_id;

} PHY_NPDCCH_CFG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_MPDCCH_CFG_REQ_T
 * Structure that describes the MPDCCH configuration for mobile.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  CALL_ID_UNION_T  call_id;

  uint16_t  rnti;

  /*!
   * Action to take (add/modify/delete). See PHY_RNTI_ACTION enum.
   */
  uint8_t action;

  /*!
   * C-RNTI Type (refer to PHY_RNTI_T enum):
   * <BR>0  - C-RNTI
   * <BR>1  - P_RNTI
   * <BR>2  - RA_RNTI
   * <BR>3  - SI_RNTI
   * <BR>4  - SPS_C_RNTI
   * <BR>5  - T_C_RNTI
   * <BR>6  - TPC_PUSCH_RNTI
   * <BR>7  - TPC_PUCCH_RNTI
   * <BR>8  - M_RNTI
   * <BR>9  - NB_RNTI
   * <BR>10 - CC_RNTI
   */
  uint8_t rnti_type;

    /*!
   * Transmission Mode:
   * <BR>1 - Single-antenna port; port 0
   * <BR>2 - Transmit diversity
   * <BR>6 - Closed-loop Rank=1 precoding
   * <BR>9
   *
   */
  uint8_t transmission_mode;

  /*!
   * UE Category (36.306)
   *
   */
  uint8_t ue_category;

  /*! This value corresponds to a total power adjust (relative to RS power) for PDSCH REs in all OFDM symbols
   *  not containing Cell-Specific RS (according to section 5.2 of 36.213) as represented by the UE-specific
   *  semi-static parameter P<SUB>A</SUB>. This parameter ranges from -6 dB to +3 dB (the specific values shown below are
   *  defined in the "PDSCH-Configuration" section of 36.331).
   *  Each value will map to a net gain adjust according to the following:
   *  <BR> 0 - -6 dB
   *  <BR> 1 - -4.77 dB
   *  <BR> 2 - -3 dB
   *  <BR> 3 - -1.77 dB
   *  <BR> 4 - 0 dB
   *  <BR> 5 - +1 dB
   *  <BR> 6 - +2 dB
   *  <BR> 7 - +3 dB
   *
   *  <BR> All other values are invalid.
   *  <BR> NOTE: Since MU MIMO is not supported in R1 and R2, there is no need to account for the additional power offset
   *  related to this transmission mode.  When this feature is reported, this interface will be adjusted to include
   *  a power_offset parameter.
   *  <BR>NOTE: relative gain for PDSCH REs in all OFDM symbols containing Cell-Specific RS is based on a value that
   *  is derived from the P<SUB>B</SUB> parameter (see pdsch_power_index_b in PHY_CELL_CONFIG_REQ_T), this value and
   *  the number of antennas.
   */
  uint8_t  ue_power_index;

   /*!
    *    startSymbol-r11 INTEGER (1..4)
    */

  uint8_t start_symbol;

   /*!
    *    transmissionType-r11  ENUMERATED {localised, distributed}
    */

  uint8_t transmission_type;

   /*!
    *    numberPRB-Pairs-r11 ENUMERATED {n2, n4, n6, n8},  //beware
    */

  uint8_t number_prb_pairs;

   /*!
    *    resourceBlockAssignment-r11 BIT STRING (SIZE(4..38))
    */

  uint8_t  resource_block_assignment[5];

   /*!
    *    mpdcch-StartSF-UESS-r13 ENUMERATED {v1, v1dot5, v2, v2dot5, v4, v5, v8, v10},
    */
  uint8_t start_sf;

   /*!
    *    mpdcch-pdsch-HoppingConfig-r13 ENUMERATED {on,off},
    */

  uint8_t hopping_config;

   /*!
    *    mpdcch-Narrowband-r13 INTEGER (1.. maxAvailNarrowBands-r13) ,
    */

  uint8_t nb_idx;


   /*!
    *   ce-Mode-r13 ENUMERATED {ceModeA, ceModeB} refer to PHY_CATM_CE_MODE
    */
  uint8_t ce_mode;

  /*!
   *   ce-PDSCH-TenProcesses-r14 ENUMERATED {on,off}
   */
  uint8_t tenHarqEnabled;

  /*!
   *   ce-HarqAckBundling-config
   */
  uint8_t harq_ack_bundling_config;

  /*!
   *   ce-schedulingEnhancement-config
   */
  uint8_t scheduling_enhancement_config;

  /*!
    *    dmrs-ScramblingSequenceInt-r11 INTEGER (0..503),
    */

  uint16_t scrambling_init;

   /*!
    *    mpdcch-NumRepetition-r13 ENUMERATED {r1, r2, r4, r8, r16, r32, r64, r128, r256},
    */
  uint16_t num_repetitions;

   /*!
    *   pdsch-maxNumRepetitionCEmodeA-r13 ENUMERATED {not_configured, r16, r32 }
    */
  uint16_t pdsch_max_num_rep_ce_mode_a;

   /*!
    *   pdsch-maxNumRepetitionCEmodeB-r13 ENUMERATED {not_configured, r192, r256, r384, r512, r768, r1024, r1536, r2048}
    */

  uint16_t pdsch_max_num_rep_ce_mode_b;


  /*!
   * Communication endpoints adresses for data and signalling.
   */
  PHY_ADDRESS_T dest_address_data;
  PHY_ADDRESS_T dest_address_sig;

  /* To perform load-balancig, L2 has to know mapping between UE and Virtual Cell to which UE is assigned to.
   */
  uint32_t virtual_cell_id;

} PHY_MPDCCH_CFG_REQ_T;


typedef struct
{
  /*! Configuration for zeroTxPower: Bitmap as defined in CSI-RS-Config of 36.331 */
  uint16_t resourceConfigList;

  /*! Configuration for zeroTxPower as defined in CSI-RS-Config of 36.331. Same range as subframeConfig */
  uint8_t  subframeConfig;

  uint8_t  reserved1;
} PHY_CSI_CFG_REQ_SUB_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CSI_CFG_REQ_T
 * Structure that describes the CSI configuration for mobile.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   *
   * This field is only to express MAC/RLC/RRC intention to inform PHY of UE that had received RRC message.
   * RTG PHY ignores it. DEBUG ONLY.
   *
   */
  CALL_ID_UNION_T  call_id;

  /*!
   * enable (1) or disable (0).
   */
  uint8_t enable;

  /*!
   * <BR> PHY_ANTENNA_PORT_COUNT_1 - 0
   * <BR> PHY_ANTENNA_PORT_COUNT_2 - 1
   * <BR> PHY_ANTENNA_PORT_COUNT_4 - 2
   * <BR> PHY_ANTENNA_PORT_COUNT_8 - 3
   */
  uint8_t  antennaPortsCount;

  /*!
   * Resource config as defined in CSI-RS-Config 36.331.
   * Refer to CSI reference signal configuration in 6.10.5.2-1 of 36.211
   * Range: 0..31 (supported: 0..9)
   */
  uint8_t  resourceConfig;

  /*!
   * Subframe config as defined in CSI-RS-Config 36.331.
   * Refer to 6.10.5.3 of 36.211
   * Range: 0..154
   */
  uint8_t  subframeConfig;

  /*!
   * p-C as defined in CSI-RS-Config 36.331.
   * Range: -8..15 [dB]
   */
  int8_t   p_C;

  /*!
   * Num zeroTx groups. For Tm9 shall be 0 or 1.
   */
  uint8_t num_zero_tx;

  /*!
   * The variable part of the message starts here.
   */
  PHY_CSI_CFG_REQ_SUB_T zero_tx_grp[1];

} PHY_CSI_CFG_REQ_T;


/*!
 * \anchor PHY_NB_CFG_REQ_T
 * Structure that describes the narrow-band configuration for mobile.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /* Resource block number in which narrow-band resides. */
  int8_t   dl_rb[PHY_MAX_NB_CARRIERS];
  int8_t   ul_rb[PHY_MAX_NB_CARRIERS];

  uint8_t  num_dl_rb;
  uint8_t  num_ul_rb;

  /* PHY_NARROWBAND_OPMODE_T PHY_NB_INBAND_SAME_PCI =  0, PHY_NB_INBAND_DIFFERENT_PCI =  1, PHY_NB_GUARDBAND  =  2, PHY_NB_STANDALONE  =  3 */
  uint8_t op_mode;

  uint8_t reserved;

} PHY_NB_CFG_REQ_T;


/*!
 * \anchor PHY_PRS_CFG_REQ_T
 * Structure that describes the narrow-band configuration for mobile.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*! Parameter defined in 36.211 6.10.4.3: 0-2399, values 2400-4095 reserved */
  uint16_t  Iprs;

  /*! Parameter defined in 36.211 6.10.4.3: One of: { 1,2,4,6 } */
  uint8_t   Nprs;

  uint8_t    padding;
} PHY_PRS_CFG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PDSCH_DEC_REQ_T
 * Structure that describes the PDSCH decoding. TODO: Potentially used only for semi-persistent
 * scheduling.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * The first two bytes of this field is not used by PHY at this point but it's part of Call ID that is defined by
   * the RRC and passed down to MAC. The second two bytes of this field contain the C-RNTI value that is assigned to
   * a UE by the RRC, and is sometimes called the UE ID.
   *
   * <b> NOTE: We can discuss changing this to a 16 bit C-RNTI. </b>
   *
   */
  CALL_ID_UNION_T  call_id;
  uint16_t  reserved;

} PHY_PDSCH_DEC_REQ_T;


typedef struct
{
   /*!
   * UE's call_id
   */
   CALL_ID_UNION_T  call_id;

  /*!
   *  Logical root seqence index. (36.211, table 5.7.2-4)
   */
  uint16_t rootLogSeq;

  /*!
   * Cyclic shift (36.211, section 5.7.2)
   */
  uint16_t cv_offset;

  /*!
   * Per preamble scaling factor. Format Q1.15
   */
  uint16_t scaling;

  /*!
  * Path delay in units of Ts. Range [0..24575]
  */
  uint16_t path_delay;

  /*!
   * Index of the preamble to be sent (range 1..64). For debug only.
   */
  uint8_t preamble_idx;

  uint8_t  reserved0;

} PHY_PRACH_ENC_REQ_SUB_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_PRACH_ENC_REQ_T
 * Structure that describes the PRACH encoding request.
 * scheduling.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
  * Prach frequency offset
  */
  int16_t f_offset;


  /*
  *preamble format [0 - format 0; 4 - format 4] for sector (36.211, table 5.7.1-2,3)
  */
  uint8_t  preamble_format;

  uint8_t  reserved0;

  /*
  * Prameters per UE
  */

  /* num_ue indicates number of repetitions of PHY_PRACH_ENC_REQ_SUB_T at the tail of the PHY_PRACH_ENC_REQ_T */
  uint32_t num_ue;

  /*
  * The variable part of the message starts here
  */

  PHY_PRACH_ENC_REQ_SUB_T ue_preamble[1];

} PHY_PRACH_ENC_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_NPRACH_ENC_REQ_SUB_T
 * Structure that describes the sub for NPRACH encoding request.
 * scheduling.
 *
 */
typedef struct
{
   /*!
   * UE's call_id
   */
   CALL_ID_UNION_T  call_id;

   uint16_t reserved0;
   uint16_t reserved1;
   /*!
    * Per preamble scaling factor. Format Q1.15
    */
   uint16_t scaling;

   uint16_t path_delay;

   /*!
    * Index of the preamble to be sent (range 0..11).
    */
   uint8_t preamble_idx;

   uint8_t resource_index;

} PHY_NPRACH_ENC_REQ_SUB_T;


/*!
 * \anchor PHY_NPRACH_ENC_REQ_T
 * Structure that describes the PRACH encoding request.
 * scheduling.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  int16_t reserved0;
  /*
  *preamble format [0 - format 0; 1 - format 1] for sector
  */
  uint8_t  preamble_format;
  /*
  * Index of configured NPRACH resource to use.
  */
  uint8_t  reserved1;

  /*
  * Prameters per UE
  */

  /* num_ue indicates number of repetitions of PHY_PRACH_ENC_REQ_SUB_T at the tail of the PHY_PRACH_ENC_REQ_T */
  uint32_t num_ue;

  /*
  * The variable part of the message starts here
  */

  PHY_NPRACH_ENC_REQ_SUB_T ue_preamble[1];

} PHY_NPRACH_ENC_REQ_T;


typedef struct
{
  /*!
   * Number of repetitions
   */
  uint16_t repetitions;

  /*!
   * Periodicity
   */
  uint16_t periodicity;

  /*!
   * Starting time of period
   */
  uint16_t starting_time;

  /*!
   * Frequency location in subcarrier offset
   */
  uint8_t sc_offset;

  /*!
   * Number of subcarriers
   */
  uint8_t num_sc;
} PHY_NPRACH_PARAMETERS_LIST_T;


/*!
 * \anchor PHY_NPRACH_CFG_REQ_T
 * Structure that describes the NPRACH config request.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   * Preamble format [0 - format 0; 1 - format 1] corresponding to CP length
   */
  uint16_t preamble_format;

  /*!
   * Number of configured resources.
   */
  uint16_t num_of_resources;

  /*!
   * NPRACH configuration list.
   */
  PHY_NPRACH_PARAMETERS_LIST_T resources[PHY_MAX_NPRACH_RESOURCES];

} PHY_NPRACH_CFG_REQ_T;


typedef struct
{
  /*!
  * UE's call_id
  */
  CALL_ID_UNION_T  call_id;

  /*!
   *  Logical root seqence index. (36.211, table 5.7.2-4)
   */
  uint16_t logical_root;

  /*!
   * Per preamble scaling factor. Format Q1.15
   */
  uint16_t scaling;

  /*!
  * Path delay in units of Ts. Range [0..24575]
  */
  uint16_t path_delay;

  /*!
   * Index of the preamble to be sent (range 1..64). For debug only.
   */
  uint8_t preamble_idx;

  /*!
   * Indexes: n_oc, n_cs and interlace_number indicate preamble number.
   * They are used to create unique preamble sequence.
   */
  uint8_t n_oc;

  uint8_t n_cs;

  uint8_t interlace_number;

} PHY_MF_PRACH_ENC_REQ_SUB_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_MF_PRACH_ENC_REQ_T
 * Structure that describes the MF-sPRACH encoding request.
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*
  * Preamble format.
  */
  uint8_t  preamble_format;

  /*!
  * Number of individual UE following the header.
  */
  uint8_t num_ue;

  /*!
  * reserved.
  */
  uint16_t reserved;

  PHY_MF_PRACH_ENC_REQ_SUB_T ue_preamble[1];

} PHY_MF_PRACH_ENC_REQ_T;


/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_FAKE_NACK
 * Structure to notify mirroring mechanism
 *
 */
typedef struct
{
  /*! Message header that contains field that will be common to all message types. Refer to PHYSAP4S_MSG_HDR_T for field
      definitions. This header occupies 8 bytes of memory.
  */
  PHY_MSG_HDR_T msg_hdr;

  /*!
   *  Nacked PDSCH data frame
   */
  uint32_t nacked_codeword;

  uint32_t padding;

} PHY_FAKE_NACK_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_GENERIC_NAK_T
 * This message is used to indicate rejection of any message without a corresponding
 * RSP or ACK message. It's function is to be a clear indication of a messaging
 * mismatch between Host and PHY. Handling of this message beyond logging and
 * pegging a stat is TBD.
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

   /*!
    * Copy of message header in the rejected message.
    */
   PHY_MSG_HDR_T rejected_msg_hdr;

   /*!
    * Integer code value identifying the rejection reason.
    *
    * Value Range: TBD
    */
   uint32_t   rejection_code;

   /*!
    * ASCII string description of the rejection. String is terminated by a
    * NULL character if less than 256 bytes long.
    */
   uint8_t reason_string[256];

} PHY_GENERIC_NAK_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_ECSAT_CONFIG_REQ_SUB_T
 * Structure describes configuration applied per each simulated LTE-U cell measurements
 */
typedef struct
{
   /*!
   * LTE-U cell physical unit identifiers
   */
   uint8_t unit_id[PHY_MAX_NUMBER_OF_SCELL_UNITS];

  /*!
   * Probability of successful CCA measurement (0 - 0%, 255 - 100%)
   * NOTE: doesn't matter for PBCH forwarding configuration
   */
   uint8_t success_probability;

  /*!
   * Physical AIF/RP3 link number on which control link for CCA measurement will run
   */
   uint8_t link_id;


   /*!
   * SCell L2x86 VM deployment (0/1)
   */
   uint8_t scell_vm_deployment;

} PHY_ECSAT_CONFIG_REQ_SUB_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_ECSAT_CONFIG_REQ_T
 * This message is used to configure CCA measurement simulation for eCSAT / LTE-U
 */
typedef struct
{
    /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

  /*!
   * Number of LTE-U cells to configure
   */
   uint8_t num_of_lteu_cells;

   /*!
   * Indicate if the message is sent to configure PBCH forwarding, not eCSAT tunnels
   */
   uint8_t pbch_bcast_config;

   /*!
   * Reserved for future use
   */
   uint16_t reserved;

   /*!
   * Configuration of each eCSAT cell
   */
   PHY_ECSAT_CONFIG_REQ_SUB_T cell[PHY_MAX_NUM_OF_ECSAT_SCELLS];

} PHY_ECSAT_CONFIG_REQ_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_CONFIG_IND_T
 * This message is used to indicate arrival of cell config
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

} PHY_CELL_CONFIG_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_CELL_DECONFIG_IND_T
 * This message is used to indicate arrival of cell deconfig
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

} PHY_CELL_DECONFIG_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TX_BURST_IND_T
 * This message is used to indicate arrival of TX burst
 */
typedef struct
{
   /*!
    * Message header that contains fields that are common to all message types.
    * Refer to PHY_MSG_HDR_T for field definitions.
    */
   PHY_MSG_HDR_T msg_hdr;

  /*!
   * Tx Burst duration expressed in subframes
   */
   uint8_t duration;

  /*!
   * This field indicates that current burst carries only Discovery Reference Signal
   */
   uint8_t burstType;

  /*!
   * This field indicates in which unlicensed mode the TX Burst should be processed
   */
   uint8_t unlicensed_mode;

   /*!
    * Reserved for future use
    */
   uint8_t reserved;

} PHY_TX_BURST_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_TIME_OFFSET_IND_T
 * Structure that indicates that timing offset was detected on PHY
 * Sends correction to L2/SCH to align DL timing
 */
typedef struct
{
   /*! Message header that contains field that will be common to all message types. Refer to PHY_MSG_HDR_T for field
    * definitions. This header occupies 8 bytes of memory.
    */
    PHY_MSG_HDR_T msg_hdr;

   /*!
    * Value of the timing correction, in 1ms units (ie. subframes)
    */
    int32_t correction;

} PHY_TIME_OFFSET_IND_T;

/*---------------------------------------------------------------------------*/
/*!
 * \anchor PHY_FSM4_WIRESHARK_CONFIG_REQ_T
 */
typedef struct
{
    /*!
     * Message header that contains fields that are common to all message types.
     * Refer to PHY_MSG_HDR_T for field definitions.
     */
    PHY_MSG_HDR_T msg_hdr;

    uint32_t  ws_teid;

    /* Event Queue Identifier */
    uint32_t  eqid;

    /* Communication Context Identifier */
    uint32_t  ccid;

} PHY_FSM4_WIRESHARK_CONFIG_REQ_T;


#ifdef __cplusplus
}

#endif

/* Disable padding guard */
#pragma GCC diagnostic ignored "-Wpadded"

#endif /* PHY_EIS_H */
