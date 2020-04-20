#include "GameCore.h"
#include "IntroScreen.h"

GameCore* GameCore::s_instance = nullptr;

GameCore* GameCore::Instance()
{
	if (s_instance == nullptr)
		s_instance = new GameCore;

	return s_instance;
}

void GameCore::Release()
{
	delete s_instance;
	s_instance = nullptr;
}

GameCore::GameCore()
{
	config = Config::Instance();
	audioManager = AudioManager::Instance();
	inputManager = InputManager::Instance();
}

GameCore::~GameCore()
{
	Config::Release();
	AudioManager::Release();
	AssetManager::Release();
	InputManager::Release();
}


void GameCore::MainLoop()
{
	IntroScreen intro;

	

	for (timer.Reset(); !config->Exit(); timer.Reset())
	{
		Sleep(1000 / config->FPS() - timer.GetDeltaTime());

		Input();
		Update();
		Render();
		intro.Render();


	}



}


void GameCore::Input()
{

}


void GameCore::Update()
{



}


void GameCore::Render()
{



}


