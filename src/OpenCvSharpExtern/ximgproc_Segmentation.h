#ifndef _CPP_XIMGPROC_SEGMENTATION_H_
#define _CPP_XIMGPROC_SEGMENTATION_H_

#include "include_opencv.h"

using namespace cv::ximgproc::segmentation;

// GraphSegmentation

CVAPI(cv::Ptr<GraphSegmentation>*) ximgproc_segmentation_createGraphSegmentation(double sigma, float k, int min_size)
{
    EXC_SAFE((
        return clone(createGraphSegmentation(sigma, k, min_size));
    ))
}

CVAPI(void) ximgproc_segmentation_Ptr_GraphSegmentation_delete(cv::Ptr<GraphSegmentation> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(GraphSegmentation*) ximgproc_segmentation_Ptr_GraphSegmentation_get(cv::Ptr<GraphSegmentation> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(void) ximgproc_segmentation_GraphSegmentation_processImage(GraphSegmentation *obj, cv::_InputArray *src, cv::_OutputArray *dst)
{
    EXC_SAFE((
        obj->processImage(*src, *dst);
    ))
}

CVAPI(void) ximgproc_segmentation_GraphSegmentation_setSigma(GraphSegmentation *obj, double value)
{
    EXC_SAFE((
        obj->setSigma(value);
    ))
}
CVAPI(double) ximgproc_segmentation_GraphSegmentation_getSigma(GraphSegmentation *obj)
{
    EXC_SAFE((
        return obj->getSigma();
    ))
}

CVAPI(void) ximgproc_segmentation_GraphSegmentation_setK(GraphSegmentation *obj, float value)
{
    EXC_SAFE((
        obj->setK(value);
    ))
}
CVAPI(float) ximgproc_segmentation_GraphSegmentation_getK(GraphSegmentation *obj)
{
    EXC_SAFE((
        return obj->getK();
    ))
}

CVAPI(void) ximgproc_segmentation_GraphSegmentation_setMinSize(GraphSegmentation *obj, int value)
{
    EXC_SAFE((
        obj->setMinSize(value);
    ))
}
CVAPI(int) ximgproc_segmentation_GraphSegmentation_getMinSize(GraphSegmentation *obj)
{
    EXC_SAFE((
        return obj->getMinSize();
    ))
}


// SelectiveSearchSegmentationStrategy

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentationStrategy_setImage(SelectiveSearchSegmentationStrategy *obj, cv::_InputArray *img, cv::_InputArray *regions, cv::_InputArray *sizes, int image_id)
{
    EXC_SAFE((
        obj->setImage(*img, *regions, *sizes, image_id);
    ))
}

CVAPI(float) ximgproc_segmentation_SelectiveSearchSegmentationStrategy_get(SelectiveSearchSegmentationStrategy *obj, int r1, int r2)
{
    EXC_SAFE((
        return obj->get(r1, r2);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentationStrategy_merge(SelectiveSearchSegmentationStrategy *obj, int r1, int r2)
{
    EXC_SAFE((
        obj->merge(r1, r2);
    ))
}

CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyColor>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyColor()
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyColor());
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategySize>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategySize()
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategySize());
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyTexture>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyTexture()
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyTexture());
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyFill>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyFill()
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyFill());
    ))
}

