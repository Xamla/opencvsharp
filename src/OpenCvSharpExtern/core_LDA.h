#ifndef _CPP_CORE_LDA_H_
#define _CPP_CORE_LDA_H_

#include "include_opencv.h"

CVAPI(cv::LDA*) core_LDA_new1(int num_components)
{
    EXC_SAFE((
        return new cv::LDA(num_components);
    ))
}

CVAPI(cv::LDA*) core_LDA_new2(cv::_InputArray *src, cv::_InputArray *labels, int num_components)
{
    EXC_SAFE((
        return new cv::LDA(*src, *labels, num_components);
    ))
}

CVAPI(void) core_LDA_delete(cv::LDA *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(void) core_LDA_save_String(cv::LDA *obj, const char *filename)
{
    EXC_SAFE((
        obj->save(filename);
    ))
}

CVAPI(void) core_LDA_load_String(cv::LDA *obj, const char *filename)
{
    EXC_SAFE((
        obj->load(filename);
    ))
}

CVAPI(void) core_LDA_save_FileStorage(cv::LDA *obj, cv::FileStorage *fs)
{
    EXC_SAFE((
        obj->save(*fs);
    ))
}

CVAPI(void) core_LDA_load_FileStorage(cv::LDA *obj, cv::FileStorage *node)
{
    EXC_SAFE((
        obj->load(*node);
    ))
}

CVAPI(void) core_LDA_compute(cv::LDA *obj, cv::_InputArray *src, cv::_InputArray *labels)
{
    EXC_SAFE((
        obj->compute(*src, *labels);
    ))
}

CVAPI(cv::Mat*) core_LDA_project(cv::LDA *obj, cv::_InputArray *src)
{
    EXC_SAFE((
        const cv::Mat mat = obj->project(*src);
        return new cv::Mat(mat);
    ))
}

CVAPI(cv::Mat*) core_LDA_reconstruct(cv::LDA *obj, cv::_InputArray *src)
{
    EXC_SAFE((
        const cv::Mat mat = obj->reconstruct(*src);
        return new cv::Mat(mat);
    ))
}

CVAPI(cv::Mat*) core_LDA_eigenvectors(cv::LDA *obj)
{ 
    EXC_SAFE((
        const cv::Mat mat = obj->eigenvectors();
        return new cv::Mat(mat);
    ))
}

CVAPI(cv::Mat*) core_LDA_eigenvalues(cv::LDA *obj)
{
    EXC_SAFE((
        const cv::Mat mat = obj->eigenvalues();
        return new cv::Mat(mat);
    ))
}

CVAPI(cv::Mat*) core_LDA_subspaceProject(cv::_InputArray *W, cv::_InputArray *mean, cv::_InputArray *src)
{
    EXC_SAFE((
        const cv::Mat mat = cv::LDA::subspaceProject(*W, *mean, *src);
        return new cv::Mat(mat);
    ))
}
CVAPI(cv::Mat*) core_LDA_subspaceReconstruct(cv::_InputArray *W, cv::_InputArray *mean, cv::_InputArray *src)
{
    EXC_SAFE((
        const cv::Mat mat = cv::LDA::subspaceReconstruct(*W, *mean, *src);
        return new cv::Mat(mat);
    ))
}

#endif