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
        double ret = imgproc_compareHist1(h1, h2, method);
        return false;
    }
    catch(std::exception e)
    {
        return true;
    }
    
}


CVAPI_EXC(bool) imgproc_exc_getPerspectiveTransform2(cv::Mat* ret, cv::_InputArray *src, cv::_InputArray *dst)
{
    try
    {
        cv::Mat* retVal = imgproc_getPerspectiveTransform2(src, dst);
        ret = retVal;
        return false;
    }
    catch(std::exception e)
    {
        return true;
    }

}