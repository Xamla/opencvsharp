#ifndef _CPP_FEATURES2D_AKAZE_H_
#define _CPP_FEATURES2D_AKAZE_H_

#include "include_opencv.h"


CVAPI(cv::Ptr<cv::AKAZE>*) features2d_AKAZE_create(
    int descriptor_type, int descriptor_size, int descriptor_channels,
    float threshold, int nOctaves, int nOctaveLayers, int diffusivity)
{
    EXC_SAFE((
        cv::Ptr<cv::AKAZE> ptr = cv::AKAZE::create(
            descriptor_type, descriptor_size, descriptor_channels,
            threshold, nOctaves, nOctaveLayers, diffusivity);
        return new cv::Ptr<cv::AKAZE>(ptr);
    ))
}
CVAPI(void) features2d_Ptr_AKAZE_delete(cv::Ptr<cv::AKAZE> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(cv::AKAZE*) features2d_Ptr_AKAZE_get(cv::Ptr<cv::AKAZE> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}


CVAPI(void) features2d_AKAZE_setDescriptorType(cv::AKAZE *obj, int val)
{
    EXC_SAFE((
        obj->setDescriptorType(val);
    ))
}
CVAPI(int) features2d_AKAZE_getDescriptorType(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getDescriptorType();
    ))
}

CVAPI(void) features2d_AKAZE_setDescriptorSize(cv::AKAZE *obj, int val)
{
    EXC_SAFE((
        obj->setDescriptorSize(val);
    ))
}
CVAPI(int) features2d_AKAZE_getDescriptorSize(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getDescriptorSize();
    ))
}

CVAPI(void) features2d_AKAZE_setDescriptorChannels(cv::AKAZE *obj, int val)
{
    EXC_SAFE((
        obj->setDescriptorChannels(val);
    ))
}
CVAPI(int) features2d_AKAZE_getDescriptorChannels(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getDescriptorChannels();
    ))
}

CVAPI(void) features2d_AKAZE_setThreshold(cv::AKAZE *obj, double val)
{
    EXC_SAFE((
        obj->setThreshold(val);
    ))
}
CVAPI(double) features2d_AKAZE_getThreshold(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getThreshold();
    ))
}

CVAPI(void) features2d_AKAZE_setNOctaves(cv::AKAZE *obj, int val)
{
    EXC_SAFE((
        obj->setNOctaves(val);
    ))
}
CVAPI(int) features2d_AKAZE_getNOctaves(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getNOctaves();
    ))
}

CVAPI(void) features2d_AKAZE_setNOctaveLayers(cv::AKAZE *obj, int val)
{
    EXC_SAFE((
        obj->setNOctaveLayers(val);
    ))
}
CVAPI(int) features2d_AKAZE_getNOctaveLayers(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getNOctaveLayers();
    ))
}

CVAPI(void) features2d_AKAZE_setDiffusivity(cv::AKAZE *obj, int val)
{
    EXC_SAFE((
        obj->setDiffusivity(val);
    ))
}
CVAPI(int) features2d_AKAZE_getDiffusivity(cv::AKAZE *obj)
{
    EXC_SAFE((
        return obj->getDiffusivity();
    ))
}

#endif
