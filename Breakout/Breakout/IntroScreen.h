#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"

class IntroScreen : public GameEntity
{
private:
	Layout* _teamLogo;
	Layout* _gameLogo;
	LayoutManager* layoutManager = LayoutManager::Instance();

public:
	IntroScreen()
	{
		_teamLogo = layoutManager->New("teamLogo.txt");
		_gameLogo = layoutManager->New("gameLogo.txt");

		_teamLogo->Position(Coord(20, 10));
		_gameLogo->Position(Coord(30, 20));
	}




	void Render()
	{
		_teamLogo->Render();
		_gameLogo->Render();

		
		
	}






};

