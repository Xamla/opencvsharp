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


CVAPI_EXC(bool) imgproc_exc_compareHist1(double &ret, cv::_InputArray *h1, cv::_InputArray *h2, int method)
{
    try
    {
        int met = method;
        double r = imgproc_compareHist1(h1, h2, method);
        ret = r;
        return false;
    }
    catch(std::exception e)
    {
        return true;
    }
    
}