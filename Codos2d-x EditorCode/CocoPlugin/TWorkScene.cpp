#include "TWorkScene.h"

USING_NS_CC;

Scene* TWorkScene::scene()
{
    auto scene = Scene::create();
    TWorkScene *layer = TWorkScene::create();
    scene->addChild(layer);
    return scene;
}

bool TWorkScene::init()
{
    if (Layer::init()){
        auto visibleSize = Director::getInstance()->getVisibleSize();
        auto origin = Director::getInstance()->getVisibleOrigin();
        auto sprite = Sprite::create("World.jpg");
        sprite->setPosition(Point(visibleSize / 2) + origin);
        this->addChild(sprite);
        return true;
    }
    return false;
}
