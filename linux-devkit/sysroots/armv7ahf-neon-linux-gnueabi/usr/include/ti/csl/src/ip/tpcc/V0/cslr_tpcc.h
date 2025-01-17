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
#ifndef CSLR_TPCC_V0_H
#define CSLR_TPCC_V0_H

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Modified Registers TPCC_DCHMAP0-TPCC_DCHMAP63 to an array of TPCC_DCHMAP[64]
 *      b) Modified Registers TPCC_QCHMAP0-TPCC_QCHMAP7 to an array of TPCC_QCHMAP[8]
 *      c) Modified Registers TPCC_DMAQNUM0-TPCC_DMAQNUM7 to an array of TPCC_DMAQNUM[8]
 *      d) Replaced TPCC_DRAE0/TPCC_DRAEH0 to TPCC_DRAE7/TPCC_DRAEH7 with an array of
 *         this CSL_EDMA3_TPCC_DRA structure
 *      e) Modified Registers TPCC_QRAE0-TPCC_QRAE6 to an array of TPCC_QRAE[8]
 *      f) Modified Registers TPCC_Q0E0-TPCC_Q7E15 to an array of TPCC_QE[8]
 *      g) Modified Registers TPCC_MPPA0-TPCC_MPPA7 to an array of TPCC_MPPA[8]
 *      h) Added Register Overlay structure for the PaRAM-Set 
 *      i) Added Register Overlay structure for SHADOW
 *      j) Appended the SHADOW and PARAM SET to the CC Register Overlay structure.
 *      k) Modified registers TPCC_QSTAT0-TPCC_QSTAT3 to an array TPCC_QSTAT[4]
 *      l) Modified header file includes as per the RTSC specification
 */

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

typedef struct CSL_EDMA3_TPCC_DRA_s
{
    volatile Uint32 DRAE;
    volatile Uint32 DRAEH;
}CSL_EDMA3_TPCC_DRA;

/**************************************************************************\
* Register Overlay Structure for SHADOW 
\**************************************************************************/
typedef struct  {
    volatile Uint32 TPCC_ER;
    volatile Uint32 TPCC_ERH;
    volatile Uint32 TPCC_ECR;
    volatile Uint32 TPCC_ECRH;
    volatile Uint32 TPCC_ESR;
    volatile Uint32 TPCC_ESRH;
    volatile Uint32 TPCC_CER;
    volatile Uint32 TPCC_CERH;
    volatile Uint32 TPCC_EER;
    volatile Uint32 TPCC_EERH;
    volatile Uint32 TPCC_EECR;
    volatile Uint32 TPCC_EECRH;
    volatile Uint32 TPCC_EESR;
    volatile Uint32 TPCC_EESRH;
    volatile Uint32 TPCC_SER;
    volatile Uint32 TPCC_SERH;
    volatile Uint32 TPCC_SECR;
    volatile Uint32 TPCC_SECRH;
    volatile Uint8 RSVD0[8];
    volatile Uint32 TPCC_IER;
    volatile Uint32 TPCC_IERH;
    volatile Uint32 TPCC_IECR;
    volatile Uint32 TPCC_IECRH;
    volatile Uint32 TPCC_IESR;
    volatile Uint32 TPCC_IESRH;
    volatile Uint32 TPCC_IPR;
    volatile Uint32 TPCC_IPRH;
    volatile Uint32 TPCC_ICR;
    volatile Uint32 TPCC_ICRH;
    volatile Uint32 TPCC_IEVAL;
    volatile Uint8 RSVD1[4];
    volatile Uint32 TPCC_QER;
    volatile Uint32 TPCC_QEER;
    volatile Uint32 TPCC_QEECR;
    volatile Uint32 TPCC_QEESR;
    volatile Uint32 TPCC_QSER;
    volatile Uint32 TPCC_QSECR;
    volatile Uint8 RSVD2[360];
} CSL_TPCC_ShadowRegs;

/**************************************************************************\
* Register Overlay Structure for PARAMSET 
\**************************************************************************/
typedef struct  {
    volatile Uint32 OPT;
    volatile Uint32 SRC;
    volatile Uint32 A_B_CNT;
    volatile Uint32 DST;
    volatile Uint32 SRC_DST_BIDX;
    volatile Uint32 LINK_BCNTRLD;
    volatile Uint32 SRC_DST_CIDX;
    volatile Uint32 CCNT;
} CSL_TPCC_ParamsetRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 TPCC_PID;
    volatile Uint32 TPCC_CFG;
    volatile Uint8 RSVD0[244];
    volatile Uint32 TPCC_CLKGDIS;
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_DCHMAP0;
    volatile Uint32 TPCC_DCHMAP1;
    volatile Uint32 TPCC_DCHMAP2;
    volatile Uint32 TPCC_DCHMAP3;
    volatile Uint32 TPCC_DCHMAP4;
    volatile Uint32 TPCC_DCHMAP5;
    volatile Uint32 TPCC_DCHMAP6;
    volatile Uint32 TPCC_DCHMAP7;
    volatile Uint32 TPCC_DCHMAP8;
    volatile Uint32 TPCC_DCHMAP9;
    volatile Uint32 TPCC_DCHMAP10;
    volatile Uint32 TPCC_DCHMAP11;
    volatile Uint32 TPCC_DCHMAP12;
    volatile Uint32 TPCC_DCHMAP13;
    volatile Uint32 TPCC_DCHMAP14;
    volatile Uint32 TPCC_DCHMAP15;
    volatile Uint32 TPCC_DCHMAP16;
    volatile Uint32 TPCC_DCHMAP17;
    volatile Uint32 TPCC_DCHMAP18;
    volatile Uint32 TPCC_DCHMAP19;
    volatile Uint32 TPCC_DCHMAP20;
    volatile Uint32 TPCC_DCHMAP21;
    volatile Uint32 TPCC_DCHMAP22;
    volatile Uint32 TPCC_DCHMAP23;
    volatile Uint32 TPCC_DCHMAP24;
    volatile Uint32 TPCC_DCHMAP25;
    volatile Uint32 TPCC_DCHMAP26;
    volatile Uint32 TPCC_DCHMAP27;
    volatile Uint32 TPCC_DCHMAP28;
    volatile Uint32 TPCC_DCHMAP29;
    volatile Uint32 TPCC_DCHMAP30;
    volatile Uint32 TPCC_DCHMAP31;
    volatile Uint32 TPCC_DCHMAP32;
    volatile Uint32 TPCC_DCHMAP33;
    volatile Uint32 TPCC_DCHMAP34;
    volatile Uint32 TPCC_DCHMAP35;
    volatile Uint32 TPCC_DCHMAP36;
    volatile Uint32 TPCC_DCHMAP37;
    volatile Uint32 TPCC_DCHMAP38;
    volatile Uint32 TPCC_DCHMAP39;
    volatile Uint32 TPCC_DCHMAP40;
    volatile Uint32 TPCC_DCHMAP41;
    volatile Uint32 TPCC_DCHMAP42;
    volatile Uint32 TPCC_DCHMAP43;
    volatile Uint32 TPCC_DCHMAP44;
    volatile Uint32 TPCC_DCHMAP45;
    volatile Uint32 TPCC_DCHMAP46;
    volatile Uint32 TPCC_DCHMAP47;
    volatile Uint32 TPCC_DCHMAP48;
    volatile Uint32 TPCC_DCHMAP49;
    volatile Uint32 TPCC_DCHMAP50;
    volatile Uint32 TPCC_DCHMAP51;
    volatile Uint32 TPCC_DCHMAP52;
    volatile Uint32 TPCC_DCHMAP53;
    volatile Uint32 TPCC_DCHMAP54;
    volatile Uint32 TPCC_DCHMAP55;
    volatile Uint32 TPCC_DCHMAP56;
    volatile Uint32 TPCC_DCHMAP57;
    volatile Uint32 TPCC_DCHMAP58;
    volatile Uint32 TPCC_DCHMAP59;
    volatile Uint32 TPCC_DCHMAP60;
    volatile Uint32 TPCC_DCHMAP61;
    volatile Uint32 TPCC_DCHMAP62;
    volatile Uint32 TPCC_DCHMAP63;
#else
    volatile Uint32 TPCC_DCHMAP[64];
#endif
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_QCHMAP0;
    volatile Uint32 TPCC_QCHMAP1;
    volatile Uint32 TPCC_QCHMAP2;
    volatile Uint32 TPCC_QCHMAP3;
    volatile Uint32 TPCC_QCHMAP4;
    volatile Uint32 TPCC_QCHMAP5;
    volatile Uint32 TPCC_QCHMAP6;
    volatile Uint32 TPCC_QCHMAP7;
#else
    volatile Uint32 TPCC_QCHMAP[8];
#endif
    volatile Uint8 RSVD1[32];
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_DMAQNUM0;
    volatile Uint32 TPCC_DMAQNUM1;
    volatile Uint32 TPCC_DMAQNUM2;
    volatile Uint32 TPCC_DMAQNUM3;
    volatile Uint32 TPCC_DMAQNUM4;
    volatile Uint32 TPCC_DMAQNUM5;
    volatile Uint32 TPCC_DMAQNUM6;
    volatile Uint32 TPCC_DMAQNUM7;
#else
    volatile Uint32 TPCC_DMAQNUM[8];
#endif    
    volatile Uint32 TPCC_QDMAQNUM;
    volatile Uint8 RSVD2[28];
    volatile Uint32 TPCC_QUETCMAP;
    volatile Uint32 TPCC_QUEPRI;
    volatile Uint8 RSVD3[120];
    volatile Uint32 TPCC_EMR;
    volatile Uint32 TPCC_EMRH;
    volatile Uint32 TPCC_EMCR;
    volatile Uint32 TPCC_EMCRH;
    volatile Uint32 TPCC_QEMR;
    volatile Uint32 TPCC_QEMCR;
    volatile Uint32 TPCC_CCERR;
    volatile Uint32 TPCC_CCERRCLR;
    volatile Uint32 TPCC_EEVAL;
    volatile Uint8 RSVD4[28];
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_DRAE0;
    volatile Uint32 TPCC_DRAEH0;
    volatile Uint32 TPCC_DRAE1;
    volatile Uint32 TPCC_DRAEH1;
    volatile Uint32 TPCC_DRAE2;
    volatile Uint32 TPCC_DRAEH2;
    volatile Uint32 TPCC_DRAE3;
    volatile Uint32 TPCC_DRAEH3;
    volatile Uint32 TPCC_DRAE4;
    volatile Uint32 TPCC_DRAEH4;
    volatile Uint32 TPCC_DRAE5;
    volatile Uint32 TPCC_DRAEH5;
    volatile Uint32 TPCC_DRAE6;
    volatile Uint32 TPCC_DRAEH6;
    volatile Uint32 TPCC_DRAE7;
    volatile Uint32 TPCC_DRAEH7;
#else
    CSL_EDMA3_TPCC_DRA  TPCC_DRA[8];
#endif
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_QRAE0;
    volatile Uint32 TPCC_QRAE1;
    volatile Uint32 TPCC_QRAE2;
    volatile Uint32 TPCC_QRAE3;
    volatile Uint32 TPCC_QRAE4;
    volatile Uint32 TPCC_QRAE5;
    volatile Uint32 TPCC_QRAE6;
    volatile Uint32 TPCC_QRAE7;
#else
    volatile Uint32 TPCC_QRAE[8];
#endif    
    volatile Uint8 RSVD5[96];
#ifdef CSL_MODIFICATION    
    volatile Uint32 TPCC_Q0E0;
    volatile Uint32 TPCC_Q0E1;
    volatile Uint32 TPCC_Q0E2;
    volatile Uint32 TPCC_Q0E3;
    volatile Uint32 TPCC_Q0E4;
    volatile Uint32 TPCC_Q0E5;
    volatile Uint32 TPCC_Q0E6;
    volatile Uint32 TPCC_Q0E7;
    volatile Uint32 TPCC_Q0E8;
    volatile Uint32 TPCC_Q0E9;
    volatile Uint32 TPCC_Q0E10;
    volatile Uint32 TPCC_Q0E11;
    volatile Uint32 TPCC_Q0E12;
    volatile Uint32 TPCC_Q0E13;
    volatile Uint32 TPCC_Q0E14;
    volatile Uint32 TPCC_Q0E15;
    volatile Uint32 TPCC_Q1E0;
    volatile Uint32 TPCC_Q1E1;
    volatile Uint32 TPCC_Q1E2;
    volatile Uint32 TPCC_Q1E3;
    volatile Uint32 TPCC_Q1E4;
    volatile Uint32 TPCC_Q1E5;
    volatile Uint32 TPCC_Q1E6;
    volatile Uint32 TPCC_Q1E7;
    volatile Uint32 TPCC_Q1E8;
    volatile Uint32 TPCC_Q1E9;
    volatile Uint32 TPCC_Q1E10;
    volatile Uint32 TPCC_Q1E11;
    volatile Uint32 TPCC_Q1E12;
    volatile Uint32 TPCC_Q1E13;
    volatile Uint32 TPCC_Q1E14;
    volatile Uint32 TPCC_Q1E15;
    volatile Uint32 TPCC_Q2E0;
    volatile Uint32 TPCC_Q2E1;
    volatile Uint32 TPCC_Q2E2;
    volatile Uint32 TPCC_Q2E3;
    volatile Uint32 TPCC_Q2E4;
    volatile Uint32 TPCC_Q2E5;
    volatile Uint32 TPCC_Q2E6;
    volatile Uint32 TPCC_Q2E7;
    volatile Uint32 TPCC_Q2E8;
    volatile Uint32 TPCC_Q2E9;
    volatile Uint32 TPCC_Q2E10;
    volatile Uint32 TPCC_Q2E11;
    volatile Uint32 TPCC_Q2E12;
    volatile Uint32 TPCC_Q2E13;
    volatile Uint32 TPCC_Q2E14;
    volatile Uint32 TPCC_Q2E15;
    volatile Uint32 TPCC_Q3E0;
    volatile Uint32 TPCC_Q3E1;
    volatile Uint32 TPCC_Q3E2;
    volatile Uint32 TPCC_Q3E3;
    volatile Uint32 TPCC_Q3E4;
    volatile Uint32 TPCC_Q3E5;
    volatile Uint32 TPCC_Q3E6;
    volatile Uint32 TPCC_Q3E7;
    volatile Uint32 TPCC_Q3E8;
    volatile Uint32 TPCC_Q3E9;
    volatile Uint32 TPCC_Q3E10;
    volatile Uint32 TPCC_Q3E11;
    volatile Uint32 TPCC_Q3E12;
    volatile Uint32 TPCC_Q3E13;
    volatile Uint32 TPCC_Q3E14;
    volatile Uint32 TPCC_Q3E15;
    volatile Uint32 TPCC_Q4E0;
    volatile Uint32 TPCC_Q4E1;
    volatile Uint32 TPCC_Q4E2;
    volatile Uint32 TPCC_Q4E3;
    volatile Uint32 TPCC_Q4E4;
    volatile Uint32 TPCC_Q4E5;
    volatile Uint32 TPCC_Q4E6;
    volatile Uint32 TPCC_Q4E7;
    volatile Uint32 TPCC_Q4E8;
    volatile Uint32 TPCC_Q4E9;
    volatile Uint32 TPCC_Q4E10;
    volatile Uint32 TPCC_Q4E11;
    volatile Uint32 TPCC_Q4E12;
    volatile Uint32 TPCC_Q4E13;
    volatile Uint32 TPCC_Q4E14;
    volatile Uint32 TPCC_Q4E15;
    volatile Uint32 TPCC_Q5E0;
    volatile Uint32 TPCC_Q5E1;
    volatile Uint32 TPCC_Q5E2;
    volatile Uint32 TPCC_Q5E3;
    volatile Uint32 TPCC_Q5E4;
    volatile Uint32 TPCC_Q5E5;
    volatile Uint32 TPCC_Q5E6;
    volatile Uint32 TPCC_Q5E7;
    volatile Uint32 TPCC_Q5E8;
    volatile Uint32 TPCC_Q5E9;
    volatile Uint32 TPCC_Q5E10;
    volatile Uint32 TPCC_Q5E11;
    volatile Uint32 TPCC_Q5E12;
    volatile Uint32 TPCC_Q5E13;
    volatile Uint32 TPCC_Q5E14;
    volatile Uint32 TPCC_Q5E15;
    volatile Uint32 TPCC_Q6E0;
    volatile Uint32 TPCC_Q6E1;
    volatile Uint32 TPCC_Q6E2;
    volatile Uint32 TPCC_Q6E3;
    volatile Uint32 TPCC_Q6E4;
    volatile Uint32 TPCC_Q6E5;
    volatile Uint32 TPCC_Q6E6;
    volatile Uint32 TPCC_Q6E7;
    volatile Uint32 TPCC_Q6E8;
    volatile Uint32 TPCC_Q6E9;
    volatile Uint32 TPCC_Q6E10;
    volatile Uint32 TPCC_Q6E11;
    volatile Uint32 TPCC_Q6E12;
    volatile Uint32 TPCC_Q6E13;
    volatile Uint32 TPCC_Q6E14;
    volatile Uint32 TPCC_Q6E15;
    volatile Uint32 TPCC_Q7E0;
    volatile Uint32 TPCC_Q7E1;
    volatile Uint32 TPCC_Q7E2;
    volatile Uint32 TPCC_Q7E3;
    volatile Uint32 TPCC_Q7E4;
    volatile Uint32 TPCC_Q7E5;
    volatile Uint32 TPCC_Q7E6;
    volatile Uint32 TPCC_Q7E7;
    volatile Uint32 TPCC_Q7E8;
    volatile Uint32 TPCC_Q7E9;
    volatile Uint32 TPCC_Q7E10;
    volatile Uint32 TPCC_Q7E11;
    volatile Uint32 TPCC_Q7E12;
    volatile Uint32 TPCC_Q7E13;
    volatile Uint32 TPCC_Q7E14;
    volatile Uint32 TPCC_Q7E15;
#else
    volatile Uint32 TPCC_QE[128];
#endif
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_QSTAT0;
    volatile Uint32 TPCC_QSTAT1;
    volatile Uint32 TPCC_QSTAT2;
    volatile Uint32 TPCC_QSTAT3;
    volatile Uint32 TPCC_QSTAT4;
    volatile Uint32 TPCC_QSTAT5;
    volatile Uint32 TPCC_QSTAT6;
    volatile Uint32 TPCC_QSTAT7;
#else
    volatile Uint32 TPCC_QSTAT[8];
#endif
    volatile Uint32 TPCC_QWMTHRA;
    volatile Uint32 TPCC_QWMTHRB;
    volatile Uint8 RSVD6[24];
    volatile Uint32 TPCC_CCSTAT;
    volatile Uint8 RSVD7[188];
    volatile Uint32 TPCC_AETCTL;
    volatile Uint32 TPCC_AETSTAT;
    volatile Uint32 TPCC_AETCMD;
    volatile Uint8 RSVD8[244];
    volatile Uint32 TPCC_MPFAR;
    volatile Uint32 TPCC_MPFSR;
    volatile Uint32 TPCC_MPFCR;
    volatile Uint32 TPCC_MPPAG;
