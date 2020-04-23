#include "MainScreen.h"


MainScreen::MainScreen()
{
	config = Config::Instance();
	layoutManager = LayoutManager::Instance();

	screenTimer = new Timer;
	screenTimer->SetInterval(500);

	_gameLogo = layoutManager->New("intro_gamelogo.txt", { config->Width() / 2, 8 }, "white");
	_brickwall = layoutManager->New("mainmenu_brickwall.txt", { config->Width() / 2, 30 }, "yellow");
	_start = layoutManager->New("Start CodeSlayer", { config->Width() / 2, 27 }, "white");
	_option = layoutManager->New("Option", { config->Width() / 2, 30 }, "white");
	_exit = layoutManager->New("Exit", { config->Width() / 2, 33 }, "white");

	_selector = _start;
}


MainScreen::~MainScreen()
{




	delete screenTimer;
}






void MainScreen::Update()
{
	if (this->Active())
	{
		_gameLogo->Visible(true);
		_brickwall->Visible(true);
		_start->Visible(true);
		_option->Visible(true);
		_exit->Visible(true);

		if (_selector == _start)
		{






		}
		else if (_selector == _option)
		{





		}
		else
		{






		}









	}
	else
	{
		_gameLogo->Visible(false);
		_brickwall->Visible(false);
		_start->Visible(false);
		_option->Visible(false);
		_exit->Visible(false);
	}
}


void MainScreen::Render()
{
	_gameLogo->Render();
	_brickwall->Render();
	_selector->Render();
	_start->Render();
	_option->Render();
	_exit->Render();

}