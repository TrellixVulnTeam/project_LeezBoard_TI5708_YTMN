/*
 * aet_trace_in_data_range.h
 *
 * AET Library public API Definitions 
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
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
 *  =====================aet_trace_in_data_range.h=============================
 *  Revision Information
 *   Changed: $LastChangedDate: 2013-01-18 15:47:09 -0600 (Fri, 18 Jan 2013) $
 *   Revision: $LastChangedRevision: 10598 $
 *   Last Update By: $Author: KarthikRamanaSankar $ 
 */

#ifndef _AET_TRACE_ACTIVE_IN_DATA_RANGE
#define _AET_TRACE_ACTIVE_IN_DATA_RANGE


/*
 #include directives
 */
#include <aet_resource.h>
 
#ifdef __cplusplus
	extern "C" {
#endif

/*
 #define directives
 */

/*
 Structure Definitions and Typedefs
 */
typedef struct {
	_AET_resourceStruct configWord;
	const _AET_triggerBuilderInfo *trigBldr;
	uint16_t tbLookUpTableValue;
	uint8_t acmpNo[4];
}AET_traceInDataRangeResources;

/*
 Static data definitions
 */

/*
 Static function prototypes
 */

/*
 Module function definitions
 */

/* 
 Static (internal) function definitions
 */
AET_error _AET_traceInDataRange(AET_jobParams *);
AET_error _AET_traceInDataRangeProgram(
					AET_traceInDataRangeResources*,
					AET_jobParams*
					);

/*
 Revision History
 */


#ifdef __cplusplus
}
#endif

#endif 