#ifdef CSL_MODIFICATION
    volatile Uint32 TPCC_MPPA0;
    volatile Uint32 TPCC_MPPA1;
    volatile Uint32 TPCC_MPPA2;
    volatile Uint32 TPCC_MPPA3;
    volatile Uint32 TPCC_MPPA4;
    volatile Uint32 TPCC_MPPA5;
    volatile Uint32 TPCC_MPPA6;
    volatile Uint32 TPCC_MPPA7;
#else
    volatile Uint32 TPCC_MPPA[8];
#endif
    volatile Uint8 RSVD9[2000];
    volatile Uint32 TPCC_ER;
    volatile Uint32 TPCC_ERH;
    volatile Uint32 TPCC_ECR;
    volatile Uint32 TPCC_ECRH;
    volatile Uint32 TPCC_ESR;
    volatile Uint32 TPCC_ESRH;
    volatile Uint32 TPCC_CER;
    volatile Uint32 TPCC_CERH;
    volatile Uint32 TPCC_EER;
    volatile Uint32 TPCC_EERH;
    volatile Uint32 TPCC_EECR;
    volatile Uint32 TPCC_EECRH;
    volatile Uint32 TPCC_EESR;
    volatile Uint32 TPCC_EESRH;
    volatile Uint32 TPCC_SER;
    volatile Uint32 TPCC_SERH;
    volatile Uint32 TPCC_SECR;
    volatile Uint32 TPCC_SECRH;
    volatile Uint8 RSVD10[8];
    volatile Uint32 TPCC_IER;
    volatile Uint32 TPCC_IERH;
    volatile Uint32 TPCC_IECR;
    volatile Uint32 TPCC_IECRH;
    volatile Uint32 TPCC_IESR;
    volatile Uint32 TPCC_IESRH;
    volatile Uint32 TPCC_IPR;
    volatile Uint32 TPCC_IPRH;
    volatile Uint32 TPCC_ICR;
    volatile Uint32 TPCC_ICRH;
    volatile Uint32 TPCC_IEVAL;
    volatile Uint8 RSVD11[4];
    volatile Uint32 TPCC_QER;
    volatile Uint32 TPCC_QEER;
    volatile Uint32 TPCC_QEECR;
    volatile Uint32 TPCC_QEESR;
    volatile Uint32 TPCC_QSER;
    volatile Uint32 TPCC_QSECR;
#ifndef CSL_MODIFICATION
    volatile Uint8 RSVD14[3944];
    CSL_TPCC_ShadowRegs SHADOW[8];
    volatile Uint8 RSVD15[4096];
    CSL_TPCC_ParamsetRegs PARAMSET[512];    
#endif
} CSL_TpccRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* TPCC_PID */

#define CSL_TPCC_TPCC_PID_SCHEME_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_PID_SCHEME_SHIFT   ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_PID_SCHEME_RESETVAL ((uint32_t)(0x00000001u))


#define CSL_TPCC_TPCC_PID_FUNC_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_PID_FUNC_SHIFT     ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_PID_FUNC_RESETVAL  ((uint32_t)(0x00000001u))

#define CSL_TPCC_TPCC_PID_RTL_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_PID_RTL_SHIFT      ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_PID_RTL_RESETVAL   ((uint32_t)(0x00000011u))

#define CSL_TPCC_TPCC_PID_MAJOR_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_PID_MAJOR_SHIFT    ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_PID_MAJOR_RESETVAL ((uint32_t)(0x00000003u))


#define CSL_TPCC_TPCC_PID_MINOR_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_PID_MINOR_SHIFT    ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_PID_MINOR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_PID_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_CFG */

#define CSL_TPCC_TPCC_CFG_MP_EXIST_MASK  ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_CFG_MP_EXIST_SHIFT ((uint32_t)(0x00000019u))

#define CSL_TPCC_TPCC_CFG_CHMAP_EXIST_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_CFG_CHMAP_EXIST_SHIFT ((uint32_t)(0x00000018u))

#define CSL_TPCC_TPCC_CFG_NUM_REGN_MASK  ((uint32_t)(0x00300000u))
#define CSL_TPCC_TPCC_CFG_NUM_REGN_SHIFT ((uint32_t)(0x00000014u))

#define CSL_TPCC_TPCC_CFG_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_CLKGDIS */

#define CSL_TPCC_TPCC_CLKGDIS_CLKGDIS_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CLKGDIS_CLKGDIS_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CLKGDIS_CLKGDIS_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CLKGDIS_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP0 */

#define CSL_TPCC_TPCC_DCHMAP0_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP0_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP0_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP0_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP1 */

#define CSL_TPCC_TPCC_DCHMAP1_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP1_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP1_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP1_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP2 */

#define CSL_TPCC_TPCC_DCHMAP2_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP2_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP2_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP2_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP3 */

#define CSL_TPCC_TPCC_DCHMAP3_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP3_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP3_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP3_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP4 */

#define CSL_TPCC_TPCC_DCHMAP4_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP4_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP4_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP4_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP5 */

#define CSL_TPCC_TPCC_DCHMAP5_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP5_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP5_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP5_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP6 */

#define CSL_TPCC_TPCC_DCHMAP6_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP6_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP6_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP6_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP7 */

#define CSL_TPCC_TPCC_DCHMAP7_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP7_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP7_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP7_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP8 */

#define CSL_TPCC_TPCC_DCHMAP8_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP8_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP8_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP8_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP9 */

#define CSL_TPCC_TPCC_DCHMAP9_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP9_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP9_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP9_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP10 */

#define CSL_TPCC_TPCC_DCHMAP10_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP10_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP10_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP10_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP11 */

#define CSL_TPCC_TPCC_DCHMAP11_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP11_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP11_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP11_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP12 */

#define CSL_TPCC_TPCC_DCHMAP12_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP12_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP12_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP12_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP13 */

#define CSL_TPCC_TPCC_DCHMAP13_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP13_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP13_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP13_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP14 */

#define CSL_TPCC_TPCC_DCHMAP14_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP14_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP14_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP14_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP15 */

#define CSL_TPCC_TPCC_DCHMAP15_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP15_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP15_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP15_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP16 */

#define CSL_TPCC_TPCC_DCHMAP16_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP16_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP16_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP16_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP17 */

#define CSL_TPCC_TPCC_DCHMAP17_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP17_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP17_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP17_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP18 */

#define CSL_TPCC_TPCC_DCHMAP18_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP18_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP18_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP18_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP19 */

#define CSL_TPCC_TPCC_DCHMAP19_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP19_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP19_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP19_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP20 */

#define CSL_TPCC_TPCC_DCHMAP20_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP20_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP20_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP20_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP21 */

#define CSL_TPCC_TPCC_DCHMAP21_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP21_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP21_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP21_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP22 */

#define CSL_TPCC_TPCC_DCHMAP22_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP22_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP22_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP22_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP23 */

#define CSL_TPCC_TPCC_DCHMAP23_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP23_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP23_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP23_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP24 */

#define CSL_TPCC_TPCC_DCHMAP24_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP24_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP24_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP24_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP25 */

#define CSL_TPCC_TPCC_DCHMAP25_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP25_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP25_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP25_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP26 */

#define CSL_TPCC_TPCC_DCHMAP26_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP26_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP26_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP26_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP27 */

#define CSL_TPCC_TPCC_DCHMAP27_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP27_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP27_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP27_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP28 */

#define CSL_TPCC_TPCC_DCHMAP28_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP28_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP28_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP28_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP29 */

#define CSL_TPCC_TPCC_DCHMAP29_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP29_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP29_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP29_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP30 */

#define CSL_TPCC_TPCC_DCHMAP30_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP30_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP30_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP30_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP31 */

#define CSL_TPCC_TPCC_DCHMAP31_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP31_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP31_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP31_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP32 */

#define CSL_TPCC_TPCC_DCHMAP32_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP32_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP32_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP32_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP33 */

#define CSL_TPCC_TPCC_DCHMAP33_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP33_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP33_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP33_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP34 */

#define CSL_TPCC_TPCC_DCHMAP34_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP34_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP34_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP34_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP35 */

#define CSL_TPCC_TPCC_DCHMAP35_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP35_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP35_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP35_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP36 */

#define CSL_TPCC_TPCC_DCHMAP36_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP36_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP36_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP36_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP37 */

#define CSL_TPCC_TPCC_DCHMAP37_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP37_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP37_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP37_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP38 */

#define CSL_TPCC_TPCC_DCHMAP38_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP38_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP38_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP38_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP39 */

#define CSL_TPCC_TPCC_DCHMAP39_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP39_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP39_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP39_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP40 */

#define CSL_TPCC_TPCC_DCHMAP40_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP40_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP40_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP40_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP41 */

#define CSL_TPCC_TPCC_DCHMAP41_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP41_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP41_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP41_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP42 */

#define CSL_TPCC_TPCC_DCHMAP42_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP42_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP42_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP42_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP43 */

#define CSL_TPCC_TPCC_DCHMAP43_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP43_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP43_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP43_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP44 */

#define CSL_TPCC_TPCC_DCHMAP44_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP44_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP44_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP44_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP45 */

#define CSL_TPCC_TPCC_DCHMAP45_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP45_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP45_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP45_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP46 */

#define CSL_TPCC_TPCC_DCHMAP46_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP46_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP46_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP46_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP47 */

#define CSL_TPCC_TPCC_DCHMAP47_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP47_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP47_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP47_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP48 */

#define CSL_TPCC_TPCC_DCHMAP48_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP48_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP48_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP48_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP49 */

#define CSL_TPCC_TPCC_DCHMAP49_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP49_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP49_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP49_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP50 */

#define CSL_TPCC_TPCC_DCHMAP50_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP50_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP50_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP50_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP51 */

#define CSL_TPCC_TPCC_DCHMAP51_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP51_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP51_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP51_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP52 */

#define CSL_TPCC_TPCC_DCHMAP52_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP52_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP52_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP52_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP53 */

#define CSL_TPCC_TPCC_DCHMAP53_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP53_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP53_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP53_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP54 */

#define CSL_TPCC_TPCC_DCHMAP54_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP54_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP54_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP54_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP55 */

#define CSL_TPCC_TPCC_DCHMAP55_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP55_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP55_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP55_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP56 */

#define CSL_TPCC_TPCC_DCHMAP56_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP56_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP56_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP56_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP57 */

#define CSL_TPCC_TPCC_DCHMAP57_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP57_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP57_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP57_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP58 */

#define CSL_TPCC_TPCC_DCHMAP58_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP58_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP58_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP58_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP59 */

#define CSL_TPCC_TPCC_DCHMAP59_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP59_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP59_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP59_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP60 */

#define CSL_TPCC_TPCC_DCHMAP60_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP60_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP60_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP60_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP61 */

#define CSL_TPCC_TPCC_DCHMAP61_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP61_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP61_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP61_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP62 */

#define CSL_TPCC_TPCC_DCHMAP62_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP62_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP62_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP62_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DCHMAP63 */

#define CSL_TPCC_TPCC_DCHMAP63_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_DCHMAP63_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DCHMAP63_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DCHMAP63_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP0 */

#define CSL_TPCC_TPCC_QCHMAP0_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP0_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP0_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP0_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP0_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP0_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP0_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP1 */

#define CSL_TPCC_TPCC_QCHMAP1_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP1_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP1_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP1_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP1_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP1_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP1_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP2 */

#define CSL_TPCC_TPCC_QCHMAP2_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP2_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP2_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP2_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP2_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP2_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP2_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP3 */

#define CSL_TPCC_TPCC_QCHMAP3_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP3_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP3_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP3_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP3_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP3_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP3_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP4 */

#define CSL_TPCC_TPCC_QCHMAP4_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP4_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP4_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP4_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP4_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP4_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP4_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP5 */

#define CSL_TPCC_TPCC_QCHMAP5_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP5_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP5_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP5_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP5_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP5_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP5_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP6 */

#define CSL_TPCC_TPCC_QCHMAP6_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP6_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP6_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP6_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP6_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP6_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP6_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_QCHMAP7 */

#define CSL_TPCC_TPCC_QCHMAP7_PAENTRY_MASK ((uint32_t)(0x00003FE0u))
#define CSL_TPCC_TPCC_QCHMAP7_PAENTRY_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QCHMAP7_PAENTRY_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP7_TRWORD_MASK ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QCHMAP7_TRWORD_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QCHMAP7_TRWORD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QCHMAP7_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM0 */

#define CSL_TPCC_TPCC_DMAQNUM0_E0_MASK   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM0_E0_SHIFT  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM0_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E1_MASK   ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM0_E1_SHIFT  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM0_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E2_MASK   ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM0_E2_SHIFT  ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM0_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E3_MASK   ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM0_E3_SHIFT  ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM0_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E4_MASK   ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM0_E4_SHIFT  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM0_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E5_MASK   ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM0_E5_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM0_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E6_MASK   ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM0_E6_SHIFT  ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM0_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_E7_MASK   ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM0_E7_SHIFT  ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM0_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM0_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM1 */

#define CSL_TPCC_TPCC_DMAQNUM1_E8_MASK   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM1_E8_SHIFT  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM1_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E9_MASK   ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM1_E9_SHIFT  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM1_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E10_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM1_E10_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM1_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E11_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM1_E11_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM1_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E12_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM1_E12_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM1_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E13_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM1_E13_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM1_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E14_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM1_E14_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM1_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_E15_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM1_E15_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM1_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM1_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM2 */

#define CSL_TPCC_TPCC_DMAQNUM2_E16_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM2_E16_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM2_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E17_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM2_E17_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM2_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E18_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM2_E18_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM2_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E19_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM2_E19_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM2_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E20_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM2_E20_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM2_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E21_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM2_E21_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM2_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E22_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM2_E22_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM2_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_E23_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM2_E23_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM2_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM2_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM3 */

#define CSL_TPCC_TPCC_DMAQNUM3_E24_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM3_E24_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM3_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E25_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM3_E25_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM3_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E26_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM3_E26_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM3_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E27_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM3_E27_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM3_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E28_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM3_E28_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM3_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E29_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM3_E29_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM3_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E30_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM3_E30_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM3_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_E31_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM3_E31_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM3_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM3_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM4 */

#define CSL_TPCC_TPCC_DMAQNUM4_E32_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM4_E32_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM4_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E33_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM4_E33_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM4_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E34_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM4_E34_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM4_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E35_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM4_E35_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM4_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E36_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM4_E36_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM4_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E37_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM4_E37_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM4_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E38_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM4_E38_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM4_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_E39_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM4_E39_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM4_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM4_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM5 */

#define CSL_TPCC_TPCC_DMAQNUM5_E40_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM5_E40_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM5_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E41_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM5_E41_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM5_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E42_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM5_E42_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM5_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E43_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM5_E43_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM5_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E44_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM5_E44_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM5_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E45_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM5_E45_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM5_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E46_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM5_E46_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM5_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_E47_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM5_E47_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM5_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM5_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM6 */

#define CSL_TPCC_TPCC_DMAQNUM6_E48_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM6_E48_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM6_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E49_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM6_E49_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM6_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E50_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM6_E50_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM6_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E51_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM6_E51_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM6_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E52_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM6_E52_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM6_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E53_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM6_E53_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM6_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E54_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM6_E54_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM6_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_E55_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM6_E55_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM6_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM6_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_DMAQNUM7 */

#define CSL_TPCC_TPCC_DMAQNUM7_E56_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DMAQNUM7_E56_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DMAQNUM7_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E57_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_DMAQNUM7_E57_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DMAQNUM7_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E58_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_DMAQNUM7_E58_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DMAQNUM7_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E59_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_DMAQNUM7_E59_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DMAQNUM7_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E60_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_DMAQNUM7_E60_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DMAQNUM7_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E61_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_DMAQNUM7_E61_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DMAQNUM7_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E62_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_DMAQNUM7_E62_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DMAQNUM7_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_E63_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_DMAQNUM7_E63_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DMAQNUM7_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DMAQNUM7_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_QDMAQNUM */

#define CSL_TPCC_TPCC_QDMAQNUM_E0_MASK   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QDMAQNUM_E0_SHIFT  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QDMAQNUM_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E1_MASK   ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_QDMAQNUM_E1_SHIFT  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QDMAQNUM_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E2_MASK   ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_QDMAQNUM_E2_SHIFT  ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QDMAQNUM_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E3_MASK   ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_QDMAQNUM_E3_SHIFT  ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_QDMAQNUM_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E4_MASK   ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_QDMAQNUM_E4_SHIFT  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QDMAQNUM_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E5_MASK   ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_QDMAQNUM_E5_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_QDMAQNUM_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E6_MASK   ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_QDMAQNUM_E6_SHIFT  ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QDMAQNUM_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_E7_MASK   ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_QDMAQNUM_E7_SHIFT  ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QDMAQNUM_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QDMAQNUM_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_QUETCMAP */

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ0_MASK ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ1_MASK ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ1_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ2_MASK ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ2_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ3_MASK ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ3_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ4_MASK ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ4_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ5_MASK ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ5_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ6_MASK ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ6_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ7_MASK ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ7_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QUETCMAP_TCNUMQ7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUETCMAP_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_QUEPRI */

#define CSL_TPCC_TPCC_QUEPRI_PRIQ0_MASK  ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ1_MASK  ((uint32_t)(0x00000070u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ1_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ2_MASK  ((uint32_t)(0x00000700u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ2_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ3_MASK  ((uint32_t)(0x00007000u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ3_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ4_MASK  ((uint32_t)(0x00070000u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ4_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ5_MASK  ((uint32_t)(0x00700000u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ5_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ6_MASK  ((uint32_t)(0x07000000u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ6_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_PRIQ7_MASK  ((uint32_t)(0x70000000u))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ7_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_QUEPRI_PRIQ7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QUEPRI_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_EMR */

#define CSL_TPCC_TPCC_EMR_EMR0_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EMR_EMR0_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMR_EMR0_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR1_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EMR_EMR1_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EMR_EMR1_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR2_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EMR_EMR2_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EMR_EMR2_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR3_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EMR_EMR3_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_EMR_EMR3_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR4_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EMR_EMR4_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EMR_EMR4_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR5_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EMR_EMR5_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_EMR_EMR5_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR6_MASK      ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_EMR_EMR6_SHIFT     ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_EMR_EMR6_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR7_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_EMR_EMR7_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_EMR_EMR7_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR8_MASK      ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_EMR_EMR8_SHIFT     ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EMR_EMR8_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR9_MASK      ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_EMR_EMR9_SHIFT     ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_EMR_EMR9_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR10_MASK     ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_EMR_EMR10_SHIFT    ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_EMR_EMR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR11_MASK     ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_EMR_EMR11_SHIFT    ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_EMR_EMR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR12_MASK     ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_EMR_EMR12_SHIFT    ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_EMR_EMR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR13_MASK     ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_EMR_EMR13_SHIFT    ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_EMR_EMR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR14_MASK     ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_EMR_EMR14_SHIFT    ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_EMR_EMR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR15_MASK     ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_EMR_EMR15_SHIFT    ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_EMR_EMR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR16_MASK     ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_EMR_EMR16_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EMR_EMR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR17_MASK     ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_EMR_EMR17_SHIFT    ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_EMR_EMR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR18_MASK     ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_EMR_EMR18_SHIFT    ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_EMR_EMR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR19_MASK     ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_EMR_EMR19_SHIFT    ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_EMR_EMR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR20_MASK     ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_EMR_EMR20_SHIFT    ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_EMR_EMR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR21_MASK     ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_EMR_EMR21_SHIFT    ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_EMR_EMR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR22_MASK     ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_EMR_EMR22_SHIFT    ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_EMR_EMR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR23_MASK     ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_EMR_EMR23_SHIFT    ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_EMR_EMR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR24_MASK     ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_EMR_EMR24_SHIFT    ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_EMR_EMR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR25_MASK     ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_EMR_EMR25_SHIFT    ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_EMR_EMR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR26_MASK     ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_EMR_EMR26_SHIFT    ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_EMR_EMR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR27_MASK     ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_EMR_EMR27_SHIFT    ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_EMR_EMR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR28_MASK     ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_EMR_EMR28_SHIFT    ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_EMR_EMR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR29_MASK     ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_EMR_EMR29_SHIFT    ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_EMR_EMR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR30_MASK     ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_EMR_EMR30_SHIFT    ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_EMR_EMR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_EMR31_MASK     ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_EMR_EMR31_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_EMR_EMR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMR_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_EMRH */

