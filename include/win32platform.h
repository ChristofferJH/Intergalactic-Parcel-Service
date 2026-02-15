#ifndef WIN32PLATFORM_H
#define WIN32PLATFORM_H

#include "core.h"
#include "win32platformImport.h"

#define APPNAME_W L"Intergalactic Parcel Service"

extern HWND windowHandle;
extern HDC deviceContextHandle;

void InitDebugConsole();
bool InitWin32Context(HINSTANCE hInstance);
void ShutdownWin32Context(HINSTANCE hInstance);
void Win32MessageLoop();
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif