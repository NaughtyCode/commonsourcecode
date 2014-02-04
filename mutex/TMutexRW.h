#ifndef TMUTEXRW_H
#define TMUTEXRW_H

class TMutexRW
{
public:
    TMutexRW();
    ~TMutexRW();
    void WriteLock();
	void WriteUnLock();
	void ReadLock();
	void ReadUnLock();
private:
	RTL_SRWLOCK RWLock;
};

#endif