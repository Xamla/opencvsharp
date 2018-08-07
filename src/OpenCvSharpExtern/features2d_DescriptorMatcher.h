#ifndef _CPP_FEATURES2D_DESCRIPTROMATCHER_H_
#define _CPP_FEATURES2D_DESCRIPTROMATCHER_H_

#include "include_opencv.h"

#pragma region DescriptorMatcher
CVAPI(void) features2d_DescriptorMatcher_add(cv::DescriptorMatcher *obj, cv::Mat **descriptors, int descriptorLength)
{
    EXC_SAFE((
        std::vector<cv::Mat> descriptorsVec(descriptorLength);
        for (int i = 0; i < descriptorLength; i++)    
            descriptorsVec[i] = *descriptors[i];
        obj->add(descriptorsVec);
    ))
}
CVAPI(void) features2d_DescriptorMatcher_getTrainDescriptors(cv::DescriptorMatcher *obj, std::vector<cv::Mat> *dst)
{
    EXC_SAFE((
        *dst = obj->getTrainDescriptors();
    ))
}
CVAPI(void) features2d_DescriptorMatcher_clear(cv::DescriptorMatcher *obj)
{
    EXC_SAFE((
        obj->clear();
    ))
}
CVAPI(int) features2d_DescriptorMatcher_empty(cv::DescriptorMatcher *obj)
{
    EXC_SAFE((
        return obj->empty() ? 1 : 0;
    ))
}
CVAPI(int) features2d_DescriptorMatcher_isMaskSupported(cv::DescriptorMatcher *obj)
{
    EXC_SAFE((
        return obj->isMaskSupported() ? 1 : 0;
    ))
}

CVAPI(void) features2d_DescriptorMatcher_train(cv::DescriptorMatcher *obj)
{
    EXC_SAFE((
        obj->train();
    ))
}

CVAPI(void) features2d_DescriptorMatcher_match1(
    cv::DescriptorMatcher *obj, cv::Mat *queryDescriptors, 
    cv::Mat *trainDescriptors, std::vector<cv::DMatch> *matches, cv::Mat *mask)
{
    EXC_SAFE((
        obj->match(*queryDescriptors, *trainDescriptors, *matches, entity(mask));
    ))
}
CVAPI(void) features2d_DescriptorMatcher_knnMatch1(
    cv::DescriptorMatcher *obj, cv::Mat *queryDescriptors,
    cv::Mat *trainDescriptors, std::vector<std::vector<cv::DMatch> > *matches, int k,
    cv::Mat *mask, int compactResult)
{
    EXC_SAFE((
        obj->knnMatch(*queryDescriptors, *trainDescriptors, *matches, k, entity(mask), compactResult != 0);
    ))
}
CVAPI(void) features2d_DescriptorMatcher_radiusMatch1(
    cv::DescriptorMatcher *obj, cv::Mat *queryDescriptors, 
    cv::Mat *trainDescriptors, std::vector<std::vector<cv::DMatch> > *matches, float maxDistance,
    cv::Mat *mask, int compactResult)
{
    EXC_SAFE((
        obj->radiusMatch(*queryDescriptors, *trainDescriptors, *matches, maxDistance, entity(mask), compactResult != 0);
    ))
}

CVAPI(void) features2d_DescriptorMatcher_match2(
    cv::DescriptorMatcher *obj, cv::Mat *queryDescriptors, std::vector<cv::DMatch> *matches,
    cv::Mat **masks, int masksSize)
{
    EXC_SAFE((
        std::vector<cv::Mat> masksVal;
        if (masksSize != 0)
        {
            masksVal = std::vector<cv::Mat>(masksSize);
            for (int i = 0; i < masksSize; i++)
            {
                masksVal[i] = *(masks[i]);
            }
        }
        obj->match(*queryDescriptors, *matches, masksVal);
    ))
}
CVAPI(void) features2d_DescriptorMatcher_knnMatch2(
    cv::DescriptorMatcher *obj, cv::Mat *queryDescriptors, std::vector<std::vector<cv::DMatch> > *matches, 
    int k, cv::Mat **masks, int masksSize, int compactResult)
{
    EXC_SAFE((
        std::vector<cv::Mat> masksVal;
        if (masksSize != 0)
        {
            masksVal = std::vector<cv::Mat>(masksSize);
            for (int i = 0; i < masksSize; i++)
            {
                masksVal[i] = *(masks[i]);
            }
        }
        obj->knnMatch(*queryDescriptors, *matches, k, masksVal, compactResult != 0);
    ))
}
CVAPI(void) features2d_DescriptorMatcher_radiusMatch2(
    cv::DescriptorMatcher *obj, cv::Mat *queryDescriptors, std::vector<std::vector<cv::DMatch> > *matches, 
    float maxDistance, cv::Mat **masks, int masksSize, int compactResult)
{
    EXC_SAFE((
        std::vector<cv::Mat> masksVal;
        if (masksSize != 0)
        {
            masksVal = std::vector<cv::Mat>(masksSize);
            for (int i = 0; i < masksSize; i++)
            {
                masksVal[i] = *(masks[i]);
            }
        }
        obj->radiusMatch(*queryDescriptors, *matches, maxDistance, masksVal, compactResult != 0);
    ))
}

