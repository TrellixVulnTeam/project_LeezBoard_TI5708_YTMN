/*
 *  Copyright (C) 2013-2016 Texas Instruments Incorporated - http://www.ti.com/
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
/**
 *  \file     dcan.c
 *
 *  \brief    This file contains the device abstraction layer APIs for DCAN
 *            peripheral.
 *
 */
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdlib.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_dcan.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 *  \brief Parity function is disabled
 */
#define DCAN_PARITY_DISABLED            (5U)
/**
 *  \brief Parity function is enabled
 */
#define DCAN_PARITY_ENABLED             (0U)
/**
 *  \brief ECC Diagnostic mode is disabled
 */
#define DCAN_ECC_DIAG_DISABLED            (0xAU)
/**
 *  \brief ECC Diagnostic mode is enabled
 */
#define DCAN_ECC_DIAG_ENABLED             (0x5U)
/**
 *  \brief SECDED Single bit Error correction is enabled
 */
#define DCAN_ECC_MODE_ENABLED             (0x0U)
/**
 *  \brief SECDED Single bit Error correction is disabled
 */
#define DCAN_ECC_MODE_DISABLED            (0x5U)
/**
 *  \brief SECDED Single bit Error Event is enabled
 */
#define DCAN_ECC_SBE_EVT_ENABLED          (0x0U)
/**
 *  \brief SECDED Single bit Error Event is disabled
 */
#define DCAN_ECC_SBE_EVT_DISABLED            (0x5U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None*/

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t DCANReset(uint32_t baseAddr, uint32_t timeOut)
{
    int32_t retVal = STW_SOK;

    /* Reset the DCAN module. */
    DCANSetMode(baseAddr, DCAN_MODE_INIT);

    HW_WR_FIELD32((baseAddr + DCAN_CTL), DCAN_CTL_SWR, DCAN_CTL_SWR_EN_2_0X1);

    /* Wait until the reset is done */
    do
    {
        if (DCAN_CTL_SWR_MASK != (HW_RD_REG32(baseAddr + DCAN_CTL) &
                                  DCAN_CTL_SWR_MASK))
        {
            break;
        }
        timeOut--;
        if (timeOut == 0)
        {
            retVal = STW_EFAIL;
        }
    }
    while (timeOut);

    if (retVal == STW_SOK)
    {
        /* Configure TX I/O Control Register */
        HW_WR_FIELD32(
            (baseAddr + DCAN_TIOC),
            DCAN_TIOC_FUNC,
            DCAN_TIOC_FUNC_EN_2_0X1);

        /* Configure RX I/O Control Register */
        HW_WR_FIELD32(
            (baseAddr + DCAN_RIOC),
            DCAN_RIOC_FUNC,
            DCAN_RIOC_FUNC_EN_2_0X1);
    }
    return retVal;
}

void DCANSetMode(uint32_t baseAddr, uint32_t mode)
{
    /* Configure the DCAN mode of operation. */
    HW_WR_FIELD32((baseAddr + DCAN_CTL), DCAN_CTL_INIT, mode);
}

void DCANSetBitTime(uint32_t baseAddr, const dcanBitTimeParams_t *pBitTimePrms)
{
    uint32_t btrValue;

    /* Write the BRP value */
    btrValue = ((pBitTimePrms->baudRatePrescaler << DCAN_BTR_BRP_SHIFT) &
                DCAN_BTR_BRP_MASK);
    btrValue |= ((pBitTimePrms->syncJumpWidth << DCAN_BTR_SJW_SHIFT) &
                 DCAN_BTR_SJW_MASK);
    btrValue |= ((pBitTimePrms->timeSegment1 << DCAN_BTR_TSEG1_SHIFT) &
                 DCAN_BTR_TSEG1_MASK);
    btrValue |= ((pBitTimePrms->timeSegment2 << DCAN_BTR_TSEG2_SHIFT) &
                 DCAN_BTR_TSEG2_MASK);
    btrValue |= ((pBitTimePrms->baudRatePrescalerExt << DCAN_BTR_BRPE_SHIFT) &
                 DCAN_BTR_BRPE_MASK);

    /* Enable write access to configuration register */
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_CCE,
        DCAN_CTL_CCE_EN_2_0X1);

    /* Program the DCAN bit time value. */
    HW_WR_REG32((baseAddr + DCAN_BTR), btrValue);

    /* Disable write access to configuration register */
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_CCE,
        DCAN_CTL_CCE_EN_1_0X0);
}

