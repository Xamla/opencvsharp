#ifndef _CPP_XIMGPROC_STRUCTUREDEDGEDETECTION_H_
#define _CPP_XIMGPROC_STRUCTUREDEDGEDETECTION_H_

#include "include_opencv.h"

// RFFeatureGetter

CVAPI(cv::Ptr<cv::ximgproc::RFFeatureGetter>*) ximgproc_createRFFeatureGetter()
{
    EXC_SAFE((
        return clone(cv::ximgproc::createRFFeatureGetter());
    ))
}

CVAPI(void) ximgproc_Ptr_RFFeatureGetter_delete(cv::Ptr<cv::ximgproc::RFFeatureGetter> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::ximgproc::RFFeatureGetter*) ximgproc_Ptr_RFFeatureGetter_get(cv::Ptr<cv::ximgproc::RFFeatureGetter> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(void) ximgproc_RFFeatureGetter_getFeatures(
    cv::ximgproc::RFFeatureGetter *obj, cv::Mat *src, cv::Mat *features,
    const int gnrmRad, const int gsmthRad, const int shrink, const int outNum, const int gradNum)
{
    EXC_SAFE((
        obj->getFeatures(*src, *features, gnrmRad, gsmthRad, shrink, outNum, gradNum);
    ))
}


// StructuredEdgeDetection

CVAPI(cv::Ptr<cv::ximgproc::StructuredEdgeDetection>*) ximgproc_createStructuredEdgeDetection(
    const char *model, cv::Ptr<cv::ximgproc::RFFeatureGetter> *howToGetFeatures)
{
    EXC_SAFE((
        if (howToGetFeatures == nullptr)
            return clone(cv::ximgproc::createStructuredEdgeDetection(model));
        return clone(cv::ximgproc::createStructuredEdgeDetection(model, *howToGetFeatures));
    ))
}

CVAPI(void) ximgproc_Ptr_StructuredEdgeDetection_delete(cv::Ptr<cv::ximgproc::StructuredEdgeDetection> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::ximgproc::StructuredEdgeDetection*) ximgproc_Ptr_StructuredEdgeDetection_get(cv::Ptr<cv::ximgproc::StructuredEdgeDetection> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(void) ximgproc_StructuredEdgeDetection_detectEdges(cv::ximgproc::StructuredEdgeDetection *obj, cv::_InputArray *src, cv::_OutputArray *dst)
{
    EXC_SAFE((
        obj->detectEdges(*src, *dst);
    ))
}

CVAPI(void) ximgproc_StructuredEdgeDetection_computeOrientation(cv::ximgproc::StructuredEdgeDetection *obj, cv::_InputArray *src, cv::_OutputArray *dst)
{
    EXC_SAFE((
        obj->computeOrientation(*src, *dst);
    ))
}

CVAPI(void) ximgproc_StructuredEdgeDetection_edgesNms(cv::ximgproc::StructuredEdgeDetection *obj,
    cv::_InputArray *edge_image, cv::_InputArray *orientation_image, cv::_OutputArray *dst, 
    int r, int s, float m, int isParallel)
{
    EXC_SAFE((
        obj->edgesNms(*edge_image, *orientation_image, *dst, r, s, m, isParallel != 0);
    ))
}

#endif