CVAPI(void) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyColor_delete(cv::Ptr<SelectiveSearchSegmentationStrategyColor> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}
CVAPI(void) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategySize_delete(cv::Ptr<SelectiveSearchSegmentationStrategySize> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}
CVAPI(void) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyTexture_delete(cv::Ptr<SelectiveSearchSegmentationStrategyTexture> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}
CVAPI(void) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyFill_delete(cv::Ptr<SelectiveSearchSegmentationStrategyFill> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(SelectiveSearchSegmentationStrategyColor*) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyColor_get(cv::Ptr<SelectiveSearchSegmentationStrategyColor> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(SelectiveSearchSegmentationStrategySize*) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategySize_get(cv::Ptr<SelectiveSearchSegmentationStrategySize> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(SelectiveSearchSegmentationStrategyTexture*) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyTexture_get(cv::Ptr<SelectiveSearchSegmentationStrategyTexture> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(SelectiveSearchSegmentationStrategyFill*) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyFill_get(cv::Ptr<SelectiveSearchSegmentationStrategyFill> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}


// SelectiveSearchSegmentationStrategyMultiple

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentationStrategyMultiple_addStrategy(SelectiveSearchSegmentationStrategyMultiple *obj, cv::Ptr<SelectiveSearchSegmentationStrategy> *g, float weight)
{
    EXC_SAFE((
        obj->addStrategy(*g, weight);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentationStrategyMultiple_clearStrategies(SelectiveSearchSegmentationStrategyMultiple *obj)
{
    EXC_SAFE((
        obj->clearStrategies();
    ))
}

CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple0()
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyMultiple());
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple1(
    cv::Ptr<SelectiveSearchSegmentationStrategy> *s1)
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyMultiple(*s1));
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple2(
    cv::Ptr<SelectiveSearchSegmentationStrategy> *s1, cv::Ptr<SelectiveSearchSegmentationStrategy> *s2)
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyMultiple(*s1, *s2));
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple3(
    cv::Ptr<SelectiveSearchSegmentationStrategy> *s1, cv::Ptr<SelectiveSearchSegmentationStrategy> *s2, cv::Ptr<SelectiveSearchSegmentationStrategy> *s3)
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyMultiple(*s1, *s2, *s3));
    ))
}
CVAPI(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple>*) ximgproc_segmentation_createSelectiveSearchSegmentationStrategyMultiple4(
    cv::Ptr<SelectiveSearchSegmentationStrategy> *s1, cv::Ptr<SelectiveSearchSegmentationStrategy> *s2, cv::Ptr<SelectiveSearchSegmentationStrategy> *s3, cv::Ptr<SelectiveSearchSegmentationStrategy> *s4)
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentationStrategyMultiple(*s1, *s2, *s3, *s4));
    ))
}

CVAPI(void) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyMultiple_delete(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(SelectiveSearchSegmentationStrategyMultiple*) ximgproc_segmentation_Ptr_SelectiveSearchSegmentationStrategyMultiple_get(cv::Ptr<SelectiveSearchSegmentationStrategyMultiple> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

// SelectiveSearchSegmentation

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_setBaseImage(SelectiveSearchSegmentation *obj, cv::_InputArray *img)
{
    EXC_SAFE((
        obj->setBaseImage(*img);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_switchToSingleStrategy(SelectiveSearchSegmentation *obj, int k, float sigma)
{
    EXC_SAFE((
        obj->switchToSingleStrategy(k, sigma);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_switchToSelectiveSearchFast(SelectiveSearchSegmentation *obj, int base_k, int inc_k, float sigma)
{
    EXC_SAFE((
        obj->switchToSelectiveSearchFast(base_k, inc_k, sigma);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_switchToSelectiveSearchQuality(SelectiveSearchSegmentation *obj, int base_k, int inc_k, float sigma) 
{
    EXC_SAFE((
        obj->switchToSelectiveSearchQuality(base_k, inc_k, sigma);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_addImage(SelectiveSearchSegmentation *obj, cv::_InputArray *img)
{
    EXC_SAFE((
        obj->addImage(*img);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_clearImages(SelectiveSearchSegmentation *obj)
{
    EXC_SAFE((
        obj->clearImages();
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_addGraphSegmentation(SelectiveSearchSegmentation *obj, cv::Ptr<GraphSegmentation> *g)
{
    EXC_SAFE((
        obj->addGraphSegmentation(*g);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_clearGraphSegmentations(SelectiveSearchSegmentation *obj) 
{
    EXC_SAFE((
        obj->clearGraphSegmentations();
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_addStrategy(SelectiveSearchSegmentation *obj, cv::Ptr<SelectiveSearchSegmentationStrategy> *s)
{
    EXC_SAFE((
        obj->addStrategy(*s);
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_clearStrategies(SelectiveSearchSegmentation *obj) 
{
    EXC_SAFE((
        obj->clearStrategies();
    ))
}

CVAPI(void) ximgproc_segmentation_SelectiveSearchSegmentation_process(SelectiveSearchSegmentation *obj, std::vector<cv::Rect> *rects) 
{
    EXC_SAFE((
        obj->process(*rects);
    ))
}

CVAPI(cv::Ptr<SelectiveSearchSegmentation>*) ximgproc_segmentation_createSelectiveSearchSegmentation()
{
    EXC_SAFE((
        return clone(createSelectiveSearchSegmentation());
    ))
}

CVAPI(void) ximgproc_segmentation_Ptr_SelectiveSearchSegmentation_delete(cv::Ptr<SelectiveSearchSegmentation> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(SelectiveSearchSegmentation*) ximgproc_segmentation_Ptr_SelectiveSearchSegmentation_get(cv::Ptr<SelectiveSearchSegmentation> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

#endif