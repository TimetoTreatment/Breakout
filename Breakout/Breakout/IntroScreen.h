#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"

class IntroScreen : public GameEntity
{
private:
	Layout* _teamLogo;
	Layout* _gameLogo;
	LayoutManager* layoutManager = LayoutManager::Instance();
	Config* config = Config::Instance();
	Timer timer;
	bool draw;

public:
	IntroScreen();



	void Update()
	{





	}




	void Render()
	{
		if (timer.GetDeltaTime() > 1000 && draw==false)
		{
			_teamLogo->Render();
			_gameLogo->Render();

			AudioManager::Instance()->PlaySFX("laugh2.ogg");

			draw = true;
		}




	}






};