#define CSL_TPCC_TPCC_EMRH_EMR32_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR32_SHIFT   ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EMRH_EMR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR33_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR33_SHIFT   ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_EMRH_EMR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR34_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR34_SHIFT   ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_EMRH_EMR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR35_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR35_SHIFT   ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_EMRH_EMR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR36_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR36_SHIFT   ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_EMRH_EMR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR37_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR37_SHIFT   ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_EMRH_EMR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR38_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR38_SHIFT   ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_EMRH_EMR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR39_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR39_SHIFT   ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_EMRH_EMR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR40_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR40_SHIFT   ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_EMRH_EMR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR41_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR41_SHIFT   ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_EMRH_EMR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR42_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR42_SHIFT   ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_EMRH_EMR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR43_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR43_SHIFT   ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_EMRH_EMR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR44_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR44_SHIFT   ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_EMRH_EMR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR45_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR45_SHIFT   ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_EMRH_EMR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR46_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR46_SHIFT   ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_EMRH_EMR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR47_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR47_SHIFT   ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_EMRH_EMR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR48_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR48_SHIFT   ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_EMRH_EMR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR49_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR49_SHIFT   ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_EMRH_EMR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR50_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR50_SHIFT   ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_EMRH_EMR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR51_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR51_SHIFT   ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_EMRH_EMR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR52_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR52_SHIFT   ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_EMRH_EMR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR53_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR53_SHIFT   ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_EMRH_EMR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR54_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR54_SHIFT   ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_EMRH_EMR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR55_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR55_SHIFT   ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_EMRH_EMR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR56_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR56_SHIFT   ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_EMRH_EMR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR57_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR57_SHIFT   ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_EMRH_EMR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR58_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR58_SHIFT   ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_EMRH_EMR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR59_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR59_SHIFT   ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_EMRH_EMR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR60_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR60_SHIFT   ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_EMRH_EMR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR61_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR61_SHIFT   ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_EMRH_EMR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR62_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR62_SHIFT   ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_EMRH_EMR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_EMR63_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMRH_EMR63_SHIFT   ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_EMRH_EMR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMRH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_EMCR */

#define CSL_TPCC_TPCC_EMCR_EMCR0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EMCR_EMCR0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EMCR_EMCR1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EMCR_EMCR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EMCR_EMCR2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EMCR_EMCR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EMCR_EMCR3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_EMCR_EMCR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EMCR_EMCR4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EMCR_EMCR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EMCR_EMCR5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_EMCR_EMCR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_EMCR_EMCR6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_EMCR_EMCR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_EMCR_EMCR7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_EMCR_EMCR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR8_MASK    ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_EMCR_EMCR8_SHIFT   ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EMCR_EMCR8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR9_MASK    ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_EMCR_EMCR9_SHIFT   ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_EMCR_EMCR9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR10_MASK   ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_EMCR_EMCR10_SHIFT  ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_EMCR_EMCR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR11_MASK   ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_EMCR_EMCR11_SHIFT  ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_EMCR_EMCR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR12_MASK   ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_EMCR_EMCR12_SHIFT  ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_EMCR_EMCR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR13_MASK   ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_EMCR_EMCR13_SHIFT  ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_EMCR_EMCR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR14_MASK   ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_EMCR_EMCR14_SHIFT  ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_EMCR_EMCR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR15_MASK   ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_EMCR_EMCR15_SHIFT  ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_EMCR_EMCR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR16_MASK   ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_EMCR_EMCR16_SHIFT  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EMCR_EMCR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR17_MASK   ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_EMCR_EMCR17_SHIFT  ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_EMCR_EMCR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR18_MASK   ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_EMCR_EMCR18_SHIFT  ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_EMCR_EMCR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR19_MASK   ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_EMCR_EMCR19_SHIFT  ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_EMCR_EMCR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR20_MASK   ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_EMCR_EMCR20_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_EMCR_EMCR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR21_MASK   ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_EMCR_EMCR21_SHIFT  ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_EMCR_EMCR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR22_MASK   ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_EMCR_EMCR22_SHIFT  ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_EMCR_EMCR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR23_MASK   ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_EMCR_EMCR23_SHIFT  ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_EMCR_EMCR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR24_MASK   ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR24_SHIFT  ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_EMCR_EMCR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR25_MASK   ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR25_SHIFT  ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_EMCR_EMCR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR26_MASK   ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR26_SHIFT  ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_EMCR_EMCR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR27_MASK   ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR27_SHIFT  ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_EMCR_EMCR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR28_MASK   ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR28_SHIFT  ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_EMCR_EMCR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR29_MASK   ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR29_SHIFT  ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_EMCR_EMCR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR30_MASK   ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR30_SHIFT  ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_EMCR_EMCR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_EMCR31_MASK   ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_EMCR_EMCR31_SHIFT  ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_EMCR_EMCR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_EMCRH */

#define CSL_TPCC_TPCC_EMCRH_EMCR32_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EMCRH_EMCR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR33_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_EMCRH_EMCR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR34_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_EMCRH_EMCR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR35_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_EMCRH_EMCR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR36_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_EMCRH_EMCR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR37_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_EMCRH_EMCR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR38_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_EMCRH_EMCR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR39_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_EMCRH_EMCR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR40_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_EMCRH_EMCR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR41_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_EMCRH_EMCR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR42_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_EMCRH_EMCR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR43_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_EMCRH_EMCR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR44_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_EMCRH_EMCR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR45_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_EMCRH_EMCR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR46_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_EMCRH_EMCR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR47_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_EMCRH_EMCR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR48_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_EMCRH_EMCR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR49_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_EMCRH_EMCR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR50_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_EMCRH_EMCR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR51_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_EMCRH_EMCR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR52_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_EMCRH_EMCR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR53_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_EMCRH_EMCR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR54_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_EMCRH_EMCR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR55_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_EMCRH_EMCR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR56_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_EMCRH_EMCR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR57_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_EMCRH_EMCR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR58_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_EMCRH_EMCR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR59_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_EMCRH_EMCR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR60_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_EMCRH_EMCR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR61_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_EMCRH_EMCR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR62_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_EMCRH_EMCR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_EMCR63_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EMCRH_EMCR63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_EMCRH_EMCR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EMCRH_RESETVAL     ((uint32_t)(0x0FFFFFFFu))

/* TPCC_QEMR */

#define CSL_TPCC_TPCC_QEMR_QEMR0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEMR_QEMR0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QEMR_QEMR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEMR_QEMR1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEMR_QEMR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEMR_QEMR2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEMR_QEMR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QEMR_QEMR3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QEMR_QEMR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QEMR_QEMR4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEMR_QEMR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QEMR_QEMR5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QEMR_QEMR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QEMR_QEMR6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QEMR_QEMR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_QEMR7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QEMR_QEMR7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QEMR_QEMR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_QEMCR */

#define CSL_TPCC_TPCC_QEMCR_QEMCR0_MASK  ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR1_MASK  ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR2_MASK  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR3_MASK  ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR4_MASK  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR5_MASK  ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR6_MASK  ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_QEMCR7_MASK  ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QEMCR_QEMCR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEMCR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_CCERR */

#define CSL_TPCC_TPCC_CCERR_QTHRXD0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_QTHRXD7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_CCERR_QTHRXD7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_TCCERR_MASK  ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_CCERR_TCCERR_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CCERR_TCCERR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_CCERRCLR */

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_CCERRCLR_QTHRXD7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_TCCERR_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_CCERRCLR_TCCERR_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CCERRCLR_TCCERR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCERRCLR_RESETVAL  ((uint32_t)(0x00000000u))

/* TPCC_EEVAL */

#define CSL_TPCC_TPCC_EEVAL_EVAL_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EEVAL_EVAL_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EEVAL_EVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EEVAL_SET_MASK     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EEVAL_SET_SHIFT    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EEVAL_SET_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EEVAL_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAE0 */

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_DRAE0_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE0_DRAE0_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE0_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH0 */

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH0_DRAEH0_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH0_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE1 */

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_DRAE1_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE1_DRAE1_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE1_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH1 */

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH1_DRAEH1_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH1_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE2 */

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_DRAE2_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE2_DRAE2_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE2_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH2 */

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH2_DRAEH2_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH2_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE3 */

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_DRAE3_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE3_DRAE3_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE3_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH3 */

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH3_DRAEH3_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH3_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE4 */

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_DRAE4_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE4_DRAE4_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE4_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH4 */

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH4_DRAEH4_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH4_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE5 */

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_DRAE5_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE5_DRAE5_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE5_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH5 */

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH5_DRAEH5_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH5_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE6 */

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_DRAE6_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE6_DRAE6_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE6_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH6 */

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH6_DRAEH6_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH6_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_DRAE7 */

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E8_MASK ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E8_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E9_MASK ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E9_SHIFT ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E10_MASK ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E10_SHIFT ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E11_MASK ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E11_SHIFT ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E12_MASK ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E12_SHIFT ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E13_MASK ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E13_SHIFT ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E14_MASK ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E14_SHIFT ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E15_MASK ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E15_SHIFT ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E16_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E16_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E17_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E17_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E18_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E18_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E19_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E19_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E20_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E20_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E21_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E21_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E22_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E22_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E23_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E23_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E24_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E24_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E25_MASK ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E25_SHIFT ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E26_MASK ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E26_SHIFT ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E27_MASK ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E27_SHIFT ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E28_MASK ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E28_SHIFT ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E29_MASK ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E29_SHIFT ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E30_MASK ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E30_SHIFT ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_DRAE7_E31_MASK ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E31_SHIFT ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_DRAE7_DRAE7_E31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAE7_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_DRAEH7 */

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E32_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E33_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E34_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E35_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E36_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E37_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E38_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E39_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E40_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E41_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E42_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E43_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E44_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E45_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E46_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E47_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E48_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E49_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E50_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E51_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E52_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E53_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E54_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E55_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E56_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E57_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E58_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E59_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E60_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E61_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E62_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E63_MASK ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_DRAEH7_DRAEH7_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_DRAEH7_RESETVAL    ((uint32_t)(0x0FFFFFFFu))

/* TPCC_QRAE0 */

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_QRAE0_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE0_QRAE0_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE0_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE1 */

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_QRAE1_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE1_QRAE1_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE1_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE2 */

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_QRAE2_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE2_QRAE2_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE2_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE3 */

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_QRAE3_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE3_QRAE3_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE3_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE4 */

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_QRAE4_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE4_QRAE4_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE4_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE5 */

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_QRAE5_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE5_QRAE5_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE5_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE6 */

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_QRAE6_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE6_QRAE6_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE6_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QRAE7 */

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E0_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E1_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E2_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E3_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E4_MASK ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E5_MASK ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E6_MASK ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_QRAE7_E7_MASK ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QRAE7_QRAE7_E7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QRAE7_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q0E0 */

#define CSL_TPCC_TPCC_Q0E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E1 */

#define CSL_TPCC_TPCC_Q0E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E2 */

#define CSL_TPCC_TPCC_Q0E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E3 */

#define CSL_TPCC_TPCC_Q0E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E4 */

#define CSL_TPCC_TPCC_Q0E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E5 */

#define CSL_TPCC_TPCC_Q0E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E6 */

#define CSL_TPCC_TPCC_Q0E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E7 */

#define CSL_TPCC_TPCC_Q0E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E8 */

#define CSL_TPCC_TPCC_Q0E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E9 */

#define CSL_TPCC_TPCC_Q0E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q0E10 */

#define CSL_TPCC_TPCC_Q0E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q0E11 */

#define CSL_TPCC_TPCC_Q0E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q0E12 */

#define CSL_TPCC_TPCC_Q0E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q0E13 */

#define CSL_TPCC_TPCC_Q0E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q0E14 */

#define CSL_TPCC_TPCC_Q0E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q0E15 */

#define CSL_TPCC_TPCC_Q0E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q0E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q0E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q0E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q0E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q0E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q1E0 */

#define CSL_TPCC_TPCC_Q1E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E1 */

#define CSL_TPCC_TPCC_Q1E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E2 */

#define CSL_TPCC_TPCC_Q1E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E3 */

#define CSL_TPCC_TPCC_Q1E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E4 */

#define CSL_TPCC_TPCC_Q1E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E5 */

#define CSL_TPCC_TPCC_Q1E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E6 */

#define CSL_TPCC_TPCC_Q1E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E7 */

#define CSL_TPCC_TPCC_Q1E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E8 */

#define CSL_TPCC_TPCC_Q1E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E9 */

#define CSL_TPCC_TPCC_Q1E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q1E10 */

#define CSL_TPCC_TPCC_Q1E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q1E11 */

#define CSL_TPCC_TPCC_Q1E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q1E12 */

#define CSL_TPCC_TPCC_Q1E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q1E13 */

#define CSL_TPCC_TPCC_Q1E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q1E14 */

#define CSL_TPCC_TPCC_Q1E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q1E15 */

#define CSL_TPCC_TPCC_Q1E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q1E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q1E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q1E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q1E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q1E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q2E0 */

#define CSL_TPCC_TPCC_Q2E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E1 */

#define CSL_TPCC_TPCC_Q2E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E2 */

#define CSL_TPCC_TPCC_Q2E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E3 */

#define CSL_TPCC_TPCC_Q2E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E4 */

#define CSL_TPCC_TPCC_Q2E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E5 */

#define CSL_TPCC_TPCC_Q2E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E6 */

#define CSL_TPCC_TPCC_Q2E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E7 */

#define CSL_TPCC_TPCC_Q2E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E8 */

#define CSL_TPCC_TPCC_Q2E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E9 */

#define CSL_TPCC_TPCC_Q2E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q2E10 */

#define CSL_TPCC_TPCC_Q2E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q2E11 */

#define CSL_TPCC_TPCC_Q2E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q2E12 */

#define CSL_TPCC_TPCC_Q2E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q2E13 */

#define CSL_TPCC_TPCC_Q2E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q2E14 */

#define CSL_TPCC_TPCC_Q2E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q2E15 */

#define CSL_TPCC_TPCC_Q2E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q2E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q2E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q2E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q2E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q2E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q3E0 */

#define CSL_TPCC_TPCC_Q3E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E1 */

#define CSL_TPCC_TPCC_Q3E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E2 */

#define CSL_TPCC_TPCC_Q3E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E3 */

#define CSL_TPCC_TPCC_Q3E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E4 */

#define CSL_TPCC_TPCC_Q3E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E5 */

#define CSL_TPCC_TPCC_Q3E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E6 */

#define CSL_TPCC_TPCC_Q3E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E7 */

#define CSL_TPCC_TPCC_Q3E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E8 */

#define CSL_TPCC_TPCC_Q3E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E9 */

#define CSL_TPCC_TPCC_Q3E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q3E10 */

#define CSL_TPCC_TPCC_Q3E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q3E11 */

#define CSL_TPCC_TPCC_Q3E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q3E12 */

#define CSL_TPCC_TPCC_Q3E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q3E13 */

#define CSL_TPCC_TPCC_Q3E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q3E14 */

#define CSL_TPCC_TPCC_Q3E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q3E15 */

#define CSL_TPCC_TPCC_Q3E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q3E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q3E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q3E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q3E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q3E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q4E0 */

#define CSL_TPCC_TPCC_Q4E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E1 */

#define CSL_TPCC_TPCC_Q4E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E2 */

#define CSL_TPCC_TPCC_Q4E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E3 */

#define CSL_TPCC_TPCC_Q4E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E4 */

#define CSL_TPCC_TPCC_Q4E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E5 */

#define CSL_TPCC_TPCC_Q4E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E6 */

#define CSL_TPCC_TPCC_Q4E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E7 */

#define CSL_TPCC_TPCC_Q4E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E8 */

#define CSL_TPCC_TPCC_Q4E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E9 */

#define CSL_TPCC_TPCC_Q4E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q4E10 */

#define CSL_TPCC_TPCC_Q4E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q4E11 */

#define CSL_TPCC_TPCC_Q4E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q4E12 */

#define CSL_TPCC_TPCC_Q4E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q4E13 */

#define CSL_TPCC_TPCC_Q4E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q4E14 */

#define CSL_TPCC_TPCC_Q4E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q4E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q4E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q4E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q4E15 */

#define CSL_TPCC_TPCC_Q4E15_TPCC_Q4E15_MASK ((uint32_t)(0xFFFFFFFFu))
#define CSL_TPCC_TPCC_Q4E15_TPCC_Q4E15_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q4E15_TPCC_Q4E15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q4E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q5E0 */

#define CSL_TPCC_TPCC_Q5E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E1 */

#define CSL_TPCC_TPCC_Q5E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E2 */

#define CSL_TPCC_TPCC_Q5E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E3 */

#define CSL_TPCC_TPCC_Q5E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E4 */

#define CSL_TPCC_TPCC_Q5E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E5 */

#define CSL_TPCC_TPCC_Q5E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E6 */

#define CSL_TPCC_TPCC_Q5E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E7 */

#define CSL_TPCC_TPCC_Q5E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E8 */

#define CSL_TPCC_TPCC_Q5E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E9 */

#define CSL_TPCC_TPCC_Q5E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q5E10 */

#define CSL_TPCC_TPCC_Q5E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q5E11 */

#define CSL_TPCC_TPCC_Q5E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q5E12 */

#define CSL_TPCC_TPCC_Q5E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q5E13 */

#define CSL_TPCC_TPCC_Q5E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q5E14 */

#define CSL_TPCC_TPCC_Q5E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q5E15 */

#define CSL_TPCC_TPCC_Q5E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q5E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q5E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q5E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q5E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q5E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q6E0 */

#define CSL_TPCC_TPCC_Q6E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E1 */

#define CSL_TPCC_TPCC_Q6E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E2 */

#define CSL_TPCC_TPCC_Q6E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E3 */

#define CSL_TPCC_TPCC_Q6E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E4 */

#define CSL_TPCC_TPCC_Q6E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E5 */

#define CSL_TPCC_TPCC_Q6E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E6 */

#define CSL_TPCC_TPCC_Q6E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E7 */

#define CSL_TPCC_TPCC_Q6E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E8 */

#define CSL_TPCC_TPCC_Q6E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E9 */

#define CSL_TPCC_TPCC_Q6E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q6E10 */

#define CSL_TPCC_TPCC_Q6E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q6E11 */

#define CSL_TPCC_TPCC_Q6E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q6E12 */

#define CSL_TPCC_TPCC_Q6E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q6E13 */

#define CSL_TPCC_TPCC_Q6E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q6E14 */

#define CSL_TPCC_TPCC_Q6E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q6E15 */

#define CSL_TPCC_TPCC_Q6E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q6E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q6E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q6E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q6E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q6E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q7E0 */

#define CSL_TPCC_TPCC_Q7E0_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E0_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E0_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E0_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E0_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E0_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E0_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E1 */

