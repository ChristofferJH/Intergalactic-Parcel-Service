#ifndef MEMORY_H
#define MEMORY_H

#include "core.h"
#include "win32platform.h"

bool InitMemory();
void FreeAllMemory();

unsigned char* TempAlloc(size_t size);
void ClearTempAlloc();

extern unsigned char* entityMemory;

#endif