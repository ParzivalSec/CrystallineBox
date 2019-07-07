#ifndef _PLATFORM_WINDOW_WINDOWS_IMPL_H_
#define _PLATFORM_WINDOW_WINDOWS_IMPL_H_

namespace cry
{
	class PlatformWindowWindowsImpl
	{
	public:
		PlatformWindowWindowsImpl(const wchar_t* title, unsigned int width, unsigned int height);

		void* GetNativeHandle(void) { return mNativeHandle; }

	private:
		void* mNativeHandle;
	};
}

#endif // _PLATFORM_WINDOW_WINDOWS_IMPL_H_