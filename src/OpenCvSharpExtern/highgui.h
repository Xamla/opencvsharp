#ifndef _CPP_HIGHGUI_H_
#define _CPP_HIGHGUI_H_

#include "include_opencv.h"

CVAPI(void) highgui_namedWindow(const char *winname, int flags)
{
    EXC_SAFE((
        cv::namedWindow(winname, flags);
    ))
}
CVAPI(void) highgui_destroyWindow(const char *winName)
{
    EXC_SAFE((
        cv::destroyWindow(winName);
    ))
}
CVAPI(void) highgui_destroyAllWindows()
{
    EXC_SAFE((
        cv::destroyAllWindows();
    ))
}
CVAPI(void) highgui_imshow(const char *winname, cv::Mat *mat)
{
    EXC_SAFE((
        cv::imshow(winname, *mat);
    ))
}

CVAPI(int) highgui_startWindowThread()
{
    EXC_SAFE((
        return cv::startWindowThread();
    ))
}
CVAPI(int) highgui_waitKey(int delay)
{
    EXC_SAFE((
        return cv::waitKey(delay);
    ))
}
CVAPI(int) highgui_waitKeyEx(int delay)
{
    EXC_SAFE((
        return cv::waitKeyEx(delay);
    ))
}

CVAPI(void) highgui_resizeWindow(const char *winName, int width, int height)
{
    EXC_SAFE((
        cv::resizeWindow(winName, width, height);
    ))
}
CVAPI(void) highgui_moveWindow(const char *winName, int x, int y)
{
    EXC_SAFE((
        cv::moveWindow(winName, x, y);
    ))
}

CVAPI(void) highgui_setWindowProperty(const char *winName, int propId, double propValue)
{
    EXC_SAFE((
        cv::setWindowProperty(winName, propId, propValue);
    ))
}

CVAPI(void) highgui_setWindowTitle(const char *winname, const char *title)
{
    EXC_SAFE((
        cv::setWindowTitle(winname, title);
    ))
}

CVAPI(double) highgui_getWindowProperty(const char *winName, int propId)
{
    EXC_SAFE((
        return cv::getWindowProperty(winName, propId);
    ))
}

CVAPI(void) highgui_setMouseCallback(const char *winName, cv::MouseCallback onMouse, void* userData)
{
    EXC_SAFE((
        cv::setMouseCallback(winName, onMouse, userData);
    ))
}

CVAPI(int) highgui_getMouseWheelDelta(int flags)
{
    EXC_SAFE((
        return cv::getMouseWheelDelta(flags);
    ))
}

CVAPI(int) highgui_createTrackbar(const char *trackbarName, const char *winName,
    int* value, int count, cv::TrackbarCallback onChange, void* userData)
{
    EXC_SAFE((
        return cv::createTrackbar(trackbarName, winName, value, count, onChange, userData);
    ))
}
CVAPI(int) highgui_getTrackbarPos(const char *trackbarName, const char *winName)
{
    EXC_SAFE((
        return cv::getTrackbarPos(trackbarName, winName);
    ))
}
CVAPI(void) highgui_setTrackbarPos(const char *trackbarName, const char *winName, int pos)
{
    EXC_SAFE((
        cv::setTrackbarPos(trackbarName, winName, pos);
    ))
}

CVAPI(void) highgui_setTrackbarMax(const char *trackbarname, const char *winname, int maxval)
{
    EXC_SAFE((
        cv::setTrackbarMax(trackbarname, winname, maxval);
    ))
}
CVAPI(void) highgui_setTrackbarMin(const char *trackbarname, const char *winname, int minval)
{
    EXC_SAFE((
        cv::setTrackbarMin(trackbarname, winname, minval);
    ))
}


CVAPI(int) highgui_createButton(const char *bar_name, cv::ButtonCallback on_change,
    void* userdata, int type, int initial_button_state)
{
    EXC_SAFE((
        return cv::createButton(bar_name, on_change, userdata, type, initial_button_state != 0);
    ))
}

#endif