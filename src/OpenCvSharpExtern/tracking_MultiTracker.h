#ifndef _CPP_TRACKING_MULTITRACKER_H_
#define _CPP_TRACKING_MULTITRACKER_H_

#include "include_opencv.h"

// TrackerMOSSE

CVAPI(cv::Ptr<cv::MultiTracker>*) tracking_MultiTracker_create()
{
    EXC_SAFE((
        const auto p = cv::MultiTracker::create();
        return clone(p);
    ))
}

CVAPI(void) tracking_Ptr_MultiTracker_delete(cv::Ptr<cv::MultiTracker> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(cv::MultiTracker*) tracking_Ptr_MultiTracker_get(cv::Ptr<cv::MultiTracker> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(int) tracking_MultiTracker_add1(cv::MultiTracker *obj, cv::Ptr<cv::Tracker> *newTracker, cv::_InputArray *image, MyCvRect2D64f boundingBox)
{
    EXC_SAFE((
        return obj->add(*newTracker, *image, cpp(boundingBox)) ? 1 : 0;
    ))
}

CVAPI(int) tracking_MultiTracker_add2(cv::MultiTracker *obj, cv::Ptr<cv::Tracker> **newTrackers, int newTrackersLength, cv::_InputArray *image, 
    MyCvRect2D64f *boundingBox, int boundingBoxLength)
{
    EXC_SAFE((
        std::vector<cv::Ptr<cv::Tracker> > newTrackersVec(newTrackersLength);
        for (int i = 0; i < newTrackersLength; i++)
        {
            newTrackersVec[i] = *newTrackers[i];
        }
    
        std::vector<cv::Rect2d> boundingBoxVec(boundingBoxLength);
        for (int i = 0; i < boundingBoxLength; i++)
        {
            boundingBoxVec[i] = cpp(boundingBox[i]);
        }
    
        return obj->add(newTrackersVec, *image, boundingBoxVec) ? 1 : 0;
    ))
}

CVAPI(int) tracking_MultiTracker_update1(cv::MultiTracker *obj, cv::_InputArray *image)
{
    EXC_SAFE((
        return obj->update(*image) ? 1 : 0;
    ))
}

CVAPI(int) tracking_MultiTracker_update2(cv::MultiTracker *obj, cv::_InputArray *image, std::vector<cv::Rect2d> *boundingBox)
{
    EXC_SAFE((
        return obj->update(*image, *boundingBox) ? 1 : 0;
    ))
}

CVAPI(void) tracking_MultiTracker_getObjects(cv::MultiTracker *obj, std::vector<cv::Rect2d> *boundingBox)
{
    EXC_SAFE((
        const auto& result = obj->getObjects();
        std::copy(result.begin(), result.end(), std::back_inserter(*boundingBox));
    ))
}


#endif