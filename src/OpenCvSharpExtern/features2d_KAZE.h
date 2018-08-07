#ifndef _CPP_FEATURES2D_KAZE_H_
#define _CPP_FEATURES2D_KAZE_H_

#include "include_opencv.h"


CVAPI(cv::Ptr<cv::KAZE>*) features2d_KAZE_create(
    bool extended, bool upright, float threshold,
    int nOctaves, int nOctaveLayers, int diffusivity)
{
    EXC_SAFE((
        cv::Ptr<cv::KAZE> ptr = cv::KAZE::create(
            extended, upright, threshold,
            nOctaves, nOctaveLayers, diffusivity);
        return new cv::Ptr<cv::KAZE>(ptr);
    ))
}
CVAPI(void) features2d_Ptr_KAZE_delete(cv::Ptr<cv::KAZE> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(cv::KAZE*) features2d_Ptr_KAZE_get(cv::Ptr<cv::KAZE> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}


CVAPI(void) features2d_KAZE_setDiffusivity(cv::KAZE *obj, int val)
{
    EXC_SAFE((
        obj->setDiffusivity(val);
    ))
}
CVAPI(int) features2d_KAZE_getDiffusivity(cv::KAZE *obj)
{
    EXC_SAFE((
        return obj->getDiffusivity();
    ))
}

CVAPI(void) features2d_KAZE_setExtended(cv::KAZE *obj, bool val)
{
    EXC_SAFE((
        obj->setExtended(val);
    ))
}
CVAPI(bool) features2d_KAZE_getExtended(cv::KAZE *obj)
{
    EXC_SAFE((
        return obj->getExtended();
    ))
}

CVAPI(void) features2d_KAZE_setNOctaveLayers(cv::KAZE *obj, int val)
{
    EXC_SAFE((
        obj->setNOctaveLayers(val);
    ))
}
CVAPI(int) features2d_KAZE_getNOctaveLayers(cv::KAZE *obj)
{
    EXC_SAFE((
        return obj->getNOctaveLayers();
    ))
}

CVAPI(void) features2d_KAZE_setNOctaves(cv::KAZE *obj, int val)
{
    EXC_SAFE((
        obj->setNOctaves(val);
    ))
}
CVAPI(int) features2d_KAZE_getNOctaves(cv::KAZE *obj)
{
    EXC_SAFE((
        return obj->getNOctaves();
    ))
}

CVAPI(void) features2d_KAZE_setThreshold(cv::KAZE *obj, double val)
{
    EXC_SAFE((
        obj->setThreshold(val);
    ))
}
CVAPI(double) features2d_KAZE_getThreshold(cv::KAZE *obj)
{
    EXC_SAFE((
        return obj->getThreshold();
    ))
}

CVAPI(void) features2d_KAZE_setUpright(cv::KAZE *obj, bool val)
{
    EXC_SAFE((
        obj->setUpright(val);
    ))
}
CVAPI(bool) features2d_KAZE_getUpright(cv::KAZE *obj)
{
    EXC_SAFE((
        return obj->getUpright();
    ))
}

#endif
