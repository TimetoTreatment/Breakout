#pragma once

#include "Config.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Timer.h"


class GameCore
{
private:
	Config* config;
	AudioManager* audioManager;
	InputManager* inputManager;
	Timer* timer;


public:
	GameCore();




	void MainLoop();

	void Input();

	void Update();

	void Render();




};

