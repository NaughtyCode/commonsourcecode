#ifndef TWORKSCENE_H
#define TWORKSCENE_H

#include "ParticlePlugin.h"

class TWorkScene
{
public: 
    TWorkScene();
    ~TWorkScene();
    void CreateParticleLayer();
private:
    cocos2d::Layer* ParticleLayer;
    cocos2d::Scene* ParticleLayerSceneContainer;
};

#endif