void DCANConfig(uint32_t baseAddr, const dcanCfgParams_t *pDcanCfgPrms)
{
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_ABO,
        pDcanCfgPrms->autoBusOnEnable);
    if (TRUE == pDcanCfgPrms->autoBusOnEnable)
    {
        HW_WR_FIELD32(
            (baseAddr + DCAN_ABOTR),
            DCAN_ABOTR_ABO_TIME,
            pDcanCfgPrms->autoBusOnTimerVal);
    }

    DCANParityEnable(baseAddr, pDcanCfgPrms->parityEnable);

    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_DAR,
        pDcanCfgPrms->autoRetransmitDisable);

    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_TEST,
        pDcanCfgPrms->testModeEnable);
    HW_WR_FIELD32(
        (baseAddr + DCAN_TEST),
        DCAN_TEST_RDA,
        pDcanCfgPrms->ramAccessEnable);
    switch (pDcanCfgPrms->testMode)
    {
        case DCAN_TEST_MODE_NONE:
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_SILENT,
                DCAN_TEST_SILENT_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_LBACK,
                DCAN_TEST_LBACK_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_EXL,
                DCAN_TEST_EXL_EN_1_0X0);
            break;

        case DCAN_TEST_MODE_SILENT:
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_SILENT,
                DCAN_TEST_SILENT_EN_2_0X1);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_LBACK,
                DCAN_TEST_LBACK_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_EXL,
                DCAN_TEST_EXL_EN_1_0X0);
            break;

        case DCAN_TEST_MODE_LPBACK:
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_SILENT,
                DCAN_TEST_SILENT_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_LBACK,
                DCAN_TEST_LBACK_EN_2_0X1);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_EXL,
                DCAN_TEST_EXL_EN_1_0X0);
            break;

        case DCAN_TEST_MODE_LPBACK_SILENT:
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_SILENT,
                DCAN_TEST_SILENT_EN_2_0X1);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_LBACK,
                DCAN_TEST_LBACK_EN_2_0X1);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_EXL,
                DCAN_TEST_EXL_EN_1_0X0);
            break;

        case DCAN_TEST_MODE_EXT_LPBACK:
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_SILENT,
                DCAN_TEST_SILENT_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_LBACK,
                DCAN_TEST_LBACK_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_EXL,
                DCAN_TEST_EXL_EN_2_0X1);
            break;

        default:
            /* Default to normal operation */
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_SILENT,
                DCAN_TEST_SILENT_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_LBACK,
                DCAN_TEST_LBACK_EN_1_0X0);
            HW_WR_FIELD32(
                (baseAddr + DCAN_TEST),
                DCAN_TEST_EXL,
                DCAN_TEST_EXL_EN_1_0X0);
            break;
    }

    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_IE0,
        pDcanCfgPrms->intrLine0Enable);
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_IE1,
        pDcanCfgPrms->intrLine1Enable);
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_EIE,
        pDcanCfgPrms->errIntrEnable);
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_SIE,
        pDcanCfgPrms->stsChangeIntrEnable);

    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_DE1,
        pDcanCfgPrms->if1DmaEnable);
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_DE2,
        pDcanCfgPrms->if2DmaEnable);
    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_DE3,
        pDcanCfgPrms->if3DmaEnable);

#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    DCANEccModeEnable(baseAddr,
                      pDcanCfgPrms->eccModeEnable,
                      pDcanCfgPrms->sbeEventEnable);
    DCANEccDiagModeEnable(baseAddr, pDcanCfgPrms->eccDiagModeEnable);
#endif
}

