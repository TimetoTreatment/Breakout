#pragma once

#include "Config.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Timer.h"


class GameCore
{
private:
	static GameCore* s_instance;

public:
	static GameCore* Instance();
	static void Release();

private:
	Config* config;
	AudioManager* audioManager;
	InputManager* inputManager;
	Timer timer;

public:
	GameCore();
	~GameCore();

	void MainLoop();
	void Input();
	void Update();
	void Render();
};

