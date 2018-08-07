#ifndef _CPP_ARUCO_H_
#define _CPP_ARUCO_H_

#include "include_opencv.h"

CVAPI(cv::Ptr<cv::aruco::DetectorParameters>*) aruco_DetectorParameters_create()
{
    EXC_SAFE((
        cv::Ptr<cv::aruco::DetectorParameters> p = cv::aruco::DetectorParameters::create();
    
        // This code corrupt memory
        //return c(*p);
        return new cv::Ptr<cv::aruco::DetectorParameters>(p);
    ))
}

CVAPI(void) aruco_drawDetectedMarkers(
    cv::_InputOutputArray *image,
    cv::Point2f **corners,
    int cornerSize1,
    int *cornerSize2,
    int *idx, int idxCount, MyCvScalar borderColor)
{
    EXC_SAFE((
        std::vector< std::vector<cv::Point2f> > cornerVec(cornerSize1);
        std::vector<int> idxVec;
    
        for (int i = 0; i < cornerSize1; i++)
            cornerVec[i] = std::vector<cv::Point2f>(corners[i], corners[i] + cornerSize2[i]);
        if (idx != NULL)
            idxVec = std::vector<int>(idx, idx + idxCount);
    
        cv::aruco::drawDetectedMarkers(*image, cornerVec, idxVec, cpp(borderColor));
    ))
}

CVAPI(void) aruco_drawMarker(cv::Ptr<cv::aruco::Dictionary> *dictionary, int id, int sidePixels, cv::_OutputArray *img, int borderBits)
{
    EXC_SAFE((
        cv::aruco::drawMarker(*dictionary, id, sidePixels, *img, borderBits);
    ))
}

CVAPI(void) aruco_detectMarkers(cv::_InputArray *image, 
    cv::Ptr<cv::aruco::Dictionary> *dictionary, 
    std::vector< std::vector<cv::Point2f> > *corners,
    std::vector<int> *ids, 
    cv::Ptr<cv::aruco::DetectorParameters> *parameters,
    std::vector< std::vector<cv::Point2f> > *rejectedImgPoints)
{
    EXC_SAFE((
        cv::aruco::detectMarkers(*image, *dictionary, *corners, *ids, *parameters, *rejectedImgPoints);
    ))
}

CVAPI(void) aruco_estimatePoseSingleMarkers(cv::Point2f **corners, int cornersLength1, int *cornersLengths2, float markerLength,
    cv::_InputArray *cameraMatrix, cv::_InputArray *distCoeffs,
    cv::_OutputArray *rvecs, cv::_OutputArray *tvecs, cv::_OutputArray *objPoints)
{
    EXC_SAFE((
        std::vector<std::vector<cv::Point2f> > cornersVec(cornersLength1);
        for (int i = 0; i < cornersLength1; i++)    
            cornersVec[i] = std::vector<cv::Point2f>(corners[i], corners[i] + cornersLengths2[i]);    
    
        cv::aruco::estimatePoseSingleMarkers(cornersVec, markerLength, *cameraMatrix, *distCoeffs, *rvecs, *tvecs, entity(objPoints));
    ))
}

CVAPI(cv::Ptr<cv::aruco::Dictionary>*) aruco_getPredefinedDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME name)
{
    EXC_SAFE((
        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(name);
    
        return new cv::Ptr<cv::aruco::Dictionary>(dictionary);
    ))
}

