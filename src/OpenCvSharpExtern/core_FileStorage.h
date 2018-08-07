#ifndef _CPP_CORE_FILESTORAGE_H_
#define _CPP_CORE_FILESTORAGE_H_

#include "include_opencv.h"

#pragma region FileStorage

CVAPI(cv::FileStorage*) core_FileStorage_new1()
{
    EXC_SAFE((
        return new cv::FileStorage();
    ))
}
CVAPI(cv::FileStorage*) core_FileStorage_new2(const char *source, int flags, const char *encoding)
{
    EXC_SAFE((
        std::string encodingStr;
        if (encoding != NULL)
            encodingStr = std::string(encoding);
        return new cv::FileStorage(source, flags, encodingStr);
    ))
}
CVAPI(cv::FileStorage*) core_FileStorage_newFromLegacy(CvFileStorage *fs)
{
    EXC_SAFE((
        return new cv::FileStorage(fs);
    ))
}

CVAPI(void) core_FileStorage_delete(cv::FileStorage *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(int) core_FileStorage_open(cv::FileStorage *obj,
                                 const char *filename, int flags, const char *encoding)
{
    EXC_SAFE((
        std::string encodingStr;
        if (encoding != NULL)
            encodingStr = std::string(encoding);
        return obj->open(filename, flags, encodingStr) ? 1 : 0;
    ))
}
CVAPI(int) core_FileStorage_isOpened(cv::FileStorage *obj)
{
    EXC_SAFE((
        return obj->isOpened() ? 1 : 0;
    ))
}
CVAPI(void) core_FileStorage_release(cv::FileStorage *obj)
{
    EXC_SAFE((
        return obj->release();
    ))
}
CVAPI(void) core_FileStorage_releaseAndGetString(cv::FileStorage *obj,
                                                 char *buf, int bufLength)
{
    EXC_SAFE((
        std::string result = obj->releaseAndGetString();
        copyString(result, buf, bufLength);
    ))
}

CVAPI(cv::FileNode*) core_FileStorage_getFirstTopLevelNode(cv::FileStorage *obj)
{
    EXC_SAFE((
        cv::FileNode node = obj->getFirstTopLevelNode();
        return new cv::FileNode(node);
    ))
}
CVAPI(cv::FileNode*) core_FileStorage_root(cv::FileStorage *obj, int streamIdx)
{
    EXC_SAFE((
        cv::FileNode node = obj->root(streamIdx);
        return new cv::FileNode(node);
    ))
}
CVAPI(cv::FileNode*) core_FileStorage_indexer(cv::FileStorage *obj, const char *nodeName)
{
    EXC_SAFE((
        cv::FileNode node = (*obj)[nodeName];
        return new cv::FileNode(node);
    ))
}

CVAPI(CvFileStorage*) core_FileStorage_toLegacy(cv::FileStorage *obj)
{
    EXC_SAFE((
        return obj->fs.get();
    ))
}
CVAPI(void) core_FileStorage_writeRaw(cv::FileStorage *obj, const char *fmt, const uchar *vec, size_t len)
{
    EXC_SAFE((
        obj->writeRaw(fmt, vec, len);
    ))
}
CVAPI(void) core_FileStorage_writeObj(cv::FileStorage *obj, const char *name, const void *value)
{
    EXC_SAFE((
        obj->writeObj(name, value);
    ))
}

CVAPI(void) core_FileStorage_getDefaultObjectName(const char *filename, char *buf, int bufLength)
{
    EXC_SAFE((
        std::string ret = cv::FileStorage::getDefaultObjectName(filename);
        copyString(ret, buf, bufLength);
    ))
}

CVAPI(const char*) core_FileStorage_elname(cv::FileStorage *obj)
{
    EXC_SAFE((
        return obj->elname.c_str();
    ))
}
CVAPI(const char*) core_FileStorage_structs(cv::FileStorage *obj, size_t* resultLength)
{
    EXC_SAFE((
        std::vector<char> &structs = obj->structs;
        *resultLength = structs.size();
        return &(structs[0]);
    ))
}
CVAPI(int) core_FileStorage_state(cv::FileStorage *obj)
{
    EXC_SAFE((
        return obj->state;
    ))
}

CVAPI(void) core_FileStorage_write_int(cv::FileStorage *fs, const char *name, int value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), value);
    ))
}
CVAPI(void) core_FileStorage_write_float(cv::FileStorage *fs, const char *name, float value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), value);
    ))
}
CVAPI(void) core_FileStorage_write_double(cv::FileStorage *fs, const char *name, double value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), value);
    ))
}
CVAPI(void) core_FileStorage_write_String(cv::FileStorage *fs, const char *name, const char *value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), value);
    ))
}
CVAPI(void) core_FileStorage_write_Mat(cv::FileStorage *fs, const char *name, const cv::Mat *value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), *value);
    ))
}
CVAPI(void) core_FileStorage_write_SparseMat(cv::FileStorage *fs, const char *name, const cv::SparseMat *value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), *value);
    ))
}
CVAPI(void) core_FileStorage_write_vectorOfKeyPoint(cv::FileStorage *fs, const char *name, const std::vector<cv::KeyPoint> *value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), *value);
    ))
}
CVAPI(void) core_FileStorage_write_vectorOfDMatch(cv::FileStorage *fs, const char *name, const std::vector<cv::DMatch> *value)
{
    EXC_SAFE((
        cv::write(*fs, cv::String(name), *value);
    ))
}

