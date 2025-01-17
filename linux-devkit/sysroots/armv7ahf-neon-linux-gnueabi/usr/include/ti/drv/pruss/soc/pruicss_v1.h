/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================
 *  @file       pruicss_v1.h
 *
 *  @brief      PRUICSS driver implementation for a am57x PRUICSS controller
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_pruss_PRUICSSv1_include
#define ti_drivers_pruss_PRUICSSv1_include
#include <ti/drv/pruss/pruicss.h>

#ifdef __cplusplus
extern "C" {
#endif


/*!
 *  @brief      PRUICSS Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PRUICSS_V1_Object_s
{

    uint32_t            pruicss_version;
    int32_t                 instance;         /* PRUICSS write semaphore*/
    void*               pruBinBuff[2];         /* Buffer data pointer */
    uint32_t        buffLen[2];
    PRUICSS_IrqFunMap   pruEvntOutFnMapArray[PRUICSS_MAX_WAIT_EVENTS];

 }PRUICSS_V1_Object;

/*!
 *  @brief      PRUICSS hardware attributes
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct PRUICSS_HWAttrs {
    /*PRUICSS Peripheral's base address for each PRUICSS instance*/
    uint32_t      baseAddr;

    uint32_t    version;

    uint32_t    prussPru0CtrlRegBase;

    uint32_t    prussPru1CtrlRegBase;

    uint32_t    prussIntcRegBase;

    uint32_t    prussCfgRegBase;

    uint32_t    prussUartRegBase;

    uint32_t    prussIepRegBase;

    uint32_t    prussEcapRegBase;

    uint32_t    prussMiiRtCfgRegBase;

    uint32_t    prussMiiMdioRegBase;

    uint32_t    prussPru0DramBase;

    uint32_t    prussPru1DramBase;

    uint32_t    prussPru0IramBase;

    uint32_t    prussPru1IramBase;

    uint32_t    prussSharedDramBase;

    uint32_t    prussPru0DramSize;

    uint32_t    prussPru1DramSize;

    uint32_t    prussPru0IramSize;

    uint32_t    prussPru1IramSize;

    uint32_t    prussSharedDramSize;
} PRUICSS_HwAttrs;




typedef enum PRUSS_PruCores_s
{
	PRUICCSS_PRU0,
	PRUICCSS_PRU1,
	PRUICSS_MAX_PRU
}PRUSS_PruCores;


#define PRU_ICSS_DATARAM(n)        		(0x00000U + ((n) * 0x02000U))
#define PRU_ICSS_SHARED_RAM		        (0x10000U)
#define PRU_ICSS_IRAM(n) 		        (0x34000U + ((n) * 0x04000U))

#define PRU_ICSS_REVISION_MAJOR_MASK            (0x00000700)
#define PRU_ICSS_REVISION_MINOR_MASK            (0x0000003F)

/***********************************************************************
  Macros representing Interrupt-Channel-Host sizes
***********************************************************************/

/***********************************************************************
  Macros to support dynamic chip detecting feature
***********************************************************************/


#ifdef __cplusplus
}
#endif

#endif
