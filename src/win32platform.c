#include "win32platform.h"


void InitDebugConsole()
{
#ifdef _DEBUG
	AllocConsole();
	FILE* filePtr;
	freopen_s(&filePtr, "CONOUT$", "w", stdout);
	freopen_s(&filePtr, "CONOUT$", "w", stderr);
	freopen_s(&filePtr, "CONIN$", "r", stdin);
#endif

}

WNDCLASSW windowsClass = { 0 };

bool InitWin32Context(HINSTANCE hinstance)
{
	windowsClass.hInstance = hinstance;
	windowsClass.lpfnWndProc = WndProc;
	windowsClass.lpszClassName = APPNAME_W;
	RegisterClassW(&windowsClass);


	return true;
}

MSG msg = { 0 };
LPMSG lpmsg = &msg;

void Win32MessageLoop()
{
	while (PeekMessageW(lpmsg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(lpmsg);
		DispatchMessageW(lpmsg);
	
	}
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{
		case WM_CLOSE:
			running = false;
			//DestroyWindow(windowHandle);
			break;

		case WM_DESTROY:
			running = false;
			PostQuitMessage(0);
			break;
	}
	return DefWindowProcW(hwnd, msg, wParam, lParam);
};


void ShutdownWin32Context(HINSTANCE hInstance)
{
	//wglMakeCurrent(NULL, NULL);
	UnregisterClassW(APPNAME_W, hInstance);
}