int32_t DCANConfigMsgObj(uint32_t                     baseAddr,
                         uint32_t                     msgObj,
                         uint32_t                     ifRegNum,
                         const dcanMsgObjCfgParams_t *pMsgObjCfgPrms)
{
    int32_t  retVal = STW_SOK;
    uint32_t regVal = 0;
    uint32_t ifCmd  = 0;

    if (TRUE != DCANIsIfRegBusy(baseAddr, ifRegNum))
    {
        if (DCAN_DIR_TX == pMsgObjCfgPrms->direction)
        {
            /* Config umask, TXIE, RMTEN  */
            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                          DCAN_IFMCTL_TXIE,
                          pMsgObjCfgPrms->intEnable);

            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                          DCAN_IFMCTL_RMTEN,
                          pMsgObjCfgPrms->remoteEnable);
        }
        else
        {
            /* Config umask, RXIE  */
            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                          DCAN_IFMCTL_UMASK,
                          pMsgObjCfgPrms->uMaskUsed);

            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                          DCAN_IFMCTL_RXIE,
                          pMsgObjCfgPrms->intEnable);

            /* Config identifier mask , MDir , MXtd */
            HW_WR_FIELD32((baseAddr + DCAN_IFMSK(ifRegNum)),
                          DCAN_IFMSK_MXTD,
                          pMsgObjCfgPrms->xIdFlagMask);

            HW_WR_FIELD32((baseAddr + DCAN_IFMSK(ifRegNum)),
                          DCAN_IFMSK_MDIR,
                          pMsgObjCfgPrms->dirMask);

            HW_WR_FIELD32((baseAddr + DCAN_IFMSK(ifRegNum)),
                          DCAN_IFMSK_MSK,
                          pMsgObjCfgPrms->msgIdentifierMask);
        }

        /* Clear the TXRQST and NEWDAT fields of IFMCTL register during Message configuration
           in order to avoid false indication of new data reception and false initiate of new
           data transmission
        */
        HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                       DCAN_IFMCTL_TXRQST,
                       DCAN_IFMCTL_TXRQST_NOREQUESTED);

        HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                      DCAN_IFMCTL_NEWDAT,
                      DCAN_IFMCTL_NEWDAT_NONEWDATA);

        /* Config STD identifier, Dir(TX/RX), ID = 1, message valid */
        HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                      DCAN_IFARB_XTD,
                      pMsgObjCfgPrms->xIdFlag);

        HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                      DCAN_IFARB_MSGVAL,
                      pMsgObjCfgPrms->msgValid);

        HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                      DCAN_IFARB_MSGID,
                      pMsgObjCfgPrms->msgIdentifier);

        HW_WR_FIELD32((baseAddr + DCAN_IFARB(ifRegNum)),
                      DCAN_IFARB_DIR,
                      pMsgObjCfgPrms->direction);


        /* Config fifoEOBFlag */
        HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                      DCAN_IFMCTL_EOB,
                      pMsgObjCfgPrms->fifoEOBFlag);

        regVal = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));

        regVal &= ~(DCAN_IFCMD_DMAACTIVE_MASK |
                    DCAN_IFCMD_DATAA_MASK |
                    DCAN_IFCMD_DATAB_MASK |
                    DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                    DCAN_IFCMD_CLRINTPND_MASK |
                    DCAN_IFCMD_CONTROL_MASK |
                    DCAN_IFCMD_ARB_MASK |
                    DCAN_IFCMD_MASK_MASK |
                    DCAN_IFCMD_MESSAGENUMBER_MASK |
                    DCAN_IFCMD_WR_RD_MASK);

        /* Config IFCMD Access for TX / RX  */
        ifCmd = (DCAN_IFCMD_CLRINTPND_MASK |
                 DCAN_IFCMD_CONTROL_MASK |
                 DCAN_IFCMD_ARB_MASK |
                 DCAN_IFCMD_WR_RD_MASK);

        if (DCAN_DIR_RX == pMsgObjCfgPrms->direction)
        {
            ifCmd = ifCmd | DCAN_IFCMD_MASK_MASK;
        }

        regVal |= (ifCmd | (msgObj & DCAN_IFCMD_MESSAGENUMBER_MASK));

        /* Now transfer from IF to RAM */
        HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);
    }
    else
    {
        retVal = STW_EFAIL;
    }

    return retVal;
}

