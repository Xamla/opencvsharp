#ifndef _CPP_STRINGWRAPPER_H_
#define _CPP_STRINGWRAPPER_H_

#include "include_opencv.h"

CVAPI(std::string*) string_new1()
{
    EXC_SAFE((
    	return new std::string;
    ))
}
CVAPI(std::string*) string_new2(const char *str)
{
    EXC_SAFE((
    	return new std::string(str);
    ))
}

CVAPI(void) string_delete(std::string *s)
{
    EXC_SAFE((
    	delete s;
    ))
}

CVAPI(const char*) string_c_str(std::string *s)
{
    EXC_SAFE((
    	return s->c_str();
    ))
}

CVAPI(size_t) string_size(std::string *s)
{
    EXC_SAFE((
    	return s->size();
    ))
}

#endif
