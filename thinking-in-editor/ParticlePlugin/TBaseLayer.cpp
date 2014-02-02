#include "TBaseLayer.h"
#include "VisibleRect.h"
#include "Resource.h"

USING_NS_CC;

void TBaseLayer::onEnter()
{
	Layer::onEnter();
}

void TBaseLayer::onExit()
{
	Layer::onExit();
}

std::string TBaseLayer::title()
{
	return "";
}

std::string TBaseLayer::subtitle()
{
	return "";
}

void TBaseLayer::restartCallback(Object* sender)
{
}

void TBaseLayer::nextCallback(Object* sender)
{
}

void TBaseLayer::backCallback(Object* sender)
{
}
