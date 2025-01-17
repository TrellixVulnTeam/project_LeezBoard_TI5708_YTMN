/******************************************************************************
 * Copyright (c) 2013-2014, Texas Instruments Incorporated - http://www.ti.com/
 *   All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions are met:
 *       * Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 *       * Redistributions in binary form must reproduce the above copyright
 *         notice, this list of conditions and the following disclaimer in the
 *         documentation and/or other materials provided with the distribution.
 *       * Neither the name of Texas Instruments Incorporated nor the
 *         names of its contributors may be used to endorse or promote products
 *         derived from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 *   THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl.hpp>
#include <iostream>
#include <cstdlib>
#include "ocl_util.h"

using namespace cl;
using namespace std;

const int NumElements     = 1024*1024;
const int NumWorkGroups   = 256;
const int VectorElements  = 4;
const int NumVecElements  = NumElements / VectorElements;
const int WorkGroupSize   = NumVecElements / NumWorkGroups;

cl_short srcA  [NumElements];
cl_short srcB  [NumElements];
cl_short dst   [NumElements];
cl_short Golden[NumElements];

int main(int argc, char *argv[])
{
   cl_int err     = CL_SUCCESS;
   int    bufsize = sizeof(srcA);

   for (int i=0; i < NumElements; ++i) 
   { 
       srcA[i] = srcB[i] = i<<2; 
       Golden[i] = srcB[i] + srcA[i]; 
       dst[i]    = 0;
   }

   try 
   {
     Context context(CL_DEVICE_TYPE_ACCELERATOR);
     std::vector<Device> devices = context.getInfo<CL_CONTEXT_DEVICES>();
     devices.resize(1); // resize to 1 since we are only running on 1 DSP

     Buffer bufA   (context, CL_MEM_READ_ONLY,  bufsize);
     Buffer bufB   (context, CL_MEM_READ_ONLY,  bufsize);
     Buffer bufDst (context, CL_MEM_WRITE_ONLY, bufsize);

     char *bin;
     int bin_length = ocl_read_binary("vadd.out", bin);

     Program::Binaries   binary(1, std::make_pair(bin, bin_length));
     Program             program = Program(context, devices, binary);
     program.build(devices);

     delete [] bin;

     Kernel kernel(program, "VectorAdd");
     kernel.setArg(0, bufA);
     kernel.setArg(1, bufB);
     kernel.setArg(2, bufDst);

     Event ev1,ev2,ev3,ev4;

     CommandQueue Q(context, devices[0], CL_QUEUE_PROFILING_ENABLE);

     Q.enqueueWriteBuffer(bufA, CL_FALSE, 0, bufsize, srcA, NULL, &ev1);
     Q.enqueueWriteBuffer(bufB, CL_FALSE, 0, bufsize, srcB, NULL, &ev2);
     Q.enqueueNDRangeKernel(kernel, NullRange, NDRange(NumVecElements), 
                            NDRange(WorkGroupSize), NULL, &ev3);
     Q.enqueueReadBuffer (bufDst, CL_TRUE, 0, bufsize, dst, NULL, &ev4);

     ocl_event_times(ev1, "Write BufA ");
     ocl_event_times(ev2, "Write BufB ");
     ocl_event_times(ev3, "Kernel Exec");
     ocl_event_times(ev4, "Read BufDst");
   }
   catch (Error err) 
   { cerr << "ERROR: " << err.what() << "(" << err.err() << ")" << endl; }

   for (int i=0; i < NumElements; ++i)
       if (Golden[i] != dst[i]) 
           { cout << "Failed at Element " << i << endl; return -1; }

   cout << "Success!" << endl; 
}
