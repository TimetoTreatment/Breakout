#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"

class IntroScreen : public GameObject
{
private:
	Config* config;
	LayoutManager* layoutManager;

	Timer* _screenTimer;
	Layout* _teamLogo;
	Layout* _teamBoard;
	Layout* _teamMember;
	Layout* _gameLogo;
	Layout* _startPrompt;
	string _promptColor;
	Timer* _promptTimer;

public:
	IntroScreen();
	~IntroScreen();

	void Update();
	void Render();
};