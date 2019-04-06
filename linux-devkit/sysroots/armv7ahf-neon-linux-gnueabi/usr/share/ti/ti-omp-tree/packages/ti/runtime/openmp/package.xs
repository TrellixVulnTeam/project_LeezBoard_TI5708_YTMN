/*
 * Copyright (c) 2012-2015, Texas Instruments Incorporated
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
 * Copyright (c) 2012-2015, Texas Instruments Incorporated
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
 *  ======== getSects ========
 */
function getSects()
{
    return "ti/runtime/openmp/linkcmd.xdt";
}

/*
 *  ======== getLibs ========
 */
function getLibs( prog )
{
    var pkg = this;
    var Settings = pkg.Settings;
 
    var suffix = prog.build.target.findSuffix(pkg);
    var debugFlag;

    switch (Settings.debugFlag) 
    {
        case Settings.DEBUG:
            debugFlag = "_debug";
            break;
        case Settings.RELEASE:
            debugFlag = "_release";
            break;
        default:
            throw new Error("debugFlag not set");
    }

    var target;
    if( String(Program.cpu.deviceName).search("DRA7XX") != -1)
    {
        target = "_am57x";
    }    
    else if( String(Program.cpu.deviceName).search("K2G") != -1)
    {
        target = "_k2g";
    }    
    else if( String(Program.cpu.deviceName).search("6678") != -1)
    {
        target = "_c6678";
    }    
    else if( String(Program.cpu.deviceName).search("6670") != -1)
    {
        target = "_c6670";
    }
    else if( String(Program.cpu.deviceName).search("6657") != -1)
    {
        target = "_c6657";
    }
    else if( String(Program.cpu.deviceName).search("663") != -1 ||
             String(Program.cpu.deviceName).search("K2H") != -1 ||
             String(Program.cpu.deviceName).search("K2L") != -1 ||
             String(Program.cpu.deviceName).search("K2E") != -1)
    {
        target = "_c6636";
    }
    else
    {
        Program.$logError("Device:" + Program.cpu.deviceName + 
                          " not supported", this);
    }

    lib = "lib/" + pkg.$name.replace(/\./g, "_") + target + debugFlag +  
                "_" + suffix + ".a" + suffix;

    if (java.io.File(this.packageBase + lib).exists())
    {
        return lib;
    }
    else
    {
         /* could not find any library, throw exception */
         throw new Error("Library not found: " + lib);
    }
}

/* Set up flags in preparation for calls to getLibs() in OEM/OMP */
function close()
{
    var profile = Program.build.profile;

    var ompSettings = this.Settings;

    if (profile.search("debug")!=-1)
    {
        ompSettings.debugFlag=ompSettings.DEBUG;
    }
    else
    {
        ompSettings.debugFlag=ompSettings.RELEASE;
    }

    if (ompSettings.usingRtsc == true)
    {
        var OpenMP = xdc.module("ti.runtime.ompbios.OpenMP");
        OpenMP.qmssInit = ompSettings.runtimeInitializesQmss;
    }

    if(String(Program.cpu.deviceName).search("DRA7XX") == -1 && String(Program.cpu.deviceName).search("K2G") == -1)
    {
       xdc.loadPackage("ti.runtime.device");
    }

    print("Configuring OpenMP runtime for device: " + Program.cpu.deviceName);
    var cslSettings = xdc.useModule ('ti.csl.Settings');
    if( String(Program.cpu.deviceName).search("DRA7XX") != -1)
    {
        cslSettings.deviceType = "am572x";
    }    
    else if( String(Program.cpu.deviceName).search("6678") != -1)
    {
        cslSettings.deviceType = "c6678";
    }
    else if( String(Program.cpu.deviceName).search("6670") != -1)
    {
        cslSettings.deviceType = "c6670";
    }
    else if( String(Program.cpu.deviceName).search("6657") != -1)
    {
        cslSettings.deviceType = "c6657";
    }
    else if( String(Program.cpu.deviceName).search("6638") != -1 ||
             String(Program.cpu.deviceName).search("6636") != -1 ||
             String(Program.cpu.deviceName).search("K2H") != -1)
    {
        cslSettings.deviceType = "k2h";
    }
    else if( String(Program.cpu.deviceName).search("K2L") != -1)
    {
        cslSettings.deviceType = "k2l";
    }
    else if( String(Program.cpu.deviceName).search("K2E") != -1)
    {
        cslSettings.deviceType = "k2e";
    }
    else if( String(Program.cpu.deviceName).search("K2G") != -1)
    {
        cslSettings.deviceType = "k2g";
    }
    else
    {
        Program.$logError("Device:" + Program.cpu.deviceName + 
                          " not supported", this);
    }
}

