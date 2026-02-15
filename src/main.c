#include "main.h"
#include "win32platform.h"


int wWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	//makes a good ol' console when compilling in debug mode, does nothing in release mode
	InitDebugConsole();


	//running is a bool localized to core.c, we access it here and in win32platform.c
	running = InitWin32Context(hinstance);
	while(running)
	{


		Win32MessageLoop();
	}


	ExitProcess(0);
}