CVAPI(void) core_FileStorage_writeScalar_int(cv::FileStorage *fs, int value)
{
    EXC_SAFE((
        cv::writeScalar(*fs, value);
    ))
}
CVAPI(void) core_FileStorage_writeScalar_float(cv::FileStorage *fs, float value)
{
    EXC_SAFE((
        cv::writeScalar(*fs, value);
    ))
}
CVAPI(void) core_FileStorage_writeScalar_double(cv::FileStorage *fs, double value)
{
    EXC_SAFE((
        cv::writeScalar(*fs, value);
    ))
}
CVAPI(void) core_FileStorage_writeScalar_String(cv::FileStorage *fs, const char *value)
{
    EXC_SAFE((
        cv::writeScalar(*fs, cv::String(value));
    ))
}

CVAPI(void) core_FileStorage_shift_String(cv::FileStorage *fs, const char *val)
{
    EXC_SAFE((
        (*fs) << val;
    ))
}
CVAPI(void) core_FileStorage_shift_int(cv::FileStorage *fs, int val)
{
    EXC_SAFE((
        (*fs) << val;
    ))
}
CVAPI(void) core_FileStorage_shift_float(cv::FileStorage *fs, float val)
{
    EXC_SAFE((
        (*fs) << val;
    ))
}
CVAPI(void) core_FileStorage_shift_double(cv::FileStorage *fs, double val)
{
    EXC_SAFE((
        (*fs) << val;
    ))
}
CVAPI(void) core_FileStorage_shift_Mat(cv::FileStorage *fs, cv::Mat *val)
{
    EXC_SAFE((
        (*fs) << *val;
    ))
}
CVAPI(void) core_FileStorage_shift_SparseMat(cv::FileStorage *fs, cv::SparseMat *val)
{
    EXC_SAFE((
        (*fs) << *val;
    ))
}
CVAPI(void) core_FileStorage_shift_Range(cv::FileStorage *fs, MyCvSlice val)
{
    EXC_SAFE((
        (*fs) << cpp(val);
    ))
}
CVAPI(void) core_FileStorage_shift_KeyPoint(cv::FileStorage *fs, cv::KeyPoint val)
{
    EXC_SAFE((
        (*fs) << val;
    ))
}
CVAPI(void) core_FileStorage_shift_DMatch(cv::FileStorage *fs, cv::DMatch val)
{
    EXC_SAFE((
        (*fs) << val;
    ))
}
CVAPI(void) core_FileStorage_shift_vectorOfKeyPoint(cv::FileStorage *fs, std::vector<cv::KeyPoint> *val)
{
    EXC_SAFE((
        (*fs) << *val;
    ))
}
CVAPI(void) core_FileStorage_shift_vectorOfDMatch(cv::FileStorage *fs, std::vector<cv::DMatch> *val)
{
    EXC_SAFE((
        (*fs) << *val;
    ))
}
CVAPI(void) core_FileStorage_shift_Point2i(cv::FileStorage *fs, MyCvPoint val)
{
    EXC_SAFE((
        (*fs) << cv::Point2i(val.x, val.y);
    ))
}
CVAPI(void) core_FileStorage_shift_Point2f(cv::FileStorage *fs, MyCvPoint2D32f val)
{
    EXC_SAFE((
        (*fs) << cv::Point2f(val.x, val.y);
    ))
}
CVAPI(void) core_FileStorage_shift_Point2d(cv::FileStorage *fs, MyCvPoint2D64f val)
{
    EXC_SAFE((
        (*fs) << cv::Point2d(val.x, val.y);
    ))
}
CVAPI(void) core_FileStorage_shift_Point3i(cv::FileStorage *fs, MyCvPoint3D32i val)
{
    EXC_SAFE((
        (*fs) << cv::Point3i(val.x, val.y, val.z);
    ))
}
CVAPI(void) core_FileStorage_shift_Point3f(cv::FileStorage *fs, MyCvPoint3D32f val)
{
    EXC_SAFE((
        (*fs) << cv::Point3f(val.x, val.y, val.z);
    ))
}
CVAPI(void) core_FileStorage_shift_Point3d(cv::FileStorage *fs, MyCvPoint3D64f val)
{
    EXC_SAFE((
        (*fs) << cv::Point3d(val.x, val.y, val.z);
    ))
}
CVAPI(void) core_FileStorage_shift_Size2i(cv::FileStorage *fs, MyCvSize val)
{
    EXC_SAFE((
        (*fs) << cv::Size2i(val.width, val.height);
    ))
}
CVAPI(void) core_FileStorage_shift_Size2f(cv::FileStorage *fs, MyCvSize2D32f val)
{
    EXC_SAFE((
        (*fs) << cv::Size2f(val.width, val.height);
    ))
}
CVAPI(void) core_FileStorage_shift_Size2d(cv::FileStorage *fs, MyCvSize2D64f val)
{
    EXC_SAFE((
        (*fs) << cv::Size2d(val.width, val.height);
    ))
}
CVAPI(void) core_FileStorage_shift_Rect2i(cv::FileStorage *fs, MyCvRect val)
{
    EXC_SAFE((
        (*fs) << cv::Rect2i(val.x, val.y, val.width, val.height);
    ))
}
CVAPI(void) core_FileStorage_shift_Rect2f(cv::FileStorage *fs, MyCvRect2D32f val)
{
    EXC_SAFE((
        (*fs) << cv::Rect2f(val.x, val.y, val.width, val.height);
    ))
}
CVAPI(void) core_FileStorage_shift_Rect2d(cv::FileStorage *fs, MyCvRect2D64f val)
{
    EXC_SAFE((
        (*fs) << cv::Rect2d(val.x, val.y, val.width, val.height);
    ))
}
CVAPI(void) core_FileStorage_shift_Scalar(cv::FileStorage *fs, MyCvScalar val)
{
    EXC_SAFE((
        (*fs) << cpp(val);
    ))
}

