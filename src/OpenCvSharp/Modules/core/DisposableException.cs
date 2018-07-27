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
        public DisposableException()
        {
            ptr = NativeMethods.core_exceptionDesc_new();
        }
        /// <summary>
        /// Get Description of Exception
        /// </summary>
        public string getDescription()
        {
            //TODO implement this properly
            return "none";
                
        }
        /// <summary>
        /// Get Name/Type of Exception 
        /// </summary>
        public string getName()
        {
            //TODO implement this properly
            return "none";
        }
        /// <summary>
        /// Check if an exception happened
        /// </summary>
        public bool exceptionHappened()
        {
            return NativeMethods.core_exceptionHappened(ptr);
        }

    }
}