#pragma once
#include "Status.h"
#include "GameObject.h"
#include "LayoutManager.h"
#include "InputManager.h"
#include "Timer.h"

class Bar : public GameObject
{
private:

	Status* mStatus;
	LayoutManager* mLayoutManager;
	InputManager* mInputManager;

	Timer* mSpeedTimer;



	Layout* mBarCurrent;
	Layout* mBarSmall;
	Layout* mBarMedium;
	Layout* mBarLarge;


	int mPositionX;
	int mPositionY;
	int mSize;


public:

	Bar();
	~Bar();







	void Update();
	void Render();
};

