#pragma once
#include "Screen.h"
#include "Core.h"
#include "Console.h"


class PlayScreen : public Screen
{
private:
	Core* mCore;
	Console* mConsole;

	Timer* mScreenTimer;

	int mNextScreen;
	

	Layout* mTopBar;

	Layout* mLife[5];


	string mPromptColor;




public:
	PlayScreen();
	~PlayScreen();

	int NextScreen();


	void Update();
	void Render();
};

