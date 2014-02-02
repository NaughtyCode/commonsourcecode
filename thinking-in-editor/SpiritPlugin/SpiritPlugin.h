#ifndef  SPIRITPLUGIN_H
#define  SPIRITPLUGIN_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include <CCEventListenerTouch.h>
#include <CCEventKeyboard.h>
#include <CCEGLView.h>
#include <cocos2d.h>
#include <CCStdC.h>

#ifdef SPIRITPLUGIN_EXPORTS
#define SPIRITPLUGINAPI __declspec(dllexport) 
#else
#define SPIRITPLUGINAPI __declspec(dllimport) 
#endif
#ifdef __cplusplus
extern "C" {
#endif

SPIRITPLUGINAPI void CreateNonBlockRender(int handle);
SPIRITPLUGINAPI void CreateBlockRender(int handle);
SPIRITPLUGINAPI void DestoryRenderEngine();

#ifdef __cplusplus
}
#endif

#endif