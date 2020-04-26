#include "IntroScreen.h"


IntroScreen::IntroScreen()
{
	mMainTimer = new Timer;
	mPromptTimer = new Timer;

	mTeamLogo = mLayoutManager->New("intro_teamLogo.txt", { mStatus->Width() / 2, 8 }, "white");
	mTeamBoard = mLayoutManager->New("intro_teamBoard.txt", { mStatus->Width() / 2, 18 }, "white");
	mTeamMember = mLayoutManager->New("intro_teamMember.txt", { mStatus->Width() / 2, 18 }, "white");
	mGameLogo = mLayoutManager->New("intro_gameLogo.txt", { mStatus->Width() / 2, 35 }, "blue");
	mStartMenuPrompt = mLayoutManager->New("* Press Enter to Start *", { mStatus->Width() / 2 + 1, 18 });

	mTeamLogo->Visible(false);
	mTeamBoard->Visible(false);
	mTeamMember->Visible(false);
	mGameLogo->Visible(false);
	mStartMenuPrompt->Visible(false);

	mPromptTimer->SetInterval(250);
	mPromptColor = "blue";
}


IntroScreen::~IntroScreen()
{
	delete mPromptTimer;
}


void IntroScreen::Update()
{
	if (this->Active() == false)
	{
		mTeamLogo->Visible(false);
		mTeamBoard->Visible(false);
		mTeamMember->Visible(false);
		mGameLogo->Visible(false);
		mStartMenuPrompt->Visible(false);
	}
	else
	{
		mTeamLogo->Visible(true);
		mTeamBoard->Visible(true);
		mTeamMember->Visible(true);

		if (mMainTimer->GetDeltaTime() > 5000)
		{
			mGameLogo->Visible(true);
		}

		if (mMainTimer->GetDeltaTime() > 9000)
		{
			mTeamMember->Visible(false);
			mStartMenuPrompt->Visible(true);

			if (mPromptTimer->Trigger())
			{
				mStartMenuPrompt->Color(mPromptColor);

				if (mPromptColor == "white")
					mPromptColor = "blue";
				else
					mPromptColor = "white";
			}
		}
	}
}


void IntroScreen::Render()
{
	mTeamLogo->Render();
	mTeamBoard->Render();
	mTeamMember->Render();
	mGameLogo->Render();
	mStartMenuPrompt->Render();
}


int IntroScreen::NextScreen()
{
	if (mInputManager->KeyPressedOnce(sf::Keyboard::Enter))
		return 1;

	return 0;
}