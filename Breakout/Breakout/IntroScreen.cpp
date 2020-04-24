#include "IntroScreen.h"


IntroScreen::IntroScreen()
{
	mScreenTimer = new Timer;
	mPromptTimer = new Timer;

	mTeamLogo = mLayoutManager->New("intro_teamLogo.txt", { mStatus->Width() / 2, 8 }, "white");
	mTeamBoard = mLayoutManager->New("intro_teamBoard.txt", { mStatus->Width() / 2, 18 }, "white");
	mTeamMember = mLayoutManager->New("intro_teamMember.txt", { mStatus->Width() / 2, 18 }, "white");
	mGameLogo = mLayoutManager->New("intro_gameLogo.txt", { mStatus->Width() / 2, 35 }, "blue");
	mStartPrompt = mLayoutManager->New("* Press Enter to Start *", { mStatus->Width() / 2 + 1, 18 }, "black");

	mTeamLogo->Visible(false);
	mTeamBoard->Visible(false);
	mTeamMember->Visible(false);
	mGameLogo->Visible(false);
	mStartPrompt->Visible(false);

	mPromptTimer->SetInterval(238);
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
		mStartPrompt->Visible(false);
	}
	else
	{
		mTeamLogo->Visible(true);
		mTeamBoard->Visible(true);
		mTeamMember->Visible(true);

		if (mScreenTimer->GetDeltaTime() > 5000)
		{
			mGameLogo->Visible(true);
		}

		if (mScreenTimer->GetDeltaTime() > 9000)
		{
			mTeamMember->Visible(false);
			mStartPrompt->Visible(true);

			if (mPromptTimer->Trigger())
			{
				mStartPrompt->Color(mPromptColor);

				if (mPromptColor == "blue")
					mPromptColor = "white";
				else
					mPromptColor = "blue";
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
	mStartPrompt->Render();
}