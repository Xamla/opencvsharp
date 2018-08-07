#ifndef _CPP_OBJDETECT_H_
#define _CPP_OBJDETECT_H_

#include "include_opencv.h"

#pragma region LatentSvmDetector
/*
CVAPI(cv::LatentSvmDetector*) objdetect_LatentSvmDetector_new()
{
    EXC_SAFE((
        return new cv::LatentSvmDetector();
    ))
}

CVAPI(void) objdetect_LatentSvmDetector_delete(cv::LatentSvmDetector *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}


CVAPI(void) objdetect_LatentSvmDetector_clear(cv::LatentSvmDetector *obj)
{
    EXC_SAFE((
        obj->clear();
    ))
}
CVAPI(int) objdetect_LatentSvmDetector_empty(cv::LatentSvmDetector *obj)
{
    EXC_SAFE((
        return obj->empty() ? 1 : 0;
    ))
}
CVAPI(int) objdetect_LatentSvmDetector_load(cv::LatentSvmDetector *obj, 
    const char **fileNames, int fileNamesLength, 
    const char **classNames, int classNamesLength)
{
    EXC_SAFE((
        std::vector<std::string> fileNamesVec(fileNamesLength);
        std::vector<std::string> classNamesVec(classNamesLength);
        for (int i = 0; i < fileNamesLength; i++)
            fileNamesVec[i] = std::string(fileNames[i]);
        for (int i = 0; i < classNamesLength; i++)
            classNamesVec[i] = std::string(classNames[i]);
        
        return obj->load(fileNamesVec, classNamesVec) ? 1 : 0;
    ))
}

CVAPI(void) objdetect_LatentSvmDetector_detect(
    cv::LatentSvmDetector *obj, cv::Mat *image, std::vector<cv::Vec6d> *objectDetections, 
    float overlapThreshold, int numThreads)
{
    EXC_SAFE((
        std::vector<cv::LatentSvmDetector::ObjectDetection> odVecs;
        obj->detect(*image, odVecs, overlapThreshold, numThreads);
        
        objectDetections->resize(odVecs.size());
        for (size_t i = 0; i < odVecs.size(); i++)
        {
            objectDetections->at(i)[0] = odVecs[i].rect.x;
            objectDetections->at(i)[1] = odVecs[i].rect.y;
            objectDetections->at(i)[2] = odVecs[i].rect.width;
            objectDetections->at(i)[3] = odVecs[i].rect.height;
            objectDetections->at(i)[4] = odVecs[i].score;
            objectDetections->at(i)[5] = odVecs[i].classID;
        }
    ))
}

CVAPI(void) objdetect_LatentSvmDetector_getClassNames(cv::LatentSvmDetector *obj, std::vector<std::string> *outValues)
{
    EXC_SAFE((
        const std::vector<std::string> &ret = obj->getClassNames();
        std::copy(ret.begin(), ret.end(), std::back_inserter(*outValues));
    ))
}
CVAPI(size_t) objdetect_LatentSvmDetector_getClassCount(cv::LatentSvmDetector *obj)
{
    EXC_SAFE((
        return obj->getClassCount();
    ))
}
*/
#pragma endregion

#pragma region CascadeClassifier

CVAPI(cv::CascadeClassifier*) objdetect_CascadeClassifier_new()
{
    EXC_SAFE((
        return new cv::CascadeClassifier();
    ))
}
CVAPI(cv::CascadeClassifier*) objdetect_CascadeClassifier_newFromFile(const char *fileName)
{
    EXC_SAFE((
        return new cv::CascadeClassifier(fileName);
    ))
}
CVAPI(void) objdetect_CascadeClassifier_delete(cv::CascadeClassifier *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(int) objdetect_CascadeClassifier_empty(cv::CascadeClassifier *obj)
{
    EXC_SAFE((
        return obj->empty() ? 1 : 0;
    ))
}
CVAPI(int) objdetect_CascadeClassifier_load(
    cv::CascadeClassifier *obj, const char *fileName)
{
    EXC_SAFE((
        return obj->load(fileName) ? 1 : 0;
    ))
}

//CVAPI(int) objdetect_CascadeClassifier_read(const FileNode& node);

CVAPI(void) objdetect_CascadeClassifier_detectMultiScale1(
    cv::CascadeClassifier *obj,
    cv::Mat *image, std::vector<cv::Rect> *objects,
    double scaleFactor, int minNeighbors, int flags, CvSize minSize, CvSize maxSize)
{
    EXC_SAFE((
        std::vector<cv::Rect> vec;
        obj->detectMultiScale(*image, *objects,
            scaleFactor, minNeighbors, flags, minSize, maxSize);
    ))
}

CVAPI(void) objdetect_CascadeClassifier_detectMultiScale2(
    cv::CascadeClassifier *obj,
    cv::Mat *image, 
    std::vector<cv::Rect> *objects,
    std::vector<int> *rejectLevels,
    std::vector<double> *levelWeights,
    double scaleFactor, int minNeighbors, int flags,
    MyCvSize minSize, MyCvSize maxSize, int outputRejectLevels)
{
    EXC_SAFE((
        obj->detectMultiScale(*image, *objects, *rejectLevels, *levelWeights,
            scaleFactor, minNeighbors, flags, cpp(minSize), cpp(maxSize), outputRejectLevels != 0);
    ))
}


CVAPI(int) objdetect_CascadeClassifier_isOldFormatCascade(cv::CascadeClassifier *obj)
{
    EXC_SAFE((
        return obj->isOldFormatCascade() ? 1 : 0;
    ))
}
CVAPI(MyCvSize) objdetect_CascadeClassifier_getOriginalWindowSize(cv::CascadeClassifier *obj)
{
    EXC_SAFE((
        return c(obj->getOriginalWindowSize());
    ))
}
CVAPI(int) objdetect_CascadeClassifier_getFeatureType(cv::CascadeClassifier *obj)
{
    EXC_SAFE((
        return obj->getFeatureType();
    ))
}

#pragma endregion

CVAPI(void) objdetect_groupRectangles1(std::vector<cv::Rect> *rectList, int groupThreshold, double eps)
{
    EXC_SAFE((
        cv::groupRectangles(*rectList, groupThreshold, eps);
    ))
}
CVAPI(void) objdetect_groupRectangles2(std::vector<cv::Rect> *rectList, std::vector<int> *weights, int groupThreshold, double eps)
{
    EXC_SAFE((
        cv::groupRectangles(*rectList, *weights, groupThreshold, eps);
    ))
}
CVAPI(void) objdetect_groupRectangles3(std::vector<cv::Rect> *rectList, int groupThreshold, double eps, std::vector<int> *weights, std::vector<double> *levelWeights)
{
    EXC_SAFE((
        cv::groupRectangles(*rectList, groupThreshold, eps, weights, levelWeights);
    ))
}
CVAPI(void) objdetect_groupRectangles4(std::vector<cv::Rect> *rectList, std::vector<int> *rejectLevels, std::vector<double> *levelWeights, int groupThreshold, double eps)
{
    EXC_SAFE((
        cv::groupRectangles(*rectList, *rejectLevels, *levelWeights, groupThreshold, eps);
    ))
}
CVAPI(void) objdetect_groupRectangles_meanshift(std::vector<cv::Rect> *rectList, std::vector<double> *foundWeights, std::vector<double> *foundScales, double detectThreshold, MyCvSize winDetSize)
{
    EXC_SAFE((
        cv::groupRectangles_meanshift(*rectList, *foundWeights, *foundScales, detectThreshold, cpp(winDetSize));
    ))
}

#endif