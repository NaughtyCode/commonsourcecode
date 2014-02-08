#include "thread.h"

void* CreateWork(ThreadCallBack_Type callback){
	HANDLE handle;
	handle = (HANDLE)_beginthreadex(NULL,
		0,
		callback,
		0,
		0,
		0);
	assert(handle);
	return (void*)handle;
}

void DestroyWork(void* handle){
	CloseHandle((HANDLE)handle);
}