int32_t DCANTransmitData(uint32_t              baseAddr,
                         uint32_t              msgObj,
                         uint32_t              ifRegNum,
                         const dcanTxParams_t *pDcanTxPrms,
                         uint32_t              timeOut)
{
    int32_t  retVal    = STW_SOK;
    uint32_t txDataVal = 0U;
    uint32_t regVal    = 0U;
    uint32_t ifCmd     = 0U;

    if (TRUE != DCANIsIfRegBusy(baseAddr, ifRegNum))
    {
        regVal = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));

        regVal &= ~(DCAN_IFCMD_DMAACTIVE_MASK |
                    DCAN_IFCMD_DATAA_MASK |
                    DCAN_IFCMD_DATAB_MASK |
                    DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                    DCAN_IFCMD_CLRINTPND_MASK |
                    DCAN_IFCMD_CONTROL_MASK |
                    DCAN_IFCMD_ARB_MASK |
                    DCAN_IFCMD_MASK_MASK |
                    DCAN_IFCMD_MESSAGENUMBER_MASK |
                    DCAN_IFCMD_WR_RD_MASK);

        /* Config IFCMD Access to read IFMCTL read value  */
        ifCmd = DCAN_IFCMD_CONTROL_MASK;

        regVal |= (ifCmd | (msgObj & DCAN_IFCMD_MESSAGENUMBER_MASK));

        /* Now transfer from RAM to IFMCTL */
        HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);

        do
        {
            if (TRUE != DCANIsIfRegBusy(baseAddr, ifRegNum))
            {
                break;
            }
            timeOut--;
            if (timeOut == 0)
            {
                retVal = STW_EFAIL;
            }
        }
        while (timeOut);

        if (retVal == STW_SOK)
        {
            regVal = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));

            regVal &= ~(DCAN_IFCMD_DMAACTIVE_MASK |
                        DCAN_IFCMD_DATAA_MASK |
                        DCAN_IFCMD_DATAB_MASK |
                        DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                        DCAN_IFCMD_CLRINTPND_MASK |
                        DCAN_IFCMD_CONTROL_MASK |
                        DCAN_IFCMD_ARB_MASK |
                        DCAN_IFCMD_MASK_MASK |
                        DCAN_IFCMD_MESSAGENUMBER_MASK |
                        DCAN_IFCMD_WR_RD_MASK);

            /* Clear the TXRQST and NEWDAT fields of IFMCTL register in order to
               avoid false initiate of new data transmission */
            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                           DCAN_IFMCTL_TXRQST,
                           DCAN_IFMCTL_TXRQST_NOREQUESTED);

            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                          DCAN_IFMCTL_DATALENGTHCODE,
                          pDcanTxPrms->dataLength);

            if (pDcanTxPrms->dataLength > 0U)
            {
                txDataVal = (((uint32_t) pDcanTxPrms->msgData[0]) |
                             ((uint32_t) pDcanTxPrms->msgData[1] << 8U) |
                             ((uint32_t) pDcanTxPrms->msgData[2] << 16U) |
                             ((uint32_t) pDcanTxPrms->msgData[3] << 24U));

                /* Write the data values to message object.  */
                HW_WR_REG32(baseAddr + DCAN_IFDATA(ifRegNum), txDataVal);

                ifCmd = DCAN_IFCMD_DATAA_MASK;
            }

            if (pDcanTxPrms->dataLength > 4U)
            {
                txDataVal = (((uint32_t) pDcanTxPrms->msgData[4]) |
                             ((uint32_t) pDcanTxPrms->msgData[5] << 8U) |
                             ((uint32_t) pDcanTxPrms->msgData[6] << 16U) |
                             ((uint32_t) pDcanTxPrms->msgData[7] << 24U));

                HW_WR_REG32(baseAddr + DCAN_IFDATB(ifRegNum), txDataVal);

                ifCmd = (ifCmd | DCAN_IFCMD_DATAB_MASK);
            }

            ifCmd = (ifCmd | DCAN_IFCMD_CONTROL_MASK |
                     DCAN_IFCMD_WR_RD_MASK);

            regVal |= (ifCmd | (msgObj & DCAN_IFCMD_MESSAGENUMBER_MASK));

            /* Now transfer from IF to RAM */
            HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);

            ifCmd = (DCAN_IFCMD_CONTROL_MASK |
                     DCAN_IFCMD_WR_RD_MASK);

            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                  DCAN_IFMCTL_TXRQST,
                  DCAN_IFMCTL_TXRQST_REQUESTED);

            regVal = (ifCmd | (msgObj & DCAN_IFCMD_MESSAGENUMBER_MASK));

            /* Now transfer from RAM to CAN Bus */
            HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);

        }
    }
    else
    {
        retVal = STW_EFAIL;
    }

    return retVal;
}

