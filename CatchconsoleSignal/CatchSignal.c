#include <stdio.h>
#include <stdlib.h>

#if defiend(WIN32)
#include <windows.h>
BOOL WINAPI SignalHandler(DWORD dwCtrlType)
{
	if(dwCtrlType == CTRL_C_EVENT)
	{
		printf("Ctrl + C has been pressed.\n");
	}else
	{
		exit(0);
	}
}

void SetSignalCallBack(){
	SetConsoleCtrlHandler(SignalHandler, TRUE);
}

#else
#include <signal.h>

void SignalHandler(int s){
	printf("Caught signal %d\n",s);
	exit(1); 

}

void SetSignalCallBack(){
	static struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = SignalHandler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT, &sigIntHandler, NULL);
}

#endif


// test
int main(int argc, char *argv[])
{
	SetSignalCallBack();
	while(true){}
	return 0;
}
