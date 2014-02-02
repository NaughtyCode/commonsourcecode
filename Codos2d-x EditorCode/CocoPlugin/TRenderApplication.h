#ifndef  TRENDERAPPLICATION_H
#define  TRENDERAPPLICATION_H

#include "CocoRenderDLL.h"

class TRenderApplication:private cocos2d::Application
{
public:
    TRenderApplication();
    virtual ~TRenderApplication();
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
};

#endif