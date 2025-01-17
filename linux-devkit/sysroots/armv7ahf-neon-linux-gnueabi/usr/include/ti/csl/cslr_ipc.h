/* =============================================================================
 *  Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2006, 2007, 2008, 
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
/** ============================================================================
 *   @file  cslr_ipc.h
 *
 *   @desc  This file contains the Register Desciptions for IPC module.
 *  ============================================================================
 */
#ifndef CSLR_IPC_H_
#define CSLR_IPC_H_

/* CSL Modification:
 *  The file has been modified from the AUTOGEN file for the following
 *  reasons:-
 *      a) Modified the header file includes to be RTSC compliant
 *      b) Updated IPCGR and IPCAR array size to reflect maximum number
 *         of CorePacs. This is to handle variants of SOCs with ARM + C66x
 *         cores. IPC registers are also part of Bootconfig structure
 *         Update done to avoid compatibility issues with different format
 *         of bootconfig macros across different SOCs 
 */
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifndef CSL_MODIFICATION
/* Minimum unit = 1 byte */
/* Maximum number of CorePacs supported by IPC
 * Includes C66x CorePacs and ARM CorePacs
 * Note: Refer SOC data sheet for CorePac mapping to each
 * index. Actual number of CorePacs may be lesser than the
 * maximum supported
 */ 
#define CSL_IPC_MAX_NUM_COREPAC     12
#endif
/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint32 NMIGR[8];
    volatile Uint8  RSVD0[32];
#ifndef CSL_MODIFICATION
    volatile Uint32 IPCGR[CSL_IPC_MAX_NUM_COREPAC];
    volatile Uint8  RSVD1[12];
#else
    volatile Uint32 IPCGR[8];
    volatile Uint8  RSVD1[28];
#endif
    volatile Uint32 IPCGRH;
#ifndef CSL_MODIFICATION
    volatile Uint32 IPCAR[CSL_IPC_MAX_NUM_COREPAC];
    volatile Uint8  RSVD2[12];
#else
    volatile Uint32 IPCAR[8];
    volatile Uint8  RSVD2[28];
#endif
    volatile Uint32 IPCARH;
} CSL_IPCRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* NMIGR */

#define CSL_IPC_NMIGR_NMIG_MASK      	(0x00000001u)
#define CSL_IPC_NMIGR_NMIG_SHIFT     	(0x00000000u)
#define CSL_IPC_NMIGR_NMIG_RESETVAL  	(0x00000000u)

/* IPCGR */

