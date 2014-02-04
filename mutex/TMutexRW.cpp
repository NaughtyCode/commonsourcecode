#include<windows.h>
#include "TMutexRW.h"

TMutexRW::TMutexRW()
{
	InitializeSRWLock(&RWLock);
}

TMutexRW::~TMutexRW()
{
}

void TMutexRW::WriteLock()
{
	AcquireSRWLockExclusive(&RWLock);
}

void TMutexRW::WriteUnLock()
{
	ReleaseSRWLockExclusive(&RWLock);
}

void TMutexRW::ReadLock()
{
	AcquireSRWLockShared(&RWLock);
}

void TMutexRW::ReadUnLock()
{
	ReleaseSRWLockShared(&RWLock);
}

