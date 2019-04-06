/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_QM_CONFIG_H_
#define CSLR_QM_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Added register overlay for the QUEUE STATUS which has now been moved
 *         out of the QM_CONFIG Regs to a new location. 
 *      b) Modified the header file includes to be RTSC compliant
 */

/* Minimum unit = 1 byte */
#ifndef CSL_MODIFICATION  
/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct CSL_Qm_Queue_Status
{
    volatile Uint32 QUEUE_THRESHOLD_STATUS_REG[256];
}CSL_Qm_Queue_Status;
#endif

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct {
    volatile Uint32 REVISION_REG;
    volatile Uint8  RSVD0[4];
    volatile Uint32 QUEUE_DIVERSION_REG;
    volatile Uint32 LINKING_RAM_REGION_0_BASE_ADDRESS_REG;
    volatile Uint32 LINKING_RAM_REGION_0_SIZE_REG;
    volatile Uint32 LINKING_RAM_REGION_1_BASE_ADDRESS_REG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 FREE_DESCRIPTOR_STARVE_COUNT_REG[16];
} CSL_Qm_configRegs;




/**************************************************************************
* Register Macros
**************************************************************************/

/* REVISION_REG */
#define CSL_QM_CONFIG_REVISION_REG                              (0x0U)

/* QUEUE_DIVERSION_REG */
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG                       (0x8U)

/* LINKING_RAM_REGION_0_BASE_ADDRESS_REG */
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG     (0xCU)

/* LINKING_RAM_REGION_0_SIZE_REG */
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG             (0x10U)

/* LINKING_RAM_REGION_1_BASE_ADDRESS_REG */
#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG     (0x14U)

/* FREE_DESCRIPTOR_STARVE_COUNT_REG */
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG(i)       (0x20U + ((i) * (0x4U)))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* REVISION_REG */

#define CSL_QM_CONFIG_REVISION_REG_SCHEME_MASK                  (0xC0000000U)
#define CSL_QM_CONFIG_REVISION_REG_SCHEME_SHIFT                 (30U)
#define CSL_QM_CONFIG_REVISION_REG_SCHEME_RESETVAL              (0x00000000U)
#define CSL_QM_CONFIG_REVISION_REG_SCHEME_MAX                   (0x00000003U)

#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_MASK                (0x0FFF0000U)
#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_SHIFT               (16U)
#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_RESETVAL            (0x00000000U)
#define CSL_QM_CONFIG_REVISION_REG_FUNCTION_MAX                 (0x00000fffU)

#define CSL_QM_CONFIG_REVISION_REG_REVRTL_MASK                  (0x0000F800U)
#define CSL_QM_CONFIG_REVISION_REG_REVRTL_SHIFT                 (11U)
#define CSL_QM_CONFIG_REVISION_REG_REVRTL_RESETVAL              (0x00000000U)
#define CSL_QM_CONFIG_REVISION_REG_REVRTL_MAX                   (0x0000001fU)

#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_MASK                  (0x00000700U)
#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_SHIFT                 (8U)
#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_RESETVAL              (0x00000000U)
#define CSL_QM_CONFIG_REVISION_REG_REVMAJ_MAX                   (0x00000007U)

#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_MASK               (0x000000C0U)
#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_SHIFT              (6U)
#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_RESETVAL           (0x00000000U)
#define CSL_QM_CONFIG_REVISION_REG_REVCUSTOM_MAX                (0x00000003U)

#define CSL_QM_CONFIG_REVISION_REG_REVMIN_MASK                  (0x0000003FU)
#define CSL_QM_CONFIG_REVISION_REG_REVMIN_SHIFT                 (0U)
#define CSL_QM_CONFIG_REVISION_REG_REVMIN_RESETVAL              (0x00000000U)
#define CSL_QM_CONFIG_REVISION_REG_REVMIN_MAX                   (0x0000003fU)

#define CSL_QM_CONFIG_REVISION_REG_RESETVAL                     (0x00000000U)

/* QUEUE_DIVERSION_REG */

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_MASK        (0x80000000U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_SHIFT       (31U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_RESETVAL    (0x00000000U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_HEAD_TAIL_MAX         (0x00000001U)

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_MASK        (0x3FFF0000U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_SHIFT       (16U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_RESETVAL    (0x00000000U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_DEST_QNUM_MAX         (0x00003fffU)

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_MASK      (0x00003FFFU)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_SHIFT     (0U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_SOURCE_QNUM_MAX       (0x00003fffU)

#define CSL_QM_CONFIG_QUEUE_DIVERSION_REG_RESETVAL              (0x00000000U)

/* LINKING_RAM_REGION_0_BASE_ADDRESS_REG */

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_MASK  (0xFFFFFFFFU)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_SHIFT  (0U)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_REGION0_BASE_MAX  (0xffffffffU)

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_BASE_ADDRESS_REG_RESETVAL  (0x00000000U)

/* LINKING_RAM_REGION_0_SIZE_REG */

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_MASK  (0x0007FFFFU)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_SHIFT  (0U)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_REGION0_SIZE_MAX  (0x0007ffffU)

#define CSL_QM_CONFIG_LINKING_RAM_REGION_0_SIZE_REG_RESETVAL    (0x00000000U)

/* LINKING_RAM_REGION_1_BASE_ADDRESS_REG */

#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_MASK  (0xFFFFFFFFU)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_SHIFT  (0U)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_REGION1_BASE_MAX  (0xffffffffU)

#define CSL_QM_CONFIG_LINKING_RAM_REGION_1_BASE_ADDRESS_REG_RESETVAL  (0x00000000U)

/* FREE_DESCRIPTOR_STARVE_COUNT_REG */

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_MASK  (0xFF000000U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_SHIFT  (24U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ3_STARVE_CNT_MAX  (0x000000ffU)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_MASK  (0x00FF0000U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_SHIFT  (16U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ2_STARVE_CNT_MAX  (0x000000ffU)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_MASK  (0x0000FF00U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_SHIFT  (8U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ1_STARVE_CNT_MAX  (0x000000ffU)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_MASK  (0x000000FFU)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_SHIFT  (0U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_RESETVAL  (0x00000000U)
#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_FDBQ0_STARVE_CNT_MAX  (0x000000ffU)

#define CSL_QM_CONFIG_FREE_DESCRIPTOR_STARVE_COUNT_REG_RESETVAL  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif