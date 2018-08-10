using System;
using System.Runtime.InteropServices;

#pragma warning disable 1591

namespace OpenCvSharp
{
    static partial class NativeMethodsExc
    {



        [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern bool imgproc_exc_adaptiveThreshold(IntPtr src, IntPtr dst,
            double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double c);
        


        //core functions to make it compile
        [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern IntPtr redirectError(CvErrorCallback errCallback, IntPtr userdata, ref IntPtr prevUserdata);


    }
}  