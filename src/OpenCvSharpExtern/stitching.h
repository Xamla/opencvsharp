#ifndef _CPP_STITCHING_H_
#define _CPP_STITCHING_H_

#include "include_opencv.h"

CVAPI(cv::Ptr<cv::Stitcher>*) stitching_createStitcher(const int try_use_gpu)
{
    EXC_SAFE((
        cv::Ptr<cv::Stitcher> ptr = cv::createStitcher(try_use_gpu != 0);
        return new cv::Ptr<cv::Stitcher>(ptr);
    ))
}

CVAPI(cv::Ptr<cv::Stitcher>*) stitching_createStitcherScans(const int try_use_gpu)
{
    EXC_SAFE((
        cv::Ptr<cv::Stitcher> ptr = cv::createStitcherScans(try_use_gpu != 0);
        return new cv::Ptr<cv::Stitcher>(ptr);
    ))
}

CVAPI(void) stitching_Ptr_Stitcher_delete(cv::Ptr<cv::Stitcher> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::Stitcher*) stitching_Ptr_Stitcher_get(cv::Ptr<cv::Stitcher> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

#pragma region getter/setter
CVAPI(double) stitching_Stitcher_registrationResol(cv::Stitcher *obj)
{ 
    EXC_SAFE((
        return obj->registrationResol();
    ))
}
CVAPI(void) stitching_Stitcher_setRegistrationResol(cv::Stitcher *obj, const double resol_mpx)
{
    EXC_SAFE((
        obj->setRegistrationResol(resol_mpx);
    ))
}

CVAPI(double) stitching_Stitcher_seamEstimationResol(cv::Stitcher *obj) 
{
    EXC_SAFE((
        return obj->seamEstimationResol();
    ))
}
CVAPI(void) stitching_Stitcher_setSeamEstimationResol(cv::Stitcher *obj, const double resol_mpx)
{
    EXC_SAFE((
        obj->setSeamEstimationResol(resol_mpx); 
    ))
}

CVAPI(double) stitching_Stitcher_compositingResol(cv::Stitcher *obj)
{
    EXC_SAFE((
        return obj->compositingResol();
    ))
}
CVAPI(void) stitching_Stitcher_setCompositingResol(cv::Stitcher *obj, const double resol_mpx)
{ 
    EXC_SAFE((
        obj->setCompositingResol(resol_mpx);
    ))
}

CVAPI(double) stitching_Stitcher_panoConfidenceThresh(cv::Stitcher *obj) 
{ 
    EXC_SAFE((
        return obj->panoConfidenceThresh();
    ))
}
CVAPI(void) stitching_Stitcher_setPanoConfidenceThresh(cv::Stitcher *obj, const double conf_thresh)
{
    EXC_SAFE((
        obj->setPanoConfidenceThresh(conf_thresh);
    ))
}

CVAPI(int) stitching_Stitcher_waveCorrection(cv::Stitcher *obj) 
{ 
    EXC_SAFE((
        return obj->waveCorrection() ? 1 : 0; 
    ))
}
CVAPI(void) stitching_Stitcher_setWaveCorrection(cv::Stitcher *obj, const int flag)
{
    EXC_SAFE((
        obj->setWaveCorrection(flag != 0); 
    ))
}

CVAPI(int) stitching_Stitcher_waveCorrectKind(cv::Stitcher *obj) 
{
    EXC_SAFE((
        return static_cast<int>(obj->waveCorrectKind());
    ))
}
CVAPI(void) stitching_Stitcher_setWaveCorrectKind(cv::Stitcher *obj, int kind) 
{ 
    EXC_SAFE((
        obj->setWaveCorrectKind(static_cast<cv::detail::WaveCorrectKind>(kind)); 
    ))
}

#pragma endregion

CVAPI(int) stitching_Stitcher_estimateTransform_InputArray1(
    cv::Stitcher *obj, cv::_InputArray *images)
{
    EXC_SAFE((
    	const cv::Stitcher::Status status = obj->estimateTransform(*images);
        return static_cast<int>(status);
    ))
}
CVAPI(int) stitching_Stitcher_estimateTransform_InputArray2(
    cv::Stitcher *obj, cv::_InputArray *images,
	const CvRect **rois, const int roisSize1, const int *roisSize2)
{
    EXC_SAFE((
        std::vector<std::vector<cv::Rect> > roisVec;
        toVec(rois, roisSize1, roisSize2, roisVec);
    
    	const cv::Stitcher::Status status = obj->estimateTransform(*images, roisVec);
        return static_cast<int>(status);
    ))
}
CVAPI(int) stitching_Stitcher_estimateTransform_MatArray1(
    cv::Stitcher *obj, const cv::Mat **images, const int imagesSize)
{
    EXC_SAFE((
        std::vector<cv::Mat> imagesVec;
        toVec(images, imagesSize, imagesVec);
    
    	const cv::Stitcher::Status status = obj->estimateTransform(imagesVec);
        return static_cast<int>(status);
    ))
}
CVAPI(int) stitching_Stitcher_estimateTransform_MatArray2(
    cv::Stitcher *obj, const cv::Mat **images, const int imagesSize,
	const CvRect **rois, const int roisSize1, const int *roisSize2)
{
    EXC_SAFE((
        std::vector<cv::Mat> imagesVec;
        toVec(images, imagesSize, imagesVec);
    
        std::vector<std::vector<cv::Rect> > roisVec;
        toVec(rois, roisSize1, roisSize2, roisVec);
    
    	const cv::Stitcher::Status status = obj->estimateTransform(imagesVec, roisVec);
        return static_cast<int>(status);
    ))
}

CVAPI(int) stitching_Stitcher_composePanorama1(
    cv::Stitcher *obj, cv::_OutputArray *pano)
{
    EXC_SAFE((
    	const cv::Stitcher::Status status = obj->composePanorama(*pano);
        return static_cast<int>(status);
    ))
}
CVAPI(int) stitching_Stitcher_composePanorama2_InputArray(
    cv::Stitcher *obj, cv::_InputArray *images, cv::_OutputArray *pano)
{
    EXC_SAFE((
    	const cv::Stitcher::Status status = obj->composePanorama(*images, *pano);
        return static_cast<int>(status);
    ))
}
CVAPI(int) stitching_Stitcher_composePanorama2_MatArray(
    cv::Stitcher *obj, const cv::Mat **images, const int imagesSize, cv::_OutputArray *pano)
{
    EXC_SAFE((
        std::vector<cv::Mat> imagesVec;
        toVec(images, imagesSize, imagesVec);
    
    	const cv::Stitcher::Status status = obj->composePanorama(imagesVec, *pano);
        return static_cast<int>(status);
    ))
}

CVAPI(int) stitching_Stitcher_stitch1_InputArray(
    cv::Stitcher *obj, cv::_InputArray *images, cv::_OutputArray *pano)
{
    EXC_SAFE((
    	const cv::Stitcher::Status status = obj->stitch(*images, *pano);
        return static_cast<int>(status);
    ))
}

CVAPI(int) stitching_Stitcher_stitch1_MatArray(
    cv::Stitcher *obj, const cv::Mat **images, const int imagesSize, cv::_OutputArray *pano)
{
    EXC_SAFE((
        std::vector<cv::Mat> imagesVec;
        toVec(images, imagesSize, imagesVec);
    
    	const cv::Stitcher::Status status = obj->stitch(imagesVec, *pano);
        return static_cast<int>(status);
    ))
}

CVAPI(int) stitching_Stitcher_stitch2_InputArray(
    cv::Stitcher *obj, cv::_InputArray *images, 
	const CvRect **rois, const int roisSize1, int *roisSize2,
    cv::_OutputArray *pano)
{
    EXC_SAFE((
        std::vector<std::vector<cv::Rect> > roisVec;
        toVec(rois, roisSize1, roisSize2, roisVec);
    
    	const cv::Stitcher::Status status = obj->stitch(*images, roisVec, *pano);
        return static_cast<int>(status);
    ))
}

CVAPI(int) stitching_Stitcher_stitch2_MatArray(
    cv::Stitcher *obj, const cv::Mat **images, const int imagesSize,
	const CvRect **rois, const int roisSize1, int *roisSize2,
    cv::_OutputArray *pano)
{
    EXC_SAFE((
        std::vector<cv::Mat> imagesVec;
        toVec(images, imagesSize, imagesVec);
    
        std::vector<std::vector<cv::Rect> > roisVec;
        toVec(rois, roisSize1, roisSize2, roisVec);
    
    	const cv::Stitcher::Status status = obj->stitch(imagesVec, roisVec, *pano);
        return static_cast<int>(status);
    ))
}



CVAPI(void) stitching_Stitcher_component(cv::Stitcher *obj, int **pointer, int *length) 
{ 
    EXC_SAFE((
        const std::vector<int> &val = obj->component();
        *pointer = const_cast<int*>(&val[0]);
        *length = static_cast<int>(val.size());
    ))
}

// std::vector<detail::CameraParams> cameras() const { return cameras_; }

CVAPI(double) stitching_Stitcher_workScale(cv::Stitcher *obj) 
{ 
    EXC_SAFE((
        return obj->workScale(); 
    ))
}

#endif