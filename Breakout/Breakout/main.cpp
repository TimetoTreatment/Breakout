#include "GameMain.h"

int main(void)
{
	GameMain::Instance()->MainLoop();
	GameMain::Release();

	return 0;
}