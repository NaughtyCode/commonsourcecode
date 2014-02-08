#include "thread.h"
#include "PrimaryWindow.h"

int main (int argc, char **argv)
{
	CreatePrimaryWindow(1024,900, "world", 32);
	MainLoop();
	return 0;
}
