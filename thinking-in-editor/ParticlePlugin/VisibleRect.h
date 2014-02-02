#ifndef VISIBLERECT_H
#define VISIBLERECT_H

#include "ParticleIncludes.h"

USING_NS_CC;

class VisibleRect
{
public:
    static Rect getVisibleRect();
    static Point left();
    static Point right();
    static Point top();
    static Point bottom();
    static Point center();
    static Point leftTop();
    static Point rightTop();
    static Point leftBottom();
    static Point rightBottom();
private:
    static void lazyInit();
    static Rect s_visibleRect;
};

#endif
