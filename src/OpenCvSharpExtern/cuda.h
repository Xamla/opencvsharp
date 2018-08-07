#ifndef _CPP_cuda_H_
#define _CPP_cuda_H_

#include "include_opencv.h"
using namespace cv::cuda;

#pragma region Device

CVAPI(int) cuda_getCudaEnabledDeviceCount()
{
    EXC_SAFE((
        return getCudaEnabledDeviceCount();
    ))
}

CVAPI(void) cuda_setDevice(int device)
{
    EXC_SAFE((
        setDevice(device);
    ))
}
CVAPI(int) cuda_getDevice()
{
    EXC_SAFE((
        return getDevice();
    ))
}

CVAPI(void) cuda_resetDevice()
{
    EXC_SAFE((
        resetDevice();
    ))
}

CVAPI(int) cuda_deviceSupports(int feature_set)
{
    EXC_SAFE((
        return deviceSupports(
            static_cast<FeatureSet>(feature_set)) ? 1 : 0;
    ))
}

// TargetArchs
CVAPI(int) cuda_TargetArchs_builtWith(int feature_set)
{
    EXC_SAFE((
        return TargetArchs::builtWith(
            static_cast<FeatureSet>(feature_set)) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_has(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::has(major, minor) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_hasPtx(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::hasPtx(major, minor) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_hasBin(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::hasBin(major, minor) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_hasEqualOrLessPtx(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::hasEqualOrLessPtx(major, minor) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_hasEqualOrGreater(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::hasEqualOrGreater(major, minor) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_hasEqualOrGreaterPtx(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::hasEqualOrGreaterPtx(major, minor) ? 1 : 0;
    ))
}
CVAPI(int) cuda_TargetArchs_hasEqualOrGreaterBin(int major, int minor)
{
    EXC_SAFE((
        return TargetArchs::hasEqualOrGreaterBin(major, minor) ? 1 : 0;
    ))
}

// DeviceInfo
CVAPI(DeviceInfo*) cuda_DeviceInfo_new1()
{
    EXC_SAFE((
        return new DeviceInfo();
    ))
}
CVAPI(DeviceInfo*) cuda_DeviceInfo_new2(int deviceId)
{
    EXC_SAFE((
        return new DeviceInfo(deviceId);
    ))
}
CVAPI(void) cuda_DeviceInfo_delete(DeviceInfo *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(void) cuda_DeviceInfo_name(DeviceInfo *obj, char *buf, int bufLength)
{ 
    EXC_SAFE((
        copyString(obj->name(), buf, bufLength);
    ))
}
CVAPI(int) cuda_DeviceInfo_majorVersion(DeviceInfo *obj)
{ 
    EXC_SAFE((
        return obj->majorVersion(); 
    ))
}
CVAPI(int) cuda_DeviceInfo_minorVersion(DeviceInfo *obj)
{ 
    EXC_SAFE((
        return obj->minorVersion();
    ))
}
CVAPI(int) cuda_DeviceInfo_multiProcessorCount(DeviceInfo *obj)
{ 
    EXC_SAFE((
        return obj->multiProcessorCount();
    ))
}
CVAPI(uint64) cuda_DeviceInfo_sharedMemPerBlock(DeviceInfo *obj)
{
    EXC_SAFE((
        return obj->sharedMemPerBlock();
    ))
}
CVAPI(void) cuda_DeviceInfo_queryMemory(
    DeviceInfo *obj, uint64 *totalMemory, uint64 *freeMemory)
{
    EXC_SAFE((
        size_t totalMemory0, freeMemory0;
        obj->queryMemory(totalMemory0, freeMemory0);
        *totalMemory = totalMemory0;
        *freeMemory = freeMemory0;
    ))
}
CVAPI(uint64) cuda_DeviceInfo_freeMemory(DeviceInfo *obj)
{
    EXC_SAFE((
        return obj->freeMemory();
    ))
}
CVAPI(uint64) cuda_DeviceInfo_totalMemory(DeviceInfo *obj)
{
    EXC_SAFE((
        return obj->totalMemory();
    ))
}
CVAPI(int) cuda_DeviceInfo_supports(DeviceInfo *obj, int feature_set)
{
    EXC_SAFE((
        return obj->supports(static_cast<FeatureSet>(feature_set)) ? 1 : 0;
    ))
}
CVAPI(int) cuda_DeviceInfo_isCompatible(DeviceInfo *obj)
{
    EXC_SAFE((
        return obj->isCompatible() ? 1 : 0;
    ))
}
CVAPI(int) cuda_DeviceInfo_deviceID(DeviceInfo *obj)
{
    EXC_SAFE((
        return obj->deviceID();
    ))
}
CVAPI(int) cuda_DeviceInfo_canMapHostMemory(DeviceInfo *obj)
{
    EXC_SAFE((
        return obj->canMapHostMemory() ? 1 : 0;
    ))
}


CVAPI(void) cuda_printCudaDeviceInfo(int device)
{
    EXC_SAFE((
        printCudaDeviceInfo(device);
    ))
}
CVAPI(void) cuda_printShortCudaDeviceInfo(int device)
{
    EXC_SAFE((
        printShortCudaDeviceInfo(device);
    ))
}

#pragma endregion

#pragma region Stream

CVAPI(Stream*) cuda_Stream_new1()
{
    EXC_SAFE((
        return new Stream();
    ))
}
CVAPI(Stream*) cuda_Stream_new2(Stream* s)
{
    EXC_SAFE((
        return new Stream(*s);
    ))
}

CVAPI(void) cuda_Stream_delete(Stream *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(void) cuda_Stream_opAssign(Stream *left, Stream *right)
{
    EXC_SAFE((
        *left = *right;
    ))
}

CVAPI(int) cuda_Stream_queryIfComplete(Stream *obj)
{
    EXC_SAFE((
        return obj->queryIfComplete() ? 1 : 0;
    ))
}
CVAPI(void) cuda_Stream_waitForCompletion(Stream *obj)
{
    EXC_SAFE((
        obj->waitForCompletion();
    ))
}

CVAPI(void) cuda_Stream_enqueueHostCallback(
    Stream *obj, Stream::StreamCallback callback, void* userData)
{
    EXC_SAFE((
        obj->enqueueHostCallback(callback, userData);
    ))
}

CVAPI(Stream*) cuda_Stream_Null()
{
    EXC_SAFE((
        return &Stream::Null();
    ))
}

CVAPI(int) cuda_Stream_bool(Stream *obj)
{
    EXC_SAFE((
        return (bool)(*obj) ? 1 : 0;
    ))
}

#pragma endregion

#endif