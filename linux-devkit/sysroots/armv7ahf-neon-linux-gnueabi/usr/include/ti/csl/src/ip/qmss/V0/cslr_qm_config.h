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
*/
/*********************************************************************
* file: cslr_qm_config.h
*
* Brief: This file contains the Register Description for qm_config
*
*********************************************************************/
#ifndef CSLR_QM_CONFIG_V0_H_
#define CSLR_QM_CONFIG_V0_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Added register overlay for the QUEUE STATUS which has now been moved
 *         out of the QM_CONFIG Regs to a new location. 
 *      b) Modified the header file includes to be RTSC compliant
 */


/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct CSL_Qm_Queue_Status
{
    volatile Uint32 QUEUE_THRESHOLD_STATUS_REG[256];
}CSL_Qm_Queue_Status;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 REVISION_REG;
    volatile Uint8 RSVD0[4];
    volatile Uint32 QUEUE_DIVERSION_REG;
    volatile Uint32 LINKING_RAM_REGION_0_BASE_ADDRESS_REG;
    volatile Uint32 LINKING_RAM_REGION_0_SIZE_REG;
    volatile Uint32 LINKING_RAM_REGION_1_BASE_ADDRESS_REG;
    volatile Uint8 RSVD1[8];
    volatile Uint32 FREE_DESCRIPTOR_STARVE_COUNT_REG[16];
} CSL_Qm_configRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* REVISION_REG */

#define CSL_QM_CONFIG_REVISION_REG_SCHEME_MASK (0xC0000000u)
#define CSL_QM_CONFIG_REVISION_REG_SCHEME_SHIFT (0x0000001Eu)
#define CSL_QM_CONFIG_REVISION_REG_SCHEME_RESETVAL (0x00000001u)

#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_MASK (0x0FFF0000u)
#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_SHIFT (0x00000010u)
#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_RESETVAL (0x00000E5Du)

#define CSL_QM_CONFIG_REVISION_REG_REVRTL_MASK (0x0000F800u)
#define CSL_QM_CONFIG_REVISION_REG_REVRTL_SHIFT (0x0000000Bu)
#define CSL_QM_CONFIG_REVISION_REG_REVRTL_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_MASK (0x00000700u)
#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_SHIFT (0x00000008u)
#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_RESETVAL (0x00000001u)

#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_MASK (0x000000C0u)
#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_SHIFT (0x00000006u)
#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_REVISION_REG_REVMIN_MASK (0x0000003Fu)
#define CSL_QM_CONFIG_REVISION_REG_REVMIN_SHIFT (0x00000000u)
#define CSL_QM_CONFIG_REVISION_REG_REVMIN_RESETVAL (0x00000005u)

#define CSL_QM_CONFIG_REVISION_REG_RESETVAL (0x4E5D0105u)

/* QUEUE_DIVERSION_REG */

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_MASK (0x80000000u)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_SHIFT (0x0000001Fu)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_MASK (0x3FFF0000u)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_SHIFT (0x00000010u)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_MASK (0x00003FFFu)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_SHIFT (0x00000000u)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_RESETVAL (0x00000000u)

/* LINKING_RAM_REGION_0_BASE_ADDRESS_REG */

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_MASK (0xFFFFFFFFu)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_SHIFT (0x00000000u)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_RESETVAL (0x00000000u)

/* LINKING_RAM_REGION_0_SIZE_REG */

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_MASK (0x0007FFFFu)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_SHIFT (0x00000000u)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_RESETVAL (0x00000000u)

/* LINKING_RAM_REGION_1_BASE_ADDRESS_REG */

#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_MASK (0xFFFFFFFFu)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_SHIFT (0x00000000u)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_RESETVAL (0x00000000u)

/* FREE_DESCRIPTOR_STARVE_COUNT_REG */

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_MASK (0xFF000000u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_SHIFT (0x00000018u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_MASK (0x00FF0000u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_SHIFT (0x00000010u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_MASK (0x0000FF00u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_SHIFT (0x00000008u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_MASK (0x000000FFu)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_SHIFT (0x00000000u)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_RESETVAL (0x00000000u)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
