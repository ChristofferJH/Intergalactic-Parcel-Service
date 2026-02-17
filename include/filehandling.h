#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include "memory.h"

#define MAXPATH 260

extern wchar_t* directory;

char* LoadTextFile(wchar_t* relativePath);
char* LoadTexture(wchar_t* relativePath);

wchar_t* GetFullPath(wchar_t* relativePath);

#endif