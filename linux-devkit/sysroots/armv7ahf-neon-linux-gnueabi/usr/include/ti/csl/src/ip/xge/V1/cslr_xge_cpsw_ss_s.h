/********************************************************************
 * Copyright (C) 2003-2018 Texas Instruments Incorporated.
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
*********************************************************************
* file: cslr_xge_cpsw_ss_s.h
*
* Brief: This file contains the Register Description for xge_cpsw_ss_s
*
*********************************************************************/
#ifndef CSLR_XGE_CPSW_SS_S_V1_H_
#define CSLR_XGE_CPSW_SS_S_V1_H_
/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Header files are included as per RTSC guidelines
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 IDVER_REG;
    volatile Uint32 SYNCE_COUNT_REG;
    volatile Uint32 SYNCE_MUX_REG;
    volatile Uint8 RSVD0[4];
    volatile Uint32 ECC_CONTROL_REG;
    volatile Uint32 ECC_INTSTAT_RAW_REG;
    volatile Uint32 ECC_INTSTAT_MASKED_REG;
    volatile Uint32 ECC_INT_ENABLE_REG;
} CSL_Xge_cpsw_ss_sRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* idver_reg */

#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_MASK (0x000000FFu)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_MASK (0x00000700u)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_SHIFT (0x00000008u)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_RESETVAL (0x00000001u)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_MASK (0x0000F800u)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_SHIFT (0x0000000Bu)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_MASK (0xFFFF0000u)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_SHIFT (0x00000010u)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_RESETVAL (0x00004EE6u)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_RESETVAL (0x4EE60100u)

/* synce_count_reg */

#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_MASK (0xFFFFFFFFu)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_RESETVAL (0x00000000u)

/* synce_mux_reg */

#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_MASK (0x00000007u)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_RESETVAL (0x00000000u)

/* ecc_control_reg */

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_RXUL_SEC_MASK (0x00000080u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_RXUL_SEC_SHIFT (0x00000007u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_RXUL_SEC_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_RXUL_DED_MASK (0x00000040u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_RXUL_DED_SHIFT (0x00000006u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_RXUL_DED_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_TXUL_SEC_MASK (0x00000020u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_TXUL_SEC_SHIFT (0x00000005u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_TXUL_SEC_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_TXUL_DED_MASK (0x00000010u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_TXUL_DED_SHIFT (0x00000004u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_TEST_TXUL_DED_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_ECC_INT_TEST_MASK (0x00000002u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_ECC_INT_TEST_SHIFT (0x00000001u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_ECC_INT_TEST_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_ECC_ADDR_EN_MASK (0x00000001u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_ECC_ADDR_EN_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_ECC_ADDR_EN_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_CONTROL_REG_RESETVAL (0x00000000u)

/* ecc_intstat_raw_reg */

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_RXUL_SEC_PEND_MASK (0x00800000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_RXUL_SEC_PEND_SHIFT (0x00000017u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_RXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_RXUL_DED_PEND_MASK (0x00400000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_RXUL_DED_PEND_SHIFT (0x00000016u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_RXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_TXUL_SEC_PEND_MASK (0x00200000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_TXUL_SEC_PEND_SHIFT (0x00000015u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_TXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_TXUL_DED_PEND_MASK (0x00100000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_TXUL_DED_PEND_SHIFT (0x00000014u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P4_TXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_RXUL_SEC_PEND_MASK (0x00080000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_RXUL_SEC_PEND_SHIFT (0x00000013u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_RXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_RXUL_DED_PEND_MASK (0x00040000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_RXUL_DED_PEND_SHIFT (0x00000012u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_RXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_TXUL_SEC_PEND_MASK (0x00020000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_TXUL_SEC_PEND_SHIFT (0x00000011u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_TXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_TXUL_DED_PEND_MASK (0x00010000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_TXUL_DED_PEND_SHIFT (0x00000010u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P3_TXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_RXUL_SEC_PEND_MASK (0x00008000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_RXUL_SEC_PEND_SHIFT (0x0000000Fu)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_RXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_RXUL_DED_PEND_MASK (0x00004000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_RXUL_DED_PEND_SHIFT (0x0000000Eu)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_RXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_TXUL_SEC_PEND_MASK (0x00002000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_TXUL_SEC_PEND_SHIFT (0x0000000Du)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_TXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_TXUL_DED_PEND_MASK (0x00001000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_TXUL_DED_PEND_SHIFT (0x0000000Cu)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P2_TXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_RXUL_SEC_PEND_MASK (0x00000800u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_RXUL_SEC_PEND_SHIFT (0x0000000Bu)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_RXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_RXUL_DED_PEND_MASK (0x00000400u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_RXUL_DED_PEND_SHIFT (0x0000000Au)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_RXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_TXUL_SEC_PEND_MASK (0x00000200u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_TXUL_SEC_PEND_SHIFT (0x00000009u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_TXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_TXUL_DED_PEND_MASK (0x00000100u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_TXUL_DED_PEND_SHIFT (0x00000008u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P1_TXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_RXUL_SEC_PEND_MASK (0x00000080u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_RXUL_SEC_PEND_SHIFT (0x00000007u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_RXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_RXUL_DED_PEND_MASK (0x00000040u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_RXUL_DED_PEND_SHIFT (0x00000006u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_RXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_TXUL_SEC_PEND_MASK (0x00000020u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_TXUL_SEC_PEND_SHIFT (0x00000005u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_TXUL_SEC_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_TXUL_DED_PEND_MASK (0x00000010u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_TXUL_DED_PEND_SHIFT (0x00000004u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_P0_TXUL_DED_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_ALE_RAM_PEND_MASK (0x00000008u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_ALE_RAM_PEND_SHIFT (0x00000003u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_ALE_RAM_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_ECC_PEND_RAW_MASK (0x00000001u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_ECC_PEND_RAW_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_ECC_PEND_RAW_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_RAW_REG_RESETVAL (0x00000000u)

/* ecc_intstat_masked_reg */

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_MASKED_REG_PEND_MASK (0x00000001u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_MASKED_REG_PEND_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_MASKED_REG_PEND_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INTSTAT_MASKED_REG_RESETVAL (0x00000000u)

/* ecc_int_enable_reg */

#define CSL_XGE_CPSW_SS_S_ECC_INT_ENABLE_REG_ENABLE_MASK (0x00000001u)
#define CSL_XGE_CPSW_SS_S_ECC_INT_ENABLE_REG_ENABLE_SHIFT (0x00000000u)
#define CSL_XGE_CPSW_SS_S_ECC_INT_ENABLE_REG_ENABLE_RESETVAL (0x00000000u)

#define CSL_XGE_CPSW_SS_S_ECC_INT_ENABLE_REG_RESETVAL (0x00000000u)

#ifdef __cplusplus
}
#endif

#endif