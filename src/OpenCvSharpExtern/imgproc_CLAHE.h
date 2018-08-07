#ifndef _CPP_IMGPROC_CLAHE_H_
#define _CPP_IMGPROC_CLAHE_H_

#include "include_opencv.h"


CVAPI(cv::Ptr<cv::CLAHE>*) imgproc_createCLAHE(double clipLimit, MyCvSize tileGridSize)
{
    EXC_SAFE((
        cv::Ptr<cv::CLAHE> ret = cv::createCLAHE(clipLimit, cpp(tileGridSize));
        return clone(ret);
    ))
}

CVAPI(void) imgproc_Ptr_CLAHE_delete(cv::Ptr<cv::CLAHE> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::CLAHE*) imgproc_Ptr_CLAHE_get(cv::Ptr<cv::CLAHE> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}


CVAPI(void) imgproc_CLAHE_apply(cv::CLAHE *obj, cv::_InputArray *src, cv::_OutputArray *dst)
{
    EXC_SAFE((
        obj->apply(*src, *dst);
    ))
}

CVAPI(void) imgproc_CLAHE_setClipLimit(cv::CLAHE *obj, double clipLimit)
{
    EXC_SAFE((
        obj->setClipLimit(clipLimit);
    ))
}

CVAPI(double) imgproc_CLAHE_getClipLimit(cv::CLAHE *obj)
{
    EXC_SAFE((
        return obj->getClipLimit();
    ))
}

CVAPI(void) imgproc_CLAHE_setTilesGridSize(cv::CLAHE *obj, MyCvSize tileGridSize)
{
    EXC_SAFE((
        obj->setTilesGridSize(cpp(tileGridSize));
    ))
}

CVAPI(MyCvSize) imgproc_CLAHE_getTilesGridSize(cv::CLAHE *obj)
{
    EXC_SAFE((
        return c(obj->getTilesGridSize());
    ))
}

CVAPI(void) imgproc_CLAHE_collectGarbage(cv::CLAHE *obj)
{
    EXC_SAFE((
        obj->collectGarbage();
    ))
}

#endif