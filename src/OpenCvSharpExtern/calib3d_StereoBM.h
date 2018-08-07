#ifndef _CPP_CALIB3D_STEREOBM_H_
#define _CPP_CALIB3D_STEREOBM_H_

#include "include_opencv.h"

CVAPI(cv::StereoBM*) calib3d_Ptr_StereoBM_get(
    cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(void) calib3d_Ptr_StereoBM_delete(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::Ptr<cv::StereoBM>*) calib3d_StereoBM_create(int numDisparities, int blockSize)
{
    EXC_SAFE((
        cv::Ptr<cv::StereoBM> obj = cv::StereoBM::create(numDisparities, blockSize);
        return new cv::Ptr<cv::StereoBM>(obj);
    ))
}

CVAPI(int) calib3d_StereoBM_getPreFilterType(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return (*obj)->getPreFilterType();
    ))
}
CVAPI(void) calib3d_StereoBM_setPreFilterType(cv::Ptr<cv::StereoBM> *obj, int value)
{
    EXC_SAFE((
        (*obj)->setPreFilterType(value);
    ))
}

CVAPI(int) calib3d_StereoBM_getPreFilterSize(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return (*obj)->getPreFilterSize();
    ))
}
CVAPI(void) calib3d_StereoBM_setPreFilterSize(cv::Ptr<cv::StereoBM> *obj, int value)
{
    EXC_SAFE((
        (*obj)->setPreFilterSize(value);
    ))
}

CVAPI(int) calib3d_StereoBM_getPreFilterCap(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return (*obj)->getPreFilterCap();
    ))
}
CVAPI(void) calib3d_StereoBM_setPreFilterCap(cv::Ptr<cv::StereoBM> *obj, int value)
{
    EXC_SAFE((
        (*obj)->setPreFilterCap(value);
    ))
}

CVAPI(int) calib3d_StereoBM_getTextureThreshold(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return (*obj)->getTextureThreshold();
    ))
}
CVAPI(void) calib3d_StereoBM_setTextureThreshold(cv::Ptr<cv::StereoBM> *obj, int value)
{
    EXC_SAFE((
        (*obj)->setTextureThreshold(value);
    ))
}

CVAPI(int) calib3d_StereoBM_getUniquenessRatio(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return (*obj)->getUniquenessRatio();
    ))
}
CVAPI(void) calib3d_StereoBM_setUniquenessRatio(cv::Ptr<cv::StereoBM> *obj, int value)
{
    EXC_SAFE((
        (*obj)->setUniquenessRatio(value);
    ))
}

CVAPI(int) calib3d_StereoBM_getSmallerBlockSize(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return (*obj)->getSmallerBlockSize();
    ))
}
CVAPI(void) calib3d_StereoBM_setSmallerBlockSize(cv::Ptr<cv::StereoBM> *obj, int value)
{
    EXC_SAFE((
        (*obj)->setSmallerBlockSize(value);
    ))
}

CVAPI(MyCvRect) calib3d_StereoBM_getROI1(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return c((*obj)->getROI1());
    ))
}
CVAPI(void) calib3d_StereoBM_setROI1(cv::Ptr<cv::StereoBM> *obj, MyCvRect value)
{
    EXC_SAFE((
        (*obj)->setROI1(cpp(value));
    ))
}

CVAPI(MyCvRect) calib3d_StereoBM_getROI2(cv::Ptr<cv::StereoBM> *obj)
{
    EXC_SAFE((
        return c((*obj)->getROI2());
    ))
}
CVAPI(void) calib3d_StereoBM_setROI2(cv::Ptr<cv::StereoBM> *obj, MyCvRect value)
{
    EXC_SAFE((
        (*obj)->setROI2(cpp(value));
    ))
}


#endif