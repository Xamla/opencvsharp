#ifndef _CPP_CORE_EXCEPTION_H_
#define _CPP_CORE_EXCEPTION_H_

#include "core_ExceptionDesc.h"

CVAPI(ExceptionDesc*) core_exceptionDesc_new()
{
    return new ExceptionDesc();
}

CVAPI(bool) core_exceptionHappened(ExceptionDesc* exc)
{
    if (exc && ! exc->ifException)
        return false;
    else
        return true;

}

#endif //_CPP_CORE_EXCEPTION_H_