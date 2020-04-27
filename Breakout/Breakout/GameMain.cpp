#include "GameMain.h"


GameMain* GameMain::sInstance = nullptr;

GameMain* GameMain::Instance()
{
	if (sInstance == nullptr)
		sInstance = new GameMain;

	return sInstance;
}

void GameMain::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

GameMain::GameMain()
{
	mStatus = Status::Instance();
	mConsole = Console::Instance();
	mInputManager = InputManager::Instance();
	mLayoutManager = LayoutManager::Instance();
	mAudioManager = AudioManager::Instance();
	mAssetManager = AssetManager::Instance();

	mFrameTimer = new Timer;
	mScreenCooldownTimer = new Timer;
	mScreenCooldownTimer->SetInterval(500);

	mIntroScreen = new IntroScreen;
	mMainScreen = new MainScreen;
	mPlayScreen = new PlayScreen;

	mCurrentScreen = mIntroScreen;
	mNextScreen = mIntroScreen;

	mRandomMusic = "music1.ogg";
	mMusicNum = 1;
	mMusicNumMax = 7;
}

GameMain::~GameMain()
{
	Status::Release();
	InputManager::Release();
	AudioManager::Release();
	AssetManager::Release();

	delete mFrameTimer;
	delete mScreenCooldownTimer;

	delete mIntroScreen;
	delete mMainScreen;
	delete mPlayScreen;
}


void GameMain::MainLoop()
{
	sf::sleep(sf::milliseconds(1000));
	mAudioManager->PlayMusic("intro.ogg");

	for (int remainTime; !mStatus->Exit(); mFrameTimer->Reset())
	{
		Update();
		Render();

		if ((remainTime = 1000 / mStatus->FPS() - mFrameTimer->GetDeltaTime()) > 0)
			sf::sleep(sf::milliseconds(remainTime));
	}
}


void GameMain::Update()
{
	mCurrentScreen = mNextScreen;

	if (mIntroScreen == mCurrentScreen)
	{
		if (mIntroScreen->NextScreen() != 0)
		{
			mIntroScreen->Active(false);
			mNextScreen = mMainScreen;
			mNextScreen->Active(true);
		}
	}
	else if (mMainScreen == mCurrentScreen)
	{
		if (mMainScreen->NextScreen() != 0)
		{
			mMainScreen->Active(false);
			mNextScreen = mPlayScreen;
			mNextScreen->Active(true);
		}
	}
	else if (mPlayScreen == mCurrentScreen)
	{
		if (mPlayScreen->NextScreen() == 1)
		{
			mPlayScreen->Active(false);
			mStatus->Exit(true);
		}
	}

	mCurrentScreen->Update();



	//////////////////////////////
	//////////////////////////////


	if (!mAudioManager->isMusicPlayed())
	{
		mAudioManager->StopMusic();

		for (char ch = '0'; ch != '9'; ch++)
		{
			if (mRandomMusic.find_first_of(ch) != string::npos)
			{
				mRandomMusic.resize(mRandomMusic.find_first_of(ch));
				mRandomMusic += to_string(mMusicNum);
				mRandomMusic += ".ogg";
				break;
			}
		}

		mAudioManager->PlayMusic(mRandomMusic);
		mMusicNum = rand() % mMusicNumMax;
	}

	mInputManager->Update();
	mConsole->setCursorPosition(mStatus->Width() - 1, mStatus->Height());
}


void GameMain::Render()
{
	mCurrentScreen->Render();
}


