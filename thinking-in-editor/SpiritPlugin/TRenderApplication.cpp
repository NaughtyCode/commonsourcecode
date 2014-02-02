#include "TRenderApplication.h"
#include "GlobalData.h"
#include "TBaseObject.h"

USING_NS_CC;

bool TRenderApplication::applicationDidFinishLaunching(){
    Director* director = Director::getInstance();
    EGLView* glView = EGLView::getInstance();
    director->setOpenGLView(glView);
    Size FrameSize = glView->getFrameSize();
    glView->setDesignResolutionSize(900,600,ResolutionPolicy::NO_BORDER);
    director->setDisplayStats(false);
    director->setAnimationInterval(1.0/60);
    SetFilePath(std::string("..\\resource\\"));
    
    Scene* scene = Scene::create();
    TBaseObject * worklayer = new TBaseObject;
    if(worklayer && worklayer->initWithColor(Color4B(0,100,100,255))){
		SetWorkScene((int)worklayer);
	worklayer->setScale(0.35f);
	worklayer->autorelease();
	scene->addChild(worklayer);
    }
    scene->setPositionX(-200);
    scene->setPositionY(100);
    director->runWithScene(scene);
    return true;
}

void TRenderApplication::applicationDidEnterBackground(){
    Director::getInstance()->stopAnimation();
}

void TRenderApplication::applicationWillEnterForeground(){
    Director::getInstance()->startAnimation();
}
