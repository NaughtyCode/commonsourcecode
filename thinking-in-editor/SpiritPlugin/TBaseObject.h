#ifndef TBASELAYER_H
#define TBASELAYER_H

#include "SpiritPlugin.h"

class TBaseObject : public cocos2d::LayerColor
{
public:
    virtual void onEnter();
    virtual void onExit();
    virtual void ProxyLeftDown(Object* sender);
    virtual void ProxyLeftUp(Object* sender);
};

#endif