using System;
using System.Threading;

namespace OpenCvSharp
{
    /// <summary>
    /// This static class defines one instance which than can be used by multiple threads to gather exception information from opencv
    /// Implemented as a singleton
    /// </summary>
    public static class ExceptionHandler
    {
        // ThreadLocal
        private static ThreadLocal<bool> exceptionHappened = new ThreadLocal<bool>(false);


        /// <summary>
        /// Returns a boolean which indicates if an exception occured for the current thread
        /// </summary>
        public static bool checkForException{
            get{
                var value = exceptionHappened.Value;
                // reset exception value
                exceptionHappened.Value = false;
                return value;
            }
        }

        public static void registerExceptionCallback()
        {
            Console.WriteLine("Register callback");
            IntPtr zero = IntPtr.Zero;
            OpenCvSharp.NativeMethods.redirectError(ErrorHandlerCallback, zero, ref zero);
        }

        /// <summary>
        /// Callback function invoked by opencv when exception occurs 
        /// Stores the information locally for every thread
        /// </summary>
        public static  readonly OpenCvSharp.CvErrorCallback ErrorHandlerCallback =
        delegate(OpenCvSharp.ErrorCode status, string funcName, string errMsg, string fileName, int line, IntPtr userdata)
        {
            try
            {
                //cvSetErrStatus(CvStatus.StsOk);
                return 0;
            }
            finally
            {
                Console.WriteLine("Callback intercepted exception: {0}", errMsg);
                Console.WriteLine("Threadid: {0}", Thread.CurrentThread.ManagedThreadId);
                exceptionHappened.Value = true;
            }
        };
    }
}