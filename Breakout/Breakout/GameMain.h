#pragma once
#include "Status.h"
#include "Timer.h"
#include "IntroScreen.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "LayoutManager.h"
#include "MainScreen.h"
#include "PlayScreen.h"


class GameMain
{
private:
	static GameMain* sInstance;

public:
	static GameMain* Instance();
	static void Release();

private:
	Status* mStatus;
	InputManager* mInputManager;
	AudioManager* mAudioManager;

	Timer* mFrameTimer;
	Timer* mMainTimer;
	Timer* mScreenTimer;

	IntroScreen* mIntroScreen;
	MainScreen* mMainScreen;

	Screen* mCurrentScreen;
	Screen* mNextScreen;
	Screen* mPlayScreen;

	string mRandomMusic;
	int mMusicNum;
	int mMusicNumMax;





public:
	GameMain();
	~GameMain();

	void MainLoop();

	void Update();
	void Render();
};

