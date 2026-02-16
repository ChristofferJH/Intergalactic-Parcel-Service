#include "win32platform.h"


WNDCLASSW windowsClass = { 0 };
MSG msg = { 0 };
LPMSG lpmsg = &msg;
HWND windowHandle = NULL;
HDC deviceContextHandle = NULL;
HGLRC renderingContextHandle = NULL;

//wglCreateContextAttribsARBProc wglCreateContextAttribsARB = NULL;
//wglChoosePixelFormatARBProc wglChoosePixelFormatARB = NULL;

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

bool InitWin32Context(HINSTANCE hinstance)
{
	windowsClass.hInstance = hinstance;
	windowsClass.lpfnWndProc = WndProc;
	windowsClass.lpszClassName = APPNAME_W;
	RegisterClassW(&windowsClass);

	windowHandle = CreateWindowW(APPNAME_W, APPNAME_W, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hinstance, NULL);
	deviceContextHandle = GetDC(windowHandle);

	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int pixelFormat = ChoosePixelFormat(deviceContextHandle, &pfd);
	SetPixelFormat(deviceContextHandle, pixelFormat, &pfd);

	renderingContextHandle = wglCreateContext(deviceContextHandle);

	wglMakeCurrent(deviceContextHandle, renderingContextHandle);

	/*wglGetProcAddress(*/

	return true;
}


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
			DestroyWindow(windowHandle);
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
	wglMakeCurrent(NULL, NULL);
	UnregisterClassW(APPNAME_W, hInstance);
}