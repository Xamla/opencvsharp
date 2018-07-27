#include <string>

class ExceptionDesc
{
    public:
        ExceptionDesc() = default;
    
    std::string exceptionName;
    std::string exceptionMessage;
    bool ifException;

};


CVAPI(ExceptionDesc*) core_ExceptionDesc_new()
{
    return new ExceptionDesc();
}