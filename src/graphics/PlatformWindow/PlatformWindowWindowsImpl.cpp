#include "PlatformWindowWindowsImpl.h"

using namespace cry;

#include <Windows.h>

PlatformWindowWindowsImpl::PlatformWindowWindowsImpl(const char* title, unsigned int width, unsigned int height)
{
	WNDCLASS winClass = {};

	winClass.hInstance = GetModuleHandle(nullptr);
	winClass.lpfnWndProc = DefWindowProc;
	winClass.lpszClassName = L"PlatformWindowWindowsImplClass";

	RegisterClass(&winClass);

	RECT rc = { 0, 0, static_cast<long>(width), static_cast<long>(height) };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	mNativeHandle = CreateWindow(
		L"PlatformWindowWindowsImplClass",
		L"Title",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, // X pos
		CW_USEDEFAULT, // Y pos
		rc.right - rc.left, // width
		rc.bottom - rc.top, // height
		NULL,
		NULL,
		GetModuleHandle(nullptr),
		NULL
	);
}

void PlatformWindowWindowsImpl::Show(void) const
{
	ShowWindow(mNativeHandle, SW_SHOW);
}

void PlatformWindowWindowsImpl::Hide(void) const
{
	ShowWindow(mNativeHandle, SW_HIDE);
}

void PlatformWindowWindowsImpl::Resize(unsigned int width, unsigned int height) const
{
	RECT wndRc = {};
	GetWindowRect(mNativeHandle, &wndRc);

	RECT clientRc = {};
	GetClientRect(mNativeHandle, &clientRc);

	clientRc.right = static_cast<long>(width);
	clientRc.bottom = static_cast<long>(height);

	AdjustWindowRect(&clientRc, WS_OVERLAPPEDWINDOW, FALSE);

	clientRc.left = wndRc.left;
	clientRc.top = wndRc.top;

	SetWindowPos(
		mNativeHandle,
		nullptr,
		clientRc.top,
		clientRc.left,
		clientRc.right,
		clientRc.bottom,
		SWP_SHOWWINDOW
	);
}
