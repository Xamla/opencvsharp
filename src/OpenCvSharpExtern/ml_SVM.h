#ifndef _CPP_ML_SVM_H_
#define _CPP_ML_SVM_H_

#include "include_opencv.h"
#include "ml.h"

using namespace cv::ml;


CVAPI(int) ml_SVM_getType(SVM *obj)
{
    EXC_SAFE((
        return obj->getType();
    ))
}
CVAPI(void) ml_SVM_setType(SVM *obj, int val)
{
    EXC_SAFE((
        obj->setType(val);
    ))
}

CVAPI(double) ml_SVM_getGamma(SVM *obj)
{
    EXC_SAFE((
        return obj->getGamma();
    ))
}
CVAPI(void) ml_SVM_setGamma(SVM *obj, double val)
{
    EXC_SAFE((
        obj->setGamma(val);
    ))
}

CVAPI(double) ml_SVM_getCoef0(SVM *obj)
{
    EXC_SAFE((
        return obj->getCoef0();
    ))
}
CVAPI(void) ml_SVM_setCoef0(SVM *obj, double val)
{
    EXC_SAFE((
        obj->setCoef0(val);
    ))
}

CVAPI(double) ml_SVM_getDegree(SVM *obj)
{
    EXC_SAFE((
        return obj->getDegree();
    ))
}
CVAPI(void) ml_SVM_setDegree(SVM *obj, double val)
{
    EXC_SAFE((
        obj->setDegree(val);
    ))
}

CVAPI(double) ml_SVM_getC(SVM *obj)
{
    EXC_SAFE((
        return obj->getC();
    ))
}
CVAPI(void) ml_SVM_setC(SVM *obj, double val)
{
    EXC_SAFE((
        obj->setC(val);
    ))
}

CVAPI(double) ml_SVM_getP(SVM *obj)
{
    EXC_SAFE((
        return obj->getP();
    ))
}
CVAPI(void) ml_SVM_setP(SVM *obj, double val)
{
    EXC_SAFE((
        obj->setP(val);
    ))
}

CVAPI(double) ml_SVM_getNu(SVM *obj)
{
    EXC_SAFE((
        return obj->getNu();
    ))
}
CVAPI(void) ml_SVM_setNu(SVM *obj, double val)
{
    EXC_SAFE((
        obj->setNu(val);
    ))
}

CVAPI(cv::Mat*) ml_SVM_getClassWeights(SVM *obj)
{
    EXC_SAFE((
        return new cv::Mat(obj->getClassWeights());
    ))
}
CVAPI(void) ml_SVM_setClassWeights(SVM *obj, cv::Mat *val)
{
    EXC_SAFE((
        obj->setClassWeights(*val);
    ))
}

CVAPI(MyCvTermCriteria) ml_SVM_getTermCriteria(SVM *obj)
{
    EXC_SAFE((
        return c(obj->getTermCriteria());
    ))
}
CVAPI(void) ml_SVM_setTermCriteria(SVM *obj, MyCvTermCriteria val)
{
    EXC_SAFE((
        obj->setTermCriteria(cpp(val));
    ))
}

CVAPI(int) ml_SVM_getKernelType(SVM *obj)
{
    EXC_SAFE((
        return obj->getKernelType();
    ))
}

CVAPI(void) ml_SVM_setKernel(SVM *obj, int kernelType)
{
    EXC_SAFE((
        obj->setKernel(kernelType);
    ))
}

CVAPI(cv::Mat*) ml_SVM_getSupportVectors(SVM *obj)
{
    EXC_SAFE((
        return new cv::Mat(obj->getSupportVectors());
    ))
}

CVAPI(double) ml_SVM_getDecisionFunction(
    cv::ml::SVM *obj, int i, cv::_OutputArray *alpha, cv::_OutputArray *svidx)
{
    EXC_SAFE((
        return obj->getDecisionFunction(i, entity(alpha), entity(svidx));
    ))
}


// static

CVAPI(ParamGridStruct) ml_SVM_getDefaultGrid(int param_id)
{ 
    EXC_SAFE((
        return c(cv::ml::SVM::getDefaultGrid(param_id));
    ))
}

CVAPI(cv::Ptr<SVM>*) ml_SVM_create()
{
    EXC_SAFE((
        cv::Ptr<SVM> ptr = SVM::create();
        return new cv::Ptr<SVM>(ptr);
    ))
}

CVAPI(void) ml_Ptr_SVM_delete(cv::Ptr<SVM> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::ml::SVM*) ml_Ptr_SVM_get(cv::Ptr<SVM>* obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(cv::Ptr<SVM>*) ml_SVM_load(const char *filePath)
{
    EXC_SAFE((
        cv::Ptr<SVM> ptr = SVM::load(filePath);
        return new cv::Ptr<SVM>(ptr);
    ))
}

CVAPI(cv::Ptr<SVM>*) ml_SVM_loadFromString(const char *strModel)
{
    EXC_SAFE((
        cv::String objname = cv::ml::SVM::create()->getDefaultName();
        cv::Ptr<SVM> ptr = cv::Algorithm::loadFromString<SVM>(strModel, objname);
        return new cv::Ptr<SVM>(ptr);
    ))
}

#endif
