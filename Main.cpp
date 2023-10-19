#include <vector>
#include <iostream>
#include <fstream>
#include <crtdbg.h>
#include "MenuSystem.h"
int main()
{
#ifdef _DEBUG
	  //_CrtSetBreakAlloc(152);
	_onexit(_CrtDumpMemoryLeaks);
#endif


	MenuSystem::StartApplication();

	return 0;
}
