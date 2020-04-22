#pragma once

#include "Config.h"
#include "Timer.h"
#include "ScreenManager.h"


class GameCore
{
private:
	static GameCore* s_instance;

public:
	static GameCore* Instance();
	static void Release();

private:
	Config* config;
	Timer timer;
	ScreenManager* screenManager;


public:
	GameCore();
	~GameCore();

	void MainLoop();
	void TimeCheck();
	void Update();
	void Render();
};

