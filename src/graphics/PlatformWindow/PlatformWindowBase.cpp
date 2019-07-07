#include "PlatformWindowBase.h"

using namespace cry;

template<typename WindowImpl>
PlatformWindowBase<WindowImpl>::PlatformWindowBae(const wchar_t* title, unsigned int width, unsigned int height)
	: mWidth(width)
	, mHeight(height)
{
}