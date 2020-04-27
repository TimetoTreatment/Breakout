#include "MainScreen.h"


MainScreen::MainScreen()
{
	mScreenTimer = new Timer;
	mScreenTimer->SetInterval(500);

	mGameLogo = mLayoutManager->New("intro_gamelogo.txt", { mStatus->Width() / 2, 8 }, "white");
	mBrickwall = mLayoutManager->New("mainmenu_brickwall.txt", { mStatus->Width() / 2, 30 }, "yellow");
	mStartMenu = mLayoutManager->New("Start CodeSlayer", { mStatus->Width() / 2, 27 }, "white");
	mOptionMenu = mLayoutManager->New("Option", { mStatus->Width() / 2, 30 }, "white");
	mExitMenu = mLayoutManager->New("Exit", { mStatus->Width() / 2, 33 }, "white");

	mSelector = mStartMenu;

	mSelectMenu = 1;
	mMoveNextScreen = false;
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
		mStartMenu->Visible(true);
		mOptionMenu->Visible(true);
		mExitMenu->Visible(true);

		if (mInputManager->KeyPressedOnce(sf::Keyboard::Down))
		{
			++mSelectMenu;
			if (mSelectMenu > 3)
				mSelectMenu = 1;
		}
		else if (mInputManager->KeyPressedOnce(sf::Keyboard::Up))
		{
			--mSelectMenu;
			if (mSelectMenu < 1)
				mSelectMenu = 3;
		}

		switch (mSelectMenu)
		{
		case 1:
			if (mInputManager->KeyPressedOnce(sf::Keyboard::Enter))
				mMoveNextScreen = true;

			mStartMenu->Color("red");
			mOptionMenu->Color("white");
			mExitMenu->Color("white");
			break;

		case 2:
			mStartMenu->Color("white");
			mOptionMenu->Color("green");
			mExitMenu->Color("white");
			break;

		case 3:
			if (mInputManager->KeyPressedOnce(sf::Keyboard::Enter))
				mStatus->Exit(true);

			mStartMenu->Color("white");
			mOptionMenu->Color("white");
			mExitMenu->Color("blue");
			break;
		}

		
	}
	else
	{
		mGameLogo->Visible(false);
		mBrickwall->Visible(false);
		mStartMenu->Visible(false);
		mOptionMenu->Visible(false);
		mExitMenu->Visible(false);
	}
}


void MainScreen::Render()
{
	mGameLogo->Render();
	mBrickwall->Render();
	mSelector->Render();
	mStartMenu->Render();
	mOptionMenu->Render();
	mExitMenu->Render();
}



int MainScreen::NextScreen()
{
	if (mMoveNextScreen == true)
		return 1;

	return 0;
}
