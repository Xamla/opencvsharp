using System;
using System.Reflection;
using System.Runtime.InteropServices;

namespace ExceptionSafeGenerator
{
    static class InnerNativeClassGenerator 
    {
        private const string INNER_CLASS_NAME = "NativeMethodsExc";
        /// <summary>
        /// Generates the inner class (uses p/invoke)
        /// </summary>
        static public string generateClass(Type classType)
        {
            AbstractMethodGenerator gen =  new InnerNativeMethodGenerator();
            return ClassGenerator.generateClass(classType, INNER_CLASS_NAME, gen);
        }
    }
}


