/*
 * Copyright (c) 2011-2013, Texas Instruments Incorporated
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
/*
 *  ======== ping_tasks.c ========
 *
 *  Works with the rpmsg_client_sample and rpmsg_server_sample Linux drivers.
 */

#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

#include <ti/ipc/MultiProc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <ti/ipc/rpmsg/RPMessage.h>
#include <ti/ipc/rpmsg/NameMap.h>

#define APP_NUM_ITERATIONS 100000

Void copyTaskFxn(UArg arg0, UArg arg1)
{
    RPMessage_Handle    handle;
    Char                buffer[128];
    Char                desc[32];
    UInt32              myEndpoint = 0;
    UInt32              remoteEndpoint;
    UInt16              dstProc;
    UInt16              len;
    Int                 i;

    System_printf("copyTask sample%d:%d: Entered...:\n", arg1, arg0);

    dstProc = MultiProc_getId("HOST");

    /* Create the messageQ for receiving (and get our endpoint for sending). */
    handle = RPMessage_create(arg0, NULL, NULL, &myEndpoint);

    System_sprintf(desc, "sample%d", arg1);

#ifdef RPMSG_NS_2_0
    NameMap_register("rpmsg-client-sample", desc, arg0);
#else
    NameMap_register("rpmsg-client-sample", arg0);
#endif

    for (i = 0; i < APP_NUM_ITERATIONS; i++) {
       /* Await a character message: */
       RPMessage_recv(handle, (Ptr)buffer, &len, &remoteEndpoint,
                         RPMessage_FOREVER);

       buffer[len] = '\0';
       System_printf("copyTask %d: Received data: %s, len:%d\n", i + 1,
                      buffer, len);

       /* Send data back to remote endpoint: */
       RPMessage_send(dstProc, remoteEndpoint, myEndpoint, (Ptr)buffer, len);
    }

    /* Teardown our side: */
    RPMessage_delete(&handle);
}

void start_ping_tasks()
{
    Task_Params params;

    /* Respond to ping tests from Linux side rpmsg sample drivers: */
    Task_Params_init(&params);
    params.instance->name = "copy0";
    params.priority = 3;
    params.arg0 = 50;
    params.arg1 = 1;
    Task_create(copyTaskFxn, &params, NULL);

    Task_Params_init(&params);
    params.instance->name = "copy1";
    params.priority = 3;
    params.arg0 = 51;
    params.arg1 = 2;
    Task_create(copyTaskFxn, &params, NULL);
}
