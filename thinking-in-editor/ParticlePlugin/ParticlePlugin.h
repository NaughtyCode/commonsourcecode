#ifndef PARTICLEPLUGIN_H
#define PARTICLEPLUGIN_H

#include "ParticleIncludes.h"

#ifdef PARTICLEPLUGIN_EXPORTS
#define PARTICLEPLUGINAPI __declspec(dllexport) 
#else
#define PARTICLEPLUGINAPI __declspec(dllimport) 
#endif

#ifdef __cplusplus
extern "C" {
#endif

PARTICLEPLUGINAPI void CreateNonBlockRender(int handle);
PARTICLEPLUGINAPI void CreateBlockRender(int handle);
PARTICLEPLUGINAPI void DestoryRenderEngine();

#ifdef __cplusplus
}
#endif

#endif
