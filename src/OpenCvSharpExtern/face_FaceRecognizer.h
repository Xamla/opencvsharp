#ifndef _CPP_FACE_FACERECOGNIZER_H_
#define _CPP_FACE_FACERECOGNIZER_H_

// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#include "include_opencv.h"
using namespace cv::face;


CVAPI(void) face_FaceRecognizer_train(
    FaceRecognizer *obj, cv::Mat **src, int srcLength, int *labels, int labelsLength)
{
    EXC_SAFE((
        std::vector<cv::Mat> srcVec(srcLength);
        for (int i = 0; i < srcLength; i++)
            srcVec[i] = *src[i];
        std::vector<int> labelsVec(labels, labels + labelsLength);
        obj->train(srcVec, labelsVec);
    ))
}
CVAPI(void) face_FaceRecognizer_update(
    FaceRecognizer *obj, cv::Mat **src, int srcLength, int *labels, int labelsLength)
{
    EXC_SAFE((
        std::vector<cv::Mat> srcVec(srcLength);
        for (int i = 0; i < srcLength; i++)
            srcVec[i] = *src[i];
        std::vector<int> labelsVec(labels, labels + labelsLength);
        obj->update(srcVec, labelsVec);
    ))
}
CVAPI(int) face_FaceRecognizer_predict1(FaceRecognizer *obj, cv::_InputArray *src)
{
    EXC_SAFE((
        return obj->predict(*src);
    ))
}
CVAPI(void) face_FaceRecognizer_predict2(
    FaceRecognizer *obj, cv::_InputArray *src, int *label, double *confidence)
{
    EXC_SAFE((
        obj->predict(*src, *label, *confidence);
    ))
}
CVAPI(void) face_FaceRecognizer_write1(FaceRecognizer *obj, const char *filename)
{
    EXC_SAFE((
        obj->write(filename);
    ))
}
CVAPI(void) face_FaceRecognizer_read1(FaceRecognizer *obj, const char *filename)
{
    EXC_SAFE((
        obj->read(filename);
    ))
}
CVAPI(void) face_FaceRecognizer_write2(FaceRecognizer *obj, cv::FileStorage *fs)
{
    EXC_SAFE((
        obj->write(*fs);
    ))
}
CVAPI(void) face_FaceRecognizer_read2(FaceRecognizer *obj, cv::FileNode *fn)
{
    EXC_SAFE((
        obj->read(*fn);
    ))
}

CVAPI(void) face_FaceRecognizer_setLabelInfo(FaceRecognizer *obj, int label, const char *strInfo)
{
    EXC_SAFE((
        obj->setLabelInfo(label, strInfo);
    ))
}
CVAPI(void) face_FaceRecognizer_getLabelInfo(FaceRecognizer *obj, int label, std::vector<uchar> *dst)
{
    EXC_SAFE((
        cv::String result = obj->getLabelInfo(label);
        dst->resize(result.size() + 1);
        std::memcpy(&((*dst)[0]), result.c_str(), result.size() + 1);
    ))
}

CVAPI(void) face_FaceRecognizer_getLabelsByString(FaceRecognizer *obj, const char* str, std::vector<int> *dst)
{
    EXC_SAFE((
        std::vector<int> result = obj->getLabelsByString(str);
        std::copy(result.begin(), result.end(), std::back_inserter(*dst));
    ))
}

CVAPI(double) face_FaceRecognizer_getThreshold(FaceRecognizer *obj)
{
    EXC_SAFE((
        return obj->getThreshold();
    ))
}
CVAPI(void) face_FaceRecognizer_setThreshold(FaceRecognizer *obj, double val)
{
    EXC_SAFE((
        obj->setThreshold(val);
    ))
}


CVAPI(FaceRecognizer*) face_Ptr_FaceRecognizer_get(cv::Ptr<FaceRecognizer> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}
CVAPI(void) face_Ptr_FaceRecognizer_delete(cv::Ptr<FaceRecognizer> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

#endif
