#ifndef  TRENDERMAIN_H
#define  TRENDERMAIN_H

#include "SpiritPlugin.h"

class  TRenderApplication : private cocos2d::Application
{
public:
    bool applicationDidFinishLaunching();
    void applicationDidEnterBackground();
    void applicationWillEnterForeground();
};

#endif
