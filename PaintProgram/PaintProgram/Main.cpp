#include <Windows.h>
#include <crtdbg.h>
#include "DrawingTool.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#ifdef _DEBUG
	//_CrtSetBreakAlloc();
	_onexit(_CrtDumpMemoryLeaks);
#endif

	DrawingTool drawingtool(hInstance);
	Information::DeleteInstance();
	return 0;
}