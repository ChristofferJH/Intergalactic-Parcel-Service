#ifndef WIN32PLATFORM_H
#define WIN32PLATFORM_H

#include "core.h"
#include "import/win32platformImport.h"
#include "openGL.h"

extern HWND windowHandle;
extern HDC deviceContextHandle;
extern int screenWidth;
extern int screenHeight;

void InitDebugConsole();
bool InitWin32Context(HINSTANCE hInstance);
void ShutdownWin32Context(HINSTANCE hInstance);
void Win32MessageLoop();
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif