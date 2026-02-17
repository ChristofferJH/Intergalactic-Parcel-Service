#include "main.h"

int wWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

	InitDebugConsole();


	running = InitWin32Context(hinstance);

	if (!InitMemory())
	{
		FatalError(L"Error: could not allocate memory");
		running = false;
	}

	InitTime();
	double lastTime = GetTime();
	GotoMainMenu();

	while(running)
	{
		Win32MessageLoop();
	

		double currentTime = GetTime();
		double dt = currentTime - lastTime;
		lastTime = currentTime;

		//do stuff
		
		ProcessEventQueue();

		Draw();
		SwapBuffers(deviceContextHandle);
	}


	ShutdownWin32Context(hinstance);
	ExitProcess(0);
}