#define CSL_TPCC_TPCC_Q7E1_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E1_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E1_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E1_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E1_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E1_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E1_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E2 */

#define CSL_TPCC_TPCC_Q7E2_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E2_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E2_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E2_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E2_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E2_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E2_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E3 */

#define CSL_TPCC_TPCC_Q7E3_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E3_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E3_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E3_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E3_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E3_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E3_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E4 */

#define CSL_TPCC_TPCC_Q7E4_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E4_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E4_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E4_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E4_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E4_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E4_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E5 */

#define CSL_TPCC_TPCC_Q7E5_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E5_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E5_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E5_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E5_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E5_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E5_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E6 */

#define CSL_TPCC_TPCC_Q7E6_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E6_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E6_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E6_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E6_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E6_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E6_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E7 */

#define CSL_TPCC_TPCC_Q7E7_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E7_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E7_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E7_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E7_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E7_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E7_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E8 */

#define CSL_TPCC_TPCC_Q7E8_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E8_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E8_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E8_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E8_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E8_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E8_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E9 */

#define CSL_TPCC_TPCC_Q7E9_ENUM_MASK     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E9_ENUM_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E9_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E9_ETYPE_MASK    ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E9_ETYPE_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E9_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E9_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_Q7E10 */

#define CSL_TPCC_TPCC_Q7E10_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E10_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E10_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E10_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E10_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E10_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E10_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q7E11 */

#define CSL_TPCC_TPCC_Q7E11_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E11_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E11_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E11_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E11_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E11_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E11_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q7E12 */

#define CSL_TPCC_TPCC_Q7E12_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E12_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E12_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E12_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E12_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E12_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E12_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q7E13 */

#define CSL_TPCC_TPCC_Q7E13_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E13_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E13_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E13_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E13_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E13_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E13_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q7E14 */

#define CSL_TPCC_TPCC_Q7E14_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E14_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E14_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E14_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E14_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E14_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E14_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_Q7E15 */

#define CSL_TPCC_TPCC_Q7E15_ENUM_MASK    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_Q7E15_ENUM_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_Q7E15_ENUM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E15_ETYPE_MASK   ((uint32_t)(0x000000C0u))
#define CSL_TPCC_TPCC_Q7E15_ETYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_Q7E15_ETYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_Q7E15_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QSTAT0 */

#define CSL_TPCC_TPCC_QSTAT0_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT0_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT0_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT0_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT0_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT0_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT0_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT0_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT0_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT0_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT0_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT0_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT0_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT1 */

#define CSL_TPCC_TPCC_QSTAT1_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT1_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT1_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT1_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT1_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT1_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT1_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT1_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT1_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT1_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT1_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT1_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT1_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT2 */

#define CSL_TPCC_TPCC_QSTAT2_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT2_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT2_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT2_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT2_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT2_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT2_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT2_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT2_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT2_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT2_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT2_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT2_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT3 */

#define CSL_TPCC_TPCC_QSTAT3_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT3_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT3_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT3_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT3_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT3_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT3_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT3_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT3_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT3_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT3_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT3_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT3_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT4 */

#define CSL_TPCC_TPCC_QSTAT4_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT4_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT4_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT4_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT4_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT4_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT4_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT4_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT4_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT4_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT4_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT4_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT4_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT5 */

#define CSL_TPCC_TPCC_QSTAT5_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT5_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT5_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT5_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT5_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT5_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT5_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT5_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT5_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT5_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT5_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT5_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT5_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT6 */

#define CSL_TPCC_TPCC_QSTAT6_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT6_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT6_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT6_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT6_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT6_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT6_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT6_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT6_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT6_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT6_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT6_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT6_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QSTAT7 */

#define CSL_TPCC_TPCC_QSTAT7_STRPTR_MASK ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_QSTAT7_STRPTR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSTAT7_STRPTR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT7_NUMVAL_MASK ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QSTAT7_NUMVAL_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSTAT7_NUMVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT7_WM_MASK     ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QSTAT7_WM_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSTAT7_WM_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT7_THRXCD_MASK ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_QSTAT7_THRXCD_SHIFT ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QSTAT7_THRXCD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSTAT7_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_QWMTHRA */

#define CSL_TPCC_TPCC_QWMTHRA_Q0_MASK    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_QWMTHRA_Q0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QWMTHRA_Q0_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRA_Q1_MASK    ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QWMTHRA_Q1_SHIFT   ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QWMTHRA_Q1_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRA_Q2_MASK    ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QWMTHRA_Q2_SHIFT   ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QWMTHRA_Q2_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRA_Q3_MASK    ((uint32_t)(0x1F000000u))
#define CSL_TPCC_TPCC_QWMTHRA_Q3_SHIFT   ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QWMTHRA_Q3_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRA_RESETVAL   ((uint32_t)(0x10101010u))

/* TPCC_QWMTHRB */

#define CSL_TPCC_TPCC_QWMTHRB_Q4_MASK    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_QWMTHRB_Q4_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QWMTHRB_Q4_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRB_Q1_MASK    ((uint32_t)(0x00001F00u))
#define CSL_TPCC_TPCC_QWMTHRB_Q1_SHIFT   ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QWMTHRB_Q1_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRB_Q2_MASK    ((uint32_t)(0x001F0000u))
#define CSL_TPCC_TPCC_QWMTHRB_Q2_SHIFT   ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QWMTHRB_Q2_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRB_Q3_MASK    ((uint32_t)(0x1F000000u))
#define CSL_TPCC_TPCC_QWMTHRB_Q3_SHIFT   ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_QWMTHRB_Q3_RESETVAL ((uint32_t)(0x00000010u))

#define CSL_TPCC_TPCC_QWMTHRB_RESETVAL   ((uint32_t)(0x10101010u))

/* TPCC_CCSTAT */

#define CSL_TPCC_TPCC_CCSTAT_EVTACTV_MASK ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CCSTAT_EVTACTV_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CCSTAT_EVTACTV_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QEVTACTV_MASK ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CCSTAT_QEVTACTV_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CCSTAT_QEVTACTV_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_TRACTV_MASK ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CCSTAT_TRACTV_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CCSTAT_TRACTV_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_WSTATACTV_MASK ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_CCSTAT_WSTATACTV_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_CCSTAT_WSTATACTV_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_ACTV_MASK   ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CCSTAT_ACTV_SHIFT  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CCSTAT_ACTV_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_COMP_ACTV_MASK ((uint32_t)(0x00003F00u))
#define CSL_TPCC_TPCC_CCSTAT_COMP_ACTV_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_CCSTAT_COMP_ACTV_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV0_MASK ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV0_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV1_MASK ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV1_SHIFT ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV2_MASK ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV2_SHIFT ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV3_MASK ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV3_SHIFT ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV4_MASK ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV4_SHIFT ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV5_MASK ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV5_SHIFT ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV6_MASK ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV6_SHIFT ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_QUEACTV7_MASK ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV7_SHIFT ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_CCSTAT_QUEACTV7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CCSTAT_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_AETCTL */

#define CSL_TPCC_TPCC_AETCTL_STRTEVT_MASK ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_AETCTL_STRTEVT_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_AETCTL_STRTEVT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_AETCTL_TYPE_MASK   ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_AETCTL_TYPE_SHIFT  ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_AETCTL_TYPE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_AETCTL_ENDINT_MASK ((uint32_t)(0x00003F00u))
#define CSL_TPCC_TPCC_AETCTL_ENDINT_SHIFT ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_AETCTL_ENDINT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_AETCTL_EN_MASK     ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_AETCTL_EN_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_AETCTL_EN_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_AETCTL_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_AETSTAT */

#define CSL_TPCC_TPCC_AETSTAT_STAT_MASK  ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_AETSTAT_STAT_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_AETSTAT_STAT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_AETSTAT_RESETVAL   ((uint32_t)(0x00000000u))

/* TPCC_AETCMD */

#define CSL_TPCC_TPCC_AETCMD_CLR_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_AETCMD_CLR_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_AETCMD_CLR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_AETCMD_RESETVAL    ((uint32_t)(0x00000000u))

/* TPCC_MPFAR */

#define CSL_TPCC_TPCC_MPFAR_FADDR_MASK   ((uint32_t)(0xFFFFFFFFu))
#define CSL_TPCC_TPCC_MPFAR_FADDR_SHIFT  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPFAR_FADDR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFAR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPFSR */

#define CSL_TPCC_TPCC_MPFSR_UXE_MASK     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPFSR_UXE_SHIFT    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPFSR_UXE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_UWE_MASK     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPFSR_UWE_SHIFT    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPFSR_UWE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_URE_MASK     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPFSR_URE_SHIFT    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPFSR_URE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_SXE_MASK     ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPFSR_SXE_SHIFT    ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPFSR_SXE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_SWE_MASK     ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPFSR_SWE_SHIFT    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPFSR_SWE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_SRE_MASK     ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPFSR_SRE_SHIFT    ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPFSR_SRE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_SECE_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPFSR_SECE_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPFSR_SECE_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_FID_MASK     ((uint32_t)(0x00001E00u))
#define CSL_TPCC_TPCC_MPFSR_FID_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPFSR_FID_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFSR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPFCR */

#define CSL_TPCC_TPCC_MPFCR_MPFCLR_MASK  ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPFCR_MPFCLR_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPFCR_MPFCLR_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPFCR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPAG */

#define CSL_TPCC_TPCC_MPPAG_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPAG_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPAG_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPAG_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPAG_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPAG_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPAG_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPAG_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPAG_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPAG_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPAG_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPAG_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPAG_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPAG_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPAG_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPAG_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPAG_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPAG_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPAG_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPAG_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPAG_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPAG_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPAG_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPAG_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPAG_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPAG_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPAG_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPAG_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPAG_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPAG_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPAG_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPAG_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA0 */

#define CSL_TPCC_TPCC_MPPA0_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA0_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA0_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA0_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA0_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA0_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA0_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA0_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA0_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA0_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA0_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA0_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA0_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA0_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA0_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA0_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA0_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA0_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA0_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA0_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA0_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA0_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA0_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA0_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA0_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA0_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA0_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA0_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA0_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA0_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA0_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA0_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA1 */

#define CSL_TPCC_TPCC_MPPA1_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA1_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA1_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA1_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA1_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA1_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA1_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA1_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA1_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA1_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA1_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA1_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA1_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA1_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA1_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA1_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA1_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA1_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA1_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA1_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA1_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA1_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA1_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA1_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA1_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA1_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA1_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA1_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA1_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA1_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA1_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA1_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA2 */

#define CSL_TPCC_TPCC_MPPA2_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA2_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA2_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA2_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA2_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA2_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA2_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA2_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA2_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA2_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA2_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA2_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA2_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA2_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA2_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA2_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA2_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA2_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA2_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA2_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA2_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA2_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA2_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA2_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA2_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA2_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA2_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA2_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA2_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA2_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA2_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA2_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA3 */

#define CSL_TPCC_TPCC_MPPA3_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA3_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA3_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA3_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA3_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA3_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA3_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA3_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA3_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA3_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA3_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA3_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA3_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA3_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA3_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA3_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA3_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA3_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA3_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA3_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA3_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA3_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA3_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA3_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA3_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA3_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA3_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA3_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA3_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA3_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA3_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA3_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA4 */

#define CSL_TPCC_TPCC_MPPA4_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA4_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA4_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA4_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA4_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA4_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA4_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA4_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA4_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA4_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA4_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA4_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA4_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA4_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA4_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA4_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA4_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA4_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA4_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA4_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA4_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA4_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA4_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA4_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA4_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA4_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA4_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA4_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA4_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA4_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA4_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA4_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA5 */

#define CSL_TPCC_TPCC_MPPA5_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA5_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA5_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA5_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA5_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA5_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA5_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA5_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA5_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA5_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA5_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA5_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA5_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA5_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA5_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA5_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA5_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA5_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA5_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA5_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA5_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA5_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA5_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA5_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA5_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA5_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA5_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA5_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA5_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA5_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA5_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA5_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA6 */

#define CSL_TPCC_TPCC_MPPA6_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA6_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA6_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA6_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA6_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA6_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA6_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA6_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA6_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA6_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA6_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA6_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA6_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA6_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA6_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA6_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA6_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA6_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA6_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA6_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA6_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA6_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA6_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA6_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA6_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA6_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA6_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA6_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA6_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA6_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA6_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA6_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_MPPA7 */

#define CSL_TPCC_TPCC_MPPA7_UX_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA7_UX_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_MPPA7_UX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_UW_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA7_UW_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_MPPA7_UW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_UR_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA7_UR_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_MPPA7_UR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_SX_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_MPPA7_SX_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_MPPA7_SX_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_SW_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_MPPA7_SW_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_MPPA7_SW_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_SR_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_MPPA7_SR_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_MPPA7_SR_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_EMU_MASK     ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_MPPA7_EMU_SHIFT    ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_MPPA7_EMU_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_NS_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_MPPA7_NS_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_MPPA7_NS_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_EXT_MASK     ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_MPPA7_EXT_SHIFT    ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_MPPA7_EXT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_AID0_MASK    ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_MPPA7_AID0_SHIFT   ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_MPPA7_AID0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_AID1_MASK    ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_MPPA7_AID1_SHIFT   ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_MPPA7_AID1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_AID2_MASK    ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_MPPA7_AID2_SHIFT   ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_MPPA7_AID2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_AID3_MASK    ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_MPPA7_AID3_SHIFT   ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_MPPA7_AID3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_AID4_MASK    ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_MPPA7_AID4_SHIFT   ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_MPPA7_AID4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_AID5_MASK    ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_MPPA7_AID5_SHIFT   ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_MPPA7_AID5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_MPPA7_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_ER */

#define CSL_TPCC_TPCC_ER_E0_MASK         ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ER_E0_SHIFT        ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ER_E0_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E1_MASK         ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ER_E1_SHIFT        ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ER_E1_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E2_MASK         ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ER_E2_SHIFT        ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ER_E2_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E3_MASK         ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ER_E3_SHIFT        ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_ER_E3_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E4_MASK         ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ER_E4_SHIFT        ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ER_E4_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E5_MASK         ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ER_E5_SHIFT        ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_ER_E5_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E6_MASK         ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_ER_E6_SHIFT        ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_ER_E6_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E7_MASK         ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_ER_E7_SHIFT        ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_ER_E7_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E8_MASK         ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_ER_E8_SHIFT        ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ER_E8_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E9_MASK         ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_ER_E9_SHIFT        ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_ER_E9_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E10_MASK        ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_ER_E10_SHIFT       ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_ER_E10_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E11_MASK        ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_ER_E11_SHIFT       ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_ER_E11_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E12_MASK        ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_ER_E12_SHIFT       ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_ER_E12_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E13_MASK        ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_ER_E13_SHIFT       ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_ER_E13_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E14_MASK        ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_ER_E14_SHIFT       ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_ER_E14_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E15_MASK        ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_ER_E15_SHIFT       ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_ER_E15_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E16_MASK        ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_ER_E16_SHIFT       ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ER_E16_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E17_MASK        ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_ER_E17_SHIFT       ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_ER_E17_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E18_MASK        ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_ER_E18_SHIFT       ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_ER_E18_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E19_MASK        ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_ER_E19_SHIFT       ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_ER_E19_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E20_MASK        ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_ER_E20_SHIFT       ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_ER_E20_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E21_MASK        ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_ER_E21_SHIFT       ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_ER_E21_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E22_MASK        ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_ER_E22_SHIFT       ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_ER_E22_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E23_MASK        ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_ER_E23_SHIFT       ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_ER_E23_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E24_MASK        ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_ER_E24_SHIFT       ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_ER_E24_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E25_MASK        ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_ER_E25_SHIFT       ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_ER_E25_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E26_MASK        ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_ER_E26_SHIFT       ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_ER_E26_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E27_MASK        ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_ER_E27_SHIFT       ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_ER_E27_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E28_MASK        ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_ER_E28_SHIFT       ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_ER_E28_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E29_MASK        ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_ER_E29_SHIFT       ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_ER_E29_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E30_MASK        ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_ER_E30_SHIFT       ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_ER_E30_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_E31_MASK        ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_ER_E31_SHIFT       ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_ER_E31_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ER_RESETVAL        ((uint32_t)(0x00000000u))

/* TPCC_ERH */

#define CSL_TPCC_TPCC_ERH_E32_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E32_SHIFT      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ERH_E32_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E33_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E33_SHIFT      ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_ERH_E33_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E34_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E34_SHIFT      ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_ERH_E34_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E35_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E35_SHIFT      ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_ERH_E35_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E36_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E36_SHIFT      ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_ERH_E36_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E37_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E37_SHIFT      ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_ERH_E37_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E38_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E38_SHIFT      ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_ERH_E38_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E39_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E39_SHIFT      ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_ERH_E39_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E40_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E40_SHIFT      ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_ERH_E40_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E41_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E41_SHIFT      ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_ERH_E41_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E42_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E42_SHIFT      ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_ERH_E42_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E43_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E43_SHIFT      ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_ERH_E43_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E44_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E44_SHIFT      ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_ERH_E44_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E45_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E45_SHIFT      ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_ERH_E45_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E46_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E46_SHIFT      ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_ERH_E46_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E47_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E47_SHIFT      ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_ERH_E47_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E48_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E48_SHIFT      ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_ERH_E48_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E49_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E49_SHIFT      ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_ERH_E49_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E50_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E50_SHIFT      ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_ERH_E50_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E51_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E51_SHIFT      ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_ERH_E51_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E52_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E52_SHIFT      ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_ERH_E52_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E53_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E53_SHIFT      ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_ERH_E53_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E54_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E54_SHIFT      ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_ERH_E54_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E55_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E55_SHIFT      ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_ERH_E55_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E56_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E56_SHIFT      ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_ERH_E56_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E57_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E57_SHIFT      ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_ERH_E57_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E58_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E58_SHIFT      ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_ERH_E58_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E59_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E59_SHIFT      ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_ERH_E59_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E60_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E60_SHIFT      ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_ERH_E60_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E61_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E61_SHIFT      ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_ERH_E61_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E62_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E62_SHIFT      ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_ERH_E62_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_E63_MASK       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ERH_E63_SHIFT      ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_ERH_E63_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ERH_RESETVAL       ((uint32_t)(0x0FFFFFFFu))

/* TPCC_ECR */

#define CSL_TPCC_TPCC_ECR_E0_MASK        ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ECR_E0_SHIFT       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECR_E0_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E1_MASK        ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ECR_E1_SHIFT       ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ECR_E1_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E2_MASK        ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ECR_E2_SHIFT       ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ECR_E2_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E3_MASK        ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ECR_E3_SHIFT       ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_ECR_E3_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E4_MASK        ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ECR_E4_SHIFT       ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ECR_E4_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E5_MASK        ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ECR_E5_SHIFT       ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_ECR_E5_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E6_MASK        ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_ECR_E6_SHIFT       ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_ECR_E6_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E7_MASK        ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_ECR_E7_SHIFT       ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_ECR_E7_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E8_MASK        ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_ECR_E8_SHIFT       ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ECR_E8_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E9_MASK        ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_ECR_E9_SHIFT       ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_ECR_E9_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E10_MASK       ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_ECR_E10_SHIFT      ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_ECR_E10_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E11_MASK       ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_ECR_E11_SHIFT      ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_ECR_E11_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E12_MASK       ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_ECR_E12_SHIFT      ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_ECR_E12_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E13_MASK       ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_ECR_E13_SHIFT      ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_ECR_E13_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E14_MASK       ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_ECR_E14_SHIFT      ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_ECR_E14_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E15_MASK       ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_ECR_E15_SHIFT      ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_ECR_E15_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E16_MASK       ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_ECR_E16_SHIFT      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ECR_E16_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E17_MASK       ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_ECR_E17_SHIFT      ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_ECR_E17_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E18_MASK       ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_ECR_E18_SHIFT      ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_ECR_E18_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E19_MASK       ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_ECR_E19_SHIFT      ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_ECR_E19_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E20_MASK       ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_ECR_E20_SHIFT      ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_ECR_E20_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E21_MASK       ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_ECR_E21_SHIFT      ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_ECR_E21_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E22_MASK       ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_ECR_E22_SHIFT      ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_ECR_E22_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E23_MASK       ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_ECR_E23_SHIFT      ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_ECR_E23_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E24_MASK       ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_ECR_E24_SHIFT      ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_ECR_E24_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E25_MASK       ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_ECR_E25_SHIFT      ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_ECR_E25_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E26_MASK       ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_ECR_E26_SHIFT      ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_ECR_E26_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E27_MASK       ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_ECR_E27_SHIFT      ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_ECR_E27_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E28_MASK       ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_ECR_E28_SHIFT      ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_ECR_E28_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E29_MASK       ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_ECR_E29_SHIFT      ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_ECR_E29_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E30_MASK       ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_ECR_E30_SHIFT      ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_ECR_E30_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_E31_MASK       ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_ECR_E31_SHIFT      ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_ECR_E31_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECR_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_ECRH */