CVAPI(cv::Ptr<cv::DescriptorMatcher>*) features2d_DescriptorMatcher_create(const char *descriptorMatcherType)
{
    EXC_SAFE((
        cv::Ptr<cv::DescriptorMatcher> ret = cv::DescriptorMatcher::create(descriptorMatcherType);
        return new cv::Ptr<cv::DescriptorMatcher>(ret);
    ))
}

CVAPI(cv::DescriptorMatcher*) features2d_Ptr_DescriptorMatcher_get(cv::Ptr<cv::DescriptorMatcher> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(void) features2d_Ptr_DescriptorMatcher_delete(cv::Ptr<cv::DescriptorMatcher> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

#pragma endregion

#pragma region BFMatcher
CVAPI(cv::BFMatcher*) features2d_BFMatcher_new(int normType, int crossCheck)
{
    EXC_SAFE((
        return new cv::BFMatcher(normType, crossCheck != 0);
    ))
}
CVAPI(void) features2d_BFMatcher_delete(cv::BFMatcher *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(int) features2d_BFMatcher_isMaskSupported(cv::BFMatcher *obj)
{
    EXC_SAFE((
        return obj->isMaskSupported() ? 1 : 0;
    ))
}

CVAPI(cv::BFMatcher*) features2d_Ptr_BFMatcher_get(cv::Ptr<cv::BFMatcher> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(void) features2d_Ptr_BFMatcher_delete(cv::Ptr<cv::BFMatcher> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

#pragma endregion

#pragma region FlannBasedMatcher

CVAPI(cv::FlannBasedMatcher*) features2d_FlannBasedMatcher_new(
    cv::Ptr<cv::flann::IndexParams> *indexParams, cv::Ptr<cv::flann::SearchParams> *searchParams)
{
    EXC_SAFE((
        cv::Ptr<cv::flann::IndexParams> indexParamsPtr;
        cv::Ptr<cv::flann::SearchParams> searchParamsPtr;
        if (indexParams == NULL)
            indexParamsPtr = cv::makePtr<cv::flann::KDTreeIndexParams>();
        else
            indexParamsPtr = *indexParams;
        
        if (searchParams == NULL)
            searchParamsPtr = cv::makePtr<cv::flann::SearchParams>();
        else    
            searchParamsPtr = *searchParams;
        
        return new cv::FlannBasedMatcher(indexParamsPtr, searchParamsPtr);
    ))
}
CVAPI(void) features2d_FlannBasedMatcher_delete(cv::FlannBasedMatcher *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(void) features2d_FlannBasedMatcher_add(
    cv::FlannBasedMatcher *obj, cv::Mat **descriptors, int descriptorsSize)
{
    EXC_SAFE((
        std::vector<cv::Mat> descriptorsVal(descriptorsSize);
        for (int i = 0; i < descriptorsSize; i++)
        {
            descriptorsVal[i] = *(descriptors[i]);
        }
        return obj->add(descriptorsVal);
    ))
}
CVAPI(void) features2d_FlannBasedMatcher_clear(cv::FlannBasedMatcher *obj)
{
    EXC_SAFE((
        return obj->clear();
    ))
}
CVAPI(void) features2d_FlannBasedMatcher_train(cv::FlannBasedMatcher *obj)
{
    EXC_SAFE((
        return obj->train();
    ))
}
CVAPI(int) features2d_FlannBasedMatcher_isMaskSupported(cv::FlannBasedMatcher *obj)
{
    EXC_SAFE((
        return obj->isMaskSupported() ? 1 : 0;
    ))
}

CVAPI(cv::FlannBasedMatcher*) features2d_Ptr_FlannBasedMatcher_get(cv::Ptr<cv::FlannBasedMatcher> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(void) features2d_Ptr_FlannBasedMatcher_delete(cv::Ptr<cv::FlannBasedMatcher> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

#pragma endregion

#endif