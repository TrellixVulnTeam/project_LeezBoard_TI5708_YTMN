/********************************************************************
* Copyright (C) 2003-2008 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
#ifndef CSLR_AT_H_
#define CSLR_AT_H_

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Modified the header file includes to be RTSC compliant
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for PI_Data
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_PIMAX_LK;
    volatile Uint32 AT_PIMMIN_LK;
    volatile Uint32 AT_PIVALUE_LK;
} CSL_AtPi_dataRegs;

/**************************************************************************\
* Register Overlay Structure for at_events
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_EVENT_OFFSET;
    volatile Uint32 AT_EVENT_MOD_TC;
    volatile Uint32 AT_EVENT_MASK_LSBS;
    volatile Uint32 AT_EVENT_MASK_MSBS;
} CSL_AtAt_eventsRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 AT_CONTROL1;
    volatile Uint32 AT_CONTROL2;
    volatile Uint32 AT_SW_SYNC;
    volatile Uint8 RSVD0[4];
    volatile Uint32 AT_RP1_TYPE;
    volatile Uint8 RSVD1[12];
    volatile Uint32 AT_RP1_TYPE_CAPTURE;
    volatile Uint32 AT_RP1_TOD_CAPTURE_L;
    volatile Uint32 AT_RP1_TOD_CAPTURE_H;
    volatile Uint32 AT_RP1_RP3_CAPTURE_L;
    volatile Uint32 AT_RP1_RP3_CAPTURE_H;
    volatile Uint32 AT_RP1_RAD_CAPTURE_L;
    volatile Uint32 AT_RP1_RAD_CAPTURE_H;
    volatile Uint8 RSVD2[4];
    volatile Uint32 AT_PHYT_CLKCNT_VALUE;
    volatile Uint32 AT_PHYT_FRM_VALUE_LSBS;
    volatile Uint32 AT_PHYT_FRM_VALUE_MSBS;
    volatile Uint32 AT_RADT_VALUE_LSBS;
    volatile Uint32 AT_RADT_VALUE_MID;
    volatile Uint32 AT_RADT_VALUE_MSBS;
    volatile Uint32 AT_ULRADT_VALUE_LSBS;
    volatile Uint32 AT_ULRADT_VALUE_MID;
    volatile Uint32 AT_ULRADT_VALUE_MSBS;
    volatile Uint32 AT_DLRADT_VALUE_LSBS;
    volatile Uint32 AT_DLRADT_VALUE_MID;
    volatile Uint32 AT_DLRADT_VALUE_MSBS;
    volatile Uint32 AT_RADT_WCDMA_VALUE;
    volatile Uint32 AT_ULRADT_WCDMA_VALUE;
    volatile Uint32 AT_DLRADT_WCDMA_VALUE;
    volatile Uint8 RSVD3[4];
    volatile Uint32 AT_PHYT_INIT_LSBS;
    volatile Uint32 AT_PHYT_INIT_MID;
    volatile Uint32 AT_PHYT_INIT_MSBS;
    volatile Uint32 AT_PHYT_TC_LSBS;
    volatile Uint32 AT_PHYT_FRAME_TC_LSBS;
    volatile Uint32 AT_PHYT_FRAME_TC_MSBS;
    volatile Uint32 AT_RADT_INIT_LSBS;
    volatile Uint32 AT_RADT_INIT_MID;
    volatile Uint32 AT_RADT_INIT_MSBS;
    volatile Uint32 AT_ULRADT_INIT_LSBS;
    volatile Uint32 AT_RADT_TSTAMP_VALUE;
    volatile Uint8 RSVD4[4];
    volatile Uint32 AT_DLRADT_INIT_LSBS;
    volatile Uint32 AT_GSM_TCOUNT;
    volatile Uint8 RSVD5[4];
    volatile Uint32 AT_RADT_SYMB_LUT_INDEX_TC;
    volatile Uint32 AT_ULRADT_SYMB_LUT_INDEX_TC;
    volatile Uint32 AT_DLRADT_SYMB_LUT_INDEX_TC;
    volatile Uint32 AT_RADT_FRAME_TC_MSBS;
    volatile Uint32 AT_RADT_FRAME_TC_LSBS;
    volatile Uint32 AT_ULRADT_FRAME_TC_MSBS;
    volatile Uint32 AT_ULRADT_FRAME_TC_LSBS;
    volatile Uint32 AT_DLRADT_FRAME_TC_MSBS;
    volatile Uint32 AT_DLRADT_FRAME_TC_LSBS;
    volatile Uint8 RSVD6[32];
    volatile Uint32 AT_RADT_SYM_LUT_RAM[128];
    volatile Uint32 AT_ULRADT_SYM_LUT_RAM[128];
    volatile Uint32 AT_DLRADT_SYM_LUT_RAM[128];
    volatile Uint8 RSVD7[256];
    CSL_AtPi_dataRegs PI_DATA[6];
    volatile Uint32 AT_EVT_ENABLE;
    volatile Uint32 AT_EVT_FORCE;
    CSL_AtAt_eventsRegs AT_EVENTS[8];
} CSL_AtRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* at_pimax_lk */