int32_t DCANGetData(uint32_t        baseAddr,
                    uint32_t        msgObj,
                    uint32_t        ifRegNum,
                    dcanRxParams_t *pDcanRxPrms,
                    uint32_t        timeOut)
{
    int32_t  retVal    = STW_SOK;
    uint32_t msgData   = 0U;
    uint32_t msgCtlVal = 0U;
    uint32_t msgArbVal = 0U;
    uint32_t regVal    = 0U;
    uint32_t ifCmd     = 0U;

    if (TRUE != DCANIsIfRegBusy(baseAddr, ifRegNum))
    {
        regVal = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));

        regVal &= ~(DCAN_IFCMD_DMAACTIVE_MASK |
                    DCAN_IFCMD_DATAA_MASK |
                    DCAN_IFCMD_DATAB_MASK |
                    DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                    DCAN_IFCMD_CLRINTPND_MASK |
                    DCAN_IFCMD_CONTROL_MASK |
                    DCAN_IFCMD_ARB_MASK |
                    DCAN_IFCMD_MASK_MASK |
                    DCAN_IFCMD_MESSAGENUMBER_MASK |
                    DCAN_IFCMD_WR_RD_MASK);

        ifCmd = (DCAN_IFCMD_DATAA_MASK |
                 DCAN_IFCMD_DATAB_MASK |
                 DCAN_IFCMD_CONTROL_MASK |
                 DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                 DCAN_IFCMD_ARB_MASK);

        regVal |= (ifCmd | (msgObj & DCAN_IFCMD_MESSAGENUMBER_MASK));

        /* Now transfer from RAM to IF */
        HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);

        do
        {
            if (TRUE != DCANIsIfRegBusy(baseAddr, ifRegNum))
            {
                break;
            }
            timeOut--;
            if (timeOut == 0)
            {
                retVal = STW_EFAIL;
            }
        }
        while (timeOut);

        if (retVal == STW_SOK)
        {
            msgCtlVal = HW_RD_REG32(baseAddr + DCAN_IFMCTL(ifRegNum));

            pDcanRxPrms->dataLength =
                (msgCtlVal & DCAN_IFMCTL_DATALENGTHCODE_MASK);

            pDcanRxPrms->msgLostFlag =
                ((msgCtlVal & DCAN_IFMCTL_MSGLST_MASK) >>
                 DCAN_IFMCTL_MSGLST_SHIFT);
            if (pDcanRxPrms->dataLength > 0U)
            {
                msgData = HW_RD_REG32(baseAddr + DCAN_IFDATA(ifRegNum));
                pDcanRxPrms->msgData[0] = (uint8_t) (msgData & 0xFFU);
                pDcanRxPrms->msgData[1] = (uint8_t) ((msgData & 0xFF00U) >> 8U);
                pDcanRxPrms->msgData[2] =
                    (uint8_t) ((msgData & 0xFF0000U) >> 16U);
                pDcanRxPrms->msgData[3] =
                    (uint8_t) ((msgData & 0xFF000000U) >> 24U);
            }

            if (pDcanRxPrms->dataLength > 4U)
            {
                msgData = HW_RD_REG32(baseAddr + DCAN_IFDATB(ifRegNum));
                pDcanRxPrms->msgData[4] = (uint8_t) (msgData & 0xFFU);
                pDcanRxPrms->msgData[5] = (uint8_t) ((msgData & 0xFF00U) >> 8U);
                pDcanRxPrms->msgData[6] =
                    (uint8_t) ((msgData & 0xFF0000U) >> 16U);
                pDcanRxPrms->msgData[7] =
                    (uint8_t) ((msgData & 0xFF000000U) >> 24U);
            }

            msgArbVal = HW_RD_REG32(baseAddr + DCAN_IFARB(ifRegNum));

            pDcanRxPrms->rxMsgIdentifier =
                ((msgArbVal & DCAN_IFARB_MSGID_MASK)>>
                 DCAN_IFARB_MSGID_SHIFT);

            pDcanRxPrms->rxIdType =
                ((msgArbVal & DCAN_IFARB_XTD_MASK)>>
                 DCAN_IFARB_XTD_SHIFT);

            /* By Default, Received Frame is Data frame as remote frame is not
             * supported*/
            pDcanRxPrms->rxFrameType = DCAN_DATA_FRAME;

            /* Clear the TXRQST and NEWDAT fields of IFMCTL register in order to
               avoid false indication of new data reception */
            HW_WR_FIELD32((baseAddr + DCAN_IFMCTL(ifRegNum)),
                          DCAN_IFMCTL_NEWDAT,
                          DCAN_IFMCTL_NEWDAT_NONEWDATA);
        }
    }
    else
    {
        retVal = STW_EFAIL;
    }

    return retVal;
}

