#include "PlayScreen.h"


PlayScreen::PlayScreen()
{
	mCore = Core::Instance();
	mConsole = Console::Instance();

	mScreenTimer = new Timer;


	mNextScreen = 0;

	mTopBar = mLayoutManager->New("play_layout.txt", { mStatus->Width() / 2, 6}, "white");

	mLife[3] = mLayoutManager->New("¡ê  ¡ê  ¡ê  ¡ê", { 107, 8 }, "red");
	mLife[2] = mLayoutManager->New("¡ê  ¡ê  ¡ê    ", { 107, 8 }, "red");
	mLife[1] = mLayoutManager->New("¡ê  ¡ê        ", { 107, 8 }, "red");
	mLife[0] = mLayoutManager->New("¡ê            ", { 107, 8 }, "red");
}


PlayScreen::~PlayScreen()
{
	delete mScreenTimer;
}



int PlayScreen::NextScreen()
{
	return mNextScreen;
}




void PlayScreen::Update()
{
	mCore->Update();

	if (mCore->GameOver())
		mNextScreen = 1;
}


void PlayScreen::Render()
{
	mTopBar->Render();
	mLife[mCore->Life() - 1]->Render();
}