#define CSL_IPC_IPCGR_SRCS27_MASK    	(0x80000000u)
#define CSL_IPC_IPCGR_SRCS27_SHIFT   	(0x0000001Fu)
#define CSL_IPC_IPCGR_SRCS27_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS26_MASK    	(0x40000000u)
#define CSL_IPC_IPCGR_SRCS26_SHIFT   	(0x0000001Eu)
#define CSL_IPC_IPCGR_SRCS26_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS25_MASK    	(0x20000000u)
#define CSL_IPC_IPCGR_SRCS25_SHIFT   	(0x0000001Du)
#define CSL_IPC_IPCGR_SRCS25_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS24_MASK    	(0x10000000u)
#define CSL_IPC_IPCGR_SRCS24_SHIFT   	(0x0000001Cu)
#define CSL_IPC_IPCGR_SRCS24_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS23_MASK    	(0x08000000u)
#define CSL_IPC_IPCGR_SRCS23_SHIFT   	(0x0000001Bu)
#define CSL_IPC_IPCGR_SRCS23_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS22_MASK    	(0x04000000u)
#define CSL_IPC_IPCGR_SRCS22_SHIFT   	(0x0000001Au)
#define CSL_IPC_IPCGR_SRCS22_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS21_MASK    	(0x02000000u)
#define CSL_IPC_IPCGR_SRCS21_SHIFT   	(0x00000019u)
#define CSL_IPC_IPCGR_SRCS21_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS20_MASK    	(0x01000000u)
#define CSL_IPC_IPCGR_SRCS20_SHIFT   	(0x00000018u)
#define CSL_IPC_IPCGR_SRCS20_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS19_MASK    	(0x00800000u)
#define CSL_IPC_IPCGR_SRCS19_SHIFT   	(0x00000017u)
#define CSL_IPC_IPCGR_SRCS19_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS18_MASK    	(0x00400000u)
#define CSL_IPC_IPCGR_SRCS18_SHIFT   	(0x00000016u)
#define CSL_IPC_IPCGR_SRCS18_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS17_MASK    	(0x00200000u)
#define CSL_IPC_IPCGR_SRCS17_SHIFT   	(0x00000015u)
#define CSL_IPC_IPCGR_SRCS17_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS16_MASK    	(0x00100000u)
#define CSL_IPC_IPCGR_SRCS16_SHIFT   	(0x00000014u)
#define CSL_IPC_IPCGR_SRCS16_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS15_MASK    	(0x00080000u)
#define CSL_IPC_IPCGR_SRCS15_SHIFT   	(0x00000013u)
#define CSL_IPC_IPCGR_SRCS15_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS14_MASK    	(0x00040000u)
#define CSL_IPC_IPCGR_SRCS14_SHIFT   	(0x00000012u)
#define CSL_IPC_IPCGR_SRCS14_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS13_MASK    	(0x00020000u)
#define CSL_IPC_IPCGR_SRCS13_SHIFT   	(0x00000011u)
#define CSL_IPC_IPCGR_SRCS13_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS12_MASK    	(0x00010000u)
#define CSL_IPC_IPCGR_SRCS12_SHIFT   	(0x00000010u)
#define CSL_IPC_IPCGR_SRCS12_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS11_MASK    	(0x00008000u)
#define CSL_IPC_IPCGR_SRCS11_SHIFT   	(0x0000000Fu)
#define CSL_IPC_IPCGR_SRCS11_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS10_MASK    	(0x00004000u)
#define CSL_IPC_IPCGR_SRCS10_SHIFT   	(0x0000000Eu)
#define CSL_IPC_IPCGR_SRCS10_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS9_MASK     	(0x00002000u)
#define CSL_IPC_IPCGR_SRCS9_SHIFT    	(0x0000000Du)
#define CSL_IPC_IPCGR_SRCS9_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS8_MASK     	(0x00001000u)
#define CSL_IPC_IPCGR_SRCS8_SHIFT    	(0x0000000Cu)
#define CSL_IPC_IPCGR_SRCS8_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS7_MASK     	(0x00000800u)
#define CSL_IPC_IPCGR_SRCS7_SHIFT    	(0x0000000Bu)
#define CSL_IPC_IPCGR_SRCS7_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS6_MASK     	(0x00000400u)
#define CSL_IPC_IPCGR_SRCS6_SHIFT    	(0x0000000Au)
#define CSL_IPC_IPCGR_SRCS6_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS5_MASK     	(0x00000200u)
#define CSL_IPC_IPCGR_SRCS5_SHIFT    	(0x00000009u)
#define CSL_IPC_IPCGR_SRCS5_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS4_MASK     	(0x00000100u)
#define CSL_IPC_IPCGR_SRCS4_SHIFT    	(0x00000008u)
#define CSL_IPC_IPCGR_SRCS4_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS3_MASK     	(0x00000080u)
#define CSL_IPC_IPCGR_SRCS3_SHIFT    	(0x00000007u)
#define CSL_IPC_IPCGR_SRCS3_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS2_MASK     	(0x00000040u)
#define CSL_IPC_IPCGR_SRCS2_SHIFT    	(0x00000006u)
#define CSL_IPC_IPCGR_SRCS2_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS1_MASK     	(0x00000020u)
#define CSL_IPC_IPCGR_SRCS1_SHIFT    	(0x00000005u)
#define CSL_IPC_IPCGR_SRCS1_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGR_SRCS0_MASK     	(0x00000010u)
#define CSL_IPC_IPCGR_SRCS0_SHIFT    	(0x00000004u)
#define CSL_IPC_IPCGR_SRCS0_RESETVAL 	(0x00000000u)


#define CSL_IPC_IPCGR_IPCG_MASK      	(0x00000001u)
#define CSL_IPC_IPCGR_IPCG_SHIFT     	(0x00000000u)
#define CSL_IPC_IPCGR_IPCG_RESETVAL  	(0x00000000u)

#define CSL_IPC_IPCGR_RESETVAL       	(0x00000000u)


/* IPCGRH */

