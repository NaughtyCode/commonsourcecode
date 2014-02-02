#include "TWorkScene.h"
#include "TRenderApplication.h"

USING_NS_CC;

TRenderApplication::TRenderApplication():WorkScene(){

}

TRenderApplication::~TRenderApplication() 
{
}

bool TRenderApplication::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glView = EGLView::getInstance();
    director->setOpenGLView(glView);
    glView->setDesignResolutionSize(900,600, ResolutionPolicy::NO_BORDER);
    Size frameSize = glView->getFrameSize();
    std::vector<std::string> searchPath;
    searchPath.push_back("..\\resource\\Particle");
    FileUtils::getInstance()->setSearchPaths(searchPath);
    director->setDisplayStats(false);
    director->setAnimationInterval(1.0 / 60);
    WorkScene.CreateParticleLayer();
    return true;
}

void TRenderApplication::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void TRenderApplication::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
