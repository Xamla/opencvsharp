#ifndef _CPP_CORE_MATEXPR_H_
#define _CPP_CORE_MATEXPR_H_

#include "include_opencv.h"

CVAPI(cv::MatExpr*) core_MatExpr_new1()
{
    EXC_SAFE((
        return new cv::MatExpr();
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_new2(cv::Mat *mat)
{
    EXC_SAFE((
        return new cv::MatExpr(*mat);
    ))
}
CVAPI(void) core_MatExpr_delete(cv::MatExpr *self)
{
    EXC_SAFE((
        delete self;
    ))
}

CVAPI(cv::Mat*) core_MatExpr_toMat(cv::MatExpr *self)
{
    EXC_SAFE((
        cv::Mat ret = (*self);
        return new cv::Mat(ret);
    ))
}

#pragma region Functions
CVAPI(cv::MatExpr*) core_MatExpr_row(cv::MatExpr *self, int y)
{
    EXC_SAFE((
        cv::MatExpr ret = self->row(y);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_col(cv::MatExpr *self, int x)
{
    EXC_SAFE((
        cv::MatExpr ret = self->col(x);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_diag1(cv::MatExpr *self)
{
    EXC_SAFE((
        cv::MatExpr ret = self->diag();
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_diag2(cv::MatExpr *self, int d)
{
    EXC_SAFE((
        cv::MatExpr ret = self->diag(d);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_submat(cv::MatExpr *self, int rowStart, int rowEnd, int colStart, int colEnd) 
{
    EXC_SAFE((
        cv::Range rowRange(rowStart, rowEnd);
        cv::Range colRange(colStart, colEnd);
        cv::MatExpr ret = (*self)(rowRange, colRange);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::Mat*) core_MatExpr_cross(cv::MatExpr *self, cv::Mat *m) 
{
    EXC_SAFE((
        cv::Mat ret = self->cross(*m);
        return new cv::Mat(ret);
    ))
}
CVAPI(double) core_MatExpr_dot(cv::MatExpr *self, cv::Mat *m) 
{
    EXC_SAFE((
        return self->dot(*m);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_t(cv::MatExpr *self) 
{
    EXC_SAFE((
        cv::MatExpr ret = self->t();
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_inv1(cv::MatExpr *self) 
{
    EXC_SAFE((
        cv::MatExpr ret = self->inv();
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_inv2(cv::MatExpr *self, int method) 
{
    EXC_SAFE((
        cv::MatExpr ret = self->inv(method);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_mul_toMatExpr(cv::MatExpr *self, cv::MatExpr *e, double scale) 
{
    EXC_SAFE((
        cv::MatExpr ret = self->mul(*e, scale);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_MatExpr_mul_toMat(cv::MatExpr *self, cv::Mat *m, double scale) 
{
    EXC_SAFE((
        cv::MatExpr ret = self->mul(*m, scale);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(MyCvSize) core_MatExpr_size(cv::MatExpr *self)
{
    EXC_SAFE((
        return c(self->size());
    ))
}
CVAPI(int) core_MatExpr_type(cv::MatExpr *self)
{
    EXC_SAFE((
        return self->type();
    ))
}
#pragma endregion

#pragma region Operators
CVAPI(cv::MatExpr*) core_operatorUnaryMinus_MatExpr(cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr expr = -(*e);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorUnaryNot_MatExpr(cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr expr = ~(*e);
        return new cv::MatExpr(expr);
    ))
}

CVAPI(cv::MatExpr*) core_operatorAdd_MatExprMat(cv::MatExpr *e, cv:: Mat *m)
{
    EXC_SAFE((
        cv::MatExpr expr = (*e) + (*m);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorAdd_MatMatExpr(cv::Mat *m, cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr expr = (*m) + (*e);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorAdd_MatExprScalar(cv::MatExpr *e, CvScalar s)
{
    EXC_SAFE((
        cv::MatExpr expr = s + (*e);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorAdd_ScalarMatExpr(CvScalar s, cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr expr = (*e) + s;
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorAdd_MatExprMatExpr(cv::MatExpr *e1, cv::MatExpr *e2)
{
    EXC_SAFE((
        cv::MatExpr expr = (*e1) + (*e2);
        return new cv::MatExpr(expr);
    ))
}

CVAPI(cv::MatExpr*) core_operatorSubtract_MatExprMat(cv::MatExpr *e, cv::Mat *m)
{
    EXC_SAFE((
        cv::MatExpr expr = (*e) - (*m);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorSubtract_MatMatExpr(cv::Mat *m, cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr expr = (*m) - (*e);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorSubtract_MatExprScalar(cv::MatExpr *e, CvScalar s)
{
    EXC_SAFE((
        cv::MatExpr expr = s - (*e);
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorSubtract_ScalarMatExpr(CvScalar s, cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr expr = (*e) - s;
        return new cv::MatExpr(expr);
    ))
}
CVAPI(cv::MatExpr*) core_operatorSubtract_MatExprMatExpr(cv::MatExpr *e1, cv::MatExpr *e2)
{
    EXC_SAFE((
        cv::MatExpr expr = (*e1) - (*e2);
        return new cv::MatExpr(expr);
    ))
}

CVAPI(cv::MatExpr*) core_operatorMultiply_MatExprMat(cv::MatExpr *e, cv::Mat *m)
{
    EXC_SAFE((
        cv::MatExpr ret = (*e) * (*m);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorMultiply_MatMatExpr(cv::Mat *m, cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr ret = (*m) * (*e);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorMultiply_MatExprDouble(cv::MatExpr *e, double s)
{
    EXC_SAFE((
        cv::MatExpr ret = (*e) * s;
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorMultiply_DoubleMatExpr(double s, cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr ret = s * (*e);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorMultiply_MatExprMatExpr(cv::MatExpr *e1, cv::MatExpr *e2)
{
    EXC_SAFE((
        cv::MatExpr ret = (*e1) * (*e2);
        return new cv::MatExpr(ret);
    ))
}

CVAPI(cv::MatExpr*) core_operatorDivide_MatExprMat(cv::MatExpr *e, cv::Mat *m)
{ 
    EXC_SAFE((
        cv::MatExpr ret = (*e) / (*m);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorDivide_MatMatExpr(cv::Mat *m, cv::MatExpr *e) 
{ 
    EXC_SAFE((
        cv::MatExpr ret = (*m) / (*e);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorDivide_MatExprDouble(cv::MatExpr *e, double s) 
{ 
    EXC_SAFE((
        cv::MatExpr ret = (*e) / s;
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorDivide_DoubleMatExpr(double s, cv::MatExpr *e) 
{ 
    EXC_SAFE((
        cv::MatExpr ret = s / (*e);
        return new cv::MatExpr(ret);
    ))
}
CVAPI(cv::MatExpr*) core_operatorDivide_MatExprMatExpr(cv::MatExpr *e1, cv::MatExpr *e2) 
{ 
    EXC_SAFE((
        cv::MatExpr ret = (*e1) / (*e2);
        return new cv::MatExpr(ret);
    ))
}
#pragma endregion

CVAPI(cv::MatExpr*) core_abs_MatExpr(cv::MatExpr *e)
{
    EXC_SAFE((
        cv::MatExpr ret = cv::abs(*e);
        return new cv::MatExpr(ret);
    ))
}

#endif