#define CSL_IPC_IPCGRH_SRCS27_MASK   	(0x80000000u)
#define CSL_IPC_IPCGRH_SRCS27_SHIFT  	(0x0000001Fu)
#define CSL_IPC_IPCGRH_SRCS27_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS26_MASK   	(0x40000000u)
#define CSL_IPC_IPCGRH_SRCS26_SHIFT  	(0x0000001Eu)
#define CSL_IPC_IPCGRH_SRCS26_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS25_MASK   	(0x20000000u)
#define CSL_IPC_IPCGRH_SRCS25_SHIFT  	(0x0000001Du)
#define CSL_IPC_IPCGRH_SRCS25_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS24_MASK   	(0x10000000u)
#define CSL_IPC_IPCGRH_SRCS24_SHIFT  	(0x0000001Cu)
#define CSL_IPC_IPCGRH_SRCS24_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS23_MASK   	(0x08000000u)
#define CSL_IPC_IPCGRH_SRCS23_SHIFT  	(0x0000001Bu)
#define CSL_IPC_IPCGRH_SRCS23_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS22_MASK   	(0x04000000u)
#define CSL_IPC_IPCGRH_SRCS22_SHIFT  	(0x0000001Au)
#define CSL_IPC_IPCGRH_SRCS22_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS21_MASK   	(0x02000000u)
#define CSL_IPC_IPCGRH_SRCS21_SHIFT  	(0x00000019u)
#define CSL_IPC_IPCGRH_SRCS21_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS20_MASK   	(0x01000000u)
#define CSL_IPC_IPCGRH_SRCS20_SHIFT  	(0x00000018u)
#define CSL_IPC_IPCGRH_SRCS20_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS19_MASK   	(0x00800000u)
#define CSL_IPC_IPCGRH_SRCS19_SHIFT  	(0x00000017u)
#define CSL_IPC_IPCGRH_SRCS19_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS18_MASK   	(0x00400000u)
#define CSL_IPC_IPCGRH_SRCS18_SHIFT  	(0x00000016u)
#define CSL_IPC_IPCGRH_SRCS18_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS17_MASK   	(0x00200000u)
#define CSL_IPC_IPCGRH_SRCS17_SHIFT  	(0x00000015u)
#define CSL_IPC_IPCGRH_SRCS17_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS16_MASK   	(0x00100000u)
#define CSL_IPC_IPCGRH_SRCS16_SHIFT  	(0x00000014u)
#define CSL_IPC_IPCGRH_SRCS16_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS15_MASK   	(0x00080000u)
#define CSL_IPC_IPCGRH_SRCS15_SHIFT  	(0x00000013u)
#define CSL_IPC_IPCGRH_SRCS15_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS14_MASK   	(0x00040000u)
#define CSL_IPC_IPCGRH_SRCS14_SHIFT  	(0x00000012u)
#define CSL_IPC_IPCGRH_SRCS14_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS13_MASK   	(0x00020000u)
#define CSL_IPC_IPCGRH_SRCS13_SHIFT  	(0x00000011u)
#define CSL_IPC_IPCGRH_SRCS13_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS12_MASK   	(0x00010000u)
#define CSL_IPC_IPCGRH_SRCS12_SHIFT  	(0x00000010u)
#define CSL_IPC_IPCGRH_SRCS12_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS11_MASK   	(0x00008000u)
#define CSL_IPC_IPCGRH_SRCS11_SHIFT  	(0x0000000Fu)
#define CSL_IPC_IPCGRH_SRCS11_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS10_MASK   	(0x00004000u)
#define CSL_IPC_IPCGRH_SRCS10_SHIFT  	(0x0000000Eu)
#define CSL_IPC_IPCGRH_SRCS10_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS9_MASK    	(0x00002000u)
#define CSL_IPC_IPCGRH_SRCS9_SHIFT   	(0x0000000Du)
#define CSL_IPC_IPCGRH_SRCS9_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS8_MASK    	(0x00001000u)
#define CSL_IPC_IPCGRH_SRCS8_SHIFT   	(0x0000000Cu)
#define CSL_IPC_IPCGRH_SRCS8_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS7_MASK    	(0x00000800u)
#define CSL_IPC_IPCGRH_SRCS7_SHIFT   	(0x0000000Bu)
#define CSL_IPC_IPCGRH_SRCS7_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS6_MASK    	(0x00000400u)
#define CSL_IPC_IPCGRH_SRCS6_SHIFT   	(0x0000000Au)
#define CSL_IPC_IPCGRH_SRCS6_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS5_MASK    	(0x00000200u)
#define CSL_IPC_IPCGRH_SRCS5_SHIFT   	(0x00000009u)
#define CSL_IPC_IPCGRH_SRCS5_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS4_MASK    	(0x00000100u)
#define CSL_IPC_IPCGRH_SRCS4_SHIFT   	(0x00000008u)
#define CSL_IPC_IPCGRH_SRCS4_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS3_MASK    	(0x00000080u)
#define CSL_IPC_IPCGRH_SRCS3_SHIFT   	(0x00000007u)
#define CSL_IPC_IPCGRH_SRCS3_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS2_MASK    	(0x00000040u)
#define CSL_IPC_IPCGRH_SRCS2_SHIFT   	(0x00000006u)
#define CSL_IPC_IPCGRH_SRCS2_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS1_MASK    	(0x00000020u)
#define CSL_IPC_IPCGRH_SRCS1_SHIFT   	(0x00000005u)
#define CSL_IPC_IPCGRH_SRCS1_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_SRCS0_MASK    	(0x00000010u)
#define CSL_IPC_IPCGRH_SRCS0_SHIFT   	(0x00000004u)
#define CSL_IPC_IPCGRH_SRCS0_RESETVAL 	(0x00000000u)


