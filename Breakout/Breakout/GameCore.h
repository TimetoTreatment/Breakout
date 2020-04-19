#pragma once

#include "AudioManager.h"
#include "InputManager.h"
#include "LayoutManager.h"
#include "Timer.h"


class GameCore
{
private:
	AudioManager* audioManager;
	InputManager* inputManager;
	LayoutManager* layoutManager;
	Timer* timer;

public:
	GameCore();




	void MainLoop();

	void Input();

	void Update();

	void Draw();




};

