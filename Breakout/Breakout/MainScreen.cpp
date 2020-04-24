#include "MainScreen.h"


MainScreen::MainScreen()
{
	mScreenTimer = new Timer;
	mScreenTimer->SetInterval(500);

	mGameLogo = mLayoutManager->New("intro_gamelogo.txt", { mStatus->Width() / 2, 8 }, "white");
	mBrickwall = mLayoutManager->New("mainmenu_brickwall.txt", { mStatus->Width() / 2, 30 }, "yellow");
	mStart = mLayoutManager->New("Start CodeSlayer", { mStatus->Width() / 2, 27 }, "white");
	mOption = mLayoutManager->New("Option", { mStatus->Width() / 2, 30 }, "white");
	mExit = mLayoutManager->New("Exit", { mStatus->Width() / 2, 33 }, "white");

	mSelector = mStart;


}


MainScreen::~MainScreen()
{




	delete mScreenTimer;
}






void MainScreen::Update()
{
	if (this->Active())
	{
		mGameLogo->Visible(true);
		mBrickwall->Visible(true);
		mStart->Visible(true);
		mOption->Visible(true);
		mExit->Visible(true);

		if (mSelector == mStart)
		{






		}
		else if (mSelector == mOption)
		{





		}
		else
		{






		}









	}
	else
	{
		mGameLogo->Visible(false);
		mBrickwall->Visible(false);
		mStart->Visible(false);
		mOption->Visible(false);
		mExit->Visible(false);
	}
}


void MainScreen::Render()
{
	mGameLogo->Render();
	mBrickwall->Render();
	mSelector->Render();
	mStart->Render();
	mOption->Render();
	mExit->Render();

}