#define CSL_TPCC_TPCC_ECRH_E32_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E32_SHIFT     ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ECRH_E32_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E33_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E33_SHIFT     ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_ECRH_E33_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E34_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E34_SHIFT     ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_ECRH_E34_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E35_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E35_SHIFT     ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_ECRH_E35_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E36_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E36_SHIFT     ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_ECRH_E36_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E37_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E37_SHIFT     ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_ECRH_E37_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E38_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E38_SHIFT     ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_ECRH_E38_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E39_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E39_SHIFT     ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_ECRH_E39_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E40_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E40_SHIFT     ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_ECRH_E40_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E41_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E41_SHIFT     ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_ECRH_E41_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E42_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E42_SHIFT     ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_ECRH_E42_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E43_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E43_SHIFT     ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_ECRH_E43_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E44_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E44_SHIFT     ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_ECRH_E44_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E45_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E45_SHIFT     ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_ECRH_E45_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E46_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E46_SHIFT     ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_ECRH_E46_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E47_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E47_SHIFT     ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_ECRH_E47_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E48_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E48_SHIFT     ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_ECRH_E48_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E49_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E49_SHIFT     ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_ECRH_E49_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E50_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E50_SHIFT     ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_ECRH_E50_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E51_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E51_SHIFT     ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_ECRH_E51_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E52_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E52_SHIFT     ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_ECRH_E52_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E53_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E53_SHIFT     ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_ECRH_E53_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E54_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E54_SHIFT     ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_ECRH_E54_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E55_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E55_SHIFT     ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_ECRH_E55_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E56_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E56_SHIFT     ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_ECRH_E56_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E57_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E57_SHIFT     ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_ECRH_E57_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E58_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E58_SHIFT     ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_ECRH_E58_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E59_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E59_SHIFT     ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_ECRH_E59_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E60_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E60_SHIFT     ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_ECRH_E60_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E61_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E61_SHIFT     ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_ECRH_E61_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E62_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E62_SHIFT     ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_ECRH_E62_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_E63_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ECRH_E63_SHIFT     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_ECRH_E63_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ECRH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_ESR */

#define CSL_TPCC_TPCC_ESR_E0_MASK        ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ESR_E0_SHIFT       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESR_E0_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E1_MASK        ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ESR_E1_SHIFT       ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ESR_E1_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E2_MASK        ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ESR_E2_SHIFT       ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ESR_E2_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E3_MASK        ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ESR_E3_SHIFT       ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_ESR_E3_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E4_MASK        ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ESR_E4_SHIFT       ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ESR_E4_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E5_MASK        ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ESR_E5_SHIFT       ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_ESR_E5_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E6_MASK        ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_ESR_E6_SHIFT       ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_ESR_E6_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E7_MASK        ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_ESR_E7_SHIFT       ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_ESR_E7_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E8_MASK        ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_ESR_E8_SHIFT       ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ESR_E8_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E9_MASK        ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_ESR_E9_SHIFT       ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_ESR_E9_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E10_MASK       ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_ESR_E10_SHIFT      ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_ESR_E10_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E11_MASK       ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_ESR_E11_SHIFT      ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_ESR_E11_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E12_MASK       ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_ESR_E12_SHIFT      ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_ESR_E12_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E13_MASK       ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_ESR_E13_SHIFT      ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_ESR_E13_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E14_MASK       ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_ESR_E14_SHIFT      ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_ESR_E14_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E15_MASK       ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_ESR_E15_SHIFT      ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_ESR_E15_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E16_MASK       ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_ESR_E16_SHIFT      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ESR_E16_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E17_MASK       ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_ESR_E17_SHIFT      ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_ESR_E17_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E18_MASK       ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_ESR_E18_SHIFT      ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_ESR_E18_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E19_MASK       ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_ESR_E19_SHIFT      ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_ESR_E19_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E20_MASK       ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_ESR_E20_SHIFT      ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_ESR_E20_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E21_MASK       ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_ESR_E21_SHIFT      ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_ESR_E21_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E22_MASK       ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_ESR_E22_SHIFT      ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_ESR_E22_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E23_MASK       ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_ESR_E23_SHIFT      ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_ESR_E23_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E24_MASK       ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_ESR_E24_SHIFT      ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_ESR_E24_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E25_MASK       ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_ESR_E25_SHIFT      ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_ESR_E25_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E26_MASK       ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_ESR_E26_SHIFT      ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_ESR_E26_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E27_MASK       ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_ESR_E27_SHIFT      ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_ESR_E27_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E28_MASK       ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_ESR_E28_SHIFT      ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_ESR_E28_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E29_MASK       ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_ESR_E29_SHIFT      ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_ESR_E29_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E30_MASK       ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_ESR_E30_SHIFT      ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_ESR_E30_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_E31_MASK       ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_ESR_E31_SHIFT      ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_ESR_E31_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESR_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_ESRH */

#define CSL_TPCC_TPCC_ESRH_E32_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E32_SHIFT     ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ESRH_E32_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E33_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E33_SHIFT     ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_ESRH_E33_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E34_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E34_SHIFT     ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_ESRH_E34_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E35_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E35_SHIFT     ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_ESRH_E35_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E36_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E36_SHIFT     ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_ESRH_E36_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E37_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E37_SHIFT     ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_ESRH_E37_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E38_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E38_SHIFT     ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_ESRH_E38_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E39_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E39_SHIFT     ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_ESRH_E39_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E40_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E40_SHIFT     ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_ESRH_E40_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E41_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E41_SHIFT     ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_ESRH_E41_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E42_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E42_SHIFT     ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_ESRH_E42_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E43_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E43_SHIFT     ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_ESRH_E43_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E44_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E44_SHIFT     ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_ESRH_E44_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E45_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E45_SHIFT     ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_ESRH_E45_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E46_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E46_SHIFT     ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_ESRH_E46_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E47_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E47_SHIFT     ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_ESRH_E47_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E48_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E48_SHIFT     ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_ESRH_E48_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E49_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E49_SHIFT     ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_ESRH_E49_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E50_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E50_SHIFT     ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_ESRH_E50_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E51_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E51_SHIFT     ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_ESRH_E51_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E52_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E52_SHIFT     ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_ESRH_E52_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E53_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E53_SHIFT     ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_ESRH_E53_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E54_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E54_SHIFT     ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_ESRH_E54_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E55_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E55_SHIFT     ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_ESRH_E55_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E56_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E56_SHIFT     ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_ESRH_E56_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E57_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E57_SHIFT     ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_ESRH_E57_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E58_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E58_SHIFT     ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_ESRH_E58_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E59_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E59_SHIFT     ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_ESRH_E59_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E60_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E60_SHIFT     ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_ESRH_E60_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E61_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E61_SHIFT     ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_ESRH_E61_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E62_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E62_SHIFT     ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_ESRH_E62_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_E63_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ESRH_E63_SHIFT     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_ESRH_E63_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ESRH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_CER */

#define CSL_TPCC_TPCC_CER_E0_MASK        ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CER_E0_SHIFT       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CER_E0_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E1_MASK        ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CER_E1_SHIFT       ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_CER_E1_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E2_MASK        ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CER_E2_SHIFT       ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_CER_E2_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E3_MASK        ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_CER_E3_SHIFT       ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_CER_E3_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E4_MASK        ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CER_E4_SHIFT       ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_CER_E4_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E5_MASK        ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_CER_E5_SHIFT       ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_CER_E5_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E6_MASK        ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_CER_E6_SHIFT       ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_CER_E6_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E7_MASK        ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_CER_E7_SHIFT       ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_CER_E7_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E8_MASK        ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_CER_E8_SHIFT       ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_CER_E8_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E9_MASK        ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_CER_E9_SHIFT       ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_CER_E9_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E10_MASK       ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_CER_E10_SHIFT      ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_CER_E10_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E11_MASK       ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_CER_E11_SHIFT      ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_CER_E11_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E12_MASK       ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_CER_E12_SHIFT      ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_CER_E12_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E13_MASK       ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_CER_E13_SHIFT      ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_CER_E13_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E14_MASK       ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_CER_E14_SHIFT      ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_CER_E14_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E15_MASK       ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_CER_E15_SHIFT      ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_CER_E15_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E16_MASK       ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_CER_E16_SHIFT      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_CER_E16_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E17_MASK       ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_CER_E17_SHIFT      ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_CER_E17_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E18_MASK       ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_CER_E18_SHIFT      ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_CER_E18_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E19_MASK       ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_CER_E19_SHIFT      ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_CER_E19_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E20_MASK       ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_CER_E20_SHIFT      ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_CER_E20_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E21_MASK       ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_CER_E21_SHIFT      ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_CER_E21_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E22_MASK       ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_CER_E22_SHIFT      ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_CER_E22_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E23_MASK       ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_CER_E23_SHIFT      ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_CER_E23_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E24_MASK       ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_CER_E24_SHIFT      ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_CER_E24_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E25_MASK       ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_CER_E25_SHIFT      ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_CER_E25_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E26_MASK       ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_CER_E26_SHIFT      ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_CER_E26_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E27_MASK       ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_CER_E27_SHIFT      ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_CER_E27_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E28_MASK       ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_CER_E28_SHIFT      ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_CER_E28_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E29_MASK       ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_CER_E29_SHIFT      ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_CER_E29_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E30_MASK       ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_CER_E30_SHIFT      ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_CER_E30_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_E31_MASK       ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_CER_E31_SHIFT      ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_CER_E31_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CER_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_CERH */

#define CSL_TPCC_TPCC_CERH_E32_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E32_SHIFT     ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_CERH_E32_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E33_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E33_SHIFT     ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_CERH_E33_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E34_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E34_SHIFT     ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_CERH_E34_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E35_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E35_SHIFT     ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_CERH_E35_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E36_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E36_SHIFT     ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_CERH_E36_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E37_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E37_SHIFT     ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_CERH_E37_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E38_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E38_SHIFT     ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_CERH_E38_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E39_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E39_SHIFT     ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_CERH_E39_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E40_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E40_SHIFT     ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_CERH_E40_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E41_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E41_SHIFT     ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_CERH_E41_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E42_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E42_SHIFT     ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_CERH_E42_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E43_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E43_SHIFT     ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_CERH_E43_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E44_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E44_SHIFT     ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_CERH_E44_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E45_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E45_SHIFT     ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_CERH_E45_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E46_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E46_SHIFT     ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_CERH_E46_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E47_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E47_SHIFT     ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_CERH_E47_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E48_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E48_SHIFT     ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_CERH_E48_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E49_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E49_SHIFT     ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_CERH_E49_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E50_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E50_SHIFT     ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_CERH_E50_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E51_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E51_SHIFT     ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_CERH_E51_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E52_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E52_SHIFT     ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_CERH_E52_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E53_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E53_SHIFT     ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_CERH_E53_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E54_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E54_SHIFT     ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_CERH_E54_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E55_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E55_SHIFT     ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_CERH_E55_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E56_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E56_SHIFT     ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_CERH_E56_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E57_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E57_SHIFT     ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_CERH_E57_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E58_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E58_SHIFT     ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_CERH_E58_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E59_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E59_SHIFT     ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_CERH_E59_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E60_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E60_SHIFT     ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_CERH_E60_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E61_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E61_SHIFT     ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_CERH_E61_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E62_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E62_SHIFT     ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_CERH_E62_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_E63_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_CERH_E63_SHIFT     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_CERH_E63_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_CERH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_EER */

#define CSL_TPCC_TPCC_EER_E0_MASK        ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EER_E0_SHIFT       ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EER_E0_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E1_MASK        ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EER_E1_SHIFT       ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EER_E1_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E2_MASK        ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EER_E2_SHIFT       ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EER_E2_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E3_MASK        ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EER_E3_SHIFT       ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_EER_E3_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E4_MASK        ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EER_E4_SHIFT       ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EER_E4_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E5_MASK        ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EER_E5_SHIFT       ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_EER_E5_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E6_MASK        ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_EER_E6_SHIFT       ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_EER_E6_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E7_MASK        ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_EER_E7_SHIFT       ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_EER_E7_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E8_MASK        ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_EER_E8_SHIFT       ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EER_E8_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E9_MASK        ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_EER_E9_SHIFT       ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_EER_E9_RESETVAL    ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E10_MASK       ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_EER_E10_SHIFT      ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_EER_E10_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E11_MASK       ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_EER_E11_SHIFT      ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_EER_E11_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E12_MASK       ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_EER_E12_SHIFT      ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_EER_E12_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E13_MASK       ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_EER_E13_SHIFT      ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_EER_E13_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E14_MASK       ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_EER_E14_SHIFT      ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_EER_E14_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E15_MASK       ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_EER_E15_SHIFT      ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_EER_E15_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E16_MASK       ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_EER_E16_SHIFT      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EER_E16_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E17_MASK       ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_EER_E17_SHIFT      ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_EER_E17_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E18_MASK       ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_EER_E18_SHIFT      ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_EER_E18_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E19_MASK       ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_EER_E19_SHIFT      ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_EER_E19_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E20_MASK       ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_EER_E20_SHIFT      ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_EER_E20_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E21_MASK       ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_EER_E21_SHIFT      ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_EER_E21_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E22_MASK       ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_EER_E22_SHIFT      ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_EER_E22_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E23_MASK       ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_EER_E23_SHIFT      ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_EER_E23_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E24_MASK       ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_EER_E24_SHIFT      ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_EER_E24_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E25_MASK       ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_EER_E25_SHIFT      ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_EER_E25_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E26_MASK       ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_EER_E26_SHIFT      ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_EER_E26_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E27_MASK       ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_EER_E27_SHIFT      ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_EER_E27_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E28_MASK       ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_EER_E28_SHIFT      ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_EER_E28_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E29_MASK       ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_EER_E29_SHIFT      ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_EER_E29_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E30_MASK       ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_EER_E30_SHIFT      ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_EER_E30_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_E31_MASK       ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_EER_E31_SHIFT      ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_EER_E31_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EER_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_EERH */

#define CSL_TPCC_TPCC_EERH_E32_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E32_SHIFT     ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EERH_E32_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E33_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E33_SHIFT     ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_EERH_E33_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E34_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E34_SHIFT     ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_EERH_E34_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E35_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E35_SHIFT     ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_EERH_E35_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E36_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E36_SHIFT     ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_EERH_E36_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E37_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E37_SHIFT     ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_EERH_E37_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E38_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E38_SHIFT     ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_EERH_E38_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E39_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E39_SHIFT     ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_EERH_E39_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E40_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E40_SHIFT     ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_EERH_E40_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E41_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E41_SHIFT     ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_EERH_E41_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E42_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E42_SHIFT     ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_EERH_E42_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E43_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E43_SHIFT     ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_EERH_E43_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E44_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E44_SHIFT     ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_EERH_E44_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E45_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E45_SHIFT     ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_EERH_E45_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E46_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E46_SHIFT     ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_EERH_E46_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E47_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E47_SHIFT     ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_EERH_E47_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E48_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E48_SHIFT     ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_EERH_E48_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E49_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E49_SHIFT     ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_EERH_E49_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E50_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E50_SHIFT     ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_EERH_E50_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E51_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E51_SHIFT     ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_EERH_E51_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E52_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E52_SHIFT     ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_EERH_E52_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E53_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E53_SHIFT     ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_EERH_E53_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E54_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E54_SHIFT     ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_EERH_E54_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E55_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E55_SHIFT     ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_EERH_E55_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E56_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E56_SHIFT     ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_EERH_E56_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E57_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E57_SHIFT     ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_EERH_E57_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E58_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E58_SHIFT     ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_EERH_E58_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E59_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E59_SHIFT     ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_EERH_E59_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E60_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E60_SHIFT     ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_EERH_E60_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E61_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E61_SHIFT     ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_EERH_E61_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E62_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E62_SHIFT     ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_EERH_E62_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_E63_MASK      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EERH_E63_SHIFT     ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_EERH_E63_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EERH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_EECR */

#define CSL_TPCC_TPCC_EECR_E0_MASK       ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EECR_E0_SHIFT      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECR_E0_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E1_MASK       ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EECR_E1_SHIFT      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EECR_E1_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E2_MASK       ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EECR_E2_SHIFT      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EECR_E2_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E3_MASK       ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EECR_E3_SHIFT      ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_EECR_E3_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E4_MASK       ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EECR_E4_SHIFT      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EECR_E4_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E5_MASK       ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EECR_E5_SHIFT      ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_EECR_E5_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E6_MASK       ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_EECR_E6_SHIFT      ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_EECR_E6_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E7_MASK       ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_EECR_E7_SHIFT      ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_EECR_E7_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E8_MASK       ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_EECR_E8_SHIFT      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EECR_E8_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E9_MASK       ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_EECR_E9_SHIFT      ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_EECR_E9_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E10_MASK      ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_EECR_E10_SHIFT     ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_EECR_E10_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E11_MASK      ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_EECR_E11_SHIFT     ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_EECR_E11_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E12_MASK      ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_EECR_E12_SHIFT     ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_EECR_E12_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E13_MASK      ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_EECR_E13_SHIFT     ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_EECR_E13_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E14_MASK      ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_EECR_E14_SHIFT     ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_EECR_E14_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E15_MASK      ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_EECR_E15_SHIFT     ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_EECR_E15_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E16_MASK      ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_EECR_E16_SHIFT     ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EECR_E16_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E17_MASK      ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_EECR_E17_SHIFT     ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_EECR_E17_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E18_MASK      ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_EECR_E18_SHIFT     ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_EECR_E18_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E19_MASK      ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_EECR_E19_SHIFT     ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_EECR_E19_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E20_MASK      ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_EECR_E20_SHIFT     ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_EECR_E20_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E21_MASK      ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_EECR_E21_SHIFT     ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_EECR_E21_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E22_MASK      ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_EECR_E22_SHIFT     ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_EECR_E22_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E23_MASK      ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_EECR_E23_SHIFT     ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_EECR_E23_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E24_MASK      ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_EECR_E24_SHIFT     ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_EECR_E24_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E25_MASK      ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_EECR_E25_SHIFT     ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_EECR_E25_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E26_MASK      ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_EECR_E26_SHIFT     ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_EECR_E26_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E27_MASK      ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_EECR_E27_SHIFT     ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_EECR_E27_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E28_MASK      ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_EECR_E28_SHIFT     ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_EECR_E28_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E29_MASK      ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_EECR_E29_SHIFT     ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_EECR_E29_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E30_MASK      ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_EECR_E30_SHIFT     ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_EECR_E30_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_E31_MASK      ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_EECR_E31_SHIFT     ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_EECR_E31_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_EECRH */

