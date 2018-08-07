#ifndef _CPP_IMGPROC_LINESEGMENTDETECTOR_H_
#define _CPP_IMGPROC_LINESEGMENTDETECTOR_H_

#include "include_opencv.h"

CVAPI(void) imgproc_LineSegmentDetector_detect_OutputArray(cv::LineSegmentDetector *obj, cv::_InputArray *image, cv::_OutputArray *lines,
    cv::_OutputArray *width, cv::_OutputArray *prec, cv::_OutputArray *nfa)
{
    EXC_SAFE((
        obj->detect(*image, *lines, entity(width), entity(prec), entity(nfa));
    ))
}

CVAPI(void) imgproc_LineSegmentDetector_detect_vector(cv::LineSegmentDetector *obj, cv::_InputArray *image, std::vector<cv::Vec4f> *lines,
    std::vector<double> *width, std::vector<double> *prec, std::vector<double> *nfa)
{
    EXC_SAFE((
        obj->detect(*image, *lines, *width, *prec, *nfa);
    ))
}

CVAPI(void) imgproc_LineSegmentDetector_drawSegments(cv::LineSegmentDetector *obj, cv::_InputOutputArray *image, cv::_InputArray *lines)
{
    EXC_SAFE((
        obj->drawSegments(*image, *lines);
    ))
}

CVAPI(int) imgproc_LineSegmentDetector_compareSegments(cv::LineSegmentDetector *obj, MyCvSize size,
    cv::_InputArray *lines1, cv::_InputArray *lines2, cv::_InputOutputArray *image)
{
    EXC_SAFE((
        return obj->compareSegments(cpp(size), *lines1, *lines2, entity(image));
    ))
}


CVAPI(cv::Ptr<cv::LineSegmentDetector>*) imgproc_createLineSegmentDetector(
    int refine, double scale, double sigma_scale, double quant, double ang_th,
    double log_eps, double density_th, int n_bins)
{
    EXC_SAFE((
        return clone( cv::createLineSegmentDetector(
            refine, scale, sigma_scale, quant, ang_th, log_eps, density_th, n_bins));
    ))
}

CVAPI(void) imgproc_Ptr_LineSegmentDetector_delete(cv::Ptr<cv::LineSegmentDetector> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::LineSegmentDetector*) imgproc_Ptr_LineSegmentDetector_get(cv::Ptr<cv::LineSegmentDetector> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

#endif