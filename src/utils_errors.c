#include "utils/utils_errors.h"

void FatalError(wchar_t* msg, HWND windowHandle)
{
#ifdef _DEBUG
	printf("%ls \n", msg);

#else

	MessageBoxW(windowHandle, (LPCWSTR)msg, L"Fatal Error", MB_OK);
	running = false;
#endif
}