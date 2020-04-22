#include "GameCore.h"

int main(void)
{
	GameCore::Instance()->MainLoop();
	GameCore::Release();

	return 0;
}