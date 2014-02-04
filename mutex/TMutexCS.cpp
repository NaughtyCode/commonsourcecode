#include "TMutexCS.h"

TMutexCS::TMutexCS()
{
    InitializeCriticalSection(&CS);
}

TMutexCS::~TMutexCS()
{
    DeleteCriticalSection(&CS);
}

void TMutexCS::Lock()
{
    EnterCriticalSection(&CS);
}

void TMutexCS::UnLock()
{
    LeaveCriticalSection(&CS);
}