CVAPI(void) core_FileStorage_shift_Vec2i(cv::FileStorage *fs, CvVec2i v)
{
    EXC_SAFE((
        (*fs) << cv::Vec2i(v.val[0], v.val[1]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec3i(cv::FileStorage *fs, CvVec3i v)
{
    EXC_SAFE((
        (*fs) << cv::Vec3i(v.val[0], v.val[1], v.val[2]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec4i(cv::FileStorage *fs, CvVec4i v)
{
    EXC_SAFE((
        (*fs) << cv::Vec4i(v.val[0], v.val[1], v.val[2], v.val[3]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec6i(cv::FileStorage *fs, CvVec6i v)
{
    EXC_SAFE((
        (*fs) << cv::Vec6i(v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec2d(cv::FileStorage *fs, CvVec2d v)
{
    EXC_SAFE((
        (*fs) << cv::Vec2d(v.val[0], v.val[1]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec3d(cv::FileStorage *fs, CvVec3d v)
{
    EXC_SAFE((
        (*fs) << cv::Vec3d(v.val[0], v.val[1], v.val[2]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec4d(cv::FileStorage *fs, CvVec4d v)
{
    EXC_SAFE((
        (*fs) << cv::Vec4d(v.val[0], v.val[1], v.val[2], v.val[3]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec6d(cv::FileStorage *fs, CvVec6d v)
{
    EXC_SAFE((
        (*fs) << cv::Vec6d(v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec2f(cv::FileStorage *fs, CvVec2f v)
{
    EXC_SAFE((
        (*fs) << cv::Vec2f(v.val[0], v.val[1]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec3f(cv::FileStorage *fs, CvVec3f v)
{
    EXC_SAFE((
        (*fs) << cv::Vec3f(v.val[0], v.val[1], v.val[2]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec4f(cv::FileStorage *fs, CvVec4f v)
{
    EXC_SAFE((
        (*fs) << cv::Vec4f(v.val[0], v.val[1], v.val[2], v.val[3]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec6f(cv::FileStorage *fs, CvVec6f v)
{
    EXC_SAFE((
        (*fs) << cv::Vec6f(v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec2b(cv::FileStorage *fs, CvVec2b v)
{
    EXC_SAFE((
        (*fs) << cv::Vec2b(v.val[0], v.val[1]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec3b(cv::FileStorage *fs, CvVec3b v)
{
    EXC_SAFE((
        (*fs) << cv::Vec3b(v.val[0], v.val[1], v.val[2]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec4b(cv::FileStorage *fs, CvVec4b v)
{
    EXC_SAFE((
        (*fs) << cv::Vec4b(v.val[0], v.val[1], v.val[2], v.val[3]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec6b(cv::FileStorage *fs, CvVec6b v)
{
    EXC_SAFE((
        (*fs) << cv::Vec6b(v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec2s(cv::FileStorage *fs, CvVec2s v)
{
    EXC_SAFE((
        (*fs) << cv::Vec2s(v.val[0], v.val[1]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec3s(cv::FileStorage *fs, CvVec3s v)
{
    EXC_SAFE((
        (*fs) << cv::Vec3s(v.val[0], v.val[1], v.val[2]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec4s(cv::FileStorage *fs, CvVec4s v)
{
    EXC_SAFE((
        (*fs) << cv::Vec4s(v.val[0], v.val[1], v.val[2], v.val[3]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec6s(cv::FileStorage *fs, CvVec6s v)
{
    EXC_SAFE((
        (*fs) << cv::Vec6s(v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec2w(cv::FileStorage *fs, CvVec2w v)
{
    EXC_SAFE((
        (*fs) << cv::Vec2w(v.val[0], v.val[1]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec3w(cv::FileStorage *fs, CvVec3w v)
{
    EXC_SAFE((
        (*fs) << cv::Vec3w(v.val[0], v.val[1], v.val[2]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec4w(cv::FileStorage *fs, CvVec4w v)
{
    EXC_SAFE((
        (*fs) << cv::Vec4w(v.val[0], v.val[1], v.val[2], v.val[3]);
    ))
}
CVAPI(void) core_FileStorage_shift_Vec6w(cv::FileStorage *fs, CvVec6w v)
{
    EXC_SAFE((
        (*fs) << cv::Vec6w(v.val[0], v.val[1], v.val[2], v.val[3], v.val[4], v.val[5]);
    ))
}

#pragma endregion

#pragma region FileNodeIterator

CVAPI(cv::FileNodeIterator*) core_FileNodeIterator_new1()
{
    EXC_SAFE((
        return new cv::FileNodeIterator;
    ))
}
CVAPI(cv::FileNodeIterator*) core_FileNodeIterator_new2(cv::FileNodeIterator *obj)
{
    EXC_SAFE((
        return new cv::FileNodeIterator(*obj);
    ))
}

CVAPI(void) core_FileNodeIterator_delete(cv::FileNodeIterator *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(cv::FileNode*) core_FileNodeIterator_operatorAsterisk(cv::FileNodeIterator *obj)
{
    EXC_SAFE((
        return new cv::FileNode(*(*obj));
    ))
}

CVAPI(int) core_FileNodeIterator_operatorIncrement(cv::FileNodeIterator *obj)
{
    EXC_SAFE((
        const size_t prev_remaining = obj->remaining; 
        ++(*obj);
        return (prev_remaining == obj->remaining) ? 0 : 1;
    ))
}
CVAPI(int) core_FileNodeIterator_operatorDecrement(cv::FileNodeIterator *obj)
{
    EXC_SAFE((
        const size_t prev_remaining = obj->remaining;
        --(*obj);
        return (prev_remaining == obj->remaining) ? 0 : 1;
    ))
}

CVAPI(int) core_FileNodeIterator_operatorPlusEqual(cv::FileNodeIterator *obj, int ofs)
{
    EXC_SAFE((
        const size_t prev_remaining = obj->remaining;
        (*obj) += ofs;
        return (prev_remaining == obj->remaining) ? 0 : 1;
    ))
}
CVAPI(int) core_FileNodeIterator_operatorMinusEqual(cv::FileNodeIterator *obj, int ofs)
{
    EXC_SAFE((
        const size_t prev_remaining = obj->remaining;
        (*obj) -= ofs;
        return (prev_remaining == obj->remaining) ? 0 : 1;
    ))
}

CVAPI(cv::FileNodeIterator*) core_FileNodeIterator_readRaw(
    cv::FileNodeIterator *obj, const char *fmt, uchar* vec, size_t maxCount)
{
    EXC_SAFE((
        return &(obj->readRaw(fmt, vec, maxCount));
    ))
}

CVAPI(int) core_FileNodeIterator_operatorEqual(cv::FileNodeIterator *it1, cv::FileNodeIterator *it2)
{
    EXC_SAFE((
        return ((*it1) == (*it2)) ? 1 : 0;
    ))
}

/*
CVAPI(int) core_FileNodeIterator_operatorNotEqual(cv::FileNodeIterator *it1, cv::FileNodeIterator *it2)
{
    EXC_SAFE((
        return ((*it1) != (*it2)) ? 1 : 0;
    ))
}*/

CVAPI(ptrdiff_t) core_FileNodeIterator_operatorMinus(cv::FileNodeIterator *it1, cv::FileNodeIterator *it2)
{
    EXC_SAFE((
        return (*it1) - (*it2);
    ))
}

CVAPI(int) core_FileNodeIterator_operatorLessThan(cv::FileNodeIterator *it1, cv::FileNodeIterator *it2)
{
    EXC_SAFE((
        return (*it1) < (*it2);
    ))
}

#pragma endregion 

#endif