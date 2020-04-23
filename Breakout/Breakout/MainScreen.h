#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"

class MainScreen : public GameObject
{
private:
	Config* config;
	LayoutManager* layoutManager;
	Timer* screenTimer;

	Layout* _gameLogo;
	Layout* _brickwall;
	Layout* _start;
	Layout* _option;
	Layout* _exit;

	Layout* _selector;


	


public:
	MainScreen();
	~MainScreen();

	void Update();
	void Render();
};

