#ifndef _CPP_XIMGPROC_EDGEBOXES_H_
#define _CPP_XIMGPROC_EDGEBOXES_H_

#include "include_opencv.h"


CVAPI(void) ximgproc_EdgeBoxes_getBoundingBoxes(cv::ximgproc::EdgeBoxes *obj, cv::_InputArray *edge_map, 
    cv::_InputArray *orientation_map, std::vector<cv::Rect> *boxes)
{
    EXC_SAFE((
        obj->getBoundingBoxes(*edge_map, *orientation_map, *boxes);
    ))
}

CVAPI(float) ximgproc_EdgeBoxes_getAlpha(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getAlpha();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setAlpha(cv::ximgproc::EdgeBoxes *obj, float value) {     EXC_SAFE((
    obj->setAlpha(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getBeta(cv::ximgproc::EdgeBoxes *obj){     EXC_SAFE((
    return obj->getBeta();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setBeta(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setBeta(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getEta(cv::ximgproc::EdgeBoxes *obj){     EXC_SAFE((
    return obj->getEta();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setEta(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setEta(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getMinScore(cv::ximgproc::EdgeBoxes *obj){     EXC_SAFE((
    return obj->getMinScore();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setMinScore(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setMinScore(value);
    )) }
CVAPI(int) ximgproc_EdgeBoxes_getMaxBoxes(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getMaxBoxes();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setMaxBoxes(cv::ximgproc::EdgeBoxes *obj, int value){     EXC_SAFE((
    obj->setMaxBoxes(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getEdgeMinMag(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getEdgeMinMag();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setEdgeMinMag(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setEdgeMinMag(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getEdgeMergeThr(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getEdgeMergeThr();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setEdgeMergeThr(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setEdgeMergeThr(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getClusterMinMag(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getClusterMinMag();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setClusterMinMag(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setClusterMinMag(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getMaxAspectRatio(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getMaxAspectRatio();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setMaxAspectRatio(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setMaxAspectRatio(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getMinBoxArea(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getMinBoxArea();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setMinBoxArea(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setMinBoxArea(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getGamma(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getGamma();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setGamma(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setGamma(value);
    )) }
CVAPI(float) ximgproc_EdgeBoxes_getKappa(cv::ximgproc::EdgeBoxes *obj) {     EXC_SAFE((
    return obj->getKappa();
    )) }
CVAPI(void) ximgproc_EdgeBoxes_setKappa(cv::ximgproc::EdgeBoxes *obj, float value){     EXC_SAFE((
    obj->setKappa(value);
    )) }


CVAPI(cv::Ptr<cv::ximgproc::EdgeBoxes>*) ximgproc_createEdgeBoxes(
    float alpha,  float beta, float eta, float minScore, int maxBoxes, float edgeMinMag, float edgeMergeThr,
    float clusterMinMag, float maxAspectRatio, float minBoxArea, float gamma, float kappa)
{
    EXC_SAFE((
        return clone(cv::ximgproc::createEdgeBoxes(alpha, beta, eta, minScore, maxBoxes, edgeMinMag, edgeMergeThr,
            clusterMinMag, maxAspectRatio, minBoxArea, gamma, kappa));
    ))
}

CVAPI(void) ximgproc_Ptr_EdgeBoxes_delete(cv::Ptr<cv::ximgproc::EdgeBoxes> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::ximgproc::EdgeBoxes*) ximgproc_Ptr_EdgeBoxes_get(cv::Ptr<cv::ximgproc::EdgeBoxes> *ptr)
{
    EXC_SAFE((
        return ptr->get();
    ))
}

#endif