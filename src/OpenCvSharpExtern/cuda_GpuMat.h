#ifndef _CPP_GPU_GPUMAT_H_
#define _CPP_GPU_GPUMAT_H_

#include "include_opencv.h"
using namespace cv::cuda;


#pragma region Init and Disposal

CVAPI(void) cuda_GpuMat_delete(GpuMat *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new1()
{
    EXC_SAFE((
        return new GpuMat();
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new2(int rows, int cols, int type)
{
    EXC_SAFE((
        return new GpuMat(rows, cols, type);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new3(int rows, int cols, int type, void* data, uint64 step)
{
    EXC_SAFE((
        return new GpuMat(rows, cols, type, data, static_cast<size_t>(step));
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new4(cv::Mat *mat)
{
    EXC_SAFE((
        return new GpuMat(*mat);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new5(GpuMat *gpumat)
{
    EXC_SAFE((
        return new GpuMat(*gpumat);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new6(CvSize size, int type)
{
    EXC_SAFE((
        return new GpuMat((cv::Size)size, type);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new7(CvSize size, int type, void* data, uint64 step)
{
    EXC_SAFE((
        return new GpuMat((cv::Size)size, type, data, static_cast<size_t>(step));
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new8(int rows, int cols, int type, CvScalar s)
{
    EXC_SAFE((
        return new GpuMat(rows, cols, type, s);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new9(GpuMat *m, CvSlice rowRange, CvSlice colRange)
{
    EXC_SAFE((
        return new GpuMat(*m, (cv::Range)rowRange, (cv::Range)colRange);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new10(GpuMat *m, CvRect roi)
{
    EXC_SAFE((
        return new GpuMat(*m, (cv::Rect)roi);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_new11(CvSize size, int type, CvScalar s)
{
    EXC_SAFE((
        return new GpuMat((cv::Size)size, type, s);
    ))
}
#pragma endregion

#pragma region Fields
CVAPI(int) cuda_GpuMat_flags(GpuMat *obj)
{
    EXC_SAFE((
        return obj->flags;
    ))
}
CVAPI(int) cuda_GpuMat_rows(GpuMat *obj)
{
    EXC_SAFE((
        return obj->rows;
    ))
}
CVAPI(int) cuda_GpuMat_cols(GpuMat *obj)
{
    EXC_SAFE((
        return obj->cols;
    ))
}
CVAPI(uint64) cuda_GpuMat_step(GpuMat *obj)
{
    EXC_SAFE((
        return static_cast<uint64>(obj->step);
    ))
}
CVAPI(uchar*) cuda_GpuMat_data(GpuMat *obj)
{
    EXC_SAFE((
        return obj->data;
    ))
}
CVAPI(int*) cuda_GpuMat_refcount(GpuMat *obj)
{
    EXC_SAFE((
        return obj->refcount;
    ))
}
CVAPI(uchar*) cuda_GpuMat_datastart(GpuMat *obj)
{
    EXC_SAFE((
        return obj->datastart;
    ))
}
CVAPI(const uchar*) cuda_GpuMat_dataend(GpuMat *obj)
{
    EXC_SAFE((
        return obj->dataend;
    ))
}
#pragma endregion

#pragma region Operators
CVAPI(void) cuda_GpuMat_opAssign(GpuMat *left, GpuMat *right)
{
    EXC_SAFE((
        *left = *right;
    ))
}

CVAPI(GpuMat*) cuda_GpuMat_opRange1(GpuMat *src, CvRect roi)
{
    EXC_SAFE((
        GpuMat gm = (*src)(roi);
        return new GpuMat(gm);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_opRange2(GpuMat *src, CvSlice rowRange, CvSlice colRange)
{
    EXC_SAFE((
        GpuMat gm = (*src)(rowRange, colRange);
        return new GpuMat(gm);
    ))
}

CVAPI(cv::Mat*) cuda_GpuMat_opToMat(GpuMat *src)
{
    EXC_SAFE((
        cv::Mat m = (cv::Mat)(*src);
        return new cv::Mat(m);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_opToGpuMat(cv::Mat *src)
{
    EXC_SAFE((
        GpuMat gm = (GpuMat)(*src);
        return new GpuMat(gm);
    ))
}
#pragma endregion

#pragma region Methods

CVAPI(void) cuda_GpuMat_upload(GpuMat *obj, cv::Mat *m)
{
    EXC_SAFE((
        obj->upload(*m);
    ))
}

CVAPI(void) cuda_GpuMat_download(GpuMat *obj, cv::Mat *m)
{
    EXC_SAFE((
        obj->download(*m);
    ))
}

CVAPI(GpuMat*) cuda_GpuMat_row(GpuMat *obj, int y)
{
    EXC_SAFE((
        GpuMat ret = obj->row(y);
        return new GpuMat(ret);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_col(GpuMat *obj, int x)
{
    EXC_SAFE((
        GpuMat ret = obj->col(x);
        return new GpuMat(ret);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_rowRange(GpuMat *obj, int startrow, int endrow)
{
    EXC_SAFE((
        GpuMat ret = obj->rowRange(startrow, endrow);
        return new GpuMat(ret);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_colRange(GpuMat *obj, int startcol, int endcol)
{
    EXC_SAFE((
        GpuMat ret = obj->colRange(startcol, endcol);
        return new GpuMat(ret);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_clone(GpuMat *obj)
{
    EXC_SAFE((
        GpuMat ret = obj->clone();
        return new GpuMat(ret);
    ))
}
CVAPI(void) cuda_GpuMat_copyTo1(GpuMat *obj, GpuMat *m)
{
    EXC_SAFE((
        obj->copyTo(*m);
    ))
}
CVAPI(void) cuda_GpuMat_copyTo2(GpuMat *obj, GpuMat *m, GpuMat *mask)
{
    EXC_SAFE((
        obj->copyTo(*m, *mask);
    ))
}
CVAPI(void) cuda_GpuMat_convertTo(GpuMat *obj, GpuMat *m, int rtype, double alpha, double beta)
{
    EXC_SAFE((
        obj->convertTo(*m, rtype, alpha, beta);
    ))
}
CVAPI(void) cuda_GpuMat_assignTo(GpuMat *obj, GpuMat *m, int type)
{
    EXC_SAFE((
        obj->assignTo(*m, type);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_setTo(GpuMat *obj, CvScalar s, GpuMat *mask)
{
    EXC_SAFE((
        GpuMat gm = obj->setTo(s, entity(mask));
        return new GpuMat(gm);
    ))
}
CVAPI(GpuMat*) cuda_GpuMat_reshape(GpuMat *obj, int cn, int rows)
{
    EXC_SAFE((
        GpuMat gm = obj->reshape(cn, rows);
        return new GpuMat(gm);
    ))
}

CVAPI(void) cuda_GpuMat_create1(GpuMat *obj, int rows, int cols, int type)
{
    EXC_SAFE((
        obj->create(rows, cols, type);
    ))
}
CVAPI(void) cuda_GpuMat_create2(GpuMat *obj, CvSize size, int type)
{
    EXC_SAFE((
        obj->create((cv::Size)size, type);
    ))
}
CVAPI(void) cuda_GpuMat_release(GpuMat *obj)
{
    EXC_SAFE((
        obj->release();
    ))
}
CVAPI(void) cuda_GpuMat_swap(GpuMat *obj, GpuMat *mat)
{
    EXC_SAFE((
        obj->swap(*mat);
    ))
}

CVAPI(void) cuda_GpuMat_locateROI(GpuMat *obj, CvSize *wholeSize, CvPoint *ofs)
{
    EXC_SAFE((
        cv::Size _wholeSize;
        cv::Point _ofs;
        obj->locateROI(_wholeSize, _ofs);
        *wholeSize = (CvSize)_wholeSize;
        *ofs = (CvPoint)_ofs;
    ))
}

CVAPI(GpuMat*) cuda_GpuMat_adjustROI(GpuMat *obj, int dtop, int dbottom, int dleft, int dright)
{
    EXC_SAFE((
        GpuMat gm = obj->adjustROI(dtop, dbottom, dleft, dright);
        return new GpuMat(gm);
    ))
}

CVAPI(int) cuda_GpuMat_isContinuous(GpuMat *obj)
{
    EXC_SAFE((
        return obj->isContinuous() ? 1 : 0;
    ))
}

CVAPI(uint64) cuda_GpuMat_elemSize(GpuMat *obj)
{
    EXC_SAFE((
        return static_cast<uint64>(obj->elemSize());
    ))
}
CVAPI(uint64) cuda_GpuMat_elemSize1(GpuMat *obj)
{
    EXC_SAFE((
        return static_cast<uint64>(obj->elemSize1());
    ))
}

CVAPI(int) cuda_GpuMat_type(GpuMat *obj)
{
    EXC_SAFE((
        return obj->type();
    ))
}
CVAPI(int) cuda_GpuMat_depth(GpuMat *obj)
{
    EXC_SAFE((
        return obj->depth();
    ))
}
CVAPI(int) cuda_GpuMat_channels(GpuMat *obj)
{
    EXC_SAFE((
        return obj->channels();
    ))
}
CVAPI(uint64) cuda_GpuMat_step1(GpuMat *obj)
{
    EXC_SAFE((
        return static_cast<uint64>(obj->step1());
    ))
}
CVAPI(MyCvSize) cuda_GpuMat_size(GpuMat *obj)
{
    EXC_SAFE((
        return c(obj->size());
    ))
}
CVAPI(int) cuda_GpuMat_empty(GpuMat *obj)
{
    EXC_SAFE((
        return obj->empty() ? 1 : 0;
    ))
}

CVAPI(const uchar*) cuda_GpuMat_ptr(const GpuMat *obj, int y)
{
    EXC_SAFE((
        return obj->ptr(y);
    ))
}

#pragma endregion

//! Creates continuous GPU matrix
CVAPI(void) cuda_createContinuous1(int rows, int cols, int type, GpuMat *gm)
{
    EXC_SAFE((
        createContinuous(rows, cols, type, *gm);
    ))
}
CVAPI(GpuMat*) cuda_createContinuous2(int rows, int cols, int type)
{
    EXC_SAFE((
        GpuMat gm = createContinuous(rows, cols, type);
        return new GpuMat(gm);
    ))
}

//! Ensures that size of the given matrix is not less than (rows, cols) size
//! and matrix type is match specified one too
CVAPI(void) cuda_ensureSizeIsEnough(int rows, int cols, int type, GpuMat *m)
{
    EXC_SAFE((
        ensureSizeIsEnough(rows, cols, type, *m);
    ))
}

#endif