#ifndef _CPP_ML_EM_H_
#define _CPP_ML_EM_H_

#include "include_opencv.h"
using namespace cv::ml;


CVAPI(int) ml_EM_getClustersNumber(EM *obj)
{
    EXC_SAFE((
        return obj->getClustersNumber();
    ))
}
CVAPI(void) ml_EM_setClustersNumber(EM *obj, int val)
{
    EXC_SAFE((
        obj->setClustersNumber(val);
    ))
}

CVAPI(int) ml_EM_getCovarianceMatrixType(EM *obj)
{
    EXC_SAFE((
        return obj->getCovarianceMatrixType();
    ))
}
CVAPI(void) ml_EM_setCovarianceMatrixType(EM *obj, int val)
{
    EXC_SAFE((
        obj->setCovarianceMatrixType(val);
    ))
}

CVAPI(MyCvTermCriteria) ml_EM_getTermCriteria(EM *obj)
{
    EXC_SAFE((
        return c(obj->getTermCriteria());
    ))
}
CVAPI(void) ml_EM_setTermCriteria(EM *obj, MyCvTermCriteria val)
{
    EXC_SAFE((
        obj->setTermCriteria(cpp(val));
    ))
}

CVAPI(cv::Mat*) ml_EM_getWeights(EM *obj)
{
    EXC_SAFE((
        cv::Mat m = obj->getWeights();
        return new cv::Mat(m);
    ))
}

CVAPI(cv::Mat*) ml_EM_getMeans(EM *obj)
{
    EXC_SAFE((
        cv::Mat m = obj->getMeans();
        return new cv::Mat(m);
    ))
}

CVAPI(void) ml_EM_getCovs(EM *obj, std::vector<cv::Mat*> *covs)
{
    EXC_SAFE((
        std::vector<cv::Mat> raw;
        obj->getCovs(raw);
        covs->resize(raw.size());
        for (size_t i = 0; i < raw.size(); i++)
        {
            covs->at(i) = new cv::Mat(raw[i]);
        }
    ))
}


CVAPI(CvVec2d) ml_EM_predict2(
    EM *obj, cv::_InputArray *sample, cv::_OutputArray *probs)
{
    EXC_SAFE((
        cv::Vec2d vec = obj->predict2(*sample, *probs);
        CvVec2d ret;
        ret.val[0] = vec[0];
        ret.val[1] = vec[1];
        return ret;
    ))
}

CVAPI(int) ml_EM_trainEM(
    EM *obj,
    cv::_InputArray *samples,
    cv::_OutputArray *logLikelihoods,
    cv::_OutputArray *labels,
    cv::_OutputArray *probs)
{
    EXC_SAFE((
        bool ret = obj->trainEM(*samples, entity(logLikelihoods), entity(labels), entity(probs));
        return ret ? 1 : 0;
    ))
}

CVAPI(int) ml_EM_trainE(
    EM *obj,
    cv::_InputArray *samples,
    cv::_InputArray *means0,
    cv::_InputArray *covs0,
    cv::_InputArray *weights0,
    cv::_OutputArray *logLikelihoods,
    cv::_OutputArray *labels,
    cv::_OutputArray *probs)
{
    EXC_SAFE((
        bool ret = obj->trainE(
            *samples, *means0, entity(covs0), entity(weights0),
            entity(logLikelihoods), entity(labels), entity(probs));
        return ret ? 1 : 0;
    ))
}

CVAPI(int) ml_EM_trainM(
    EM *obj,
    cv::_InputArray *samples,
    cv::_InputArray *probs0,
    cv::_OutputArray *logLikelihoods,
    cv::_OutputArray *labels,
    cv::_OutputArray *probs)
{
    EXC_SAFE((
        bool ret = obj->trainM(
            *samples, *probs0, entity(logLikelihoods), entity(labels), entity(probs));
        return ret ? 1 : 0;
    ))
}


CVAPI(cv::Ptr<EM>*) ml_EM_create()
{
    EXC_SAFE((
        cv::Ptr<EM> obj = EM::create();
        return new cv::Ptr<EM>(obj);
    ))
}

CVAPI(void) ml_Ptr_EM_delete(cv::Ptr<EM> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(EM*) ml_Ptr_EM_get(cv::Ptr<EM> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(cv::Ptr<EM>*) ml_EM_load(const char *filePath)
{
    EXC_SAFE((
        cv::Ptr<EM> ptr = cv::Algorithm::load<EM>(filePath);
        return new cv::Ptr<EM>(ptr);
    ))
}

CVAPI(cv::Ptr<EM>*) ml_EM_loadFromString(const char *strModel)
{
    EXC_SAFE((
        cv::String objname = cv::ml::EM::create()->getDefaultName();
        cv::Ptr<EM> ptr = cv::Algorithm::loadFromString<EM>(strModel, objname);
        return new cv::Ptr<EM>(ptr);
    ))
}

#endif
