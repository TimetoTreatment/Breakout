#pragma once
#include "Screen.h"

class PlayScreen : public Screen
{
private:
	Timer* mScreenTimer;


	Layout* mScreenLayout;


	string mPromptColor;


public:
	PlayScreen();
	~PlayScreen();

	void Update();
	void Render();
};