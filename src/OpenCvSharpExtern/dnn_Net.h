#ifndef _CPP_DNN_NET_H_
#define _CPP_DNN_NET_H_

#include "include_opencv.h"

CVAPI(cv::dnn::Net*) dnn_Net_new()
{
    EXC_SAFE((
    	return new cv::dnn::Net;
    ))
}

CVAPI(void) dnn_Net_delete(cv::dnn::Net* net)
{
    EXC_SAFE((
    	delete net;
    ))
}

CVAPI(int) dnn_Net_empty(cv::dnn::Net* net)
{
    EXC_SAFE((
    	return net->empty() ? 1 : 0;
    ))
}

CVAPI(int) dnn_Net_getLayerId(cv::dnn::Net* net, const char *layer)
{
    EXC_SAFE((
    	return net->getLayerId(layer);
    ))
}

CVAPI(void) dnn_Net_getLayerNames(cv::dnn::Net* net, std::vector<cv::String> *outVec)
{
    EXC_SAFE((
    	const auto result = net->getLayerNames();
    	outVec->assign(result.begin(), result.end());
    ))
}

CVAPI(void) dnn_Net_connect1(cv::dnn::Net* net, const char *outPin, const char *inpPin)
{
    EXC_SAFE((
    	net->connect(outPin, inpPin);
    ))
}

CVAPI(void) dnn_Net_connect2(cv::dnn::Net* net, int outLayerId, int outNum, int inpLayerId, int inpNum)
{
    EXC_SAFE((
    	net->connect(outLayerId, outNum, inpLayerId, inpNum);
    ))
}

CVAPI(void) dnn_Net_setInputsNames(cv::dnn::Net* net, const char **inputBlobNames, int inputBlobNamesLength)
{
    EXC_SAFE((
    	std::vector<cv::String> inputBlobNamesVec(inputBlobNamesLength);
    	for (int i = 0; i < inputBlobNamesLength; i++)
    	{
    		inputBlobNamesVec[i] = inputBlobNames[i];
    	}
    	net->setInputsNames(inputBlobNamesVec);
    ))
}

CVAPI(cv::Mat*) dnn_Net_forward1(cv::dnn::Net* net, const char *outputName)
{
    EXC_SAFE((
    	const cv::String outputNameStr = (outputName == nullptr) ? cv::String() : cv::String(outputName);
    	const auto ret = net->forward(outputNameStr);
    	return new cv::Mat(ret);
    ))
}

CVAPI(void) dnn_Net_forward2(
	cv::dnn::Net* net, const cv::Mat **outputBlobs, int outputBlobsLength, const char *outputName)
{
    EXC_SAFE((
    	const auto outputNameStr = (outputName == nullptr) ? cv::String() : cv::String(outputName);
    	std::vector<cv::Mat> outputBlobsVec;
    	toVec(outputBlobs, outputBlobsLength, outputBlobsVec);
    
    	net->forward(outputBlobsVec, outputNameStr);
    ))
}

CVAPI(void) dnn_Net_forward3(
	cv::dnn::Net* net, const cv::Mat **outputBlobs, int outputBlobsLength, const char **outBlobNames, int outBlobNamesLength)
{
    EXC_SAFE((
    	std::vector<cv::Mat> outputBlobsVec;
    	toVec(outputBlobs, outputBlobsLength, outputBlobsVec);
    
    	std::vector<cv::String> outBlobNamesVec(outBlobNamesLength);
    	for (int i = 0; i < outBlobNamesLength; i++)
    	{
    		outBlobNamesVec[i] = outBlobNames[i];
    	}
    
    	net->forward(outputBlobsVec, outBlobNamesVec);
    ))
}

CVAPI(void) dnn_Net_setHalideScheduler(cv::dnn::Net* net, const char *scheduler)
{
    EXC_SAFE((
        net->setHalideScheduler(scheduler);
    ))
}

CVAPI(void) dnn_Net_setPreferableBackend(cv::dnn::Net* net, int backendId)
{
    EXC_SAFE((
        net->setPreferableBackend(backendId);
    ))
}

CVAPI(void) dnn_Net_setPreferableTarget(cv::dnn::Net* net, int targetId)
{
    EXC_SAFE((
        net->setPreferableTarget(targetId);
    ))
}

CVAPI(void) dnn_Net_setInput(cv::dnn::Net* net, const cv::Mat *blob, const char *name)
{
    EXC_SAFE((
        const cv::String nameStr = (name == nullptr) ? "" : cv::String(name);
        net->setInput(*blob, name);
    ))
}

CVAPI(void) dnn_Net_enableFusion(cv::dnn::Net* net, int fusion)
{
    EXC_SAFE((
        net->enableFusion(fusion != 0);
    ))
}

CVAPI(int64) dnn_Net_getPerfProfile(cv::dnn::Net* net, std::vector<double> *timings)
{
    EXC_SAFE((
        return net->getPerfProfile(*timings);
    ))
}

#endif