CVAPI(void) aruco_Ptr_DetectorParameters_delete(cv::Ptr<cv::aruco::DetectorParameters> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(cv::aruco::DetectorParameters*) aruco_Ptr_DetectorParameters_get(cv::Ptr<cv::aruco::DetectorParameters> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

CVAPI(void) aruco_DetectorParameters_setAdaptiveThreshWinSizeMin(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->adaptiveThreshWinSizeMin = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setAdaptiveThreshWinSizeMax(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->adaptiveThreshWinSizeMax = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setAdaptiveThreshWinSizeStep(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->adaptiveThreshWinSizeStep = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setAdaptiveThreshConstant(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->adaptiveThreshConstant = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMinMarkerPerimeterRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->minMarkerPerimeterRate = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMaxMarkerPerimeterRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->maxMarkerPerimeterRate = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setPolygonalApproxAccuracyRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->polygonalApproxAccuracyRate = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMinCornerDistanceRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->minCornerDistanceRate = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMinDistanceToBorder(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->minDistanceToBorder = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMinMarkerDistanceRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->minMarkerDistanceRate = value;
    ))
}
/*
CVAPI(void) aruco_DetectorParameters_setDoCornerRefinement(cv::aruco::DetectorParameters *obj, bool value)
{
    EXC_SAFE((
        obj->doCornerRefinement = value;
    ))
}*/
CVAPI(void) aruco_DetectorParameters_setCornerRefinementWinSize(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->cornerRefinementWinSize = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setCornerRefinementMaxIterations(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->cornerRefinementMaxIterations = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setCornerRefinementMinAccuracy(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->cornerRefinementMinAccuracy = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMarkerBorderBits(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->markerBorderBits = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setPerspectiveRemovePixelPerCell(cv::aruco::DetectorParameters *obj, int value)
{
    EXC_SAFE((
        obj->perspectiveRemovePixelPerCell = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setPerspectiveRemoveIgnoredMarginPerCell(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->perspectiveRemoveIgnoredMarginPerCell = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMaxErroneousBitsInBorderRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->maxErroneousBitsInBorderRate = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setMinOtsuStdDev(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->minOtsuStdDev = value;
    ))
}
CVAPI(void) aruco_DetectorParameters_setErrorCorrectionRate(cv::aruco::DetectorParameters *obj, double value)
{
    EXC_SAFE((
        obj->errorCorrectionRate = value;
    ))
}
CVAPI(int) aruco_DetectorParameters_getAdaptiveThreshWinSizeMin(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->adaptiveThreshWinSizeMin;
    ))
}
CVAPI(int) aruco_DetectorParameters_getAdaptiveThreshWinSizeMax(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->adaptiveThreshWinSizeMax;
    ))
}
CVAPI(int) aruco_DetectorParameters_getAdaptiveThreshWinSizeStep(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->adaptiveThreshWinSizeStep;
    ))
}
CVAPI(double) aruco_DetectorParameters_getAdaptiveThreshConstant(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->adaptiveThreshConstant;
    ))
}
CVAPI(double) aruco_DetectorParameters_getMinMarkerPerimeterRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->minMarkerPerimeterRate;
    ))
}
CVAPI(double) aruco_DetectorParameters_getMaxMarkerPerimeterRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->maxMarkerPerimeterRate;
    ))
}
CVAPI(double) aruco_DetectorParameters_getPolygonalApproxAccuracyRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->polygonalApproxAccuracyRate;
    ))
}
CVAPI(double) aruco_DetectorParameters_getMinCornerDistanceRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->minCornerDistanceRate;
    ))
}
CVAPI(int) aruco_DetectorParameters_getMinDistanceToBorder(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->minDistanceToBorder;
    ))
}
CVAPI(double) aruco_DetectorParameters_getMinMarkerDistanceRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->minMarkerDistanceRate;
    ))
}
/*
CVAPI(bool) aruco_DetectorParameters_getDoCornerRefinement(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->doCornerRefinement;
    ))
}*/
CVAPI(int) aruco_DetectorParameters_getCornerRefinementWinSize(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->cornerRefinementWinSize;
    ))
}
CVAPI(int) aruco_DetectorParameters_getCornerRefinementMaxIterations(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->cornerRefinementMaxIterations;
    ))
}
CVAPI(double) aruco_DetectorParameters_getCornerRefinementMinAccuracy(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->cornerRefinementMinAccuracy;
    ))
}
CVAPI(int) aruco_DetectorParameters_getMarkerBorderBits(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->markerBorderBits;
    ))
}
CVAPI(int) aruco_DetectorParameters_getPerspectiveRemovePixelPerCell(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->perspectiveRemovePixelPerCell;
    ))
}
CVAPI(double) aruco_DetectorParameters_getPerspectiveRemoveIgnoredMarginPerCell(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->perspectiveRemoveIgnoredMarginPerCell;
    ))
}
CVAPI(double) aruco_DetectorParameters_getMaxErroneousBitsInBorderRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->maxErroneousBitsInBorderRate;
    ))
}
CVAPI(double) aruco_DetectorParameters_getMinOtsuStdDev(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->minOtsuStdDev;
    ))
}
CVAPI(double) aruco_DetectorParameters_getErrorCorrectionRate(cv::aruco::DetectorParameters *obj)
{
    EXC_SAFE((
        return obj->errorCorrectionRate;
    ))
}

CVAPI(void) aruco_Ptr_Dictionary_delete(cv::Ptr<cv::aruco::Dictionary> *ptr)
{
    EXC_SAFE((
        delete ptr;
    ))
}

CVAPI(cv::aruco::Dictionary*) aruco_Ptr_Dictionary_get(cv::Ptr<cv::aruco::Dictionary> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}
CVAPI(void) aruco_Dictionary_setMarkerSize(cv::aruco::Dictionary *obj, int value)
{
    EXC_SAFE((
        obj->markerSize = value;
    ))
}
CVAPI(void) aruco_Dictionary_setMaxCorrectionBits(cv::aruco::Dictionary *obj, int value)
{
    EXC_SAFE((
        obj->maxCorrectionBits = value;
    ))
}
CVAPI(cv::Mat*) aruco_Dictionary_getBytesList(cv::aruco::Dictionary *obj)
{
    EXC_SAFE((
        return new cv::Mat(obj->bytesList);
    ))
}
CVAPI(int) aruco_Dictionary_getMarkerSize(cv::aruco::Dictionary *obj)
{
    EXC_SAFE((
        return obj->markerSize;
    ))
}
CVAPI(int) aruco_Dictionary_getMaxCorrectionBits(cv::aruco::Dictionary *obj)
{
    EXC_SAFE((
        return obj->maxCorrectionBits;
    ))
}

#endif
