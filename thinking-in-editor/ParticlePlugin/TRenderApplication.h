#ifndef  TRENDERAPPLICATION_H
#define  TRENDERAPPLICATION_H

#include "TWorkScene.h"
#include "ParticlePlugin.h"

class TRenderApplication:private cocos2d::Application
{
public:
    TRenderApplication();
    ~TRenderApplication();
    bool applicationDidFinishLaunching();
    void applicationDidEnterBackground();
    void applicationWillEnterForeground();
    
private:
	TWorkScene WorkScene;
};

#endif