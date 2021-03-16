#include "Utility.hpp"

#include <windows.h>

void sleep(const unsigned long int milliseconds) {

	TIMECAPS timeCaps;
	timeGetDevCaps(&timeCaps, sizeof(TIMECAPS));

	timeBeginPeriod(timeCaps.wPeriodMin);
	::Sleep(milliseconds);
	timeEndPeriod(timeCaps.wPeriodMin);

}
