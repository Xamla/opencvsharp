using System;
using OpenCvSharp.Util;


namespace OpenCvSharp
{
    /// <summary>
    /// Proxy datatype for passing Exceptions output parameters
    /// </summary>
    public class DisposableException : DisposableObject
    {
        /// <summary>
        /// Contains the exception data of catched opencv Exception
        /// </summary>
        public IntPtr ptr;
        
        /// <summary>
        /// Just initializes the IntPtr
        /// </summary>
        public DisposableException(){
            ptr = NativeMethods.core_ExceptionDesc_new();
        }
    }
}