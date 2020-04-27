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

	Layout* mStartMenu;
	Layout* mOptionMenu;
	Layout* mExitMenu;

	Layout* mSelector;

	int mSelectMenu;
	bool mMoveNextScreen;

public:
	MainScreen();
	~MainScreen();

	void Update();
	void Render();

	int NextScreen();
};

