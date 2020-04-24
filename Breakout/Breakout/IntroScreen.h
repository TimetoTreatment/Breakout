#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"
#include "Screen.h"

class IntroScreen : public Screen
{
private:
	Timer* mScreenTimer;
	Timer* mPromptTimer;

	Layout* mTeamLogo;
	Layout* mTeamBoard;
	Layout* mTeamMember;
	Layout* mGameLogo;
	Layout* mStartPrompt;

	string mPromptColor;


public:
	IntroScreen();
	~IntroScreen();

	void Update();
	void Render();
};