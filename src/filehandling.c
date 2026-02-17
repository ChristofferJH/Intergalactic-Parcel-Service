#include "filehandling.h"

wchar_t* directory = NULL;
size_t directorySize;

#define MAXPATHINWIDECHARS MAXPATH*sizeof(wchar_t)


//filepath format
// L"folder\\folder2\\thing.extension

wchar_t* GetFullPath(wchar_t* relativePath)
{
	wchar_t* combinedpath = (wchar_t*)TempAlloc(MAXPATHINWIDECHARS);
	PathCchCombineEx(combinedpath, MAXPATHINWIDECHARS, directory, relativePath, PATHCCH_NONE);
	return combinedpath;
}

char* LoadTextFile(wchar_t* relativePath)
{

}

char* LoadTexture(wchar_t* relativePath)
{


}
