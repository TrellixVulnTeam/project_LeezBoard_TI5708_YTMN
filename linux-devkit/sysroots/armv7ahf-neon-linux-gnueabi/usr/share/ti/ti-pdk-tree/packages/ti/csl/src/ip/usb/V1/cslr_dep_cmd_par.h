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
#ifndef CSLR_DEPCMDPAR_H_
#define CSLR_DEPCMDPAR_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 DEPCMDPAR1_DEPCFG;
    volatile Uint32 DEPCMDPAR0_DEPCFG;
    volatile Uint8  RSVD0[12];
    volatile Uint32 DEPCMDPAR0_DEPXFERCFG;
    volatile Uint8  RSVD1[8];
    volatile Uint32 DEPCMDPAR1_DEPSTRTXFER;
    volatile Uint32 DEPCMDPAR0_DEPSTRTXFER;
} CSL_depCmdParRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Fields of DEPCMDPAR1[n] programming register when used for command DEPCFG */
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG                         (0x0U)

/* Fields of DEPCMDPAR0[n] programming register when used for command DEPCFG */
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG                         (0x4U)

/* Fields of DEPCMDPAR0[n] programming register when used for command 
 * DEPXFERCFG */
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG                     (0x14U)

/* Fields of DEPCMDPAR1[n] programming register when used for command 
 * DEPSTRTXFER */
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER                    (0x20U)

/* Fields of DEPCMDPAR0[n] programming register when used for command 
 * DEPSTRTXFER */
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER                    (0x24U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* DEPCMDPAR1_DEPCFG */

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_MASK            (0x0000001FU)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_SHIFT           (0U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_RESETVAL        (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_INT0            (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_INTRNUM_MAX             (0x0000001fU)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_MASK         (0x00000100U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_SHIFT        (8U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_RESETVAL     (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_DIS          (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERCMPLEN_EN           (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_MASK       (0x00000200U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_SHIFT      (9U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_RESETVAL   (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_DIS        (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERINPROGEN_EN         (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_MASK         (0x00000400U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_SHIFT        (10U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_RESETVAL     (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_DIS          (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_XFERNRDYEN_EN           (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_MASK      (0x00000800U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_SHIFT     (11U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_RESETVAL  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_DIS       (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_RXTXFIFOEVTEN_EN        (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_MASK        (0x00002000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_SHIFT       (13U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_RESETVAL    (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_DIS         (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STREAMEVTEN_EN          (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BINTERVAL_M1_MASK       (0x00FF0000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BINTERVAL_M1_SHIFT      (16U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BINTERVAL_M1_RESETVAL   (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BINTERVAL_M1_MAX        (0x000000ffU)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_MASK            (0x01000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_SHIFT           (24U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_RESETVAL        (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_NOTCAP          (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_STRMCAP_CAP             (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_MASK        (0x02000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_SHIFT       (25U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_RESETVAL    (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_OUT         (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPDIRECTION_IN          (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER_MASK           (0x3C000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER_SHIFT          (26U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER_RESETVAL       (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_EPNUMBER_MAX            (0x0000000fU)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_MASK          (0x40000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_SHIFT         (30U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_RESETVAL      (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_DEFAULT       (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_BULKBASED_BBISOC        (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_MASK  (0x80000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_SHIFT  (31U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_RESETVAL  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_DISABLED  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_FIFOBASED_EBCBASED_ENABLED  (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_MASK  (0x00008000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_SHIFT  (15U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_RESETVAL  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_DIS  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_LIMITOUTSTANDINGTXDMA_EBC  (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPCFG_RESETVAL                (0x00000000U)

/* DEPCMDPAR0_DEPCFG */

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_MASK             (0x00000006U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_SHIFT            (1U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_RESETVAL         (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_CTRL             (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_ISOC             (0x00000001U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_BULK             (0x00000002U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_EPTYPE_INT              (0x00000003U)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS_MASK                (0x00003FF8U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS_SHIFT               (3U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS_RESETVAL            (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_MPS_MAX                 (0x000007ffU)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM_MASK            (0x003E0000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM_SHIFT           (17U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM_RESETVAL        (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_FIFONUM_MAX             (0x0000001fU)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MASK            (0x03C00000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_SHIFT           (22U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_RESETVAL        (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MIN             (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MAX             (0x0000000fU)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_BRSTSIZ_MAX             (0x0000000fU)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_DSEQNUM_MASK            (0x7C000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_DSEQNUM_SHIFT           (26U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_DSEQNUM_RESETVAL        (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_DSEQNUM_MAX             (0x0000001fU)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_MASK       (0x80000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_SHIFT      (31U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_RESETVAL   (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_RESET      (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_IGNORESEQNUM_IGNORE     (0x00000001U)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPCFG_RESETVAL                (0x00000000U)

/* DEPCMDPAR0_DEPXFERCFG */

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_MASK     (0x0000FFFFU)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_SHIFT    (0U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_RESETVAL  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_ONE      (0x00000001U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_NUMXFERRES_MAX      (0x0000ffffU)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPXFERCFG_RESETVAL            (0x00000000U)

/* DEPCMDPAR1_DEPSTRTXFER */

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_TDADDR_LOW_MASK    (0xFFFFFFFFU)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_TDADDR_LOW_SHIFT   (0U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_TDADDR_LOW_RESETVAL  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_TDADDR_LOW_MAX     (0xffffffffU)

#define CSL_DEPCMDPAR_DEPCMDPAR1_DEPSTRTXFER_RESETVAL           (0x00000000U)

/* DEPCMDPAR0_DEPSTRTXFER */

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_TDADDR_HIGH_MASK   (0xFFFFFFFFU)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_TDADDR_HIGH_SHIFT  (0U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_TDADDR_HIGH_RESETVAL  (0x00000000U)
#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_TDADDR_HIGH_MAX    (0xffffffffU)

#define CSL_DEPCMDPAR_DEPCMDPAR0_DEPSTRTXFER_RESETVAL           (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif