#ifndef _PLATFORM_WINDOW_WINDOWS_H_
#define _PLATFORM_WINDOW_WINDOWS_H_

#include "PlatformWindowBase.h"

namespace cry
{
	class PlatformWindowWindowsImpl;

	using PlatformWindow = PlatformWindowBase<PlatformWindowWindowsImpl>;
}

#endif // _PLATFORM_WINDOW_WINDOWS_H_