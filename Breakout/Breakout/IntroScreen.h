#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"

class IntroScreen : public GameObject
{
private:
	Layout* _teamLogo;
	Layout* _teamBoard;
	Layout* _teamMember;
	Layout* _gameLogo;
	Layout* _startPrompt;
	LayoutManager* layoutManager = LayoutManager::Instance();
	Config* config = Config::Instance();
	Timer* layoutTimer;
	Timer* colorTimer;

public:
	IntroScreen();
	~IntroScreen();

	void Update();
	void Render();
};