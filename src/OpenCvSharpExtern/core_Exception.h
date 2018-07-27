#ifndef _CPP_CORE_EXCEPTION_H_
#define _CPP_CORE_EXCEPTION_H_

#include "core_ExceptionDesc.h"

CVAPI(ExceptionDesc*) core_ExceptionDesc_new()
{
    return new ExceptionDesc();
}

#endif //_CPP_CORE_EXCEPTION_H_