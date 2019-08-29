#ifndef _PLATFORM_WINDOW_WINDOWS_IMPL_H_
#define _PLATFORM_WINDOW_WINDOWS_IMPL_H_

typedef struct HWND__* HWND;

namespace cry
{
	class PlatformWindowWindowsImpl
	{
	public:
		PlatformWindowWindowsImpl(const char* title, unsigned int width, unsigned int height);

		void Show(void) const;
		void Hide(void) const;

		void Resize(unsigned int width, unsigned int height) const;

		void* GetNativeHandle(void) const { return mNativeHandle; }

	private:
		HWND mNativeHandle;
	};
}

#endif // _PLATFORM_WINDOW_WINDOWS_IMPL_H_