#include "TMutex.h"

TMutex::TMutex()
{
    InitializeCriticalSection(&CS);
}

TMutex::~TMutex()
{
    DeleteCriticalSection(&CS);
}

void TMutex::Lock()
{
    EnterCriticalSection(&CS);
}

void TMutex::UnLock()
{
    LeaveCriticalSection(&CS);
}
