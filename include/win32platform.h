#ifndef WIN32PLATFORM_H
#define WIN32PLATFORM_H

#include "core.h"
#include "win32platformImport.h"

#define APPNAME_W L"Intergalactic Parcel Service"

extern HWND windowHandle;

void InitDebugConsole();
bool InitWin32Context(HINSTANCE hinstance);
void ShutdownWin32Context();
void Win32MessageLoop();
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

#endif