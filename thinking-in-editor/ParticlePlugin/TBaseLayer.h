#ifndef BASELAYER_H
#define BASELAYER_H

#include "ParticleIncludes.h"

class TBaseLayer : public cocos2d::Layer
{
public:
    virtual void onEnter();
    virtual void onExit();
    virtual std::string title();
    virtual std::string subtitle();
    virtual void restartCallback(Object* sender);
    virtual void nextCallback(Object* sender);
    virtual void backCallback(Object* sender);
};

#endif
