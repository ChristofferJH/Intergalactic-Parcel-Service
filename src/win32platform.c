#include "win32platform.h"

int screenWidth = 0;
int screenHeight = 0;

WNDCLASSW windowsClass = { 0 };
MSG msg = { 0 };
LPMSG lpmsg = &msg;
HWND windowHandle = NULL;
HDC deviceContextHandle = NULL;
HGLRC renderingContextHandle = NULL;

HWND dummyWindowHandle = NULL;
HDC dummyDeviceContextHandle = NULL;
HGLRC dummyRenderingContextHandle = NULL;


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

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

#ifdef _DEBUG
	//smaller window in debug mode
	screenWidth = screenWidth / 2;
	screenHeight = screenHeight / 2;
#endif

	dummyWindowHandle = CreateWindowW(APPNAME_W, APPNAME_W, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, NULL, NULL, hinstance, NULL);
	dummyDeviceContextHandle = GetDC(dummyWindowHandle);

	PIXELFORMATDESCRIPTOR dummypfd = { 0 };
	dummypfd.nSize = sizeof(dummypfd);
	dummypfd.nVersion = 1;
	dummypfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	dummypfd.iPixelType = PFD_TYPE_RGBA;
	dummypfd.cColorBits = 32;
	dummypfd.cDepthBits = 24;
	dummypfd.iLayerType = PFD_MAIN_PLANE;

	int dummypixelFormat = ChoosePixelFormat(dummyDeviceContextHandle, &dummypfd);
	SetPixelFormat(dummyDeviceContextHandle, dummypixelFormat, &dummypfd);

	dummyRenderingContextHandle = wglCreateContext(dummyDeviceContextHandle);

	wglMakeCurrent(dummyDeviceContextHandle, dummyRenderingContextHandle);

	LoadOpenGLFunctions();

	wglMakeCurrent(NULL, NULL);
	
	wglDeleteContext(dummyRenderingContextHandle);
	ReleaseDC(dummyWindowHandle, dummyDeviceContextHandle);
	DestroyWindow(dummyWindowHandle);

	windowHandle = CreateWindowW(APPNAME_W, APPNAME_W, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, screenWidth, screenHeight, NULL, NULL, hinstance, NULL);
	deviceContextHandle = GetDC(windowHandle);


	int pixelAttributes[] =
	{
	WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
	WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
	WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
	WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
	WGL_COLOR_BITS_ARB, 32,
	WGL_DEPTH_BITS_ARB, 24,
	WGL_STENCIL_BITS_ARB, 8,
	0
	};

	PIXELFORMATDESCRIPTOR pfd = { 0 };
	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.iLayerType = PFD_MAIN_PLANE;

	int pixelFormat;
	int numberOfFormats;

	wglChoosePixelFormatARB(deviceContextHandle, pixelAttributes, NULL, 1, &pixelFormat, &numberOfFormats);
	DescribePixelFormat(deviceContextHandle, pixelFormat, sizeof(pfd), &pfd);
	SetPixelFormat(deviceContextHandle, pixelFormat, &pfd);

	int contextAttributes[] =
	{
	WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
	WGL_CONTEXT_MINOR_VERSION_ARB, 3,
	WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
	0
	};

	renderingContextHandle = wglCreateContextAttribsARB(deviceContextHandle,0,contextAttributes);

	wglMakeCurrent(deviceContextHandle, renderingContextHandle);

	glSwapInterval(1);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glViewport(0, 0, screenWidth, screenHeight);



	directory = malloc(sizeof(wchar_t) * MAXPATH);
	if (directory)
	{
		GetModuleFileNameW(NULL, directory, MAXPATH);
		PathCchRemoveFileSpec(directory, MAXPATH);

	}
	else {
		FatalError(L"Failed allocating memory");
		return false;
	}

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
	wglDeleteContext(renderingContextHandle);
	ReleaseDC(windowHandle,deviceContextHandle);
	UnregisterClassW(APPNAME_W, hInstance);
	free(directory);
}