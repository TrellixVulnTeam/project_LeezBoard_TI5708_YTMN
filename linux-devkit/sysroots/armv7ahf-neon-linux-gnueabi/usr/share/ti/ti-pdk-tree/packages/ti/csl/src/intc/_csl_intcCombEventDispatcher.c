/*  ============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2008, 2016                 
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

/*
 *  @file  _csl_intcCombEventDispatcher.c
 *
 *  @brief  File for functional layer of CSL API CSL_intcEvent0Dispatcher()
 *
 *  PATH  $(CSLPATH)\src\intc
 */
 
/* =============================================================================
 *  Revision History
 *  ===============
 *  12-Jun-2004 Ruchika Kharwar File Created
 *  19-Nov-2008 Updated for Doxygen
 * =============================================================================
 */
 
#include <ti/csl/src/intc/csl_intc.h>
#include <ti/csl/src/intc/_csl_intc.h>
#include <ti/csl/src/intc/csl_intcAux.h>

#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_intcEvent0Dispatcher, ".text:csl_section:intc")
#endif

interrupt void CSL_intcEvent0Dispatcher (void)
{
    volatile CSL_BitMask32  evtRcv;
    Uint32                  evtId;
    Uint32                  evtMask ;
    
    evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[0];
    
    while (evtRcv) {
        /* Clear the events */
        ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[0] = evtRcv ;
        evtMask = (((uint32_t)1U) << 4);
        evtId = 4U;
        evtRcv &= ~((uint32_t)0xFU);
        do {
            if (evtRcv & evtMask) {
                if (CSL_intcEventOffsetMap[evtId] != CSL_INTC_MAPPED_NONE)
                { 
                    CSL_intcEventHandlerRecord_p
                    [CSL_intcEventOffsetMap[evtId]].handler (
                        CSL_intcEventHandlerRecord_p 
                        [CSL_intcEventOffsetMap[evtId]].arg
                   );
                }
                evtRcv &= ~evtMask;
            }
                
            evtMask = evtMask << 1;         
            evtId++;
        } while (evtRcv);   
        
        /* Read the MEVTFLAG[0] register */
        evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[0];
    }
}
#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_intcEvent1Dispatcher, ".text:csl_section:intc")
#endif
interrupt void CSL_intcEvent1Dispatcher (void)
{
    volatile CSL_BitMask32  evtRcv;
    Uint32                  evtId;
    Uint32                  evtMask ;
    
    /* Read the MEVTFLAG[1] register */
    evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[1];
    while (evtRcv) {
        /* Clear the events */
        ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[1] = evtRcv ;
        evtId = 32U;
        evtMask = 1U;
        do {
            if (evtRcv & evtMask) {
                if (CSL_intcEventOffsetMap[evtId] != CSL_INTC_MAPPED_NONE) 
                {
                    CSL_intcEventHandlerRecord_p 
                        [CSL_intcEventOffsetMap[evtId]].handler (
                        CSL_intcEventHandlerRecord_p 
                            [CSL_intcEventOffsetMap[evtId]].arg
                    );
                }
                evtRcv &= ~evtMask;
            }    
            evtMask = evtMask << 1;         
            evtId++;
        } while (evtRcv);   
        
        /* Read the MEVTFLAG[1] register */
        evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[1];
    }
}
#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_intcEvent2Dispatcher, ".text:csl_section:intc")
#endif
interrupt void CSL_intcEvent2Dispatcher (void)
{
    volatile CSL_BitMask32  evtRcv;
    Uint32                  evtId;
    Uint32                  evtMask ;
    
    /* Read the MEVTFLAG[2] register */
    evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[2];
    while (evtRcv) {
        /* Clear the events */
        ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[2] = evtRcv ;
        evtId = 64U;
        evtMask = 1U;
        do {
            if (evtRcv & evtMask) {
                if (CSL_intcEventOffsetMap[evtId] != CSL_INTC_MAPPED_NONE) 
                {
                    CSL_intcEventHandlerRecord_p 
                        [CSL_intcEventOffsetMap[evtId]].handler (
                        CSL_intcEventHandlerRecord_p 
                            [CSL_intcEventOffsetMap[evtId]].arg
                    );
                }
                evtRcv &= ~evtMask;
            }    
            evtMask = evtMask << 1;         
            evtId++;
        } while (evtRcv);   
        
        /* Read the MEVTFLAG[2] register */
        evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[2];
    }
}
#if defined(_TMS320C6X)
CSL_SET_CSECT (CSL_intcEvent3Dispatcher, ".text:csl_section:intc")
#endif
interrupt void CSL_intcEvent3Dispatcher (void)
{
    volatile CSL_BitMask32  evtRcv;
    Uint32                  evtId;
    Uint32                  evtMask ;
    
    /* Read the MEVTFLAG[3] register */
    evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[3];
    while (evtRcv) {
        /* Clear the events */
        ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->EVTCLR[3] = evtRcv ;
        evtId = 96U;
        evtMask = 1U;
        do {
            if (evtRcv & evtMask) {
                if (CSL_intcEventOffsetMap[evtId] != CSL_INTC_MAPPED_NONE) 
                {
                    CSL_intcEventHandlerRecord_p 
                        [CSL_intcEventOffsetMap[evtId]].handler (
                        CSL_intcEventHandlerRecord_p 
                            [CSL_intcEventOffsetMap[evtId]].arg
                    );
                }
                evtRcv &= ~evtMask;
            }    
            evtMask = evtMask << 1;   
            evtId++;    
        } while (evtRcv);   
        
       /* Read the MEVTFLAG[3] register */
        evtRcv = ((CSL_IntcRegsOvly)CSL_INTC_BASE_ADDR)->MEVTFLAG[3];
    }
}
