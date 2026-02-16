#include "utils/utils_debug.h"

void FatalError(wchar_t* msg)
{
#ifdef _DEBUG
	printf("%ls \n", msg);

#else

	MessageBoxW(windowHandle, (LPCWSTR)msg, L"Fatal Error", MB_OK);
	running = false;
#endif
}

void ConOut(wchar_t* msg)
{
#ifdef _DEBUG

	printf("%ls \n", msg);

#endif
};


void ConOutI(wchar_t* msg, int val)
{
#ifdef _DEBUG

	printf("%ls %d \n", msg, val);

#endif
};


void ConOutD(wchar_t* msg, double val)
{
#ifdef _DEBUG

	printf("%ls %f \n", msg, val);

#endif
};