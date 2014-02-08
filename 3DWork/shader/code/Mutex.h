#ifndef MUTEX_H
#define MUTEX_H

#include "DependencyConfig.h"

class mutex_type
{
public:
	mutex_type();
	virtual ~mutex_type();
	void CreateLock();
	void DestroyLock();
	void Lock();
	void UnLock();
	
private:
	CRITICAL_SECTION CS;
};

#endif