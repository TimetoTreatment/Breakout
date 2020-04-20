#include "IntroScreen.h"




IntroScreen::IntroScreen()
{
	_teamLogo = layoutManager->New("teamLogo.txt", { config->Width() / 2, 14 }, "white");
	_gameLogo = layoutManager->New("gameLogo.txt", { config->Width() / 2, 35 }, "green");

	timer.Reset();
	draw = false;
}









