#ifndef _CPP_ML_DTREE_H_
#define _CPP_ML_DTREE_H_

#include "include_opencv.h"
using namespace cv::ml;

extern "C"
{
    typedef struct DTrees_Node
    {
        double value;
        int classIdx; 
        int parent; 
        int left;
        int right; 
        int defaultDir; 
        int split; 
    } DTrees_Node;

    typedef struct DTrees_Split
    {
        int varIdx; 
        int inversed; // bool
        float quality;
        int next;
        float c;
        int subsetOfs;
    } DTrees_Split;
}

static inline DTrees_Node c(DTrees::Node obj)
{
    DTrees_Node ret;
    ret.value = obj.value;
    ret.classIdx = obj.classIdx;
    ret.parent = obj.parent;
    ret.left = obj.left;
    ret.right = obj.right;
    ret.defaultDir = obj.defaultDir;
    ret.split = obj.split;
    return ret;
}
static inline DTrees::Node cpp(DTrees_Node obj)
{
    DTrees::Node ret;
    ret.value = obj.value;
    ret.classIdx = obj.classIdx;
    ret.parent = obj.parent;
    ret.left = obj.left;
    ret.right = obj.right;
    ret.defaultDir = obj.defaultDir;
    ret.split = obj.split;
    return ret;
}

static inline DTrees_Split c(DTrees::Split obj)
{
    DTrees_Split ret;
    ret.varIdx = obj.varIdx;
    ret.inversed = obj.inversed ? 1 : 0;
    ret.quality = obj.quality;
    ret.next = obj.next;
    ret.c = obj.c;
    ret.subsetOfs = obj.subsetOfs;
    return ret;
}
static inline DTrees::Split cpp(DTrees_Split obj)
{
    DTrees::Split ret;
    ret.varIdx = obj.varIdx;
    ret.inversed = obj.inversed != 0;
    ret.quality = obj.quality;
    ret.next = obj.next;
    ret.c = obj.c;
    ret.subsetOfs = obj.subsetOfs;
    return ret;
}


CVAPI(int) ml_DTrees_getMaxCategories(DTrees *obj)
{
    EXC_SAFE((
        return obj->getMaxCategories();
    ))
}
CVAPI(void) ml_DTrees_setMaxCategories(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setMaxCategories(val);
    ))
}

CVAPI(int) ml_DTrees_getMaxDepth(DTrees *obj)
{
    EXC_SAFE((
        return obj->getMaxDepth();
    ))
}
CVAPI(void) ml_DTrees_setMaxDepth(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setMaxDepth(val);
    ))
}

CVAPI(int) ml_DTrees_getMinSampleCount(DTrees *obj)
{
    EXC_SAFE((
        return obj->getMinSampleCount();
    ))
}
CVAPI(void) ml_DTrees_setMinSampleCount(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setMinSampleCount(val);
    ))
}

CVAPI(int) ml_DTrees_getCVFolds(DTrees *obj)
{
    EXC_SAFE((
        return obj->getCVFolds();
    ))
}
CVAPI(void) ml_DTrees_setCVFolds(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setCVFolds(val);
    ))
}

CVAPI(int) ml_DTrees_getUseSurrogates(DTrees *obj)
{
    EXC_SAFE((
        return obj->getUseSurrogates() ? 1 : 0;
    ))
}
CVAPI(void) ml_DTrees_setUseSurrogates(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setUseSurrogates(val != 0);
    ))
}

CVAPI(int) ml_DTrees_getUse1SERule(DTrees *obj)
{
    EXC_SAFE((
        return obj->getUse1SERule() ? 1 : 0;
    ))
}
CVAPI(void) ml_DTrees_setUse1SERule(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setUse1SERule(val != 0);
    ))
}

CVAPI(int) ml_DTrees_getTruncatePrunedTree(DTrees *obj)
{
    EXC_SAFE((
        return obj->getTruncatePrunedTree() ? 1 : 0;
    ))
}
CVAPI(void) ml_DTrees_setTruncatePrunedTree(DTrees *obj, int val)
{
    EXC_SAFE((
        return obj->setTruncatePrunedTree(val != 0);
    ))
}

CVAPI(float) ml_DTrees_getRegressionAccuracy(DTrees *obj)
{
    EXC_SAFE((
        return obj->getRegressionAccuracy();
    ))
}
CVAPI(void) ml_DTrees_setRegressionAccuracy(DTrees *obj, float val)
{
    EXC_SAFE((
        return obj->setRegressionAccuracy(val);
    ))
}

CVAPI(cv::Mat*) ml_DTrees_getPriors(DTrees *obj)
{
    EXC_SAFE((
        cv::Mat m = obj->getPriors();
        return new cv::Mat(m);
    ))
}
CVAPI(void) ml_DTrees_setPriors(DTrees *obj, cv::Mat *val)
{
    EXC_SAFE((
        obj->setPriors(*val);
    ))
}


CVAPI(void) ml_DTrees_getRoots(DTrees *obj, std::vector<int> *result)
{ 
    EXC_SAFE((
        const std::vector<int> &org = obj->getRoots();
    
        result->clear();
        for (size_t i = 0; i < org.size(); i++)
        {
            result->push_back(org[i]);
        }
    ))
}

CVAPI(void) ml_DTrees_getNodes(DTrees *obj, std::vector<DTrees_Node> *result)
{
    EXC_SAFE((
        const std::vector<DTrees::Node> &org = obj->getNodes();
    
        result->clear();
        for (size_t i = 0; i < org.size(); i++)
        {
            result->push_back(c(org[i]));
        }
    ))
}

CVAPI(void) ml_DTrees_getSplits(DTrees *obj, std::vector<DTrees_Split> *result)
{
    EXC_SAFE((
        const std::vector<DTrees::Split> &org = obj->getSplits();
    
        result->clear();
        for (size_t i = 0; i < org.size(); i++)
        {
            result->push_back(c(org[i]));
        }
    ))
}

CVAPI(void) ml_DTrees_getSubsets(DTrees *obj, std::vector<int> *result)
{
    EXC_SAFE((
        const std::vector<int> &org = obj->getSubsets();
    
        result->clear();
        for (size_t i = 0; i < org.size(); i++)
        {
            result->push_back(org[i]);
        }
    ))
}


CVAPI(cv::Ptr<DTrees>*) ml_DTrees_create()
{
    EXC_SAFE((
        cv::Ptr<DTrees> ptr = DTrees::create();
        return new cv::Ptr<DTrees>(ptr);
    ))
}

CVAPI(void) ml_Ptr_DTrees_delete(cv::Ptr<DTrees> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(DTrees*) ml_Ptr_DTrees_get(cv::Ptr<DTrees> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(cv::Ptr<DTrees>*) ml_DTrees_load(const char *filePath)
{
    EXC_SAFE((
        cv::Ptr<DTrees> ptr = cv::Algorithm::load<DTrees>(filePath);
        return new cv::Ptr<DTrees>(ptr);
    ))
}

CVAPI(cv::Ptr<DTrees>*) ml_DTrees_loadFromString(const char *strModel)
{
    EXC_SAFE((
        cv::String objname = cv::ml::DTrees::create()->getDefaultName();
        cv::Ptr<DTrees> ptr = cv::Algorithm::loadFromString<DTrees>(strModel, objname);
        return new cv::Ptr<DTrees>(ptr);
    ))
}

#endif
