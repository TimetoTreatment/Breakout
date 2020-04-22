#include "ScreenManager.h"



ScreenManager* ScreenManager::s_instance = nullptr;

ScreenManager* ScreenManager::Instance()
{
	if (s_instance == nullptr)
		s_instance = new ScreenManager;

	return s_instance;
}

void ScreenManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}



ScreenManager::ScreenManager()
{
	inputManager = InputManager::Instance();
	_introScreen = new IntroScreen;



	timer = new Timer;

	_screen = _introScreen;
	_nextScreen = _introScreen;
}


ScreenManager::~ScreenManager()
{
	InputManager::Release();
	inputManager = nullptr;

	delete _introScreen;

	delete timer;
	timer = nullptr;
}



void ScreenManager::Update()
{
	using namespace sf;

	_screen = _nextScreen;

	if (_screen != nullptr)
		_screen->Update();


	if (_screen == _introScreen)
	{
		if (inputManager->KeyPressed(Keyboard::Enter))
		{
			_screen->Active(false);
			_screen->Update();
			_nextScreen = nullptr;
		}
	}

	else if (_screen == nullptr)
	{
		if (inputManager->KeyPressed(Keyboard::Escape))
		{
			_nextScreen = _introScreen;
			_nextScreen->Active(true);
		}
	}



}


void ScreenManager::Render()
{
	if (_screen != nullptr)
		_screen->Render();
}