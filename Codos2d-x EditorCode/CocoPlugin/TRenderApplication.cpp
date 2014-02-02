#include "TRenderApplication.h"
#include "TWorkScene.h"

USING_NS_CC;
using namespace std;

TRenderApplication::TRenderApplication() {

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
    vector<string> searchPath;
    searchPath.push_back("Data\\");
    FileUtils::getInstance()->setSearchPaths(searchPath);
    director->setDisplayStats(false);
    director->setAnimationInterval(1.0 / 60);
    auto scene = TWorkScene::scene();
    director->runWithScene(scene);
    return true;
}

void TRenderApplication::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
}

void TRenderApplication::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
}
