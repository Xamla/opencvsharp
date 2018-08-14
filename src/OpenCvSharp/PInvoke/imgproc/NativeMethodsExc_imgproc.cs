using System;
using System.Runtime.InteropServices;

#pragma warning disable 1591

namespace OpenCvSharp
{
    static partial class NativeMethodsExc
    {



       /* [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern bool imgproc_exc_adaptiveThreshold(IntPtr src, IntPtr dst,
            double maxValue, int adaptiveMethod, int thresholdType, int blockSize, double c);
        */
        // generated function
        [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern System.Boolean imgproc_exc_adaptiveThreshold( System.IntPtr src ,  System.IntPtr dst ,  
            System.Double maxValue ,  System.Int32 adaptiveMethod ,  System.Int32 thresholdType ,  System.Int32 blockSize ,  System.Double c );


        [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern bool imgproc_exc_compareHist1(ref double  ret , IntPtr h1, IntPtr h2, int method);


        [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern bool imgproc_exc_getPerspectiveTransform2(IntPtr ret, IntPtr src, IntPtr dst);


        //core functions to make it compile
        [DllImport(DllExtern, CallingConvention = CallingConvention.Cdecl, ExactSpelling = true)]
        public static extern IntPtr redirectError(CvErrorCallback errCallback, IntPtr userdata, ref IntPtr prevUserdata);


    }
}  