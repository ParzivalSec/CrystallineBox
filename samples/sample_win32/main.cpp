#include <cstdio>

#include "../../src/graphics/PlatformWindow/PlatformWindowWindowsImpl.h"
#include "../../src/graphics/PlatformWindow/PlatformWindow.h"

#include <Windows.h>

LRESULT CALLBACK MessageProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int main(int argc, char** argv)
{
	printf("Hello, Crystallinebox!\n");

	cry::PlatformWindow window("Sample Win32", 1920u, 1080u);

	window.Show();

	SetWindowLongPtr(reinterpret_cast<HWND>(window.GetNativeHandle()), -4, reinterpret_cast<LONG_PTR>(&MessageProc));

	// Main message loop
	MSG msg = { nullptr };
	while (WM_QUIT != msg.message)
	{
		if (msg.message == WM_KEYDOWN)
		{
			if (msg.wParam == VK_SPACE)
			{
				if (window.GetWidth() == 1280u)
				{
					window.Resize(1920u, 1080u);
				}
				else
				{
					window.Resize(1280u, 720u);
				}

				printf("Size: %d x %d\n", window.GetWidth(), window.GetHeight());
			}
			else if (msg.wParam == VK_RETURN)
			{
				window.Hide();
			}
		}

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
		}
	}

	return 0;
}

LRESULT CALLBACK MessageProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		case WM_SIZE:
		{
			return 0;
		}

		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}