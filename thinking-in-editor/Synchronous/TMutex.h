#ifndef TMUTEX_H
#define TMUTEX_H

#include<windows.h>

class TMutex
{
public:
    TMutex();
    ~TMutex();
    void Lock();
    void UnLock();
private:
    CRITICAL_SECTION CS;
};

#endif