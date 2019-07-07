#ifndef _PLATFORM_WINDOW_H_
#define _PLATFORM_WINDOW_H_

#if defined(PLATFORM_WIN32)
	#include "PlatformWindowWindows.h"
#else
	#error Unsupported platform
#endif

#endif // _PLATFORM_WINDOW_H_