#define CSL_IPC_IPCGRH_IPCG_MASK     	(0x00000001u)
#define CSL_IPC_IPCGRH_IPCG_SHIFT    	(0x00000000u)
#define CSL_IPC_IPCGRH_IPCG_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCGRH_RESETVAL      	(0x00000000u)

/* IPCAR */

#define CSL_IPC_IPCAR_SRCC27_MASK    	(0x80000000u)
#define CSL_IPC_IPCAR_SRCC27_SHIFT   	(0x0000001Fu)
#define CSL_IPC_IPCAR_SRCC27_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC26_MASK    	(0x40000000u)
#define CSL_IPC_IPCAR_SRCC26_SHIFT   	(0x0000001Eu)
#define CSL_IPC_IPCAR_SRCC26_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC25_MASK    	(0x20000000u)
#define CSL_IPC_IPCAR_SRCC25_SHIFT   	(0x0000001Du)
#define CSL_IPC_IPCAR_SRCC25_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC24_MASK    	(0x10000000u)
#define CSL_IPC_IPCAR_SRCC24_SHIFT   	(0x0000001Cu)
#define CSL_IPC_IPCAR_SRCC24_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC23_MASK    	(0x08000000u)
#define CSL_IPC_IPCAR_SRCC23_SHIFT   	(0x0000001Bu)
#define CSL_IPC_IPCAR_SRCC23_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC22_MASK    	(0x04000000u)
#define CSL_IPC_IPCAR_SRCC22_SHIFT   	(0x0000001Au)
#define CSL_IPC_IPCAR_SRCC22_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC21_MASK    	(0x02000000u)
#define CSL_IPC_IPCAR_SRCC21_SHIFT   	(0x00000019u)
#define CSL_IPC_IPCAR_SRCC21_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC20_MASK    	(0x01000000u)
#define CSL_IPC_IPCAR_SRCC20_SHIFT   	(0x00000018u)
#define CSL_IPC_IPCAR_SRCC20_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC19_MASK    	(0x00800000u)
#define CSL_IPC_IPCAR_SRCC19_SHIFT   	(0x00000017u)
#define CSL_IPC_IPCAR_SRCC19_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC18_MASK    	(0x00400000u)
#define CSL_IPC_IPCAR_SRCC18_SHIFT   	(0x00000016u)
#define CSL_IPC_IPCAR_SRCC18_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC17_MASK    	(0x00200000u)
#define CSL_IPC_IPCAR_SRCC17_SHIFT   	(0x00000015u)
#define CSL_IPC_IPCAR_SRCC17_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC16_MASK    	(0x00100000u)
#define CSL_IPC_IPCAR_SRCC16_SHIFT   	(0x00000014u)
#define CSL_IPC_IPCAR_SRCC16_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC15_MASK    	(0x00080000u)
#define CSL_IPC_IPCAR_SRCC15_SHIFT   	(0x00000013u)
#define CSL_IPC_IPCAR_SRCC15_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC14_MASK    	(0x00040000u)
#define CSL_IPC_IPCAR_SRCC14_SHIFT   	(0x00000012u)
#define CSL_IPC_IPCAR_SRCC14_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC13_MASK    	(0x00020000u)
#define CSL_IPC_IPCAR_SRCC13_SHIFT   	(0x00000011u)
#define CSL_IPC_IPCAR_SRCC13_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC12_MASK    	(0x00010000u)
#define CSL_IPC_IPCAR_SRCC12_SHIFT   	(0x00000010u)
#define CSL_IPC_IPCAR_SRCC12_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC11_MASK    	(0x00008000u)
#define CSL_IPC_IPCAR_SRCC11_SHIFT   	(0x0000000Fu)
#define CSL_IPC_IPCAR_SRCC11_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC10_MASK    	(0x00004000u)
#define CSL_IPC_IPCAR_SRCC10_SHIFT   	(0x0000000Eu)
#define CSL_IPC_IPCAR_SRCC10_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC9_MASK     	(0x00002000u)
#define CSL_IPC_IPCAR_SRCC9_SHIFT    	(0x0000000Du)
#define CSL_IPC_IPCAR_SRCC9_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC8_MASK     	(0x00001000u)
#define CSL_IPC_IPCAR_SRCC8_SHIFT    	(0x0000000Cu)
#define CSL_IPC_IPCAR_SRCC8_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC7_MASK     	(0x00000800u)
#define CSL_IPC_IPCAR_SRCC7_SHIFT    	(0x0000000Bu)
#define CSL_IPC_IPCAR_SRCC7_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC6_MASK     	(0x00000400u)
#define CSL_IPC_IPCAR_SRCC6_SHIFT    	(0x0000000Au)
#define CSL_IPC_IPCAR_SRCC6_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC5_MASK     	(0x00000200u)
#define CSL_IPC_IPCAR_SRCC5_SHIFT    	(0x00000009u)
#define CSL_IPC_IPCAR_SRCC5_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC4_MASK     	(0x00000100u)
#define CSL_IPC_IPCAR_SRCC4_SHIFT    	(0x00000008u)
#define CSL_IPC_IPCAR_SRCC4_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC3_MASK     	(0x00000080u)
#define CSL_IPC_IPCAR_SRCC3_SHIFT    	(0x00000007u)
#define CSL_IPC_IPCAR_SRCC3_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC2_MASK     	(0x00000040u)
#define CSL_IPC_IPCAR_SRCC2_SHIFT    	(0x00000006u)
#define CSL_IPC_IPCAR_SRCC2_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC1_MASK     	(0x00000020u)
#define CSL_IPC_IPCAR_SRCC1_SHIFT    	(0x00000005u)
#define CSL_IPC_IPCAR_SRCC1_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_SRCC0_MASK     	(0x00000010u)
#define CSL_IPC_IPCAR_SRCC0_SHIFT    	(0x00000004u)
#define CSL_IPC_IPCAR_SRCC0_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCAR_RESETVAL       	(0x00000000u)


