#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"
#include "Screen.h"

class MainScreen : public Screen
{
private:
	Timer* mScreenTimer;

	Layout* mGameLogo;
	Layout* mBrickwall;
	Layout* mStart;
	Layout* mOption;
	Layout* mExit;

	Layout* mSelector;




public:
	MainScreen();
	~MainScreen();

	void Update();
	void Render();
};