#define CSL_TPCC_TPCC_EECRH_E32_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E32_SHIFT    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EECRH_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E33_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E33_SHIFT    ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_EECRH_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E34_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E34_SHIFT    ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_EECRH_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E35_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E35_SHIFT    ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_EECRH_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E36_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E36_SHIFT    ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_EECRH_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E37_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E37_SHIFT    ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_EECRH_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E38_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E38_SHIFT    ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_EECRH_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E39_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E39_SHIFT    ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_EECRH_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E40_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E40_SHIFT    ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_EECRH_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E41_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E41_SHIFT    ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_EECRH_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E42_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E42_SHIFT    ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_EECRH_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E43_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E43_SHIFT    ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_EECRH_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E44_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E44_SHIFT    ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_EECRH_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E45_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E45_SHIFT    ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_EECRH_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E46_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E46_SHIFT    ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_EECRH_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E47_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E47_SHIFT    ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_EECRH_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E48_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E48_SHIFT    ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_EECRH_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E49_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E49_SHIFT    ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_EECRH_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E50_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E50_SHIFT    ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_EECRH_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E51_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E51_SHIFT    ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_EECRH_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E52_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E52_SHIFT    ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_EECRH_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E53_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E53_SHIFT    ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_EECRH_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E54_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E54_SHIFT    ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_EECRH_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E55_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E55_SHIFT    ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_EECRH_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E56_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E56_SHIFT    ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_EECRH_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E57_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E57_SHIFT    ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_EECRH_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E58_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E58_SHIFT    ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_EECRH_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E59_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E59_SHIFT    ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_EECRH_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E60_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E60_SHIFT    ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_EECRH_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E61_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E61_SHIFT    ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_EECRH_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E62_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E62_SHIFT    ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_EECRH_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_E63_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EECRH_E63_SHIFT    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_EECRH_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EECRH_RESETVAL     ((uint32_t)(0x0FFFFFFFu))

/* TPCC_EESR */

#define CSL_TPCC_TPCC_EESR_E0_MASK       ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EESR_E0_SHIFT      ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESR_E0_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E1_MASK       ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EESR_E1_SHIFT      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_EESR_E1_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E2_MASK       ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EESR_E2_SHIFT      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_EESR_E2_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E3_MASK       ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EESR_E3_SHIFT      ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_EESR_E3_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E4_MASK       ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EESR_E4_SHIFT      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_EESR_E4_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E5_MASK       ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EESR_E5_SHIFT      ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_EESR_E5_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E6_MASK       ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_EESR_E6_SHIFT      ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_EESR_E6_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E7_MASK       ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_EESR_E7_SHIFT      ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_EESR_E7_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E8_MASK       ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_EESR_E8_SHIFT      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_EESR_E8_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E9_MASK       ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_EESR_E9_SHIFT      ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_EESR_E9_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E10_MASK      ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_EESR_E10_SHIFT     ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_EESR_E10_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E11_MASK      ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_EESR_E11_SHIFT     ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_EESR_E11_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E12_MASK      ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_EESR_E12_SHIFT     ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_EESR_E12_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E13_MASK      ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_EESR_E13_SHIFT     ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_EESR_E13_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E14_MASK      ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_EESR_E14_SHIFT     ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_EESR_E14_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E15_MASK      ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_EESR_E15_SHIFT     ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_EESR_E15_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E16_MASK      ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_EESR_E16_SHIFT     ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_EESR_E16_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E17_MASK      ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_EESR_E17_SHIFT     ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_EESR_E17_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E18_MASK      ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_EESR_E18_SHIFT     ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_EESR_E18_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E19_MASK      ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_EESR_E19_SHIFT     ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_EESR_E19_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E20_MASK      ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_EESR_E20_SHIFT     ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_EESR_E20_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E21_MASK      ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_EESR_E21_SHIFT     ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_EESR_E21_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E22_MASK      ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_EESR_E22_SHIFT     ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_EESR_E22_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E23_MASK      ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_EESR_E23_SHIFT     ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_EESR_E23_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E24_MASK      ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_EESR_E24_SHIFT     ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_EESR_E24_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E25_MASK      ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_EESR_E25_SHIFT     ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_EESR_E25_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E26_MASK      ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_EESR_E26_SHIFT     ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_EESR_E26_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E27_MASK      ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_EESR_E27_SHIFT     ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_EESR_E27_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E28_MASK      ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_EESR_E28_SHIFT     ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_EESR_E28_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E29_MASK      ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_EESR_E29_SHIFT     ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_EESR_E29_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E30_MASK      ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_EESR_E30_SHIFT     ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_EESR_E30_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_E31_MASK      ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_EESR_E31_SHIFT     ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_EESR_E31_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_EESRH */

#define CSL_TPCC_TPCC_EESRH_E32_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E32_SHIFT    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_EESRH_E32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E33_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E33_SHIFT    ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_EESRH_E33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E34_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E34_SHIFT    ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_EESRH_E34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E35_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E35_SHIFT    ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_EESRH_E35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E36_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E36_SHIFT    ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_EESRH_E36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E37_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E37_SHIFT    ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_EESRH_E37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E38_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E38_SHIFT    ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_EESRH_E38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E39_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E39_SHIFT    ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_EESRH_E39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E40_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E40_SHIFT    ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_EESRH_E40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E41_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E41_SHIFT    ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_EESRH_E41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E42_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E42_SHIFT    ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_EESRH_E42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E43_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E43_SHIFT    ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_EESRH_E43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E44_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E44_SHIFT    ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_EESRH_E44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E45_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E45_SHIFT    ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_EESRH_E45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E46_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E46_SHIFT    ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_EESRH_E46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E47_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E47_SHIFT    ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_EESRH_E47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E48_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E48_SHIFT    ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_EESRH_E48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E49_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E49_SHIFT    ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_EESRH_E49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E50_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E50_SHIFT    ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_EESRH_E50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E51_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E51_SHIFT    ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_EESRH_E51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E52_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E52_SHIFT    ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_EESRH_E52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E53_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E53_SHIFT    ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_EESRH_E53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E54_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E54_SHIFT    ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_EESRH_E54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E55_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E55_SHIFT    ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_EESRH_E55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E56_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E56_SHIFT    ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_EESRH_E56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E57_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E57_SHIFT    ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_EESRH_E57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E58_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E58_SHIFT    ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_EESRH_E58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E59_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E59_SHIFT    ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_EESRH_E59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E60_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E60_SHIFT    ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_EESRH_E60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E61_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E61_SHIFT    ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_EESRH_E61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E62_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E62_SHIFT    ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_EESRH_E62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_E63_MASK     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_EESRH_E63_SHIFT    ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_EESRH_E63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_EESRH_RESETVAL     ((uint32_t)(0x0FFFFFFFu))

/* TPCC_SER */

#define CSL_TPCC_TPCC_SER_SER0_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_SER_SER0_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SER_SER0_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER1_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_SER_SER1_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_SER_SER1_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER2_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_SER_SER2_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_SER_SER2_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER3_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_SER_SER3_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_SER_SER3_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER4_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_SER_SER4_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_SER_SER4_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER5_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_SER_SER5_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_SER_SER5_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER6_MASK      ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_SER_SER6_SHIFT     ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_SER_SER6_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER7_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_SER_SER7_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_SER_SER7_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER8_MASK      ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_SER_SER8_SHIFT     ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_SER_SER8_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER9_MASK      ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_SER_SER9_SHIFT     ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_SER_SER9_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER10_MASK     ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_SER_SER10_SHIFT    ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_SER_SER10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER11_MASK     ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_SER_SER11_SHIFT    ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_SER_SER11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER12_MASK     ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_SER_SER12_SHIFT    ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_SER_SER12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER13_MASK     ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_SER_SER13_SHIFT    ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_SER_SER13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER14_MASK     ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_SER_SER14_SHIFT    ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_SER_SER14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER15_MASK     ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_SER_SER15_SHIFT    ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_SER_SER15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER16_MASK     ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_SER_SER16_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_SER_SER16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER17_MASK     ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_SER_SER17_SHIFT    ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_SER_SER17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER18_MASK     ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_SER_SER18_SHIFT    ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_SER_SER18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER19_MASK     ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_SER_SER19_SHIFT    ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_SER_SER19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER20_MASK     ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_SER_SER20_SHIFT    ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_SER_SER20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER21_MASK     ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_SER_SER21_SHIFT    ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_SER_SER21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER22_MASK     ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_SER_SER22_SHIFT    ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_SER_SER22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER23_MASK     ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_SER_SER23_SHIFT    ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_SER_SER23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER24_MASK     ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_SER_SER24_SHIFT    ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_SER_SER24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER25_MASK     ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_SER_SER25_SHIFT    ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_SER_SER25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER26_MASK     ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_SER_SER26_SHIFT    ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_SER_SER26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER27_MASK     ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_SER_SER27_SHIFT    ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_SER_SER27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER28_MASK     ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_SER_SER28_SHIFT    ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_SER_SER28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER29_MASK     ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_SER_SER29_SHIFT    ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_SER_SER29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER30_MASK     ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_SER_SER30_SHIFT    ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_SER_SER30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_SER31_MASK     ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_SER_SER31_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_SER_SER31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SER_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_SERH */

#define CSL_TPCC_TPCC_SERH_SER32_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER32_SHIFT   ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_SERH_SER32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER33_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER33_SHIFT   ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_SERH_SER33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER34_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER34_SHIFT   ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_SERH_SER34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER35_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER35_SHIFT   ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_SERH_SER35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER36_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER36_SHIFT   ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_SERH_SER36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER37_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER37_SHIFT   ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_SERH_SER37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER38_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER38_SHIFT   ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_SERH_SER38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER39_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER39_SHIFT   ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_SERH_SER39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER40_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER40_SHIFT   ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_SERH_SER40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER41_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER41_SHIFT   ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_SERH_SER41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER42_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER42_SHIFT   ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_SERH_SER42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER43_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER43_SHIFT   ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_SERH_SER43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER44_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER44_SHIFT   ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_SERH_SER44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER45_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER45_SHIFT   ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_SERH_SER45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER46_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER46_SHIFT   ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_SERH_SER46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER47_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER47_SHIFT   ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_SERH_SER47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER48_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER48_SHIFT   ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_SERH_SER48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER49_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER49_SHIFT   ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_SERH_SER49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER50_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER50_SHIFT   ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_SERH_SER50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER51_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER51_SHIFT   ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_SERH_SER51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER52_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER52_SHIFT   ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_SERH_SER52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER53_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER53_SHIFT   ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_SERH_SER53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER54_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER54_SHIFT   ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_SERH_SER54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER55_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER55_SHIFT   ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_SERH_SER55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER56_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER56_SHIFT   ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_SERH_SER56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER57_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER57_SHIFT   ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_SERH_SER57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER58_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER58_SHIFT   ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_SERH_SER58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER59_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER59_SHIFT   ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_SERH_SER59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER60_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER60_SHIFT   ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_SERH_SER60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER61_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER61_SHIFT   ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_SERH_SER61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER62_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER62_SHIFT   ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_SERH_SER62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_SER63_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SERH_SER63_SHIFT   ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_SERH_SER63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SERH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_SECR */

#define CSL_TPCC_TPCC_SECR_SECR0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_SECR_SECR0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECR_SECR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_SECR_SECR1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_SECR_SECR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_SECR_SECR2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_SECR_SECR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_SECR_SECR3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_SECR_SECR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_SECR_SECR4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_SECR_SECR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_SECR_SECR5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_SECR_SECR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_SECR_SECR6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_SECR_SECR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_SECR_SECR7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_SECR_SECR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR8_MASK    ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_SECR_SECR8_SHIFT   ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_SECR_SECR8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR9_MASK    ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_SECR_SECR9_SHIFT   ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_SECR_SECR9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR10_MASK   ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_SECR_SECR10_SHIFT  ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_SECR_SECR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR11_MASK   ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_SECR_SECR11_SHIFT  ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_SECR_SECR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR12_MASK   ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_SECR_SECR12_SHIFT  ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_SECR_SECR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR13_MASK   ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_SECR_SECR13_SHIFT  ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_SECR_SECR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR14_MASK   ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_SECR_SECR14_SHIFT  ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_SECR_SECR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR15_MASK   ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_SECR_SECR15_SHIFT  ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_SECR_SECR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR16_MASK   ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_SECR_SECR16_SHIFT  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_SECR_SECR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR17_MASK   ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_SECR_SECR17_SHIFT  ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_SECR_SECR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR18_MASK   ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_SECR_SECR18_SHIFT  ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_SECR_SECR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR19_MASK   ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_SECR_SECR19_SHIFT  ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_SECR_SECR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR20_MASK   ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_SECR_SECR20_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_SECR_SECR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR21_MASK   ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_SECR_SECR21_SHIFT  ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_SECR_SECR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR22_MASK   ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_SECR_SECR22_SHIFT  ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_SECR_SECR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR23_MASK   ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_SECR_SECR23_SHIFT  ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_SECR_SECR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR24_MASK   ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_SECR_SECR24_SHIFT  ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_SECR_SECR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR25_MASK   ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_SECR_SECR25_SHIFT  ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_SECR_SECR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR26_MASK   ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_SECR_SECR26_SHIFT  ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_SECR_SECR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR27_MASK   ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_SECR_SECR27_SHIFT  ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_SECR_SECR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR28_MASK   ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_SECR_SECR28_SHIFT  ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_SECR_SECR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR29_MASK   ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_SECR_SECR29_SHIFT  ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_SECR_SECR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR30_MASK   ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_SECR_SECR30_SHIFT  ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_SECR_SECR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_SECR31_MASK   ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_SECR_SECR31_SHIFT  ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_SECR_SECR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_SECRH */

#define CSL_TPCC_TPCC_SECRH_SECR32_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_SECRH_SECR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR33_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_SECRH_SECR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR34_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_SECRH_SECR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR35_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_SECRH_SECR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR36_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_SECRH_SECR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR37_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_SECRH_SECR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR38_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_SECRH_SECR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR39_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_SECRH_SECR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR40_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_SECRH_SECR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR41_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_SECRH_SECR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR42_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_SECRH_SECR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR43_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_SECRH_SECR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR44_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_SECRH_SECR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR45_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_SECRH_SECR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR46_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_SECRH_SECR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR47_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_SECRH_SECR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR48_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_SECRH_SECR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR49_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_SECRH_SECR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR50_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_SECRH_SECR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR51_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_SECRH_SECR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR52_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_SECRH_SECR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR53_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_SECRH_SECR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR54_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_SECRH_SECR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR55_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_SECRH_SECR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR56_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_SECRH_SECR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR57_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_SECRH_SECR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR58_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_SECRH_SECR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR59_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_SECRH_SECR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR60_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_SECRH_SECR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR61_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_SECRH_SECR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR62_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_SECRH_SECR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_SECR63_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_SECRH_SECR63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_SECRH_SECR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_SECRH_RESETVAL     ((uint32_t)(0x0FFFFFFFu))

/* TPCC_IER */

#define CSL_TPCC_TPCC_IER_IER0_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IER_IER0_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IER_IER0_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER1_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IER_IER1_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IER_IER1_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER2_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IER_IER2_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IER_IER2_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER3_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IER_IER3_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_IER_IER3_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER4_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IER_IER4_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IER_IER4_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER5_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IER_IER5_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_IER_IER5_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER6_MASK      ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_IER_IER6_SHIFT     ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_IER_IER6_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER7_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_IER_IER7_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_IER_IER7_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER8_MASK      ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_IER_IER8_SHIFT     ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IER_IER8_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER9_MASK      ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_IER_IER9_SHIFT     ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_IER_IER9_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER10_MASK     ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_IER_IER10_SHIFT    ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_IER_IER10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER11_MASK     ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_IER_IER11_SHIFT    ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_IER_IER11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER12_MASK     ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_IER_IER12_SHIFT    ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_IER_IER12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER13_MASK     ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_IER_IER13_SHIFT    ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_IER_IER13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER14_MASK     ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_IER_IER14_SHIFT    ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_IER_IER14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER15_MASK     ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_IER_IER15_SHIFT    ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_IER_IER15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER16_MASK     ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_IER_IER16_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IER_IER16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER17_MASK     ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_IER_IER17_SHIFT    ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_IER_IER17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER18_MASK     ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_IER_IER18_SHIFT    ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_IER_IER18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER19_MASK     ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_IER_IER19_SHIFT    ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_IER_IER19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER20_MASK     ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_IER_IER20_SHIFT    ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_IER_IER20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER21_MASK     ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_IER_IER21_SHIFT    ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_IER_IER21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER22_MASK     ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_IER_IER22_SHIFT    ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_IER_IER22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER23_MASK     ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_IER_IER23_SHIFT    ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_IER_IER23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER24_MASK     ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_IER_IER24_SHIFT    ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_IER_IER24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER25_MASK     ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_IER_IER25_SHIFT    ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_IER_IER25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER26_MASK     ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_IER_IER26_SHIFT    ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_IER_IER26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER27_MASK     ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_IER_IER27_SHIFT    ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_IER_IER27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER28_MASK     ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_IER_IER28_SHIFT    ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_IER_IER28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER29_MASK     ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_IER_IER29_SHIFT    ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_IER_IER29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER30_MASK     ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_IER_IER30_SHIFT    ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_IER_IER30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_IER31_MASK     ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_IER_IER31_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_IER_IER31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IER_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_IERH */

#define CSL_TPCC_TPCC_IERH_IER32_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER32_SHIFT   ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IERH_IER32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER33_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER33_SHIFT   ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_IERH_IER33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER34_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER34_SHIFT   ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_IERH_IER34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER35_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER35_SHIFT   ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_IERH_IER35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER36_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER36_SHIFT   ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_IERH_IER36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER37_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER37_SHIFT   ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_IERH_IER37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER38_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER38_SHIFT   ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_IERH_IER38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER39_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER39_SHIFT   ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_IERH_IER39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER40_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER40_SHIFT   ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_IERH_IER40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER41_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER41_SHIFT   ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_IERH_IER41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER42_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER42_SHIFT   ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_IERH_IER42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER43_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER43_SHIFT   ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_IERH_IER43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER44_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER44_SHIFT   ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_IERH_IER44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER45_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER45_SHIFT   ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_IERH_IER45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER46_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER46_SHIFT   ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_IERH_IER46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER47_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER47_SHIFT   ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_IERH_IER47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER48_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER48_SHIFT   ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_IERH_IER48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER49_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER49_SHIFT   ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_IERH_IER49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER50_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER50_SHIFT   ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_IERH_IER50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER51_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER51_SHIFT   ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_IERH_IER51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER52_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER52_SHIFT   ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_IERH_IER52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER53_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER53_SHIFT   ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_IERH_IER53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER54_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER54_SHIFT   ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_IERH_IER54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER55_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER55_SHIFT   ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_IERH_IER55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER56_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER56_SHIFT   ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_IERH_IER56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER57_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER57_SHIFT   ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_IERH_IER57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER58_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER58_SHIFT   ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_IERH_IER58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER59_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER59_SHIFT   ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_IERH_IER59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER60_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER60_SHIFT   ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_IERH_IER60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER61_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER61_SHIFT   ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_IERH_IER61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER62_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER62_SHIFT   ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_IERH_IER62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_IER63_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IERH_IER63_SHIFT   ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_IERH_IER63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IERH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_IECR */

