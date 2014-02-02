#include <tbb/tbb_stddef.h>
#include <tbb/atomic.h>
#include <tbb/tick_count.h>
#include <tbb/task_scheduler_init.h>
#include <tbb/task_group.h>

#include <cstdio>
#include <cstdlib>
#include <string>

using namespace tbb;
using namespace std;

tbb::atomic<unsigned> quit;

class Worker1{
public:
	Worker1(){}
	void operator() () const{
		quit+=1;
		printf("Worker1 Over!!!\n");
	}
};

class Worker2{
public:
	Worker2(){}
	void operator() () const{
		quit+=2;
		printf("Worker2 Over!!!\n");
	}
};

class Worker3{
public:
	Worker3(){}
	void operator() () const{
		quit+=3;
		printf("Worker3 Over!!!\n");
	}
};

class Worker4{
public:
	Worker4(){}
	void operator() () const{
		int count=0;
		while(count<1000000){
			quit+=1;
			++count;
		}
		printf("Worker4 Over!!!\n");
	}
};

void ExecWorker() {
	task_scheduler_init init(4);
	quit = 0;
	task_group TaskGroup;
	TaskGroup.run(Worker1());
	TaskGroup.run(Worker2());
	TaskGroup.run(Worker3());
	TaskGroup.run(Worker4());
	TaskGroup.wait();
	printf("resoult: %d\n",quit);
}

int main(int argc, char *argv[]) {
	ExecWorker();
};