/* IPCARH */

#define CSL_IPC_IPCARH_SRCC27_MASK   	(0x80000000u)
#define CSL_IPC_IPCARH_SRCC27_SHIFT  	(0x0000001Fu)
#define CSL_IPC_IPCARH_SRCC27_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC26_MASK   	(0x40000000u)
#define CSL_IPC_IPCARH_SRCC26_SHIFT  	(0x0000001Eu)
#define CSL_IPC_IPCARH_SRCC26_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC25_MASK   	(0x20000000u)
#define CSL_IPC_IPCARH_SRCC25_SHIFT  	(0x0000001Du)
#define CSL_IPC_IPCARH_SRCC25_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC24_MASK   	(0x10000000u)
#define CSL_IPC_IPCARH_SRCC24_SHIFT  	(0x0000001Cu)
#define CSL_IPC_IPCARH_SRCC24_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC23_MASK   	(0x08000000u)
#define CSL_IPC_IPCARH_SRCC23_SHIFT  	(0x0000001Bu)
#define CSL_IPC_IPCARH_SRCC23_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC22_MASK   	(0x04000000u)
#define CSL_IPC_IPCARH_SRCC22_SHIFT  	(0x0000001Au)
#define CSL_IPC_IPCARH_SRCC22_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC21_MASK   	(0x02000000u)
#define CSL_IPC_IPCARH_SRCC21_SHIFT  	(0x00000019u)
#define CSL_IPC_IPCARH_SRCC21_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC20_MASK   	(0x01000000u)
#define CSL_IPC_IPCARH_SRCC20_SHIFT  	(0x00000018u)
#define CSL_IPC_IPCARH_SRCC20_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC19_MASK   	(0x00800000u)
#define CSL_IPC_IPCARH_SRCC19_SHIFT  	(0x00000017u)
#define CSL_IPC_IPCARH_SRCC19_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC18_MASK   	(0x00400000u)
#define CSL_IPC_IPCARH_SRCC18_SHIFT  	(0x00000016u)
#define CSL_IPC_IPCARH_SRCC18_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC17_MASK   	(0x00200000u)
#define CSL_IPC_IPCARH_SRCC17_SHIFT  	(0x00000015u)
#define CSL_IPC_IPCARH_SRCC17_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC16_MASK   	(0x00100000u)
#define CSL_IPC_IPCARH_SRCC16_SHIFT  	(0x00000014u)
#define CSL_IPC_IPCARH_SRCC16_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC15_MASK   	(0x00080000u)
#define CSL_IPC_IPCARH_SRCC15_SHIFT  	(0x00000013u)
#define CSL_IPC_IPCARH_SRCC15_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC14_MASK   	(0x00040000u)
#define CSL_IPC_IPCARH_SRCC14_SHIFT  	(0x00000012u)
#define CSL_IPC_IPCARH_SRCC14_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC13_MASK   	(0x00020000u)
#define CSL_IPC_IPCARH_SRCC13_SHIFT  	(0x00000011u)
#define CSL_IPC_IPCARH_SRCC13_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC12_MASK   	(0x00010000u)
#define CSL_IPC_IPCARH_SRCC12_SHIFT  	(0x00000010u)
#define CSL_IPC_IPCARH_SRCC12_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC11_MASK   	(0x00008000u)
#define CSL_IPC_IPCARH_SRCC11_SHIFT  	(0x0000000Fu)
#define CSL_IPC_IPCARH_SRCC11_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC10_MASK   	(0x00004000u)
#define CSL_IPC_IPCARH_SRCC10_SHIFT  	(0x0000000Eu)
#define CSL_IPC_IPCARH_SRCC10_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC9_MASK    	(0x00002000u)
#define CSL_IPC_IPCARH_SRCC9_SHIFT   	(0x0000000Du)
#define CSL_IPC_IPCARH_SRCC9_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC8_MASK    	(0x00001000u)
#define CSL_IPC_IPCARH_SRCC8_SHIFT   	(0x0000000Cu)
#define CSL_IPC_IPCARH_SRCC8_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC7_MASK    	(0x00000800u)
#define CSL_IPC_IPCARH_SRCC7_SHIFT   	(0x0000000Bu)
#define CSL_IPC_IPCARH_SRCC7_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC6_MASK    	(0x00000400u)
#define CSL_IPC_IPCARH_SRCC6_SHIFT   	(0x0000000Au)
#define CSL_IPC_IPCARH_SRCC6_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC5_MASK    	(0x00000200u)
#define CSL_IPC_IPCARH_SRCC5_SHIFT   	(0x00000009u)
#define CSL_IPC_IPCARH_SRCC5_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC4_MASK    	(0x00000100u)
#define CSL_IPC_IPCARH_SRCC4_SHIFT   	(0x00000008u)
#define CSL_IPC_IPCARH_SRCC4_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC3_MASK    	(0x00000080u)
#define CSL_IPC_IPCARH_SRCC3_SHIFT   	(0x00000007u)
#define CSL_IPC_IPCARH_SRCC3_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC2_MASK    	(0x00000040u)
#define CSL_IPC_IPCARH_SRCC2_SHIFT   	(0x00000006u)
#define CSL_IPC_IPCARH_SRCC2_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC1_MASK    	(0x00000020u)
#define CSL_IPC_IPCARH_SRCC1_SHIFT   	(0x00000005u)
#define CSL_IPC_IPCARH_SRCC1_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_SRCC0_MASK    	(0x00000010u)
#define CSL_IPC_IPCARH_SRCC0_SHIFT   	(0x00000004u)
#define CSL_IPC_IPCARH_SRCC0_RESETVAL 	(0x00000000u)

#define CSL_IPC_IPCARH_RESETVAL      	(0x00000000u)

#endif /*CSLR_IPC_H_*/