uint32_t DCANIsTxMsgPending(uint32_t baseAddr, uint32_t msgObj)
{
    uint32_t regNum, regOffSet;
    uint32_t regVal, isPending;

    regNum    = (msgObj - 1U) / 32U;
    regOffSet = (msgObj - 1U) % 32U;

    /* Return the status from DCAN_TXRQ register */
    regVal = HW_RD_REG32(baseAddr + DCAN_TXRQ(regNum));
    if ((regVal & ((uint32_t) 1 << regOffSet)) == ((uint32_t) 1 << regOffSet))
    {
        isPending = (uint32_t) TRUE;
    }
    else
    {
        isPending = (uint32_t) FALSE;
    }

    return (isPending);
}

uint32_t DCANHasRxMsgArrived(uint32_t baseAddr, uint32_t msgObj)
{
    uint32_t regNum, regOffSet;
    uint32_t regVal, isPending;

    regNum    = (msgObj - 1U) / 32U;
    regOffSet = (msgObj - 1U) % 32U;

    /* Return the status from DCAN_NWDAT register. */
    regVal = HW_RD_REG32(baseAddr + DCAN_NWDAT(regNum));
    if ((regVal & ((uint32_t) 1 << regOffSet)) == ((uint32_t) 1 << regOffSet))
    {
        isPending = (uint32_t) TRUE;
    }
    else
    {
        isPending = (uint32_t) FALSE;
    }

    return (isPending);
}

uint32_t DCANIsMsgValid(uint32_t baseAddr, uint32_t msgObj)
{
    uint32_t regNum    = 0U;
    uint32_t regOffSet = 0U;
    uint32_t regVal    = 0U;
    uint32_t isValid   = 0U;

    regNum    = (msgObj - 1U) / 32U;
    regOffSet = (msgObj - 1U) % 32U;

    /* Return the status from DCAN_MSGVAL register */
    regVal = HW_RD_REG32(baseAddr + DCAN_MSGVAL(regNum));
    if ((regVal & ((uint32_t) 1 << regOffSet)) == ((uint32_t) 1 << regOffSet))
    {
        isValid = (uint32_t) TRUE;
    }
    else
    {
        isValid = (uint32_t) FALSE;
    }

    return (isValid);
}

uint32_t DCANIsIfRegBusy(uint32_t baseAddr, uint32_t ifRegNum)
{
    uint32_t ifRegStatus, isBusy;

    ifRegStatus = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));
    if ((ifRegStatus & DCAN_IFCMD_BUSY_MASK) == DCAN_IFCMD_BUSY_MASK)
    {
        isBusy = (uint32_t) TRUE;
    }
    else
    {
        isBusy = (uint32_t) FALSE;
    }

    return (isBusy);
}

void DCANConfigIntrMux(uint32_t baseAddr, uint32_t intrLineNum, uint32_t msgObj)
{
    uint32_t regNum;
    uint32_t regOffSet;
    uint32_t regVal;

    if (msgObj == DCAN_MAX_MSG_OBJECTS)
    {
        regNum    = 0U;
        regOffSet = 0U;
    }
    else
    {
        regNum    = msgObj / 32U;
        regOffSet = msgObj % 32U;
    }

    regVal = HW_RD_REG32(baseAddr + DCAN_INTMUX(regNum));

    if (DCAN_INTR_LINE_NUM_0 == intrLineNum)
    {
        /* Clear the IntMux field of DCAN_INTMUX register. */
        regVal &= ~((uint32_t) 1 << regOffSet);
    }
    else
    {
        /* Set the IntMux field of DCAN_INTMUX register. */
        regVal |= ((uint32_t) 1 << regOffSet);
    }

    /* Set the DCAN_INTMUX field corresponding to msgNum. */
    HW_WR_REG32((baseAddr + DCAN_INTMUX(regNum)), regVal);
}

uint32_t DCANGetIntrStatus(uint32_t baseAddr, uint32_t intrLineNum)
{
    uint32_t retVal;

    retVal = HW_RD_REG32(baseAddr + DCAN_INT);
    if (DCAN_INTR_LINE_NUM_0 == intrLineNum)
    {
        /* Fetch the Interrupt line 0 status. */
        retVal = (retVal & DCAN_INT_INT0ID_MASK);
    }
    else
    {
        /* Fetch the Interrupt line 1 status. */
        retVal = ((retVal & DCAN_INT_INT1ID_MASK) >> DCAN_INT_INT1ID_SHIFT);
    }

    return (retVal);
}

