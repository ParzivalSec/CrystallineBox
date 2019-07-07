#ifndef _PLATFORM_WINDOW_BASE_H_
#define _PLATFORM_WINDOW_BASE_H_

namespace cry
{
	template<typename WindowImpl>
	class PlatformWindowBase
	{
	public:
		PlatformWindowBase(const wchar_t* title, unsigned int width, unsigned int height);

		unsigned int GetWidth(void) const { return mWidth; }
		unsigned int GetHeight(void) const { return mHeight; }
		const wchar_t* GetTitle(void) const { return mTitle; }

		void* GetNativeHandle(void) { return mImpl->GetNativeHandle(); }

	private:
		
		unsigned int mWidth;
		unsigned int mHeight;
		
		const wchar_t* mTitle;

		WindowImpl* mImpl;
	};

	template<typename WindowImpl>
	inline PlatformWindowBase<WindowImpl>::PlatformWindowBase(const wchar_t * title, unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
		, mTitle(title)
	{
		mImpl = new WindowImpl(title, width, height);
	}
}

#endif // _PLATFORM_WINDOW_BASE_H_