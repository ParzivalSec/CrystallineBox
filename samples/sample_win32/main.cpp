#include <cstdio>

#include "../../src/graphics/PlatformWindow/PlatformWindow.h"
#include "../../src/graphics/PlatformWindow/PlatformWindowWindowsImpl.h"

int main(int argc, char** argv)
{
	printf("Hello, Crystallinebox!\n");

	cry::PlatformWindow window(L"ASDF", 1920u, 1080u);


	printf("Window title: %S\n", window.GetTitle());

	return 0;
}