uint32_t DCANIsMsgObjIntrPending(uint32_t baseAddr, uint32_t msgObj)
{
    uint32_t regNum;
    uint32_t regOffSet;
    uint32_t regVal, isPending;

    regNum    = (msgObj - 1U) / 32U;
    regOffSet = (msgObj - 1U) % 32U;

    /* Return the status from DCAN_INTPND register. */
    regVal = HW_RD_REG32(baseAddr + DCAN_INTPND(regNum));
    if ((regVal & ((uint32_t) 1 << regOffSet)) == ((uint32_t) 1 << regOffSet))
    {
        isPending = (uint32_t) TRUE;
    }
    else
    {
        isPending = (uint32_t) FALSE;
    }

    return (isPending);
}

void DCANIntrClearStatus(uint32_t baseAddr, uint32_t msgObj, uint32_t ifRegNum)
{
    uint32_t regVal = 0U;
    uint32_t ifCmd  = 0U;

    regVal = HW_RD_REG32(baseAddr + DCAN_IFCMD(ifRegNum));

    regVal &= ~(DCAN_IFCMD_DMAACTIVE_MASK |
                DCAN_IFCMD_DATAA_MASK |
                DCAN_IFCMD_DATAB_MASK |
                DCAN_IFCMD_TXRQST_NEWDAT_MASK |
                DCAN_IFCMD_CLRINTPND_MASK |
                DCAN_IFCMD_CONTROL_MASK |
                DCAN_IFCMD_ARB_MASK |
                DCAN_IFCMD_MASK_MASK |
                DCAN_IFCMD_MESSAGENUMBER_MASK |
                DCAN_IFCMD_WR_RD_MASK);

    ifCmd = DCAN_IFCMD_CLRINTPND_MASK;

    regVal |= (ifCmd | (msgObj & DCAN_IFCMD_MESSAGENUMBER_MASK));

    /* Now transfer from RAM to IF  */
    HW_WR_REG32(baseAddr + DCAN_IFCMD(ifRegNum), regVal);
}

uint32_t DCANGetErrStatus(uint32_t baseAddr)
{
    /* Return the DCAN error and status register value. */
    return (HW_RD_REG32(baseAddr + DCAN_ES));
}

uint32_t DCANGetErrCntrStatus(uint32_t baseAddr)
{
    /* Return the DCAN error counter value. */
    return (HW_RD_REG32(baseAddr + DCAN_ERRC));
}

uint32_t DCANGetParityErrStatus(uint32_t baseAddr)
{
    /* Return the DCAN parity error value. */
    return (HW_RD_REG32(baseAddr + DCAN_PERR));
}

uint32_t DCANGetMsgObjBitErrDetected(uint32_t baseAddr)
{
    uint32_t retVal = (uint32_t) STW_SOK;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Return the message object number where DCAN ECC Single Bit Error Code
     * is detected
     */
    retVal = ((HW_RD_REG32(baseAddr + DCAN_ECC_SBE_CODE)) &
              DCAN_ECC_SBE_CODE_MSG_NUM_MASK);
#else
    retVal = DCAN_INVALID_MSG_OBJECT;
#endif
    return retVal;
}

uint32_t DCANGetEccDiagErrStatus(uint32_t baseAddr)
{
    uint32_t retVal = (uint32_t) STW_SOK;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Returns the ECC disagnostic error status information. */
    retVal = (HW_RD_REG32(baseAddr + DCAN_ECC_DIAG_STATUS));
#else
    retVal = DCAN_INVALID_MSG_OBJECT;
#endif
    return retVal;
}

uint32_t DCANGetEccErrStatus(uint32_t baseAddr)
{
    uint32_t retVal = (uint32_t) STW_SOK;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    /* Returns the ECC error status information. */
    retVal = (HW_RD_REG32(baseAddr + DCAN_ECC_CSR));
#else
    retVal = DCAN_INVALID_MSG_OBJECT;
#endif
    return retVal;
}

void DCANParityEnable(uint32_t baseAddr, uint32_t enablePMD)
{
    if (TRUE == enablePMD)
    {
        /* Enable DCAN parity/ECC */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                      DCAN_CTL_PMD,
                      DCAN_PARITY_ENABLED);
    }
    else
    {
        /* Disable DCAN parity/ECC */
        HW_WR_FIELD32((baseAddr + DCAN_CTL),
                      DCAN_CTL_PMD,
                      DCAN_PARITY_DISABLED);
    }
}

