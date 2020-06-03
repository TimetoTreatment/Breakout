#pragma once
#include "Status.h"
#include "Timer.h"
#include "Console.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "LayoutManager.h"
#include "IntroScreen.h"
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
	Console* mConsole;
	InputManager* mInputManager;
	LayoutManager* mLayoutManager;
	AudioManager* mAudioManager;
	AssetManager* mAssetManager;

	Timer* mFrameTimer;
	Timer* mScreenCooldownTimer;

	IntroScreen* mIntroScreen;
	MainScreen* mMainScreen;
	PlayScreen* mPlayScreen;

	Screen* mCurrentScreen;
	Screen* mNextScreen;

	string mRandomMusic;
	int mMusicNum;
	int mMusicNumMax;

	enum class page
	{
		a = 1,
		b,
		c,
		d
	};





public:
	GameMain();
	~GameMain();

	void MainLoop();

	void Update();
	void Render();
};

