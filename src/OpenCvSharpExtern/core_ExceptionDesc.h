#ifndef _CPP_CORE_EXCEPTION_CLASS_H_
#define _CPP_CORE_EXCEPTION_CLASS_H_

#include <string>

class ExceptionDesc
{
    public:
        ExceptionDesc() = default;
    
    std::string exceptionName;
    std::string exceptionMessage;
    bool ifException;

};

#endif //_CPP_CORE_EXCEPTION_CLASS_H_