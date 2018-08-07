#ifndef _CPP_CORE_INPUTARRAY_H_
#define _CPP_CORE_INPUTARRAY_H_

#include "include_opencv.h"

// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

CVAPI(cv::_InputArray*) core_InputArray_new_byMat(cv::Mat *mat)
{
    EXC_SAFE((
        return new cv::_InputArray(*mat);
    ))
}

CVAPI(cv::_InputArray*) core_InputArray_new_byMatExpr(cv::MatExpr *expr)
{
    EXC_SAFE((
        return new cv::_InputArray(*expr);
    ))
}

CVAPI(cv::_InputArray*) core_InputArray_new_byScalar(MyCvScalar val)
{
    EXC_SAFE((
    	cv::Scalar scalar = cpp(val);
    	return new cv::_InputArray(scalar);
    ))
}

CVAPI(cv::_InputArray*) core_InputArray_new_byDouble(double val)
{
    EXC_SAFE((
        return new cv::_InputArray(val);
    ))
}

CVAPI(cv::_InputArray*) core_InputArray_new_byGpuMat(cv::cuda::GpuMat *gm)
{
    EXC_SAFE((
        return new cv::_InputArray(*gm);
    ))
}

CVAPI(cv::_InputArray*) core_InputArray_new_byVectorOfMat(std::vector<cv::Mat> *vector)
{
    EXC_SAFE((
        return new cv::_InputArray(*vector);
    ))
}

CVAPI(void) core_InputArray_delete(cv::_InputArray *ia)
{
    EXC_SAFE((
        delete ia;
    ))
}

CVAPI(cv::Mat*) core_InputArray_getMat(cv::_InputArray *ia, int idx)
{
    EXC_SAFE((
    	return new cv::Mat(ia->getMat(idx));
    ))
}
CVAPI(cv::Mat*) core_InputArray_getMat_(cv::_InputArray *ia, int idx)
{
    EXC_SAFE((
    	return new cv::Mat(ia->getMat_(idx));
    ))
}
CVAPI(cv::UMat*) core_InputArray_getUMat(cv::_InputArray *ia, int idx)
{
    EXC_SAFE((
    	return new cv::UMat(ia->getUMat(idx));
    ))
}
CVAPI(void) core_InputArray_getMatVector(cv::_InputArray *ia, std::vector<cv::Mat> *mv)
{
    EXC_SAFE((
    	ia->getMatVector(*mv);
    ))
}
CVAPI(void) core_InputArray_getUMatVector(cv::_InputArray *ia, std::vector<cv::UMat> *umv)
{
    EXC_SAFE((
    	ia->getUMatVector(*umv);
    ))
}
CVAPI(void) core_InputArray_getGpuMatVector(cv::_InputArray *ia, std::vector<cv::cuda::GpuMat> *gpumv)
{
    EXC_SAFE((
    	ia->getGpuMatVector(*gpumv);
    ))
}
CVAPI(cv::cuda::GpuMat*) core_InputArray_getGpuMat(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return new cv::cuda::GpuMat(ia->getGpuMat());
    ))
}
//CVAPI(cv::ogl::Buffer*) core_InputArray_getOGlBuffer(cv::_InputArray *ia)
//{
//	return new cv::ogl::Buffer(ia->getOGlBuffer());
//}

CVAPI(int) core_InputArray_getFlags(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->getFlags();
    ))
}
CVAPI(void*) core_InputArray_getObj(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->getObj();
    ))
}
CVAPI(MyCvSize) core_InputArray_getSz(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return c(ia->getSz());
    ))
}

CVAPI(int) core_InputArray_kind(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->kind();
    ))
}
CVAPI(int) core_InputArray_dims(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->dims(i);
    ))
}
CVAPI(int) core_InputArray_cols(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->cols();
    ))
}
CVAPI(int) core_InputArray_rows(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->rows();
    ))
}
CVAPI(MyCvSize) core_InputArray_size(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return c(ia->size(i));
    ))
}
CVAPI(int) core_InputArray_sizend(cv::_InputArray *ia, int* sz, int i)
{
    EXC_SAFE((
    	return ia->sizend(sz, i);
    ))
}
CVAPI(int) core_InputArray_sameSize(cv::_InputArray *self, cv::_InputArray * target)
{
    EXC_SAFE((
    	return self->sameSize(*target) ? 1 : 0;
    ))
}
CVAPI(size_t) core_InputArray_total(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->total(i);
    ))
}
CVAPI(int) core_InputArray_type(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->type(i);
    ))
}
CVAPI(int) core_InputArray_depth(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->depth(i);
    ))
}
CVAPI(int) core_InputArray_channels(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->channels(i);
    ))
}
CVAPI(int) core_InputArray_isContinuous(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->isContinuous(i) ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isSubmatrix(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->isSubmatrix(i) ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_empty(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->empty() ? 1 : 0;
    ))
}
CVAPI(void) core_InputArray_copyTo1(cv::_InputArray *ia, cv::_OutputArray *arr)
{
    EXC_SAFE((
    	ia->copyTo(*arr);
    ))
}
CVAPI(void) core_InputArray_copyTo2(cv::_InputArray *ia, cv::_OutputArray *arr, cv::_InputArray *mask)
{
    EXC_SAFE((
    	ia->copyTo(*arr, *mask);
    ))
}
CVAPI(size_t) core_InputArray_offset(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->offset(i);
    ))
}
CVAPI(size_t) core_InputArray_step(cv::_InputArray *ia, int i)
{
    EXC_SAFE((
    	return ia->step(i);
    ))
}
CVAPI(int) core_InputArray_isMat(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isMat() ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isUMat(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isUMat() ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isMatVector(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isMatVector() ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isUMatVector(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isUMatVector() ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isMatx(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isMatx() ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isVector(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isVector() ? 1 : 0;
    ))
}
CVAPI(int) core_InputArray_isGpuMatVector(cv::_InputArray *ia)
{
    EXC_SAFE((
    	return ia->isGpuMatVector() ? 1 : 0;
    ))
}

#endif