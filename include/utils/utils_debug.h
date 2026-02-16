#ifndef UTILS_DEBUG_H
#define UTILS_DEBUG_H

#include "import/win32platformImport.h"
#include <stdio.h>
#include <stdbool.h>

extern bool running;
extern HWND windowHandle;

void FatalError(wchar_t* msg);
void ConOut(wchar_t* msg);
void ConOutI(wchar_t* msg, int val);
void ConOutD(wchar_t* msg, double val);

#endif