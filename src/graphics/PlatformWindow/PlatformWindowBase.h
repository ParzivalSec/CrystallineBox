#ifndef _PLATFORM_WINDOW_BASE_H_
#define _PLATFORM_WINDOW_BASE_H_

namespace cry
{
	template<typename WindowImpl>
	class PlatformWindowBase
	{
	public:
		PlatformWindowBase(const char* title, unsigned int width, unsigned int height);

		void Show(void) const { mImpl->Show(); }
		void Hide(void) const { mImpl->Hide(); }

		void Resize(unsigned int width, unsigned int height);

		unsigned int GetWidth(void) const { return mWidth; }
		unsigned int GetHeight(void) const { return mHeight; }
		const char* GetTitle(void) const { return mTitle; }

		void* GetNativeHandle(void) const { return mImpl->GetNativeHandle(); }

	private:
		
		unsigned int mWidth;
		unsigned int mHeight;
		
		const char* mTitle;

		WindowImpl* mImpl;
	};

	template<typename WindowImpl>
	PlatformWindowBase<WindowImpl>::PlatformWindowBase(const char* title, unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
		, mTitle(title)
	{
		mImpl = new WindowImpl(title, width, height);
	}

	template<typename WindowImpl>
	void PlatformWindowBase<WindowImpl>::Resize(unsigned int width, unsigned int height)
	{
		mImpl->Resize(width, height);

		mWidth = width;
		mHeight = height;
	}
}

#endif // _PLATFORM_WINDOW_BASE_H_