#define CSL_AT_AT_PIMAX_LK_PIMAX_MASK    (0x01FFFFFFu)
#define CSL_AT_AT_PIMAX_LK_PIMAX_SHIFT   (0x00000000u)
#define CSL_AT_AT_PIMAX_LK_PIMAX_RESETVAL (0x00000000u)


#define CSL_AT_AT_PIMAX_LK_RESETVAL      (0x00000000u)

/* at_pimmin_lk */

#define CSL_AT_AT_PIMMIN_LK_PIMIN_MASK   (0x01FFFFFFu)
#define CSL_AT_AT_PIMMIN_LK_PIMIN_SHIFT  (0x00000000u)
#define CSL_AT_AT_PIMMIN_LK_PIMIN_RESETVAL (0x00000000u)


#define CSL_AT_AT_PIMMIN_LK_RESETVAL     (0x00000000u)

/* at_pivalue_lk */

#define CSL_AT_AT_PIVALUE_LK_PICAPTURED_VALUE_MASK (0x01FFFFFFu)
#define CSL_AT_AT_PIVALUE_LK_PICAPTURED_VALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_PIVALUE_LK_PICAPTURED_VALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_PIVALUE_LK_RESETVAL    (0x00000000u)

/* at_event_offset */

#define CSL_AT_AT_EVENT_OFFSET_EVENTINDEX_MASK (0x003FFFFFu)
#define CSL_AT_AT_EVENT_OFFSET_EVENTINDEX_SHIFT (0x00000000u)
#define CSL_AT_AT_EVENT_OFFSET_EVENTINDEX_RESETVAL (0x00000000u)


