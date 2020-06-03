#include "Bar.h"

Bar::Bar()
{
	mStatus = Status::Instance();
	mLayoutManager = LayoutManager::Instance();
	mInputManager = InputManager::Instance();

	mSpeedTimer = new Timer;
	mSpeedTimer->SetInterval(10);

	mPositionX = mStatus->Width() / 2;
	mPositionY = 43;

	mBarSmall = mLayoutManager->New(" �̢ƢƢƢƢ� ", { mPositionX,mPositionY }, "white");
	mBarMedium = mLayoutManager->New(" �̢ƢƢƢƢƢƢƢƢ� ", { mPositionX,mPositionY }, "white");
	mBarLarge = mLayoutManager->New(" �̢ƢƢƢƢƢƢƢƢƢƢƢƢƢ� ", { mPositionX,mPositionY }, "white");
	mBarCurrent = mBarMedium;
	mSize = 1;
}


Bar::~Bar()
{








}



void Bar::Update()
{


	if (mInputManager->KeyPressed(sf::Keyboard::Left) && mSpeedTimer->Trigger())
	{
		if (mPositionX > 6)
		{
			mPositionX--;

			this->Drawed(false);
		}
	}

	else if (mInputManager->KeyPressed(sf::Keyboard::Right) && mSpeedTimer->Trigger())
	{
		mPositionX++;

		this->Drawed(false);
	}

	mBarCurrent->Position({ mPositionX,mPositionY });
	mBarCurrent->Drawed(Drawed());
}


void Bar::Render()
{
	mBarCurrent->Render();




}