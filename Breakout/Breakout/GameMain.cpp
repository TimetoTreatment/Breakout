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
	mInputManager = InputManager::Instance();
	mAudioManager = AudioManager::Instance();

	mFrameTimer = new Timer;
	mMainTimer = new Timer;
	mScreenTimer = new Timer;
	mScreenTimer->SetInterval(500);

	mIntroScreen = new IntroScreen;
	mMainScreen = new MainScreen;
	mPlayScreen = new PlayScreen;

	mCurrentScreen = mIntroScreen;
	mNextScreen = mIntroScreen;

	mRandomMusic = "music1.ogg";
	mMusicNum = 1;
	mMusicNumMax = 1;
}

GameMain::~GameMain()
{
	Status::Release();

	delete mIntroScreen;

	delete mFrameTimer;
	mFrameTimer = nullptr;
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

	if (mCurrentScreen == mIntroScreen)
	{
		if (mInputManager->KeyPressed(sf::Keyboard::Enter) && mScreenTimer->Trigger())
		{
			mCurrentScreen->Active(false);
			mNextScreen = mMainScreen;
			mNextScreen->Active(true);
		}
	}
	else if (mCurrentScreen == mMainScreen)
	{
		if (mInputManager->KeyPressed(sf::Keyboard::Enter) && mScreenTimer->Trigger())
		{
			mCurrentScreen->Active(false);
			mNextScreen = mPlayScreen;
			mNextScreen->Active(true);
		}
	}
	else if (mCurrentScreen == mPlayScreen)
	{
		if (mInputManager->KeyPressed(sf::Keyboard::Escape) && mScreenTimer->Trigger())
		{





		}
	}

	mCurrentScreen->Update();
	



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
}


void GameMain::Render()
{
	mCurrentScreen->Render();
}


