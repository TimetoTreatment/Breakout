#pragma once
#include "Status.h"
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"

class Screen : public GameObject
{
protected:

	Status* mStatus;
	LayoutManager* mLayoutManager;


public:

	Screen();
	~Screen();



	//virtual string HandleNextMenu()
	//{

	//}



	virtual void Update()
	{

	}

	virtual void Render()
	{

	}







};

