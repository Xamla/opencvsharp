#ifndef _CPP_FEATURES2D_FAST_H_
#define _CPP_FEATURES2D_FAST_H_

#include "include_opencv.h"

CVAPI(void) features2d_FAST1(cv::_InputArray *image, std::vector<cv::KeyPoint> *keypoints, int threshold, int nonmaxSupression)
{
    EXC_SAFE((
        cv::FAST(*image, *keypoints, threshold, nonmaxSupression != 0);
    ))
}

CVAPI(void) features2d_FAST2(cv::_InputArray *image, std::vector<cv::KeyPoint> *keypoints, int threshold, int nonmaxSupression, int type)
{
    EXC_SAFE((
        cv::FAST(*image, *keypoints, threshold, nonmaxSupression != 0, type);
    ))
}


CVAPI(cv::Ptr<cv::FastFeatureDetector>*) features2d_FastFeatureDetector_create(
    int threshold, int nonmaxSuppression)
{
    EXC_SAFE((
        cv::Ptr<cv::FastFeatureDetector> ptr = cv::FastFeatureDetector::create(threshold, nonmaxSuppression != 0);
        return new cv::Ptr<cv::FastFeatureDetector>(ptr);
    ))
}
CVAPI(void) features2d_Ptr_FastFeatureDetector_delete(cv::Ptr<cv::FastFeatureDetector> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(cv::FastFeatureDetector*) features2d_Ptr_FastFeatureDetector_get(cv::Ptr<cv::FastFeatureDetector> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(void) features2d_FastFeatureDetector_setThreshold(cv::FastFeatureDetector *obj, int threshold)
{
    EXC_SAFE((
        obj->setThreshold(threshold);
    ))
}
CVAPI(int) features2d_FastFeatureDetector_getThreshold(cv::FastFeatureDetector *obj)
{
    EXC_SAFE((
        return obj->getThreshold();
    ))
}

CVAPI(void) features2d_FastFeatureDetector_setNonmaxSuppression(cv::FastFeatureDetector *obj, int f)
{
    EXC_SAFE((
        obj->setNonmaxSuppression(f != 0);
    ))
}
CVAPI(int) features2d_FastFeatureDetector_getNonmaxSuppression(cv::FastFeatureDetector *obj)
{
    EXC_SAFE((
        return obj->getNonmaxSuppression() ? 1 : 0;
    ))
}

CVAPI(void) features2d_FastFeatureDetector_setType(cv::FastFeatureDetector *obj, int type)
{
    EXC_SAFE((
        obj->setType(type);
    ))
}
CVAPI(int) features2d_FastFeatureDetector_getType(cv::FastFeatureDetector *obj)
{
    EXC_SAFE((
        return obj->getType();
    ))
}

#endif