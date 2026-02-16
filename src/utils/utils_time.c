#include "utils/utils_time.h"


LARGE_INTEGER freq = { 0 };
LARGE_INTEGER counter = { 0 };
double lastTime=0;
double secondsPerTick = 0;

void InitTime()
{
	QueryPerformanceFrequency(&freq);
	secondsPerTick = 1.0 / (double)freq.QuadPart;
}

double GetTime()
{
	QueryPerformanceCounter(&counter);
	return (double)counter.QuadPart*secondsPerTick;
}