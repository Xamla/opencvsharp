#ifndef _CPP_ML_BOOST_H_
#define _CPP_ML_BOOST_H_

#include "include_opencv.h"
using namespace cv::ml;


CVAPI(int) ml_Boost_getBoostType(Boost *obj)
{
    EXC_SAFE((
        return obj->getBoostType();
    ))
}
CVAPI(void) ml_Boost_setBoostType(Boost *obj, int val)
{
    EXC_SAFE((
        obj->setBoostType(val);
    ))
}

CVAPI(int) ml_Boost_getWeakCount(Boost *obj)
{
    EXC_SAFE((
        return obj->getWeakCount();
    ))
}
CVAPI(void) ml_Boost_setWeakCount(Boost *obj, int val)
{
    EXC_SAFE((
        obj->setWeakCount(val);
    ))
}

CVAPI(double) ml_Boost_getWeightTrimRate(Boost *obj)
{
    EXC_SAFE((
        return obj->getWeightTrimRate();
    ))
}
CVAPI(void) ml_Boost_setWeightTrimRate(Boost *obj, double val)
{
    EXC_SAFE((
        obj->setWeightTrimRate(val);
    ))
}


CVAPI(cv::Ptr<Boost>*) ml_Boost_create()
{
    EXC_SAFE((
        cv::Ptr<Boost> ptr = Boost::create();
        return new cv::Ptr<Boost>(ptr);
    ))
}

CVAPI(void) ml_Ptr_Boost_delete(cv::Ptr<Boost> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(Boost*) ml_Ptr_Boost_get(cv::Ptr<Boost>* obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(cv::Ptr<Boost>*) ml_Boost_load(const char *filePath)
{
    EXC_SAFE((
        cv::Ptr<Boost> ptr = cv::Algorithm::load<Boost>(filePath);
        return new cv::Ptr<Boost>(ptr);
    ))
}

CVAPI(cv::Ptr<Boost>*) ml_Boost_loadFromString(const char *strModel)
{
    EXC_SAFE((
        cv::String objname = cv::ml::Boost::create()->getDefaultName();
        cv::Ptr<Boost> ptr = cv::Algorithm::loadFromString<Boost>(strModel, objname);
        return new cv::Ptr<Boost>(ptr);
    ))
}

#endif
