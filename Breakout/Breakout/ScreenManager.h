#pragma once
#include "IntroScreen.h"
#include "InputManager.h"



class ScreenManager
{
private:
	static ScreenManager* s_instance;

public:
	static ScreenManager* Instance();
	static void Release();

private:

	ScreenManager();
	~ScreenManager();

	InputManager* inputManager;

	Timer* timer;
	IntroScreen* _introScreen;

	GameObject* _screen;
	GameObject* _nextScreen;

	bool _musicPlayed;



public:

	void Update();
	void Render();






};

