#include "memory.h"

#define TEMPMEMORYSIZE 1024
#define ENTITYMEMORYSIZE 1024

unsigned char* tempMemory = NULL;
size_t tempAllocHead = 0;

unsigned char* entityMemory;

bool InitMemory()
{
	tempMemory = (unsigned char*)VirtualAlloc(NULL, TEMPMEMORYSIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	entityMemory = (unsigned char*)VirtualAlloc(NULL, ENTITYMEMORYSIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	if ((tempMemory != 0) && (entityMemory != 0))
	{
		return true;
	}
	else
	{
		FatalError(L"Error: Failed allocating memory");
		return false;
	}
}


void FreeAllMemory()
{

	VirtualFree(entityMemory, 0, MEM_RELEASE);
	VirtualFree(tempMemory, 0, MEM_RELEASE);

}

unsigned char* TempAlloc(size_t size)
{
	if (tempAllocHead + size >= TEMPMEMORYSIZE)
	{
		FatalError(L"Error: Temp memory overflow");
		return NULL;
	}

	unsigned char* ptr = tempMemory + tempAllocHead;
	tempAllocHead += size;
	return ptr;
}


void ClearTempAlloc()
{

	tempAllocHead = 0;
}
