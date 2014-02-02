#ifndef GLOBALSETTING_H
#define GLOBALSETTING_H

#include "ControlHeaders.h"

const std::string GetEditorResourcePath(const std::string& filename);

void SetEditorResourcePath(const std::string& pathname);

const std::string GetGameResourcePath(const std::string& filename);

void SetGameResourcePath(const std::string& pathname);

void PushEditorMessage(int key, const std::string& message);
void GetEngineMessage(int key,std::string& message);

void CreateRenderEngine(int handle);
void DestroyRenderEngine();

#endif