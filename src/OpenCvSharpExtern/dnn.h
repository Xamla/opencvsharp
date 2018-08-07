#ifndef _CPP_DNN_H_
#define _CPP_DNN_H_

#include "include_opencv.h"


CVAPI(cv::dnn::Net*) dnn_readNetFromDarknet(const char *cfgFile, const char *darknetModel)
{
    EXC_SAFE((
    	const auto darknetModelStr = (darknetModel == nullptr) ? cv::String() : cv::String(darknetModel);
    	const auto net = cv::dnn::readNetFromDarknet(cfgFile, darknetModelStr);
    	return new cv::dnn::Net(net);
    ))
}

CVAPI(cv::dnn::Net*) dnn_readNetFromCaffe(const char *prototxt, const char *caffeModel)
{
    EXC_SAFE((
    	const auto caffeModelStr = (caffeModel == nullptr) ? cv::String() : cv::String(caffeModel);
    	const auto net = cv::dnn::readNetFromCaffe(prototxt, caffeModelStr);
    	return new cv::dnn::Net(net);
    ))
}

CVAPI(cv::dnn::Net*) dnn_readNetFromTensorflow(const char *model, const char *config)
{
    EXC_SAFE((
    	const auto configStr = (config == nullptr) ? cv::String() : cv::String(config);
    	const auto net = cv::dnn::readNetFromTensorflow(model, configStr);
    	return new cv::dnn::Net(net);
    ))
}

CVAPI(cv::dnn::Net*) dnn_readNetFromTorch(const char *model, const int isBinary)
{
    EXC_SAFE((
    	const auto net = cv::dnn::readNetFromTorch(model, isBinary != 0);
    	return new cv::dnn::Net(net);
    ))
}

CVAPI(cv::Mat*) dnn_readTorchBlob(const char *filename, const int isBinary)
{
    EXC_SAFE((
    	const auto blob = cv::dnn::readTorchBlob(filename, isBinary != 0);
    	return new cv::Mat(blob);
    ))
}

CVAPI(cv::Mat*) dnn_blobFromImage(
	cv::Mat *image, const double scalefactor, const MyCvSize size, const MyCvScalar mean, const int swapRB, const int crop)
{
    EXC_SAFE((
    	const auto blob = cv::dnn::blobFromImage(*image, scalefactor, cpp(size), cpp(mean), swapRB != 0, crop != 0);
    	return new cv::Mat(blob);
    ))
}

CVAPI(cv::Mat*) dnn_blobFromImages(
	const cv::Mat **images, const int imagesLength, const double scalefactor, const MyCvSize size, const MyCvScalar mean, const int swapRB, const int crop)
{
    EXC_SAFE((
    	std::vector<cv::Mat> imagesVec;
    	toVec(images, imagesLength, imagesVec);
    
    	const auto blob = cv::dnn::blobFromImages(imagesVec, scalefactor, cpp(size), cpp(mean), swapRB != 0, crop != 0);
    	return new cv::Mat(blob);
    ))
}

CVAPI(void) dnn_shrinkCaffeModel(const char *src, const char *dst)
{
    EXC_SAFE((
    	cv::dnn::shrinkCaffeModel(src, dst);
    ))
}

#endif