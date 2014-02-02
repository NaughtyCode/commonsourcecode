#ifndef COCORENDERDLL_H
#define COCORENDERDLL_H

#ifdef COCORENDERDLL_EXPORTS
#include "CocosIncludes.h"
#define COCORENDERDLLAPI __declspec(dllexport) 
#else
#define COCORENDERDLLAPI __declspec(dllimport) 
#endif

#include<process.h>

COCORENDERDLLAPI void CreateRenderEngine(int handle);
COCORENDERDLLAPI void RenderFrame();
COCORENDERDLLAPI void DestoryRenderEngine();

#endif
