#ifndef TMUTEXCS_H
#define TMUTEXCS_H

#include<windows.h>

class TMutexCS
{
public:
    TMutexCS();
    ~TMutexCS();
    void Lock();
    void UnLock();
private:
    CRITICAL_SECTION CS;
};

#endif