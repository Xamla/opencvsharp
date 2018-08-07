#ifndef _CPP_ML_RTREES_H_
#define _CPP_ML_RTREES_H_

#include "include_opencv.h"
using namespace cv::ml;


CVAPI(int) ml_RTrees_getCalculateVarImportance(RTrees *obj)
{
    EXC_SAFE((
        return obj->getCalculateVarImportance() ? 1 : 0;
    ))
}
CVAPI(void) ml_RTrees_setCalculateVarImportance(RTrees *obj, int val)
{
    EXC_SAFE((
        obj->setCalculateVarImportance(val != 0);
    ))
}

CVAPI(int) ml_RTrees_getActiveVarCount(RTrees *obj)
{
    EXC_SAFE((
        return obj->getActiveVarCount();
    ))
}
CVAPI(void) ml_RTrees_setActiveVarCount(RTrees *obj, int val)
{
    EXC_SAFE((
        obj->setActiveVarCount(val);
    ))
}

CVAPI(MyCvTermCriteria) ml_RTrees_getTermCriteria(RTrees *obj)
{
    EXC_SAFE((
        return c(obj->getTermCriteria());
    ))
}
CVAPI(void) ml_RTrees_setTermCriteria(RTrees *obj, MyCvTermCriteria val)
{
    EXC_SAFE((
        obj->setTermCriteria(cpp(val));
    ))
}

CVAPI(cv::Mat*) ml_RTrees_getVarImportance(RTrees *obj)
{
    EXC_SAFE((
        return new cv::Mat(obj->getVarImportance());
    ))
}

CVAPI(cv::Ptr<RTrees>*) ml_RTrees_create()
{
    EXC_SAFE((
        cv::Ptr<RTrees> ptr = RTrees::create();
        return new cv::Ptr<RTrees>(ptr);
    ))
}

CVAPI(void) ml_Ptr_RTrees_delete(cv::Ptr<RTrees> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(RTrees*) ml_Ptr_RTrees_get(cv::Ptr<RTrees> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(cv::Ptr<RTrees>*) ml_RTrees_load(const char *filePath)
{
    EXC_SAFE((
        cv::Ptr<RTrees> ptr = cv::Algorithm::load<RTrees>(filePath);
        return new cv::Ptr<RTrees>(ptr);
    ))
}

CVAPI(cv::Ptr<RTrees>*) ml_RTrees_loadFromString(const char *strModel)
{
    EXC_SAFE((
        cv::String objname = cv::ml::RTrees::create()->getDefaultName();
        cv::Ptr<RTrees> ptr = cv::Algorithm::loadFromString<RTrees>(strModel, objname);
        return new cv::Ptr<RTrees>(ptr);
    ))
}

#endif
