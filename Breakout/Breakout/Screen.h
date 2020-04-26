#pragma once
#include "Status.h"
#include "LayoutManager.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "Timer.h"

class Screen : public GameObject
{
protected:

	Status* mStatus;
	LayoutManager* mLayoutManager;
	InputManager* mInputManager;


public:

	Screen();
	~Screen();





	virtual void Update()
	{

	}

	virtual void Render()
	{

	}


	virtual int NextScreen()
	{
		return 0;
	}




};

