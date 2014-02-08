#ifndef PRIMARYWINDOW_H
#define PRIMARYWINDOW_H

#include "DependencyConfig.h"

void CreatePrimaryWindow(const int width,const int height,const char* name,const int depth);
void MainLoop();
void WindowSwapBuffers();
void DispatchEvent();
void DestroyPrimaryWindow();

#endif