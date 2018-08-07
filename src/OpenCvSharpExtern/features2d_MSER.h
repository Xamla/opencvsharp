#ifndef _CPP_FEATURES2D_MSER_H_
#define _CPP_FEATURES2D_MSER_H_

#include "include_opencv.h"


CVAPI(cv::Ptr<cv::MSER>*) features2d_MSER_create(int delta, int minArea, int maxArea,
    double maxVariation, double minDiversity, int maxEvolution,
    double areaThreshold, double minMargin, int edgeBlurSize)
{
    EXC_SAFE((
        cv::Ptr<cv::MSER> ptr = cv::MSER::create(delta, minArea, maxArea, maxVariation, minDiversity, maxEvolution,
            areaThreshold, minMargin, edgeBlurSize);
        return new cv::Ptr<cv::MSER>(ptr);
    ))
}
CVAPI(void) features2d_Ptr_MSER_delete(cv::Ptr<cv::MSER> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(void) features2d_MSER_detectRegions(
    cv::MSER *obj, cv::_InputArray *image,
    std::vector<std::vector<cv::Point> > *msers,
    std::vector<cv::Rect> *bboxes)
{
    EXC_SAFE((
        obj->detectRegions(*image, *msers, *bboxes);
    ))
}

CVAPI(cv::MSER*) features2d_Ptr_MSER_get(cv::Ptr<cv::MSER> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(void) features2d_MSER_setDelta(cv::MSER *obj, int delta)
{
    EXC_SAFE((
        obj->setDelta(delta);
    ))
}
CVAPI(int) features2d_MSER_getDelta(cv::MSER *obj)
{
    EXC_SAFE((
        return obj->getDelta();
    ))
}

CVAPI(void) features2d_MSER_setMinArea(cv::MSER *obj, int minArea)
{
    EXC_SAFE((
        obj->setMinArea(minArea);
    ))
}
CVAPI(int) features2d_MSER_getMinArea(cv::MSER *obj)
{
    EXC_SAFE((
        return obj->getMinArea();
    ))
}

CVAPI(void) features2d_MSER_setMaxArea(cv::MSER *obj, int maxArea)
{
    EXC_SAFE((
        obj->setMaxArea(maxArea);
    ))
}
CVAPI(int) features2d_MSER_getMaxArea(cv::MSER *obj)
{
    EXC_SAFE((
        return obj->getMaxArea();
    ))
}

CVAPI(void) features2d_MSER_setPass2Only(cv::MSER *obj, int f)
{
    EXC_SAFE((
        obj->setPass2Only(f != 0);
    ))
}
CVAPI(int) features2d_MSER_getPass2Only(cv::MSER *obj)
{
    EXC_SAFE((
        return obj->getPass2Only() ? 1 : 0;
    ))
}

#endif