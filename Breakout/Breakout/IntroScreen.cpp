#include "IntroScreen.h"


IntroScreen::IntroScreen()
{
	config = Config::Instance();
	layoutManager = LayoutManager::Instance();

	_promptTimer = new Timer;
	_screenTimer = new Timer;

	_teamLogo = layoutManager->New("intro_teamLogo.txt", { config->Width() / 2, 8 }, "white");
	_teamBoard = layoutManager->New("intro_teamBoard.txt", { config->Width() / 2, 18 }, "white");
	_teamMember = layoutManager->New("intro_teamMember.txt", { config->Width() / 2, 18 }, "white");
	_gameLogo = layoutManager->New("intro_gameLogo.txt", { config->Width() / 2, 35 }, "blue");
	_startPrompt = layoutManager->New("* Press Enter to Start *", { config->Width() / 2 + 1, 18 }, "black");

	_teamLogo->Visible(false);
	_teamBoard->Visible(false);
	_teamMember->Visible(false);
	_gameLogo->Visible(false);
	_startPrompt->Visible(false);

	_promptTimer->SetInterval(238);
	_promptColor = "blue";
}


IntroScreen::~IntroScreen()
{
	delete _screenTimer;
	delete _promptTimer;
}


void IntroScreen::Update()
{
	if (this->Active() == false)
	{
		_teamLogo->Visible(false);
		_teamBoard->Visible(false);
		_teamMember->Visible(false);
		_gameLogo->Visible(false);
		_startPrompt->Visible(false);
	}
	else
	{
		if (_screenTimer->GetDeltaTime() > 1000)
		{
			AudioManager::Instance()->PlayMusic("mainmenu.ogg");

			_teamLogo->Visible(true);
			_teamBoard->Visible(true);
			_teamMember->Visible(true);
		}

		if (_screenTimer->GetDeltaTime() > 5000)
		{
			_gameLogo->Visible(true);
		}

		if (_screenTimer->GetDeltaTime() > 9000)
		{
			_teamMember->Visible(false);
			_startPrompt->Visible(true);

			if (_promptTimer->Trigger())
			{
				_startPrompt->Color(_promptColor);

				if (_promptColor == "blue")
					_promptColor = "white";
				else
					_promptColor = "blue";
			}
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