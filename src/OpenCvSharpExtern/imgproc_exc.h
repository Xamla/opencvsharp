#include "imgproc.h"

CVAPI_EXC(bool) imgproc_exc_adaptiveThreshold(cv::_InputArray *src, cv::_OutputArray *dst,    double maxValue, int adaptiveMethod,
    int thresholdType, int blockSize, double C)
{
    try
    {
        imgproc_adaptiveThreshold(src, dst,  maxValue, adaptiveMethod,
        thresholdType, blockSize,  C);
        return false;
    }
    catch(std::exception e)
    {
        return true;
    }
}