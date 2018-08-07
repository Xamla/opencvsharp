#ifndef _CPP_FACE_FACEMARK_H_
#define _CPP_FACE_FACEMARK_H_

// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

#include "include_opencv.h"
using namespace cv::face;


#pragma region Facemark

CVAPI(void) face_Facemark_read(Facemark *obj, cv::FileNode *fn)
{
    EXC_SAFE((
        obj->read(*fn);
    ))
}

CVAPI(void) face_Facemark_write(Facemark *obj, cv::FileStorage *fs)
{
    EXC_SAFE((
        obj->write(*fs);
    ))
}

CVAPI(int) face_Facemark_addTrainingSample(Facemark *obj, cv::_InputArray *image, cv::_InputArray *landmarks)
{
    EXC_SAFE((
        return obj->addTrainingSample(*image, *landmarks) ? 1 : 0;
    ))
}

CVAPI(void) face_Facemark_training(Facemark *obj, void* parameters)
{
    EXC_SAFE((
        obj->training(parameters);
    ))
}

CVAPI(void) face_Facemark_loadModel(Facemark *obj, const char *model)
{
    EXC_SAFE((
        obj->loadModel(model);
    ))
}

CVAPI(int) face_Facemark_fit(Facemark *obj, 
    cv::_InputArray *image,
    cv::_InputArray *faces,
    cv::_InputOutputArray *landmarks,
    void * config)
{
    EXC_SAFE((
        return obj->fit(*image, *faces, *landmarks, config) ? 1 : 0;
    ))
}

CVAPI(int) face_Facemark_setFaceDetector(Facemark *obj, FN_FaceDetector detector, void* userData)
{
    EXC_SAFE((
        return obj->setFaceDetector(detector, userData) ? 1 : 0;
    ))
}

CVAPI(int) face_Facemark_getFaces_OutputArray(Facemark *obj, cv::_InputArray *image, cv::_OutputArray *faces)
{
    EXC_SAFE((
        return obj->getFaces(*image, *faces) ? 1 : 0;
    ))
}
CVAPI(int) face_Facemark_getFaces_vectorOfRect(Facemark *obj, cv::_InputArray *image, std::vector<cv::Rect> *faces)
{
    EXC_SAFE((
        return obj->getFaces(*image, *faces) ? 1 : 0;
    ))
}

#pragma endregion

#pragma region FacemarkLBF

CVAPI(cv::Ptr<FacemarkLBF>*) face_FacemarkLBF_create(FacemarkLBF::Params *params)
{
    EXC_SAFE((
        const cv::Ptr<FacemarkLBF> obj = (params == nullptr) ? 
            FacemarkLBF::create() :
            FacemarkLBF::create(*params);
        return clone(obj);
    ))
}

CVAPI(FacemarkLBF*) face_Ptr_FacemarkLBF_get(cv::Ptr<FacemarkLBF> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(void) face_Ptr_FacemarkLBF_delete(cv::Ptr<FacemarkLBF> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

#pragma region Params

CVAPI(FacemarkLBF::Params*) face_FacemarkLBF_Params_new()
{
    EXC_SAFE((
        return new FacemarkLBF::Params;
    ))
}

CVAPI(void) face_FacemarkLBF_Params_delete(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(double) face_FacemarkLBF_Params_shape_offset_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->shape_offset;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_shape_offset_set(FacemarkLBF::Params *obj, double val)
{
    EXC_SAFE((
        obj->shape_offset = val;
    ))
}

CVAPI(void) face_FacemarkLBF_Params_cascade_face_get(FacemarkLBF::Params *obj, std::string *s)
{
    EXC_SAFE((
        *s = obj->cascade_face;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_cascade_face_set(FacemarkLBF::Params *obj, const char *s)
{
    EXC_SAFE((
         obj->cascade_face = s;
    ))
}

CVAPI(int) face_FacemarkLBF_Params_verbose_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->verbose ? 1 : 0;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_verbose_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->verbose = (val != 0);
    ))
}

CVAPI(int) face_FacemarkLBF_Params_n_landmarks_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->n_landmarks;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_n_landmarks_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->n_landmarks = val;
    ))
}

CVAPI(int) face_FacemarkLBF_Params_initShape_n_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->initShape_n;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_initShape_n_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->initShape_n = val;
    ))
}

