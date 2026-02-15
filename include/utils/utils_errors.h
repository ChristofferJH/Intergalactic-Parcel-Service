#ifndef UTILS_ERRORS_H
#define UTILS_ERRORS_H

#include "win32platformImport.h"
#include <stdio.h>
#include <stdbool.h>

extern bool running;


void FatalError(wchar_t* msg, HWND windowHandle);

#endif