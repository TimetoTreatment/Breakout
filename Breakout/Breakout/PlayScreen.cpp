#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	mScreenTimer = new Timer;

	mScreenLayout = mLayoutManager->New("play_layout.txt", { mStatus->Width() / 2, 4 }, "white");




}


PlayScreen::~PlayScreen()
{
	delete mScreenTimer;
}

void PlayScreen::Update()
{

}

void PlayScreen::Render()
{
	mScreenLayout->Render();
}