#pragma once
#include "LayoutManager.h"
#include "AudioManager.h"
#include "Timer.h"

class MainmenuScreen : public GameObject
{
private:
	LayoutManager* layoutManager = LayoutManager::Instance();

	Layout* _start;
	Layout* _option;
	Layout* _exit;

	Config* config = Config::Instance();
	Timer* timer = new Timer;


public:


	void Update()
	{



	}

	void Render()
	{




	}





};

