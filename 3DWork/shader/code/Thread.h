#ifndef THREAD_H
#define THREAD_H

#include "DependencyConfig.h"

typedef  unsigned int (__stdcall *ThreadCallBack_Type)(void*);

void* CreateWork(ThreadCallBack_Type callback);
void DestroyWork(void* handle);

#endif