void DCANTestModeEnable(uint32_t baseAddr,
                        uint32_t enableTestMode,
                        uint32_t testMode)
{
    uint32_t regVal;

    HW_WR_FIELD32(
        (baseAddr + DCAN_CTL),
        DCAN_CTL_TEST,
        enableTestMode);

    if (TRUE == enableTestMode)
    {
        regVal = HW_RD_REG32(baseAddr + DCAN_TEST);
        regVal = (regVal & (~testMode));
        /* Enable the DCAN test mode */
        regVal = regVal | testMode;
        HW_WR_REG32((baseAddr + DCAN_TEST), regVal);
    }
}

void DCANEccDiagModeEnable(uint32_t baseAddr, uint32_t enableEccDiagMode)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    if (TRUE == enableEccDiagMode)
    {
        /* Enable DCAN ECC Diagnostic Mode */
        HW_WR_FIELD32((baseAddr + DCAN_ECC_DIAG),
                      DCAN_ECC_DIAG_ECCDIAG,
                      DCAN_ECC_DIAG_ENABLED);
    }
    else
    {
        /* Disable DCAN ECC Diagnostic Mode */
        HW_WR_FIELD32((baseAddr + DCAN_ECC_DIAG),
                      DCAN_ECC_DIAG_ECCDIAG,
                      DCAN_ECC_DIAG_DISABLED);
    }
#endif
}

void DCANEccModeEnable(uint32_t baseAddr,
                       uint32_t enableEccMode,
                       uint32_t enableSbeEvent)
{
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    uint32_t regVal;

    regVal = HW_RD_REG32(baseAddr + DCAN_ECC_CSR);

    if (TRUE == enableEccMode)
    {
        /* Enable SECDED Single bit Error correction */
        HW_SET_FIELD32(
            regVal,
            DCAN_ECC_CSR_ECCMODE,
            DCAN_ECC_MODE_ENABLED);
    }
    else
    {
        /* Disable SECDED Single bit Error correction */
        HW_SET_FIELD32(
            regVal,
            DCAN_ECC_CSR_ECCMODE,
            DCAN_ECC_MODE_DISABLED);
    }

    if (TRUE == enableSbeEvent)
    {
        /* Enable SECDED Single bit Error Event */
        HW_SET_FIELD32(
            regVal,
            DCAN_ECC_CSR_SBE_EVT_EN,
            DCAN_ECC_SBE_EVT_ENABLED);
    }
    else
    {
        /* Disable SECDED Single bit Error Event */
        HW_SET_FIELD32(
            regVal,
            DCAN_ECC_CSR_SBE_EVT_EN,
            DCAN_ECC_SBE_EVT_DISABLED);
    }
    HW_WR_REG32((baseAddr + DCAN_ECC_CSR), regVal);
#endif
}

int32_t DCANClrEccErrStatus(uint32_t baseAddr, const dcanEccErrStatus_t *errClr)
{
    int32_t retVal = STW_SOK;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    if (NULL == errClr)
    {
        retVal = STW_EFAIL;
    }
    else
    {
        /* Writing 1 clears the bit, writing 0 has no effect */
        HW_WR_FIELD32(baseAddr + DCAN_ECC_CSR, DCAN_ECC_CSR_SE_FLAG,
                      errClr->singleBitErr);
        HW_WR_FIELD32(baseAddr + DCAN_ECC_CSR, DCAN_ECC_CSR_DE_FLAG,
                      errClr->doubleBitErr);
    }
#endif
    return retVal;
}

int32_t DCANClrEccDiagErrStatus(uint32_t                  baseAddr,
                                const dcanEccErrStatus_t *errClr)
{
    int32_t retVal = STW_SOK;
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    if (NULL == errClr)
    {
        retVal = STW_EFAIL;
    }
    else
    {
        /* Writing 1 clears the bit, writing 0 has no effect */
        HW_WR_FIELD32(baseAddr + DCAN_ECC_DIAG_STATUS,
                      DCAN_ECC_DIAG_STATUS_SE_FLAG,
                      errClr->singleBitErr);
        HW_WR_FIELD32(baseAddr + DCAN_ECC_DIAG_STATUS,
                      DCAN_ECC_DIAG_STATUS_DE_FLAG,
                      errClr->doubleBitErr);
    }
#endif
    return retVal;
}

void DCANClrParityIntrStatus(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + DCAN_ES, DCAN_ES_PER,
                  DCAN_ES_PER_EN_2_0X1);
}

/********************************* End of file ******************************/

