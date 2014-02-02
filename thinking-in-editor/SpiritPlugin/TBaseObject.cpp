#include "TVisibleRect.h"
#include "TBaseObject.h"
#include "GlobalData.h"

USING_NS_CC;

void TBaseObject::onEnter()
{
    LayerColor::onEnter();
    
    MenuItemImage* item = MenuItemImage::create("GameRes//interface//playnormal.png","GameRes//interface//playselected.png",CC_CALLBACK_1(TBaseObject::ProxyLeftDown, this));
    Menu* menu = Menu::create(item,NULL,NULL,NULL);
    menu->setPosition(Point::ZERO);
    item->setPosition(Point(TVisibleRect::center().x, TVisibleRect::center().y + item->getContentSize().height / 2));
    this->addChild(menu,9999);
}

void TBaseObject::onExit()
{
    LayerColor::onExit();
}

void TBaseObject::ProxyLeftDown(Object* sender)
{

}

void TBaseObject::ProxyLeftUp(Object* sender)
{
    
}
