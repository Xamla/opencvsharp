#ifndef _CPP_CORE_OUTPUTARRAY_H_
#define _CPP_CORE_OUTPUTARRAY_H_

#include "include_opencv.h"

CVAPI(cv::_OutputArray*) core_OutputArray_new_byMat(cv::Mat *mat)
{
    EXC_SAFE((
        cv::_OutputArray ia(*mat);
        return new cv::_OutputArray(ia);
    ))
}

CVAPI(cv::_OutputArray*) core_OutputArray_new_byGpuMat(cv::cuda::GpuMat *gm)
{
    EXC_SAFE((
        cv::_OutputArray ia(*gm);
        return new cv::_OutputArray(ia);
    ))
}

CVAPI(cv::_OutputArray*) core_OutputArray_new_byScalar(MyCvScalar scalar)
{
    EXC_SAFE((
        cv::Scalar scalarVal(cpp(scalar));
        cv::_OutputArray ia(scalarVal);
        return new cv::_OutputArray(ia);
    ))
}

CVAPI(cv::_OutputArray*) core_OutputArray_new_byVectorOfMat(std::vector<cv::Mat> *vector)
{
    EXC_SAFE((
        cv::_OutputArray ia(*vector);
        return new cv::_OutputArray(ia);
    ))
}

CVAPI(void) core_OutputArray_delete(cv::_OutputArray *oa)
{
    EXC_SAFE((
        delete oa;
    ))
}

CVAPI(cv::Mat*) core_OutputArray_getMat(cv::_OutputArray *oa)
{
    EXC_SAFE((
        cv::Mat &mat = oa->getMatRef();
        return new cv::Mat(mat);
    ))
}

CVAPI(MyCvScalar) core_OutputArray_getScalar(cv::_OutputArray *oa)
{
    EXC_SAFE((
        cv::Mat &mat = oa->getMatRef();
        cv::Scalar scalar = mat.at<cv::Scalar>(0);
        return c(scalar);
    ))
}

CVAPI(void) core_OutputArray_getVectorOfMat(cv::_OutputArray *oa, std::vector<cv::Mat*> *vector)
{
    EXC_SAFE((
        std::vector<cv::Mat> temp;
        oa->getMatVector(temp);
    
        vector->resize(temp.size());
        for (size_t i = 0; i < temp.size(); i++)
        {
            (*vector)[i] = new cv::Mat(temp[i]);
        }
    ))
}

#endif