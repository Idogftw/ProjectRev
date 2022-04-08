#include <iostream>
#include <common/Engine.hpp>

#ifdef win32
#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Gateway::Engine* engine = new Gateway::Engine;

	if (!engine->Init())
	{
		return -1;
	}

	engine->Run();

	return 0;
}

#elif linux || macos

int main(int argc, char* argv[])
{
	std::cout << "Hello, World!" << std::endl;
	return 0;
}

#endif // win32