#define CSL_TPCC_TPCC_IECR_IECR0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IECR_IECR0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECR_IECR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IECR_IECR1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IECR_IECR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IECR_IECR2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IECR_IECR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IECR_IECR3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_IECR_IECR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IECR_IECR4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IECR_IECR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IECR_IECR5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_IECR_IECR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_IECR_IECR6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_IECR_IECR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_IECR_IECR7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_IECR_IECR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR8_MASK    ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_IECR_IECR8_SHIFT   ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IECR_IECR8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR9_MASK    ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_IECR_IECR9_SHIFT   ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_IECR_IECR9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR10_MASK   ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_IECR_IECR10_SHIFT  ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_IECR_IECR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR11_MASK   ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_IECR_IECR11_SHIFT  ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_IECR_IECR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR12_MASK   ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_IECR_IECR12_SHIFT  ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_IECR_IECR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR13_MASK   ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_IECR_IECR13_SHIFT  ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_IECR_IECR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR14_MASK   ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_IECR_IECR14_SHIFT  ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_IECR_IECR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR15_MASK   ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_IECR_IECR15_SHIFT  ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_IECR_IECR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR16_MASK   ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_IECR_IECR16_SHIFT  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IECR_IECR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR17_MASK   ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_IECR_IECR17_SHIFT  ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_IECR_IECR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR18_MASK   ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_IECR_IECR18_SHIFT  ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_IECR_IECR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR19_MASK   ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_IECR_IECR19_SHIFT  ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_IECR_IECR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR20_MASK   ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_IECR_IECR20_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_IECR_IECR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR21_MASK   ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_IECR_IECR21_SHIFT  ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_IECR_IECR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR22_MASK   ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_IECR_IECR22_SHIFT  ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_IECR_IECR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR23_MASK   ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_IECR_IECR23_SHIFT  ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_IECR_IECR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR24_MASK   ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_IECR_IECR24_SHIFT  ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_IECR_IECR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR25_MASK   ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_IECR_IECR25_SHIFT  ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_IECR_IECR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR26_MASK   ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_IECR_IECR26_SHIFT  ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_IECR_IECR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR27_MASK   ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_IECR_IECR27_SHIFT  ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_IECR_IECR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR28_MASK   ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_IECR_IECR28_SHIFT  ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_IECR_IECR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR29_MASK   ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_IECR_IECR29_SHIFT  ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_IECR_IECR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR30_MASK   ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_IECR_IECR30_SHIFT  ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_IECR_IECR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_IECR31_MASK   ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_IECR_IECR31_SHIFT  ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_IECR_IECR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_IECRH */

#define CSL_TPCC_TPCC_IECRH_IECR32_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IECRH_IECR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR33_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_IECRH_IECR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR34_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_IECRH_IECR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR35_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_IECRH_IECR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR36_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_IECRH_IECR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR37_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_IECRH_IECR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR38_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_IECRH_IECR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR39_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_IECRH_IECR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR40_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_IECRH_IECR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR41_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_IECRH_IECR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR42_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_IECRH_IECR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR43_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_IECRH_IECR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR44_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_IECRH_IECR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR45_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_IECRH_IECR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR46_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_IECRH_IECR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR47_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_IECRH_IECR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR48_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_IECRH_IECR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR49_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_IECRH_IECR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR50_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_IECRH_IECR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR51_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_IECRH_IECR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR52_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_IECRH_IECR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR53_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_IECRH_IECR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR54_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_IECRH_IECR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR55_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_IECRH_IECR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR56_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_IECRH_IECR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR57_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_IECRH_IECR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR58_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_IECRH_IECR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR59_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_IECRH_IECR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR60_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_IECRH_IECR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR61_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_IECRH_IECR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR62_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_IECRH_IECR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_IECR63_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IECRH_IECR63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_IECRH_IECR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IECRH_RESETVAL     ((uint32_t)(0x0FFFFFFFu))

/* TPCC_IESR */

#define CSL_TPCC_TPCC_IESR_IESR0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IESR_IESR0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESR_IESR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IESR_IESR1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IESR_IESR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IESR_IESR2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IESR_IESR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IESR_IESR3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_IESR_IESR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IESR_IESR4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IESR_IESR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IESR_IESR5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_IESR_IESR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_IESR_IESR6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_IESR_IESR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_IESR_IESR7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_IESR_IESR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR8_MASK    ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_IESR_IESR8_SHIFT   ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IESR_IESR8_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR9_MASK    ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_IESR_IESR9_SHIFT   ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_IESR_IESR9_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR10_MASK   ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_IESR_IESR10_SHIFT  ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_IESR_IESR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR11_MASK   ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_IESR_IESR11_SHIFT  ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_IESR_IESR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR12_MASK   ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_IESR_IESR12_SHIFT  ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_IESR_IESR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR13_MASK   ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_IESR_IESR13_SHIFT  ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_IESR_IESR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR14_MASK   ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_IESR_IESR14_SHIFT  ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_IESR_IESR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR15_MASK   ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_IESR_IESR15_SHIFT  ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_IESR_IESR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR16_MASK   ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_IESR_IESR16_SHIFT  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IESR_IESR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR17_MASK   ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_IESR_IESR17_SHIFT  ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_IESR_IESR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR18_MASK   ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_IESR_IESR18_SHIFT  ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_IESR_IESR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR19_MASK   ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_IESR_IESR19_SHIFT  ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_IESR_IESR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR20_MASK   ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_IESR_IESR20_SHIFT  ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_IESR_IESR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR21_MASK   ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_IESR_IESR21_SHIFT  ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_IESR_IESR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR22_MASK   ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_IESR_IESR22_SHIFT  ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_IESR_IESR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR23_MASK   ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_IESR_IESR23_SHIFT  ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_IESR_IESR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR24_MASK   ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_IESR_IESR24_SHIFT  ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_IESR_IESR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR25_MASK   ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_IESR_IESR25_SHIFT  ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_IESR_IESR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR26_MASK   ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_IESR_IESR26_SHIFT  ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_IESR_IESR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR27_MASK   ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_IESR_IESR27_SHIFT  ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_IESR_IESR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR28_MASK   ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_IESR_IESR28_SHIFT  ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_IESR_IESR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR29_MASK   ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_IESR_IESR29_SHIFT  ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_IESR_IESR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR30_MASK   ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_IESR_IESR30_SHIFT  ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_IESR_IESR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_IESR31_MASK   ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_IESR_IESR31_SHIFT  ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_IESR_IESR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESR_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_IESRH */

#define CSL_TPCC_TPCC_IESRH_IESR32_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR32_SHIFT ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IESRH_IESR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR33_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR33_SHIFT ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_IESRH_IESR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR34_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR34_SHIFT ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_IESRH_IESR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR35_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR35_SHIFT ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_IESRH_IESR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR36_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR36_SHIFT ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_IESRH_IESR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR37_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR37_SHIFT ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_IESRH_IESR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR38_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR38_SHIFT ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_IESRH_IESR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR39_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR39_SHIFT ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_IESRH_IESR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR40_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR40_SHIFT ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_IESRH_IESR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR41_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR41_SHIFT ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_IESRH_IESR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR42_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR42_SHIFT ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_IESRH_IESR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR43_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR43_SHIFT ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_IESRH_IESR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR44_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR44_SHIFT ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_IESRH_IESR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR45_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR45_SHIFT ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_IESRH_IESR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR46_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR46_SHIFT ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_IESRH_IESR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR47_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR47_SHIFT ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_IESRH_IESR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR48_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR48_SHIFT ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_IESRH_IESR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR49_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR49_SHIFT ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_IESRH_IESR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR50_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR50_SHIFT ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_IESRH_IESR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR51_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR51_SHIFT ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_IESRH_IESR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR52_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR52_SHIFT ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_IESRH_IESR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR53_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR53_SHIFT ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_IESRH_IESR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR54_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR54_SHIFT ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_IESRH_IESR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR55_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR55_SHIFT ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_IESRH_IESR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR56_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR56_SHIFT ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_IESRH_IESR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR57_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR57_SHIFT ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_IESRH_IESR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR58_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR58_SHIFT ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_IESRH_IESR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR59_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR59_SHIFT ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_IESRH_IESR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR60_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR60_SHIFT ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_IESRH_IESR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR61_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR61_SHIFT ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_IESRH_IESR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR62_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR62_SHIFT ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_IESRH_IESR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_IESR63_MASK  ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IESRH_IESR63_SHIFT ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_IESRH_IESR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IESRH_RESETVAL     ((uint32_t)(0x0FFFFFFFu))

/* TPCC_IPR */

#define CSL_TPCC_TPCC_IPR_IPR0_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IPR_IPR0_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPR_IPR0_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR1_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IPR_IPR1_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IPR_IPR1_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR2_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IPR_IPR2_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IPR_IPR2_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR3_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IPR_IPR3_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_IPR_IPR3_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR4_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IPR_IPR4_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_IPR_IPR4_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR5_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IPR_IPR5_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_IPR_IPR5_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR6_MASK      ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_IPR_IPR6_SHIFT     ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_IPR_IPR6_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR7_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_IPR_IPR7_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_IPR_IPR7_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR8_MASK      ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_IPR_IPR8_SHIFT     ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_IPR_IPR8_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR9_MASK      ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_IPR_IPR9_SHIFT     ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_IPR_IPR9_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR10_MASK     ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_IPR_IPR10_SHIFT    ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_IPR_IPR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR11_MASK     ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_IPR_IPR11_SHIFT    ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_IPR_IPR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR12_MASK     ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_IPR_IPR12_SHIFT    ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_IPR_IPR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR13_MASK     ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_IPR_IPR13_SHIFT    ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_IPR_IPR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR14_MASK     ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_IPR_IPR14_SHIFT    ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_IPR_IPR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR15_MASK     ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_IPR_IPR15_SHIFT    ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_IPR_IPR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR16_MASK     ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_IPR_IPR16_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_IPR_IPR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR17_MASK     ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_IPR_IPR17_SHIFT    ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_IPR_IPR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR18_MASK     ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_IPR_IPR18_SHIFT    ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_IPR_IPR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR19_MASK     ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_IPR_IPR19_SHIFT    ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_IPR_IPR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR20_MASK     ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_IPR_IPR20_SHIFT    ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_IPR_IPR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR21_MASK     ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_IPR_IPR21_SHIFT    ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_IPR_IPR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR22_MASK     ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_IPR_IPR22_SHIFT    ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_IPR_IPR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR23_MASK     ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_IPR_IPR23_SHIFT    ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_IPR_IPR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR24_MASK     ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_IPR_IPR24_SHIFT    ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_IPR_IPR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR25_MASK     ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_IPR_IPR25_SHIFT    ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_IPR_IPR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR26_MASK     ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_IPR_IPR26_SHIFT    ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_IPR_IPR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR27_MASK     ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_IPR_IPR27_SHIFT    ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_IPR_IPR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR28_MASK     ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_IPR_IPR28_SHIFT    ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_IPR_IPR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR29_MASK     ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_IPR_IPR29_SHIFT    ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_IPR_IPR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR30_MASK     ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_IPR_IPR30_SHIFT    ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_IPR_IPR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_IPR31_MASK     ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_IPR_IPR31_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_IPR_IPR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPR_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_IPRH */

#define CSL_TPCC_TPCC_IPRH_IPR32_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR32_SHIFT   ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_IPRH_IPR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR33_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR33_SHIFT   ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_IPRH_IPR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR34_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR34_SHIFT   ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_IPRH_IPR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR35_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR35_SHIFT   ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_IPRH_IPR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR36_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR36_SHIFT   ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_IPRH_IPR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR37_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR37_SHIFT   ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_IPRH_IPR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR38_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR38_SHIFT   ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_IPRH_IPR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR39_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR39_SHIFT   ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_IPRH_IPR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR40_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR40_SHIFT   ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_IPRH_IPR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR41_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR41_SHIFT   ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_IPRH_IPR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR42_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR42_SHIFT   ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_IPRH_IPR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR43_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR43_SHIFT   ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_IPRH_IPR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR44_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR44_SHIFT   ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_IPRH_IPR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR45_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR45_SHIFT   ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_IPRH_IPR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR46_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR46_SHIFT   ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_IPRH_IPR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR47_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR47_SHIFT   ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_IPRH_IPR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR48_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR48_SHIFT   ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_IPRH_IPR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR49_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR49_SHIFT   ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_IPRH_IPR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR50_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR50_SHIFT   ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_IPRH_IPR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR51_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR51_SHIFT   ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_IPRH_IPR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR52_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR52_SHIFT   ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_IPRH_IPR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR53_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR53_SHIFT   ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_IPRH_IPR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR54_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR54_SHIFT   ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_IPRH_IPR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR55_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR55_SHIFT   ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_IPRH_IPR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR56_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR56_SHIFT   ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_IPRH_IPR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR57_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR57_SHIFT   ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_IPRH_IPR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR58_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR58_SHIFT   ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_IPRH_IPR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR59_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR59_SHIFT   ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_IPRH_IPR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR60_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR60_SHIFT   ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_IPRH_IPR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR61_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR61_SHIFT   ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_IPRH_IPR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR62_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR62_SHIFT   ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_IPRH_IPR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_IPR63_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IPRH_IPR63_SHIFT   ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_IPRH_IPR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IPRH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_ICR */

#define CSL_TPCC_TPCC_ICR_ICR0_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ICR_ICR0_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICR_ICR0_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR1_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ICR_ICR1_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_ICR_ICR1_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR2_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ICR_ICR2_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_ICR_ICR2_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR3_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ICR_ICR3_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_ICR_ICR3_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR4_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ICR_ICR4_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_ICR_ICR4_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR5_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ICR_ICR5_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_ICR_ICR5_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR6_MASK      ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_ICR_ICR6_SHIFT     ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_ICR_ICR6_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR7_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_ICR_ICR7_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_ICR_ICR7_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR8_MASK      ((uint32_t)(0x00000100u))
#define CSL_TPCC_TPCC_ICR_ICR8_SHIFT     ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_ICR_ICR8_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR9_MASK      ((uint32_t)(0x00000200u))
#define CSL_TPCC_TPCC_ICR_ICR9_SHIFT     ((uint32_t)(0x00000009u))
#define CSL_TPCC_TPCC_ICR_ICR9_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR10_MASK     ((uint32_t)(0x00000400u))
#define CSL_TPCC_TPCC_ICR_ICR10_SHIFT    ((uint32_t)(0x0000000Au))
#define CSL_TPCC_TPCC_ICR_ICR10_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR11_MASK     ((uint32_t)(0x00000800u))
#define CSL_TPCC_TPCC_ICR_ICR11_SHIFT    ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_TPCC_ICR_ICR11_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR12_MASK     ((uint32_t)(0x00001000u))
#define CSL_TPCC_TPCC_ICR_ICR12_SHIFT    ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_TPCC_ICR_ICR12_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR13_MASK     ((uint32_t)(0x00002000u))
#define CSL_TPCC_TPCC_ICR_ICR13_SHIFT    ((uint32_t)(0x0000000Du))
#define CSL_TPCC_TPCC_ICR_ICR13_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR14_MASK     ((uint32_t)(0x00004000u))
#define CSL_TPCC_TPCC_ICR_ICR14_SHIFT    ((uint32_t)(0x0000000Eu))
#define CSL_TPCC_TPCC_ICR_ICR14_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR15_MASK     ((uint32_t)(0x00008000u))
#define CSL_TPCC_TPCC_ICR_ICR15_SHIFT    ((uint32_t)(0x0000000Fu))
#define CSL_TPCC_TPCC_ICR_ICR15_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR16_MASK     ((uint32_t)(0x00010000u))
#define CSL_TPCC_TPCC_ICR_ICR16_SHIFT    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_ICR_ICR16_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR17_MASK     ((uint32_t)(0x00020000u))
#define CSL_TPCC_TPCC_ICR_ICR17_SHIFT    ((uint32_t)(0x00000011u))
#define CSL_TPCC_TPCC_ICR_ICR17_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR18_MASK     ((uint32_t)(0x00040000u))
#define CSL_TPCC_TPCC_ICR_ICR18_SHIFT    ((uint32_t)(0x00000012u))
#define CSL_TPCC_TPCC_ICR_ICR18_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR19_MASK     ((uint32_t)(0x00080000u))
#define CSL_TPCC_TPCC_ICR_ICR19_SHIFT    ((uint32_t)(0x00000013u))
#define CSL_TPCC_TPCC_ICR_ICR19_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR20_MASK     ((uint32_t)(0x00100000u))
#define CSL_TPCC_TPCC_ICR_ICR20_SHIFT    ((uint32_t)(0x00000014u))
#define CSL_TPCC_TPCC_ICR_ICR20_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR21_MASK     ((uint32_t)(0x00200000u))
#define CSL_TPCC_TPCC_ICR_ICR21_SHIFT    ((uint32_t)(0x00000015u))
#define CSL_TPCC_TPCC_ICR_ICR21_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR22_MASK     ((uint32_t)(0x00400000u))
#define CSL_TPCC_TPCC_ICR_ICR22_SHIFT    ((uint32_t)(0x00000016u))
#define CSL_TPCC_TPCC_ICR_ICR22_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR23_MASK     ((uint32_t)(0x00800000u))
#define CSL_TPCC_TPCC_ICR_ICR23_SHIFT    ((uint32_t)(0x00000017u))
#define CSL_TPCC_TPCC_ICR_ICR23_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR24_MASK     ((uint32_t)(0x01000000u))
#define CSL_TPCC_TPCC_ICR_ICR24_SHIFT    ((uint32_t)(0x00000018u))
#define CSL_TPCC_TPCC_ICR_ICR24_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR25_MASK     ((uint32_t)(0x02000000u))
#define CSL_TPCC_TPCC_ICR_ICR25_SHIFT    ((uint32_t)(0x00000019u))
#define CSL_TPCC_TPCC_ICR_ICR25_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR26_MASK     ((uint32_t)(0x04000000u))
#define CSL_TPCC_TPCC_ICR_ICR26_SHIFT    ((uint32_t)(0x0000001Au))
#define CSL_TPCC_TPCC_ICR_ICR26_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR27_MASK     ((uint32_t)(0x08000000u))
#define CSL_TPCC_TPCC_ICR_ICR27_SHIFT    ((uint32_t)(0x0000001Bu))
#define CSL_TPCC_TPCC_ICR_ICR27_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR28_MASK     ((uint32_t)(0x10000000u))
#define CSL_TPCC_TPCC_ICR_ICR28_SHIFT    ((uint32_t)(0x0000001Cu))
#define CSL_TPCC_TPCC_ICR_ICR28_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR29_MASK     ((uint32_t)(0x20000000u))
#define CSL_TPCC_TPCC_ICR_ICR29_SHIFT    ((uint32_t)(0x0000001Du))
#define CSL_TPCC_TPCC_ICR_ICR29_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR30_MASK     ((uint32_t)(0x40000000u))
#define CSL_TPCC_TPCC_ICR_ICR30_SHIFT    ((uint32_t)(0x0000001Eu))
#define CSL_TPCC_TPCC_ICR_ICR30_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_ICR31_MASK     ((uint32_t)(0x80000000u))
#define CSL_TPCC_TPCC_ICR_ICR31_SHIFT    ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_TPCC_ICR_ICR31_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICR_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_ICRH */