CVAPI(int) face_FacemarkLBF_Params_stages_n_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->stages_n;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_stages_n_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->stages_n = val;
    ))
}

CVAPI(int) face_FacemarkLBF_Params_tree_n_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->tree_n;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_tree_n_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->tree_n = val;
    ))
}

CVAPI(int) face_FacemarkLBF_Params_tree_depth_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->tree_depth;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_tree_depth_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->tree_depth = val;
    ))
}

CVAPI(double) face_FacemarkLBF_Params_bagging_overlap_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->bagging_overlap;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_bagging_overlap_set(FacemarkLBF::Params *obj, double val)
{
    EXC_SAFE((
        obj->bagging_overlap = val;
    ))
}

CVAPI(void) face_FacemarkLBF_Params_model_filename_get(FacemarkLBF::Params *obj, std::string *s)
{
    EXC_SAFE((
        *s = obj->model_filename;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_model_filename_set(FacemarkLBF::Params *obj, const char *s)
{
    EXC_SAFE((
        obj->model_filename = s;
    ))
}

CVAPI(int) face_FacemarkLBF_Params_save_model_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->save_model ? 1 : 0;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_save_model_set(FacemarkLBF::Params *obj, int val)
{
    EXC_SAFE((
        obj->save_model = (val != 0);
    ))
}

CVAPI(unsigned int) face_FacemarkLBF_Params_seed_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return obj->seed;
    ))
}
CVAPI(void) face_FacemarkLBF_Params_seed_set(FacemarkLBF::Params *obj, unsigned int val)
{
    EXC_SAFE((
        obj->seed = val;
    ))
}

CVAPI(void) face_FacemarkLBF_Params_feats_m_get(FacemarkLBF::Params *obj, std::vector<int> *v)
{
    EXC_SAFE((
        std::copy(obj->feats_m.begin(), obj->feats_m.end(), std::back_inserter(*v));
    ))
}
CVAPI(void) face_FacemarkLBF_Params_feats_m_set(FacemarkLBF::Params *obj, std::vector<int> *v)
{
    EXC_SAFE((
        obj->feats_m.clear();
        std::copy(v->begin(), v->end(), std::back_inserter(obj->feats_m));
    ))
}

CVAPI(void) face_FacemarkLBF_Params_radius_m_get(FacemarkLBF::Params *obj, std::vector<double> *v)
{
    EXC_SAFE((
        std::copy(obj->radius_m.begin(), obj->radius_m.end(), std::back_inserter(*v));
    ))
}
CVAPI(void) face_FacemarkLBF_Params_radius_m_set(FacemarkLBF::Params *obj, std::vector<double> *v)
{
    EXC_SAFE((
        obj->radius_m.clear();
        std::copy(v->begin(), v->end(), std::back_inserter(obj->radius_m));
    ))
}

CVAPI(void) face_FacemarkLBF_Params_pupils0_get(FacemarkLBF::Params *obj, std::vector<int> *v)
{
    EXC_SAFE((
        std::copy(obj->pupils[0].begin(), obj->pupils[0].end(), std::back_inserter(*v));
    ))
}
CVAPI(void) face_FacemarkLBF_Params_pupils0_set(FacemarkLBF::Params *obj, std::vector<int> *v)
{
    EXC_SAFE((
        obj->pupils[0].clear();
        std::copy(v->begin(), v->end(), std::back_inserter(obj->pupils[0]));
    ))
}

CVAPI(void) face_FacemarkLBF_Params_pupils1_get(FacemarkLBF::Params *obj, std::vector<int> *v)
{
    EXC_SAFE((
        std::copy(obj->pupils[1].begin(), obj->pupils[1].end(), std::back_inserter(*v));
    ))
}
CVAPI(void) face_FacemarkLBF_Params_pupils1_set(FacemarkLBF::Params *obj, std::vector<int> *v)
{
    EXC_SAFE((
        obj->pupils[1].clear();
        std::copy(v->begin(), v->end(), std::back_inserter(obj->pupils[1]));
    ))
}

CVAPI(MyCvRect) face_FacemarkLBF_Params_detectROI_get(FacemarkLBF::Params *obj)
{
    EXC_SAFE((
        return c(obj->detectROI);
    ))
}
CVAPI(void) face_FacemarkLBF_Params_detectROI_set(FacemarkLBF::Params *obj, MyCvRect val)
{
    EXC_SAFE((
        obj->detectROI = cpp(val);
    ))
}


