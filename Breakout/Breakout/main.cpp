#include "GameCore.h"

int main(void)
{
	GameCore::Instance()->MainLoop();
	GameCore::Release();

	Sleep(10000);
	return 0;
}