#define CSL_TPCC_TPCC_ICRH_ICR32_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR32_SHIFT   ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_ICRH_ICR32_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR33_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR33_SHIFT   ((uint32_t)(0x00000021u))
#define CSL_TPCC_TPCC_ICRH_ICR33_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR34_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR34_SHIFT   ((uint32_t)(0x00000022u))
#define CSL_TPCC_TPCC_ICRH_ICR34_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR35_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR35_SHIFT   ((uint32_t)(0x00000023u))
#define CSL_TPCC_TPCC_ICRH_ICR35_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR36_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR36_SHIFT   ((uint32_t)(0x00000024u))
#define CSL_TPCC_TPCC_ICRH_ICR36_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR37_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR37_SHIFT   ((uint32_t)(0x00000025u))
#define CSL_TPCC_TPCC_ICRH_ICR37_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR38_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR38_SHIFT   ((uint32_t)(0x00000026u))
#define CSL_TPCC_TPCC_ICRH_ICR38_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR39_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR39_SHIFT   ((uint32_t)(0x00000027u))
#define CSL_TPCC_TPCC_ICRH_ICR39_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR40_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR40_SHIFT   ((uint32_t)(0x00000028u))
#define CSL_TPCC_TPCC_ICRH_ICR40_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR41_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR41_SHIFT   ((uint32_t)(0x00000029u))
#define CSL_TPCC_TPCC_ICRH_ICR41_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR42_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR42_SHIFT   ((uint32_t)(0x0000002Au))
#define CSL_TPCC_TPCC_ICRH_ICR42_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR43_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR43_SHIFT   ((uint32_t)(0x0000002Bu))
#define CSL_TPCC_TPCC_ICRH_ICR43_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR44_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR44_SHIFT   ((uint32_t)(0x0000002Cu))
#define CSL_TPCC_TPCC_ICRH_ICR44_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR45_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR45_SHIFT   ((uint32_t)(0x0000002Du))
#define CSL_TPCC_TPCC_ICRH_ICR45_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR46_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR46_SHIFT   ((uint32_t)(0x0000002Eu))
#define CSL_TPCC_TPCC_ICRH_ICR46_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR47_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR47_SHIFT   ((uint32_t)(0x0000002Fu))
#define CSL_TPCC_TPCC_ICRH_ICR47_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR48_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR48_SHIFT   ((uint32_t)(0x00000030u))
#define CSL_TPCC_TPCC_ICRH_ICR48_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR49_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR49_SHIFT   ((uint32_t)(0x00000031u))
#define CSL_TPCC_TPCC_ICRH_ICR49_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR50_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR50_SHIFT   ((uint32_t)(0x00000032u))
#define CSL_TPCC_TPCC_ICRH_ICR50_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR51_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR51_SHIFT   ((uint32_t)(0x00000033u))
#define CSL_TPCC_TPCC_ICRH_ICR51_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR52_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR52_SHIFT   ((uint32_t)(0x00000034u))
#define CSL_TPCC_TPCC_ICRH_ICR52_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR53_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR53_SHIFT   ((uint32_t)(0x00000035u))
#define CSL_TPCC_TPCC_ICRH_ICR53_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR54_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR54_SHIFT   ((uint32_t)(0x00000036u))
#define CSL_TPCC_TPCC_ICRH_ICR54_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR55_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR55_SHIFT   ((uint32_t)(0x00000037u))
#define CSL_TPCC_TPCC_ICRH_ICR55_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR56_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR56_SHIFT   ((uint32_t)(0x00000038u))
#define CSL_TPCC_TPCC_ICRH_ICR56_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR57_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR57_SHIFT   ((uint32_t)(0x00000039u))
#define CSL_TPCC_TPCC_ICRH_ICR57_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR58_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR58_SHIFT   ((uint32_t)(0x0000003Au))
#define CSL_TPCC_TPCC_ICRH_ICR58_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR59_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR59_SHIFT   ((uint32_t)(0x0000003Bu))
#define CSL_TPCC_TPCC_ICRH_ICR59_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR60_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR60_SHIFT   ((uint32_t)(0x0000003Cu))
#define CSL_TPCC_TPCC_ICRH_ICR60_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR61_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR61_SHIFT   ((uint32_t)(0x0000003Du))
#define CSL_TPCC_TPCC_ICRH_ICR61_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR62_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR62_SHIFT   ((uint32_t)(0x0000003Eu))
#define CSL_TPCC_TPCC_ICRH_ICR62_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_ICR63_MASK    ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_ICRH_ICR63_SHIFT   ((uint32_t)(0x0000003Fu))
#define CSL_TPCC_TPCC_ICRH_ICR63_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_ICRH_RESETVAL      ((uint32_t)(0x0FFFFFFFu))

/* TPCC_IEVAL */

#define CSL_TPCC_TPCC_IEVAL_EVAL_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IEVAL_EVAL_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_IEVAL_EVAL_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IEVAL_SET_MASK     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_IEVAL_SET_SHIFT    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_IEVAL_SET_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_IEVAL_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QER */

#define CSL_TPCC_TPCC_QER_QER0_MASK      ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QER_QER0_SHIFT     ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QER_QER0_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER1_MASK      ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QER_QER1_SHIFT     ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QER_QER1_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER2_MASK      ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QER_QER2_SHIFT     ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QER_QER2_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER3_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QER_QER3_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QER_QER3_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER4_MASK      ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QER_QER4_SHIFT     ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QER_QER4_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER5_MASK      ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QER_QER5_SHIFT     ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QER_QER5_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER6_MASK      ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QER_QER6_SHIFT     ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QER_QER6_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_QER7_MASK      ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QER_QER7_SHIFT     ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QER_QER7_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QER_RESETVAL       ((uint32_t)(0x00000000u))

/* TPCC_QEER */

#define CSL_TPCC_TPCC_QEER_QEER0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEER_QEER0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QEER_QEER0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEER_QEER1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEER_QEER1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEER_QEER2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEER_QEER2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QEER_QEER3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QEER_QEER3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QEER_QEER4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEER_QEER4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QEER_QEER5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QEER_QEER5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QEER_QEER6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QEER_QEER6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_QEER7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QEER_QEER7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QEER_QEER7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEER_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_QEECR */

#define CSL_TPCC_TPCC_QEECR_QEECR0_MASK  ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEECR_QEECR0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QEECR_QEECR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR1_MASK  ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEECR_QEECR1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEECR_QEECR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR2_MASK  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEECR_QEECR2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEECR_QEECR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR3_MASK  ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QEECR_QEECR3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QEECR_QEECR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR4_MASK  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QEECR_QEECR4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEECR_QEECR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR5_MASK  ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QEECR_QEECR5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QEECR_QEECR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR6_MASK  ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QEECR_QEECR6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QEECR_QEECR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_QEECR7_MASK  ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QEECR_QEECR7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QEECR_QEECR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEECR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QEESR */

#define CSL_TPCC_TPCC_QEESR_QEESR0_MASK  ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEESR_QEESR0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QEESR_QEESR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR1_MASK  ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEESR_QEESR1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QEESR_QEESR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR2_MASK  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEESR_QEESR2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QEESR_QEESR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR3_MASK  ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QEESR_QEESR3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QEESR_QEESR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR4_MASK  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QEESR_QEESR4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QEESR_QEESR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR5_MASK  ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QEESR_QEESR5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QEESR_QEESR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR6_MASK  ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QEESR_QEESR6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QEESR_QEESR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_QEESR7_MASK  ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QEESR_QEESR7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QEESR_QEESR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QEESR_RESETVAL     ((uint32_t)(0x00000000u))

/* TPCC_QSER */

#define CSL_TPCC_TPCC_QSER_QSER0_MASK    ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QSER_QSER0_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSER_QSER0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER1_MASK    ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QSER_QSER1_SHIFT   ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QSER_QSER1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER2_MASK    ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QSER_QSER2_SHIFT   ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QSER_QSER2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER3_MASK    ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSER_QSER3_SHIFT   ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QSER_QSER3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER4_MASK    ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSER_QSER4_SHIFT   ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QSER_QSER4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER5_MASK    ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QSER_QSER5_SHIFT   ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QSER_QSER5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER6_MASK    ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QSER_QSER6_SHIFT   ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QSER_QSER6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_QSER7_MASK    ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QSER_QSER7_SHIFT   ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QSER_QSER7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSER_RESETVAL      ((uint32_t)(0x00000000u))

/* TPCC_QSECR */

#define CSL_TPCC_TPCC_QSECR_QSECR0_MASK  ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QSECR_QSECR0_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_TPCC_QSECR_QSECR0_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR1_MASK  ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QSECR_QSECR1_SHIFT ((uint32_t)(0x00000001u))
#define CSL_TPCC_TPCC_QSECR_QSECR1_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR2_MASK  ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QSECR_QSECR2_SHIFT ((uint32_t)(0x00000002u))
#define CSL_TPCC_TPCC_QSECR_QSECR2_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR3_MASK  ((uint32_t)(0x00000008u))
#define CSL_TPCC_TPCC_QSECR_QSECR3_SHIFT ((uint32_t)(0x00000003u))
#define CSL_TPCC_TPCC_QSECR_QSECR3_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR4_MASK  ((uint32_t)(0x00000010u))
#define CSL_TPCC_TPCC_QSECR_QSECR4_SHIFT ((uint32_t)(0x00000004u))
#define CSL_TPCC_TPCC_QSECR_QSECR4_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR5_MASK  ((uint32_t)(0x00000020u))
#define CSL_TPCC_TPCC_QSECR_QSECR5_SHIFT ((uint32_t)(0x00000005u))
#define CSL_TPCC_TPCC_QSECR_QSECR5_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR6_MASK  ((uint32_t)(0x00000040u))
#define CSL_TPCC_TPCC_QSECR_QSECR6_SHIFT ((uint32_t)(0x00000006u))
#define CSL_TPCC_TPCC_QSECR_QSECR6_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_QSECR7_MASK  ((uint32_t)(0x00000080u))
#define CSL_TPCC_TPCC_QSECR_QSECR7_SHIFT ((uint32_t)(0x00000007u))
#define CSL_TPCC_TPCC_QSECR_QSECR7_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_TPCC_QSECR_RESETVAL     ((uint32_t)(0x00000000u))

/* Adding Custom Bit Mask Definitions for Param
 * Set Configuration.
 *
 * NOT AUTO_GENERATED.
 */

/* OPT */
#define CSL_TPCC_PARAM_OPT_PRIV_MASK        ((uint32_t)(0x80000000u))
#define CSL_TPCC_PARAM_OPT_PRIV_SHIFT       ((uint32_t)(0x0000001Fu))
#define CSL_TPCC_PARAM_OPT_PRIV_RESETVAL    ((uint32_t)(0x00000000u))

/*----PRIV Tokens----*/
#define CSL_TPCC_PARAM_OPT_PRIV_USER        ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_PRIV_SUPERVISOR  ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_PRIVID_MASK      ((uint32_t)(0x0F000000u))
#define CSL_TPCC_PARAM_OPT_PRIVID_SHIFT     ((uint32_t)(0x00000018u))
#define CSL_TPCC_PARAM_OPT_PRIVID_RESETVAL  ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_OPT_ITCCHEN_MASK     ((uint32_t)(0x00800000u))
#define CSL_TPCC_PARAM_OPT_ITCCHEN_SHIFT    ((uint32_t)(0x00000017u))
#define CSL_TPCC_PARAM_OPT_ITCCHEN_RESETVAL ((uint32_t)(0x00000000u))

/*----ITCCHEN Tokens----*/
#define CSL_TPCC_PARAM_OPT_ITCCHEN_DISABLE  ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_ITCCHEN_ENABLE   ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_TCCHEN_MASK      ((uint32_t)(0x00400000u))
#define CSL_TPCC_PARAM_OPT_TCCHEN_SHIFT     ((uint32_t)(0x00000016u))
#define CSL_TPCC_PARAM_OPT_TCCHEN_RESETVAL  ((uint32_t)(0x00000000u))

/*----TCCHEN Tokens----*/
#define CSL_TPCC_PARAM_OPT_TCCHEN_DISABLE   ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_TCCHEN_ENABLE    ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_ITCINTEN_MASK    ((uint32_t)(0x00200000u))
#define CSL_TPCC_PARAM_OPT_ITCINTEN_SHIFT   ((uint32_t)(0x00000015u))
#define CSL_TPCC_PARAM_OPT_ITCINTEN_RESETVAL ((uint32_t)(0x00000000u))

/*----ITCINTEN Tokens----*/
#define CSL_TPCC_PARAM_OPT_ITCINTEN_DISABLE ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_ITCINTEN_ENABLE  ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_TCINTEN_MASK     ((uint32_t)(0x00100000u))
#define CSL_TPCC_PARAM_OPT_TCINTEN_SHIFT    ((uint32_t)(0x00000014u))
#define CSL_TPCC_PARAM_OPT_TCINTEN_RESETVAL ((uint32_t)(0x00000000u))

/*----TCINTEN Tokens----*/
#define CSL_TPCC_PARAM_OPT_TCINTEN_DISABLE  ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_TCINTEN_ENABLE   ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_TCC_MASK         ((uint32_t)(0x0003F000u))
#define CSL_TPCC_PARAM_OPT_TCC_SHIFT        ((uint32_t)(0x0000000Cu))
#define CSL_TPCC_PARAM_OPT_TCC_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_OPT_TCCMOD_MASK      ((uint32_t)(0x00000800u))
#define CSL_TPCC_PARAM_OPT_TCCMOD_SHIFT     ((uint32_t)(0x0000000Bu))
#define CSL_TPCC_PARAM_OPT_TCCMOD_RESETVAL  ((uint32_t)(0x00000000u))

/*----TCCMODE Tokens----*/
#define CSL_TPCC_PARAM_OPT_TCCMOD_NORMAL    ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_TCCMOD_EARLY     ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_FWID_MASK        ((uint32_t)(0x00000700u))
#define CSL_TPCC_PARAM_OPT_FWID_SHIFT       ((uint32_t)(0x00000008u))
#define CSL_TPCC_PARAM_OPT_FWID_RESETVAL    ((uint32_t)(0x00000000u))

/*----FWID Tokens----*/
#define CSL_TPCC_PARAM_OPT_FWID_8           ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_FWID_16          ((uint32_t)(0x00000001u))
#define CSL_TPCC_PARAM_OPT_FWID_32          ((uint32_t)(0x00000002u))
#define CSL_TPCC_PARAM_OPT_FWID_64          ((uint32_t)(0x00000003u))
#define CSL_TPCC_PARAM_OPT_FWID_128         ((uint32_t)(0x00000004u))
#define CSL_TPCC_PARAM_OPT_FWID_256         ((uint32_t)(0x00000005u))

#define CSL_TPCC_PARAM_OPT_STATIC_MASK      ((uint32_t)(0x00000008u))
#define CSL_TPCC_PARAM_OPT_STATIC_SHIFT     ((uint32_t)(0x00000003u))
#define CSL_TPCC_PARAM_OPT_STATIC_RESETVAL  ((uint32_t)(0x00000000u))

/*----STATIC Tokens----*/
#define CSL_TPCC_PARAM_OPT_STATIC_NORMAL    ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_STATIC_STATIC    ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_SYNCDIM_MASK     ((uint32_t)(0x00000004u))
#define CSL_TPCC_PARAM_OPT_SYNCDIM_SHIFT    ((uint32_t)(0x00000002u))
#define CSL_TPCC_PARAM_OPT_SYNCDIM_RESETVAL ((uint32_t)(0x00000000u))

/*----SYNCDIM Tokens----*/
#define CSL_TPCC_PARAM_OPT_SYNCDIM_ASYNC    ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_SYNCDIM_ABSYNC   ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_DAM_MASK         ((uint32_t)(0x00000002u))
#define CSL_TPCC_PARAM_OPT_DAM_SHIFT        ((uint32_t)(0x00000001u))
#define CSL_TPCC_PARAM_OPT_DAM_RESETVAL     ((uint32_t)(0x00000000u))

/*----DAM Tokens----*/
#define CSL_TPCC_PARAM_OPT_DAM_INCR         ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_DAM_FIFO         ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_SAM_MASK         ((uint32_t)(0x00000001u))
#define CSL_TPCC_PARAM_OPT_SAM_SHIFT        ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_SAM_RESETVAL     ((uint32_t)(0x00000000u))

/*----SAM Tokens----*/
#define CSL_TPCC_PARAM_OPT_SAM_INCR         ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_OPT_SAM_FIFO         ((uint32_t)(0x00000001u))

#define CSL_TPCC_PARAM_OPT_RESETVAL         ((uint32_t)(0x00000000u))

/* SRC */

#define CSL_TPCC_PARAM_SRC_SRC_MASK         ((uint32_t)(0xFFFFFFFFu))
#define CSL_TPCC_PARAM_SRC_SRC_SHIFT        ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_SRC_SRC_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_SRC_RESETVAL         ((uint32_t)(0x00000000u))

/* A_B_CNT */

#define CSL_TPCC_PARAM_A_B_CNT_BCNT_MASK    ((uint32_t)(0xFFFF0000u))
#define CSL_TPCC_PARAM_A_B_CNT_BCNT_SHIFT   ((uint32_t)(0x00000010u))
#define CSL_TPCC_PARAM_A_B_CNT_BCNT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_A_B_CNT_ACNT_MASK    ((uint32_t)(0x0000FFFFu))
#define CSL_TPCC_PARAM_A_B_CNT_ACNT_SHIFT   ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_A_B_CNT_ACNT_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_A_B_CNT_RESETVAL     ((uint32_t)(0x00000000u))

/* DST */

#define CSL_TPCC_PARAM_DST_DST_MASK         ((uint32_t)(0xFFFFFFFFu))
#define CSL_TPCC_PARAM_DST_DST_SHIFT        ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_DST_DST_RESETVAL     ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_DST_RESETVAL         ((uint32_t)(0x00000000u))

/* SRC_DST_BIDX */

#define CSL_TPCC_PARAM_SRC_DST_BIDX_DSTBIDX_MASK ((uint32_t)(0xFFFF0000u))
#define CSL_TPCC_PARAM_SRC_DST_BIDX_DSTBIDX_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_PARAM_SRC_DST_BIDX_DSTBIDX_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_SRC_DST_BIDX_SRCBIDX_MASK ((uint32_t)(0x0000FFFFu))
#define CSL_TPCC_PARAM_SRC_DST_BIDX_SRCBIDX_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_SRC_DST_BIDX_SRCBIDX_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_SRC_DST_BIDX_RESETVAL ((uint32_t)(0x00000000u))

/* LINK_BCNTRLD */

#define CSL_TPCC_PARAM_LINK_BCNTRLD_BCNTRLD_MASK ((uint32_t)(0xFFFF0000u))
#define CSL_TPCC_PARAM_LINK_BCNTRLD_BCNTRLD_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_PARAM_LINK_BCNTRLD_BCNTRLD_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_LINK_BCNTRLD_LINK_MASK ((uint32_t)(0x0000FFFFu))
#define CSL_TPCC_PARAM_LINK_BCNTRLD_LINK_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_LINK_BCNTRLD_LINK_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_LINK_BCNTRLD_RESETVAL ((uint32_t)(0x00000000u))

/* SRC_DST_CIDX */

#define CSL_TPCC_PARAM_SRC_DST_CIDX_DSTCIDX_MASK ((uint32_t)(0xFFFF0000u))
#define CSL_TPCC_PARAM_SRC_DST_CIDX_DSTCIDX_SHIFT ((uint32_t)(0x00000010u))
#define CSL_TPCC_PARAM_SRC_DST_CIDX_DSTCIDX_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_SRC_DST_CIDX_SRCCIDX_MASK ((uint32_t)(0x0000FFFFu))
#define CSL_TPCC_PARAM_SRC_DST_CIDX_SRCCIDX_SHIFT ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_SRC_DST_CIDX_SRCCIDX_RESETVAL ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_SRC_DST_CIDX_RESETVAL ((uint32_t)(0x00000000u))

/* CCNT */

#define CSL_TPCC_PARAM_CCNT_CCNT_MASK       ((uint32_t)(0x0000FFFFu))
#define CSL_TPCC_PARAM_CCNT_CCNT_SHIFT      ((uint32_t)(0x00000000u))
#define CSL_TPCC_PARAM_CCNT_CCNT_RESETVAL   ((uint32_t)(0x00000000u))

#define CSL_TPCC_PARAM_CCNT_RESETVAL        ((uint32_t)(0x00000000u))


#ifdef __cplusplus
}
#endif

#endif


