#include "mutex.h"

mutex_type::mutex_type()
{
	
}

mutex_type::~mutex_type()
{
	
}

void mutex_type::CreateLock()
{
	InitializeCriticalSection(&CS);
}

void mutex_type::DestroyLock()
{
	DeleteCriticalSection(&CS);
}

void mutex_type::Lock()
{
	EnterCriticalSection(&CS);
}

void mutex_type::UnLock()
{
	LeaveCriticalSection(&CS);
}
