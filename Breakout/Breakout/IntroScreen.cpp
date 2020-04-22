#include "IntroScreen.h"


IntroScreen::IntroScreen()
{
	_teamLogo = layoutManager->New("teamLogo.txt", { config->Width() / 2, 8 }, "white");
	_teamBoard = layoutManager->New("teamBoard.txt", { config->Width() / 2, 18 }, "white");
	_teamMember = layoutManager->New("teamMember.txt", { config->Width() / 2, 18 }, "white");
	_gameLogo = layoutManager->New("gameLogo.txt", { config->Width() / 2, 35 }, "blue");
	_startPrompt = layoutManager->New("Press Enter to Start", { config->Width() / 2 + 1, 18 }, "black");

	_teamLogo->Visible(false);
	_teamBoard->Visible(false);
	_teamMember->Visible(false);
	_gameLogo->Visible(false);
	_startPrompt->Visible(false);

	layoutTimer = new Timer;
	colorTimer = new Timer;
}


IntroScreen::~IntroScreen()
{
	delete layoutTimer;
	delete colorTimer;
}


void IntroScreen::Update()
{
	if (Active() == false)
	{
		_teamLogo->Visible(false);
		_teamBoard->Visible(false);
		_teamMember->Visible(false);
		_gameLogo->Visible(false);
		_startPrompt->Visible(false);

		return;
	}

	if (layoutTimer->GetDeltaTime() > 1000)
	{
		AudioManager::Instance()->PlayMusic("clearSky.ogg");

		_teamLogo->Visible(true);
		_teamBoard->Visible(true);
		_teamMember->Visible(true);
	}

	if (layoutTimer->GetDeltaTime() > 5000)
	{
		_gameLogo->Visible(true);
	}

	if (layoutTimer->GetDeltaTime() > 9000)
	{
		_teamMember->Visible(false);
		_startPrompt->Visible(true);

		if (colorTimer->GetDeltaTime() > 500)
		{
			_startPrompt->Color("blue");

			colorTimer->Reset();
		}
	}
}


void IntroScreen::Render()
{
	_teamLogo->Render();
	_teamBoard->Render();
	_teamMember->Render();
	_gameLogo->Render();
	_startPrompt->Render();
}




