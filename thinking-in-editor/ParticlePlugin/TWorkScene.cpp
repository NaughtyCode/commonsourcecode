#include "TWorkScene.h"
#include "ParticleSystem.h"

TWorkScene::TWorkScene():ParticleLayer(0),
                        ParticleLayerSceneContainer(0)
{
}

TWorkScene::~TWorkScene()
{
    
}

void TWorkScene::CreateParticleLayer()
{
    if(ParticleLayer==0){
		ParticleLayerSceneContainer = cocos2d::Scene::create();
		ParticleLayer = createParticleLayer();
		ParticleLayerSceneContainer->addChild(ParticleLayer);
        cocos2d::Director::getInstance()->runWithScene(ParticleLayerSceneContainer);
    }
}
