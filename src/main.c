#include "main.h"

int wWinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{

	InitDebugConsole();


	running = InitWin32Context(hinstance);
	InitMemory();
	InitTime();
	double lastTime = GetTime();

	ConOut(GetFullPath(L"test\\lul.gq"));


	while(running)
	{
		Win32MessageLoop();

		double currentTime = GetTime();

		double dt = currentTime - lastTime;
		lastTime = currentTime;

		
		Draw();
		SwapBuffers(deviceContextHandle);
	}


	ShutdownWin32Context(hinstance);
	ExitProcess(0);
}