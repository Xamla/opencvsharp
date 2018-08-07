#ifndef _CPP_BGSEGM_H_
#define _CPP_BGSEGM_H_

#include "include_opencv.h"
using namespace cv::bgsegm;


#pragma region BackgroundSubtractorMOG

CVAPI(cv::Ptr<BackgroundSubtractorMOG>*) bgsegm_createBackgroundSubtractorMOG(
    int history, int nmixtures,    double backgroundRatio, double noiseSigma)
{
    EXC_SAFE((
        cv::Ptr<BackgroundSubtractorMOG> ptr = createBackgroundSubtractorMOG(history, nmixtures, backgroundRatio, noiseSigma);
        return new cv::Ptr<BackgroundSubtractorMOG>(ptr);
    ))
}
CVAPI(void) bgsegm_Ptr_BackgroundSubtractorMOG_delete(cv::Ptr<BackgroundSubtractorMOG> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(BackgroundSubtractorMOG*) bgsegm_Ptr_BackgroundSubtractorMOG_get(
    cv::Ptr<BackgroundSubtractorMOG> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorMOG_getHistory(cv::Ptr<BackgroundSubtractorMOG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getHistory();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorMOG_setHistory(cv::Ptr<BackgroundSubtractorMOG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setHistory(value);
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorMOG_getNMixtures(cv::Ptr<BackgroundSubtractorMOG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getNMixtures();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorMOG_setNMixtures(cv::Ptr<BackgroundSubtractorMOG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setNMixtures(value);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorMOG_getBackgroundRatio(cv::Ptr<BackgroundSubtractorMOG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getBackgroundRatio();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorMOG_setBackgroundRatio(cv::Ptr<BackgroundSubtractorMOG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setBackgroundRatio(value);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorMOG_getNoiseSigma(cv::Ptr<BackgroundSubtractorMOG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getNoiseSigma();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorMOG_setNoiseSigma(cv::Ptr<BackgroundSubtractorMOG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setNoiseSigma(value);
    ))
}

#pragma endregion

#pragma region BackgroundSubtractorGMG

CVAPI(cv::Ptr<BackgroundSubtractorGMG>*) bgsegm_createBackgroundSubtractorGMG(
    int initializationFrames, double decisionThreshold)
{
    EXC_SAFE((
        cv::Ptr<BackgroundSubtractorGMG> ptr = createBackgroundSubtractorGMG(initializationFrames, decisionThreshold);
        return new cv::Ptr<BackgroundSubtractorGMG>(ptr);
    ))
}
CVAPI(void) bgsegm_Ptr_BackgroundSubtractorGMG_delete(cv::Ptr<BackgroundSubtractorGMG> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(BackgroundSubtractorGMG*) bgsegm_Ptr_BackgroundSubtractorGMG_get(
    cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorGMG_getMaxFeatures(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getMaxFeatures();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setMaxFeatures(cv::Ptr<BackgroundSubtractorGMG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setMaxFeatures(value);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorGMG_getDefaultLearningRate(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getDefaultLearningRate();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setDefaultLearningRate(cv::Ptr<BackgroundSubtractorGMG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setDefaultLearningRate(value);
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorGMG_getNumFrames(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getNumFrames();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setNumFrames(cv::Ptr<BackgroundSubtractorGMG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setNumFrames(value);
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorGMG_getQuantizationLevels(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getQuantizationLevels();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setQuantizationLevels(cv::Ptr<BackgroundSubtractorGMG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setQuantizationLevels(value);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorGMG_getBackgroundPrior(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getBackgroundPrior();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setBackgroundPrior(cv::Ptr<BackgroundSubtractorGMG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setBackgroundPrior(value);
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorGMG_getSmoothingRadius(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getSmoothingRadius();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setSmoothingRadius(cv::Ptr<BackgroundSubtractorGMG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setSmoothingRadius(value);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorGMG_getDecisionThreshold(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getDecisionThreshold();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setDecisionThreshold(cv::Ptr<BackgroundSubtractorGMG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setDecisionThreshold(value);
    ))
}

CVAPI(int) bgsegm_BackgroundSubtractorGMG_getUpdateBackgroundModel(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getUpdateBackgroundModel() ? 1 : 0;
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setUpdateBackgroundModel(cv::Ptr<BackgroundSubtractorGMG> *ptr, int value)
{
    EXC_SAFE((
        (*ptr)->setUpdateBackgroundModel(value != 0);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorGMG_getMinVal(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getMinVal();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setMinVal(cv::Ptr<BackgroundSubtractorGMG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setMinVal(value);
    ))
}

CVAPI(double) bgsegm_BackgroundSubtractorGMG_getMaxVal(cv::Ptr<BackgroundSubtractorGMG> *ptr)
{
    EXC_SAFE((
        return (*ptr)->getMaxVal();
    ))
}
CVAPI(void) bgsegm_BackgroundSubtractorGMG_setMaxVal(cv::Ptr<BackgroundSubtractorGMG> *ptr, double value)
{
    EXC_SAFE((
        (*ptr)->setMaxVal(value);
    ))
}

#pragma endregion

#endif