#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_MASK (0x07000000u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_SHIFT (0x00000018u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_RESETVAL (0x00000000u)
/*----Strobe Select Tokens----*/
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_RADT_SYMB (0x00000000u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_RADT_FRAME (0x00000001u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_ULRADT_SYMB (0x00000002u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_ULRADT_FRAME (0x00000003u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_DLRADT_SYMB (0x00000004u)
#define CSL_AT_AT_EVENT_OFFSET_STROBESELECT_DLRADT_FRAME (0x00000005u)


#define CSL_AT_AT_EVENT_OFFSET_RESETVAL  (0x00000000u)

/* at_event_mod_tc */

#define CSL_AT_AT_EVENT_MOD_TC_EVENTMODULO_MASK (0x003FFFFFu)
#define CSL_AT_AT_EVENT_MOD_TC_EVENTMODULO_SHIFT (0x00000000u)
#define CSL_AT_AT_EVENT_MOD_TC_EVENTMODULO_RESETVAL (0x00000000u)


#define CSL_AT_AT_EVENT_MOD_TC_RESETVAL  (0x00000000u)

/* at_event_mask_lsbs */

#define CSL_AT_AT_EVENT_MASK_LSBS_EVENTMASK_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_EVENT_MASK_LSBS_EVENTMASK_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_EVENT_MASK_LSBS_EVENTMASK_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_EVENT_MASK_LSBS_RESETVAL (0x00000000u)

/* at_event_mask_msbs */

#define CSL_AT_AT_EVENT_MASK_MSBS_EVENTMASK_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_EVENT_MASK_MSBS_EVENTMASK_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_EVENT_MASK_MSBS_EVENTMASK_MSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_EVENT_MASK_MSBS_RESETVAL (0x00000000u)

/* at_control1 */

#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_MASK (0x00000007u)
#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_SHIFT (0x00000000u)
#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_RESETVAL (0x00000000u)
/*----PHY syncsel Tokens----*/
#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_PR1 (0x00000000u)
#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_PHYSYNC (0x00000001u)
#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_AT_SW_SYNC (0x00000002u)
#define CSL_AT_AT_CONTROL1_PHYSYNCSEL_RM (0x00000003u)

#define CSL_AT_AT_CONTROL1_RADSYNCSEL_MASK (0x00000038u)
#define CSL_AT_AT_CONTROL1_RADSYNCSEL_SHIFT (0x00000003u)
#define CSL_AT_AT_CONTROL1_RADSYNCSEL_RESETVAL (0x00000000u)
/*----RAD syncsel Tokens----*/
#define CSL_AT_AT_CONTROL1_RADSYNCSEL_PR1 (0x00000000u)
#define CSL_AT_AT_CONTROL1_RADSYNCSEL_RADSYNC (0x00000001u)
#define CSL_AT_AT_CONTROL1_RADSYNCSEL_AT_SW_SYNC (0x00000002u)
#define CSL_AT_AT_CONTROL1_RADSYNCSEL_RM (0x00000003u)

#define CSL_AT_AT_CONTROL1_RP1MODE_MASK  (0x00000040u)
#define CSL_AT_AT_CONTROL1_RP1MODE_SHIFT (0x00000006u)
#define CSL_AT_AT_CONTROL1_RP1MODE_RESETVAL (0x00000000u)
/*----RP1 mode Tokens----*/
#define CSL_AT_AT_CONTROL1_RP1MODE_PR1   (0x00000000u)
#define CSL_AT_AT_CONTROL1_RP1MODE_NONPR1 (0x00000001u)

#define CSL_AT_AT_CONTROL1_AUTORESYNC_MASK (0x00000080u)
#define CSL_AT_AT_CONTROL1_AUTORESYNC_SHIFT (0x00000007u)
#define CSL_AT_AT_CONTROL1_AUTORESYNC_RESETVAL (0x00000000u)
/*----Auto resync Tokens----*/
#define CSL_AT_AT_CONTROL1_AUTORESYNC_NORESYNC (0x00000000u)
#define CSL_AT_AT_CONTROL1_AUTORESYNC_RESYNC (0x00000001u)

#define CSL_AT_AT_CONTROL1_CRCUSE_MASK   (0x00000100u)
#define CSL_AT_AT_CONTROL1_CRCUSE_SHIFT  (0x00000008u)
#define CSL_AT_AT_CONTROL1_CRCUSE_RESETVAL (0x00000000u)
/*----CRC use Tokens----*/
#define CSL_AT_AT_CONTROL1_CRCUSE_       (0x00000000u)
#define CSL_AT_AT_CONTROL1_CRCUSE_USE    (0x00000001u)

#define CSL_AT_AT_CONTROL1_CRCFLIP_MASK  (0x00000200u)
#define CSL_AT_AT_CONTROL1_CRCFLIP_SHIFT (0x00000009u)
#define CSL_AT_AT_CONTROL1_CRCFLIP_RESETVAL (0x00000000u)
/*----CRC flip Tokens----*/
#define CSL_AT_AT_CONTROL1_CRCFLIP_NORMAL (0x00000000u)
#define CSL_AT_AT_CONTROL1_CRCFLIP_REVERSE (0x00000001u)

#define CSL_AT_AT_CONTROL1_CRCINIT_ONES_MASK (0x00000400u)
#define CSL_AT_AT_CONTROL1_CRCINIT_ONES_SHIFT (0x0000000Au)
#define CSL_AT_AT_CONTROL1_CRCINIT_ONES_RESETVAL (0x00000000u)
/*----CRC init ones Tokens----*/
#define CSL_AT_AT_CONTROL1_CRCINIT_ONES_INIT0 (0x00000000u)
#define CSL_AT_AT_CONTROL1_CRCINIT_ONES_INIT1 (0x00000001u)

#define CSL_AT_AT_CONTROL1_CRCINVERT_MASK (0x00000800u)
#define CSL_AT_AT_CONTROL1_CRCINVERT_SHIFT (0x0000000Bu)
#define CSL_AT_AT_CONTROL1_CRCINVERT_RESETVAL (0x00000000u)
/*----CRC invert Tokens----*/
#define CSL_AT_AT_CONTROL1_CRCINVERT_NOINVERT (0x00000000u)
#define CSL_AT_AT_CONTROL1_CRCINVERT_INVERT (0x00000001u)

#define CSL_AT_AT_CONTROL1_SYNC_SAMPL_WINDOW_MASK (0x0000F000u)
#define CSL_AT_AT_CONTROL1_SYNC_SAMPL_WINDOW_SHIFT (0x0000000Cu)
#define CSL_AT_AT_CONTROL1_SYNC_SAMPL_WINDOW_RESETVAL (0x00000000u)

#define CSL_AT_AT_CONTROL1_RP1RADT_FRAME_LOAD_MASK (0x00030000u)
#define CSL_AT_AT_CONTROL1_RP1RADT_FRAME_LOAD_SHIFT (0x00000010u)
#define CSL_AT_AT_CONTROL1_RP1RADT_FRAME_LOAD_RESETVAL (0x00000000u)
/*----RP1 RADT Frame Load Tokens----*/
#define CSL_AT_AT_CONTROL1_RP1RADT_FRAME_LOAD_PR1_40BIT (0x00000000u)
#define CSL_AT_AT_CONTROL1_RP1RADT_FRAME_LOAD_RP1_12LS (0x00000001u)
#define CSL_AT_AT_CONTROL1_RP1RADT_FRAME_LOAD_SW_40BIT (0x00000002u)

#define CSL_AT_AT_CONTROL1_RP1PHYT_FRAME_LOAD_MASK (0x000C0000u)
#define CSL_AT_AT_CONTROL1_RP1PHYT_FRAME_LOAD_SHIFT (0x00000012u)
#define CSL_AT_AT_CONTROL1_RP1PHYT_FRAME_LOAD_RESETVAL (0x00000000u)
/*----RP1 PHYT Frame Load Tokens----*/
#define CSL_AT_AT_CONTROL1_RP1PHYT_FRAME_LOAD_PR1_40BIT (0x00000000u)
#define CSL_AT_AT_CONTROL1_RP1PHYT_FRAME_LOAD_RP1_12LS (0x00000001u)
#define CSL_AT_AT_CONTROL1_RP1PHYT_FRAME_LOAD_SW_40BIT (0x00000002u)


#define CSL_AT_AT_CONTROL1_RESETVAL      (0x00000000u)

/* at_control2 */

#define CSL_AT_AT_CONTROL2_HALT_TIMER_MASK (0x00000001u)
#define CSL_AT_AT_CONTROL2_HALT_TIMER_SHIFT (0x00000000u)
#define CSL_AT_AT_CONTROL2_HALT_TIMER_RESETVAL (0x00000000u)
/*----halt_timer Tokens----*/
#define CSL_AT_AT_CONTROL2_HALT_TIMER_NOHALT (0x00000000u)
#define CSL_AT_AT_CONTROL2_HALT_TIMER_HALT (0x00000001u)

#define CSL_AT_AT_CONTROL2_ARM_TIMER_MASK (0x00000002u)
#define CSL_AT_AT_CONTROL2_ARM_TIMER_SHIFT (0x00000001u)
#define CSL_AT_AT_CONTROL2_ARM_TIMER_RESETVAL (0x00000000u)
/*----arm_timer Tokens----*/
#define CSL_AT_AT_CONTROL2_ARM_TIMER_NOARM (0x00000000u)
#define CSL_AT_AT_CONTROL2_ARM_TIMER_ARM (0x00000001u)


#define CSL_AT_AT_CONTROL2_RESETVAL      (0x00000000u)

/* at_sw_sync */

#define CSL_AT_AT_SW_SYNC_RAD_SYNC_MASK  (0x00000001u)
#define CSL_AT_AT_SW_SYNC_RAD_SYNC_SHIFT (0x00000000u)
#define CSL_AT_AT_SW_SYNC_RAD_SYNC_RESETVAL (0x00000000u)
/*----RAD_sync Tokens----*/
#define CSL_AT_AT_SW_SYNC_RAD_SYNC_NOSYNC (0x00000000u)
#define CSL_AT_AT_SW_SYNC_RAD_SYNC_SYNC  (0x00000001u)

#define CSL_AT_AT_SW_SYNC_PHY_SYNC_MASK  (0x00000002u)
#define CSL_AT_AT_SW_SYNC_PHY_SYNC_SHIFT (0x00000001u)
#define CSL_AT_AT_SW_SYNC_PHY_SYNC_RESETVAL (0x00000000u)
/*----PHY_sync Tokens----*/
#define CSL_AT_AT_SW_SYNC_PHY_SYNC_NOSYNC (0x00000000u)
#define CSL_AT_AT_SW_SYNC_PHY_SYNC_SYNC  (0x00000001u)


#define CSL_AT_AT_SW_SYNC_RESETVAL       (0x00000000u)

/* at_rp1_type */

#define CSL_AT_AT_RP1_TYPE_RP1RAD_TYPE_SELECT_MASK (0x000000FFu)
#define CSL_AT_AT_RP1_TYPE_RP1RAD_TYPE_SELECT_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_TYPE_RP1RAD_TYPE_SELECT_RESETVAL (0x00000000u)


#define CSL_AT_AT_RP1_TYPE_RESETVAL      (0x00000000u)

/* at_rp1_type_capture */

#define CSL_AT_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED_MASK (0x000000FFu)
#define CSL_AT_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_TYPE_CAPTURE_RP1TYPE_CAPTURED_RESETVAL (0x00000000u)


#define CSL_AT_AT_RP1_TYPE_CAPTURE_RESETVAL (0x00000000u)

/* at_rp1_tod_capture_l */

#define CSL_AT_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_TOD_CAPTURE_L_RP1TOD_CAPTURE_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RP1_TOD_CAPTURE_L_RESETVAL (0x00000000u)

/* at_rp1_tod_capture_h */

#define CSL_AT_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_TOD_CAPTURE_H_RP1TOD_CAPTURE_MSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RP1_TOD_CAPTURE_H_RESETVAL (0x00000000u)

/* at_rp1_rp3_capture_l */

#define CSL_AT_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_RP3_CAPTURE_L_RP1RP3_CAPTURE_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RP1_RP3_CAPTURE_L_RESETVAL (0x00000000u)

/* at_rp1_rp3_capture_h */

#define CSL_AT_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_RP3_CAPTURE_H_RP1RP3_CAPTURE_MSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RP1_RP3_CAPTURE_H_RESETVAL (0x00000000u)

/* at_rp1_rad_capture_l */

#define CSL_AT_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_RAD_CAPTURE_L_RP1RADIO_SYSTEM_CAPTURE_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RP1_RAD_CAPTURE_L_RESETVAL (0x00000000u)

/* at_rp1_rad_capture_h */

#define CSL_AT_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RP1_RAD_CAPTURE_H_RP1RADIO_SYSTEM_CAPTURE_MSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RP1_RAD_CAPTURE_H_RESETVAL (0x00000000u)

/* at_phyt_clkcnt_value */

#define CSL_AT_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE_MASK (0x00FFFFFFu)
#define CSL_AT_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_CLKCNT_VALUE_PHYTCLOCK_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_CLKCNT_VALUE_RESETVAL (0x00000000u)

/* at_phyt_frm_value_lsbs */

#define CSL_AT_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AT_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_FRM_VALUE_LSBS_PHYTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_FRM_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_phyt_frm_value_msbs */

#define CSL_AT_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AT_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_FRM_VALUE_MSBS_PHYTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_FRM_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_radt_value_lsbs */

#define CSL_AT_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE_MASK (0x07FFFFFFu)
#define CSL_AT_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_VALUE_LSBS_RADTSYMBOL_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_radt_value_mid */

#define CSL_AT_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AT_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_VALUE_MID_RADTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_VALUE_MID_RESETVAL (0x00000000u)

/* at_radt_value_msbs */

#define CSL_AT_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AT_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_VALUE_MSBS_RADTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_ulradt_value_lsbs */

#define CSL_AT_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE_MASK (0x07FFFFFFu)
#define CSL_AT_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_VALUE_LSBS_ULRADTSYMBOL_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_ulradt_value_mid */

#define CSL_AT_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AT_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_VALUE_MID_ULRADTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_VALUE_MID_RESETVAL (0x00000000u)

/* at_ulradt_value_msbs */

#define CSL_AT_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AT_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_VALUE_MSBS_ULRADTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_dlradt_value_lsbs */

#define CSL_AT_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE_MASK (0x0007FFFFu)
#define CSL_AT_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_VALUE_LSBS_DLRADTCLOCK_COUNT_VALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE_MASK (0x07F80000u)
#define CSL_AT_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE_SHIFT (0x00000013u)
#define CSL_AT_AT_DLRADT_VALUE_LSBS_DLRADTSYMBOL_COUNT_VALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_VALUE_LSBS_RESETVAL (0x00000000u)

/* at_dlradt_value_mid */

#define CSL_AT_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS_MASK (0x00000FFFu)
#define CSL_AT_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_VALUE_MID_DLRADTFRAME_VALUE_LSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_VALUE_MID_RESETVAL (0x00000000u)

/* at_dlradt_value_msbs */

#define CSL_AT_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AT_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_VALUE_MSBS_DLRADTFRAME_VALUE_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_VALUE_MSBS_RESETVAL (0x00000000u)

/* at_radt_wcdma_value */

#define CSL_AT_AT_RADT_WCDMA_VALUE_CHIPVALUE_MASK (0x00000FFFu)
#define CSL_AT_AT_RADT_WCDMA_VALUE_CHIPVALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_WCDMA_VALUE_CHIPVALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_RADT_WCDMA_VALUE_SLOTVALUE_MASK (0x0000F000u)
#define CSL_AT_AT_RADT_WCDMA_VALUE_SLOTVALUE_SHIFT (0x0000000Cu)
#define CSL_AT_AT_RADT_WCDMA_VALUE_SLOTVALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_RADT_WCDMA_VALUE_FRAMEVALUE_MASK (0x0FFF0000u)
#define CSL_AT_AT_RADT_WCDMA_VALUE_FRAMEVALUE_SHIFT (0x00000010u)
#define CSL_AT_AT_RADT_WCDMA_VALUE_FRAMEVALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_WCDMA_VALUE_RESETVAL (0x00000000u)

/* at_ulradt_wcdma_value */

#define CSL_AT_AT_ULRADT_WCDMA_VALUE_CHIPVALUE_MASK (0x00000FFFu)
#define CSL_AT_AT_ULRADT_WCDMA_VALUE_CHIPVALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_WCDMA_VALUE_CHIPVALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_ULRADT_WCDMA_VALUE_SLOTVALUE_MASK (0x0000F000u)
#define CSL_AT_AT_ULRADT_WCDMA_VALUE_SLOTVALUE_SHIFT (0x0000000Cu)
#define CSL_AT_AT_ULRADT_WCDMA_VALUE_SLOTVALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE_MASK (0x0FFF0000u)
#define CSL_AT_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE_SHIFT (0x00000010u)
#define CSL_AT_AT_ULRADT_WCDMA_VALUE_FRAMEVALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_WCDMA_VALUE_RESETVAL (0x00000000u)

/* at_dlradt_wcdma_value */

#define CSL_AT_AT_DLRADT_WCDMA_VALUE_CHIPVALUE_MASK (0x00000FFFu)
#define CSL_AT_AT_DLRADT_WCDMA_VALUE_CHIPVALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_WCDMA_VALUE_CHIPVALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_DLRADT_WCDMA_VALUE_SLOTVALUE_MASK (0x0000F000u)
#define CSL_AT_AT_DLRADT_WCDMA_VALUE_SLOTVALUE_SHIFT (0x0000000Cu)
#define CSL_AT_AT_DLRADT_WCDMA_VALUE_SLOTVALUE_RESETVAL (0x00000000u)

#define CSL_AT_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE_MASK (0x0FFF0000u)
#define CSL_AT_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE_SHIFT (0x00000010u)
#define CSL_AT_AT_DLRADT_WCDMA_VALUE_FRAMEVALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_WCDMA_VALUE_RESETVAL (0x00000000u)

/* at_phyt_init_lsbs */

#define CSL_AT_AT_PHYT_INIT_LSBS_PHYTCLOCK_COUNT_INIT_MASK (0x003FFFFFu)
#define CSL_AT_AT_PHYT_INIT_LSBS_PHYTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_INIT_LSBS_PHYTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_phyt_init_mid */

#define CSL_AT_AT_PHYT_INIT_MID_PHYTFRAME_INIT_LSBS_MASK (0x00000FFFu)
#define CSL_AT_AT_PHYT_INIT_MID_PHYTFRAME_INIT_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_INIT_MID_PHYTFRAME_INIT_LSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_INIT_MID_RESETVAL (0x00000000u)

/* at_phyt_init_msbs */

#define CSL_AT_AT_PHYT_INIT_MSBS_PHYTFRAME_INIT_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AT_AT_PHYT_INIT_MSBS_PHYTFRAME_INIT_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_INIT_MSBS_PHYTFRAME_INIT_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_INIT_MSBS_RESETVAL (0x00000000u)

/* at_phyt_tc_lsbs */

#define CSL_AT_AT_PHYT_TC_LSBS_PHYTCLOCK_COUNTER_TC_MASK (0x003FFFFFu)
#define CSL_AT_AT_PHYT_TC_LSBS_PHYTCLOCK_COUNTER_TC_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_TC_LSBS_PHYTCLOCK_COUNTER_TC_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_TC_LSBS_RESETVAL  (0x00000000u)

/* at_phyt_frame_tc_lsbs */

#define CSL_AT_AT_PHYT_FRAME_TC_LSBS_PHYTFRAME_TC_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_PHYT_FRAME_TC_LSBS_PHYTFRAME_TC_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_FRAME_TC_LSBS_PHYTFRAME_TC_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_PHYT_FRAME_TC_LSBS_RESETVAL (0x00000000u)

/* at_phyt_frame_tc_msbs */

#define CSL_AT_AT_PHYT_FRAME_TC_MSBS_PHYTFRAME_TC_MSBS_MASK (0x000000FFu)
#define CSL_AT_AT_PHYT_FRAME_TC_MSBS_PHYTFRAME_TC_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_PHYT_FRAME_TC_MSBS_PHYTFRAME_TC_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_PHYT_FRAME_TC_MSBS_RESETVAL (0x00000000u)

/* at_radt_init_lsbs */

#define CSL_AT_AT_RADT_INIT_LSBS_RADTCLOCK_COUNT_INIT_MASK (0x0007FFFFu)
#define CSL_AT_AT_RADT_INIT_LSBS_RADTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_INIT_LSBS_RADTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)

#define CSL_AT_AT_RADT_INIT_LSBS_RADTSYMBOL_COUNT_INIT_MASK (0x07FC0000u)
#define CSL_AT_AT_RADT_INIT_LSBS_RADTSYMBOL_COUNT_INIT_SHIFT (0x00000012u)
#define CSL_AT_AT_RADT_INIT_LSBS_RADTSYMBOL_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_radt_init_mid */

#define CSL_AT_AT_RADT_INIT_MID_RADTFRAME_INIT_LSBS_MASK (0x00000FFFu)
#define CSL_AT_AT_RADT_INIT_MID_RADTFRAME_INIT_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_INIT_MID_RADTFRAME_INIT_LSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_INIT_MID_RESETVAL (0x00000000u)

/* at_radt_init_msbs */

#define CSL_AT_AT_RADT_INIT_MSBS_RADTFRAME_INIT_MSBS_MASK (0x0FFFFFFFu)
#define CSL_AT_AT_RADT_INIT_MSBS_RADTFRAME_INIT_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_INIT_MSBS_RADTFRAME_INIT_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_INIT_MSBS_RESETVAL (0x00000000u)

/* at_ulradt_init_lsbs */

#define CSL_AT_AT_ULRADT_INIT_LSBS_ULRADTCLOCK_COUNT_INIT_MASK (0x0007FFFFu)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULRADTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULRADTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)

#define CSL_AT_AT_ULRADT_INIT_LSBS_ULRADTSYMBOL_COUNT_INIT_MASK (0x07F80000u)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULRADTSYMBOL_COUNT_INIT_SHIFT (0x00000013u)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULRADTSYMBOL_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_MASK (0x80000000u)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_SHIFT (0x0000001Fu)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_RESETVAL (0x00000000u)
/*----ULFCB_minusone Tokens----*/
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_RADF (0x00000000u)
#define CSL_AT_AT_ULRADT_INIT_LSBS_ULFCB_MINUSONE_RADF_MINUS_1 (0x00000001u)

#define CSL_AT_AT_ULRADT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_radt_tstamp_value */

#define CSL_AT_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE_MASK (0x003FFFFFu)
#define CSL_AT_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_TSTAMP_VALUE_RADTTSTAMP_CLOCK_COUNTER_VALUE_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_TSTAMP_VALUE_RESETVAL (0x00000000u)

/* at_dlradt_init_lsbs */

#define CSL_AT_AT_DLRADT_INIT_LSBS_DLRADTCLOCK_COUNT_INIT_MASK (0x0007FFFFu)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLRADTCLOCK_COUNT_INIT_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLRADTCLOCK_COUNT_INIT_RESETVAL (0x00000000u)

#define CSL_AT_AT_DLRADT_INIT_LSBS_DLRADTSYMBOL_COUNT_INIT_MASK (0x07F80000u)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLRADTSYMBOL_COUNT_INIT_SHIFT (0x00000013u)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLRADTSYMBOL_COUNT_INIT_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_MASK (0x80000000u)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_SHIFT (0x0000001Fu)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_RESETVAL (0x00000000u)
/*----DLFCB_minusone Tokens----*/
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_RADF (0x00000000u)
#define CSL_AT_AT_DLRADT_INIT_LSBS_DLFCB_MINUSONE_RADF_MINUS_1 (0x00000001u)

#define CSL_AT_AT_DLRADT_INIT_LSBS_RESETVAL (0x00000000u)

/* at_gsm_tcount */

#define CSL_AT_AT_GSM_TCOUNT_T1_MASK     (0x000007FFu)
#define CSL_AT_AT_GSM_TCOUNT_T1_SHIFT    (0x00000000u)
#define CSL_AT_AT_GSM_TCOUNT_T1_RESETVAL (0x00000000u)

#define CSL_AT_AT_GSM_TCOUNT_T2_MASK     (0x0000F800u)
#define CSL_AT_AT_GSM_TCOUNT_T2_SHIFT    (0x0000000Bu)
#define CSL_AT_AT_GSM_TCOUNT_T2_RESETVAL (0x00000000u)

#define CSL_AT_AT_GSM_TCOUNT_T3_MASK     (0x003F0000u)
#define CSL_AT_AT_GSM_TCOUNT_T3_SHIFT    (0x00000010u)
#define CSL_AT_AT_GSM_TCOUNT_T3_RESETVAL (0x00000000u)


#define CSL_AT_AT_GSM_TCOUNT_RESETVAL    (0x00000000u)

/* at_radt_symb_lut_index_tc */

#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_MASK (0x0000007Fu)
#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_SYMBOLTC_MASK (0x0000FF00u)
#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_SYMBOLTC_SHIFT (0x00000008u)
#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_SYMBOLTC_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_SYMB_LUT_INDEX_TC_RESETVAL (0x00000000u)

/* at_ulradt_symb_lut_index_tc */

#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_MASK (0x0000007Fu)
#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_SYMBOLTC_MASK (0x0000FF00u)
#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_SYMBOLTC_SHIFT (0x00000008u)
#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_SYMBOLTC_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_SYMB_LUT_INDEX_TC_RESETVAL (0x00000000u)

/* at_dlradt_symb_lut_index_tc */

#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_MASK (0x0000007Fu)
#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_LUTINDEX_TC_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_SYMBOLTC_MASK (0x0000FF00u)
#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_SYMBOLTC_SHIFT (0x00000008u)
#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_SYMBOLTC_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_SYMB_LUT_INDEX_TC_RESETVAL (0x00000000u)

/* at_radt_frame_tc_msbs */

#define CSL_AT_AT_RADT_FRAME_TC_MSBS_RADTFRAME_TC_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RADT_FRAME_TC_MSBS_RADTFRAME_TC_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_FRAME_TC_MSBS_RADTFRAME_TC_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_RADT_FRAME_TC_MSBS_RESETVAL (0x00000000u)

/* at_radt_frame_tc_lsbs */

#define CSL_AT_AT_RADT_FRAME_TC_LSBS_RADTFRAME_TC_MSBS_MASK (0x000000FFu)
#define CSL_AT_AT_RADT_FRAME_TC_LSBS_RADTFRAME_TC_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_FRAME_TC_LSBS_RADTFRAME_TC_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_RADT_FRAME_TC_LSBS_RESETVAL (0x00000000u)

/* at_ulradt_frame_tc_msbs */

#define CSL_AT_AT_ULRADT_FRAME_TC_MSBS_ULRADTFRAME_TC_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_ULRADT_FRAME_TC_MSBS_ULRADTFRAME_TC_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_FRAME_TC_MSBS_ULRADTFRAME_TC_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_ULRADT_FRAME_TC_MSBS_RESETVAL (0x00000000u)

/* at_ulradt_frame_tc_lsbs */

#define CSL_AT_AT_ULRADT_FRAME_TC_LSBS_ULRADTFRAME_TC_MSBS_MASK (0x000000FFu)
#define CSL_AT_AT_ULRADT_FRAME_TC_LSBS_ULRADTFRAME_TC_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_FRAME_TC_LSBS_ULRADTFRAME_TC_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_ULRADT_FRAME_TC_LSBS_RESETVAL (0x00000000u)

/* at_dlradt_frame_tc_msbs */

#define CSL_AT_AT_DLRADT_FRAME_TC_MSBS_DLRADTFRAME_TC_LSBS_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_DLRADT_FRAME_TC_MSBS_DLRADTFRAME_TC_LSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_FRAME_TC_MSBS_DLRADTFRAME_TC_LSBS_RESETVAL (0x00000000u)

#define CSL_AT_AT_DLRADT_FRAME_TC_MSBS_RESETVAL (0x00000000u)

/* at_dlradt_frame_tc_lsbs */

#define CSL_AT_AT_DLRADT_FRAME_TC_LSBS_DLRADTFRAME_TC_MSBS_MASK (0x000000FFu)
#define CSL_AT_AT_DLRADT_FRAME_TC_LSBS_DLRADTFRAME_TC_MSBS_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_FRAME_TC_LSBS_DLRADTFRAME_TC_MSBS_RESETVAL (0x00000000u)


#define CSL_AT_AT_DLRADT_FRAME_TC_LSBS_RESETVAL (0x00000000u)

/* at_radt_sym_lut_ram */

#define CSL_AT_AT_RADT_SYM_LUT_RAM_RADT_SYM_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_RADT_SYM_LUT_RAM_RADT_SYM_SHIFT (0x00000000u)
#define CSL_AT_AT_RADT_SYM_LUT_RAM_RADT_SYM_RESETVAL (0x00000000u)

#define CSL_AT_AT_RADT_SYM_LUT_RAM_RESETVAL (0x00000000u)

/* at_ulradt_sym_lut_ram */

#define CSL_AT_AT_ULRADT_SYM_LUT_RAM_ULRADT_SYM_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_ULRADT_SYM_LUT_RAM_ULRADT_SYM_SHIFT (0x00000000u)
#define CSL_AT_AT_ULRADT_SYM_LUT_RAM_ULRADT_SYM_RESETVAL (0x00000000u)

#define CSL_AT_AT_ULRADT_SYM_LUT_RAM_RESETVAL (0x00000000u)

/* at_dlradt_sym_lut_ram */

#define CSL_AT_AT_DLRADT_SYM_LUT_RAM_DLRADT_SYM_MASK (0xFFFFFFFFu)
#define CSL_AT_AT_DLRADT_SYM_LUT_RAM_DLRADT_SYM_SHIFT (0x00000000u)
#define CSL_AT_AT_DLRADT_SYM_LUT_RAM_DLRADT_SYM_RESETVAL (0x00000000u)

#define CSL_AT_AT_DLRADT_SYM_LUT_RAM_RESETVAL (0x00000000u)

/* at_evt_enable */

#define CSL_AT_AT_EVT_ENABLE_EVENTENABLE_MASK (0x000000FFu)
#define CSL_AT_AT_EVT_ENABLE_EVENTENABLE_SHIFT (0x00000000u)
#define CSL_AT_AT_EVT_ENABLE_EVENTENABLE_RESETVAL (0x00000000u)


#define CSL_AT_AT_EVT_ENABLE_RESETVAL    (0x00000000u)

/* at_evt_force */

#define CSL_AT_AT_EVT_FORCE_EVENTFORCE_MASK (0x000000FFu)
#define CSL_AT_AT_EVT_FORCE_EVENTFORCE_SHIFT (0x00000000u)
#define CSL_AT_AT_EVT_FORCE_EVENTFORCE_RESETVAL (0x00000000u)


#define CSL_AT_AT_EVT_FORCE_RESETVAL     (0x00000000u)

#endif