CVAPI(void) face_FacemarkLBF_Params_read(FacemarkLBF::Params *obj, cv::FileNode *fn)
{
    EXC_SAFE((
        obj->read(*fn);
    ))
}

CVAPI(void) face_FacemarkLBF_Params_write(FacemarkLBF::Params *obj, cv::FileStorage *fs)
{
    EXC_SAFE((
        obj->write(*fs);
    ))
}

#pragma endregion
#pragma endregion

#pragma region FacemarkAAM

CVAPI(cv::Ptr<FacemarkAAM>*) face_FacemarkAAM_create(FacemarkAAM::Params *params)
{
    EXC_SAFE((
        const cv::Ptr<FacemarkAAM> obj = (params == nullptr) ?
            FacemarkAAM::create() :
            FacemarkAAM::create(*params);
        return clone(obj);
    ))
}

CVAPI(FacemarkAAM*) face_Ptr_FacemarkAAM_get(cv::Ptr<FacemarkAAM> *obj)
{
    EXC_SAFE((
        return obj->get();
    ))
}

CVAPI(void) face_Ptr_FacemarkAAM_delete(cv::Ptr<FacemarkAAM> *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

#pragma region Params

CVAPI(FacemarkAAM::Params*) face_FacemarkAAM_Params_new()
{
    EXC_SAFE((
        return new FacemarkAAM::Params;
    ))
}

CVAPI(void) face_FacemarkAAM_Params_delete(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        delete obj;
    ))
}

CVAPI(void) face_FacemarkAAM_Params_model_filename_get(FacemarkAAM::Params *obj, std::string *s)
{
    EXC_SAFE((
        *s = obj->model_filename;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_model_filename_set(FacemarkAAM::Params *obj, const char *s)
{
    EXC_SAFE((
        obj->model_filename = s;
    ))
}

CVAPI(int) face_FacemarkAAM_Params_m_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->m;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_m_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->m = val;
    ))
}

CVAPI(int) face_FacemarkAAM_Params_n_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->n;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_n_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->n = val;
    ))
}

CVAPI(int) face_FacemarkAAM_Params_n_iter_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->n_iter;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_n_iter_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->n_iter = val;
    ))
}

CVAPI(int) face_FacemarkAAM_Params_verbose_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->verbose ? 1 : 0;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_verbose_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->verbose = (val != 0);
    ))
}

CVAPI(int) face_FacemarkAAM_Params_save_model_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->save_model ? 1 : 0;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_save_model_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->save_model = (val != 0);
    ))
}

CVAPI(int) face_FacemarkAAM_Params_max_m_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->max_m;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_max_m_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->max_m = val;
    ))
}

CVAPI(int) face_FacemarkAAM_Params_max_n_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->max_n;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_max_n_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->max_n = val;
    ))
}

CVAPI(int) face_FacemarkAAM_Params_texture_max_m_get(FacemarkAAM::Params *obj)
{
    EXC_SAFE((
        return obj->texture_max_m;
    ))
}
CVAPI(void) face_FacemarkAAM_Params_texture_max_m_set(FacemarkAAM::Params *obj, int val)
{
    EXC_SAFE((
        obj->texture_max_m = val;
    ))
}

CVAPI(void) face_FacemarkAAM_Params_scales_get(FacemarkAAM::Params *obj, std::vector<float> *v)
{
    EXC_SAFE((
        std::copy(obj->scales.begin(), obj->scales.end(), std::back_inserter(*v));
    ))
}
CVAPI(void) face_FacemarkAAM_Params_scales_set(FacemarkAAM::Params *obj, std::vector<float> *v)
{
    EXC_SAFE((
        obj->scales.clear();
        std::copy(v->begin(), v->end(), std::back_inserter(obj->scales));
    ))
}


CVAPI(void) face_FacemarkAAM_Params_read(FacemarkAAM::Params *obj, cv::FileNode *fn)
{
    EXC_SAFE((
        obj->read(*fn);
    ))
}

CVAPI(void) face_FacemarkAAM_Params_write(FacemarkAAM::Params *obj, cv::FileStorage *fs)
{
    EXC_SAFE((
        obj->write(*fs);
    ))
}

#pragma endregion
#pragma endregion

#endif