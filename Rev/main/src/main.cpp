#include <iostream>
#include <common/Engine.hpp>

#ifdef win32
#include <Windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Gateway::Engine* engine = new Gateway::Engine;

	if (!engine->Init(lpCmdLine))
	{
		return -1;
	}

	engine->Run();

	delete engine;

	return 0;
}

#elif linux || macos

int main(int argc, char* argv[])
{
	Gateway::Engine* engine = new Gateway::Engine;

	if (!engine->Init(argc, argv))
	{
		return -1;
	}

	engine->Run();

	delete engine;

	return 0;
}

#endif // win32