#ifndef TWORKSCENE_H
#define TWORKSCENE_H

#include "CocoRenderDLL.h"

class TWorkScene:public cocos2d::Layer
{
public:
    virtual bool init();
    static cocos2d::Scene* scene();
    CREATE_FUNC(TWorkScene);
};

#endif