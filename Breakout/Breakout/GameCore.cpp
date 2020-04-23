#include "GameCore.h"
#include "IntroScreen.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "LayoutManager.h"
#include "ScreenManager.h"

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
	screenManager = ScreenManager::Instance();
	AssetManager::Instance();





}

GameCore::~GameCore()
{
	Config::Release();
	config = nullptr;

	ScreenManager::Release();
	screenManager = nullptr;
}


void GameCore::MainLoop()
{
	for (int remainTime; !config->Exit(); timer.Reset())
	{
		Update();
		Render();

		if ((remainTime = 1000 / config->FPS() - timer.GetDeltaTime()) > 0)
			sf::sleep(sf::milliseconds(remainTime));
	}
}


void GameCore::Update()
{
	screenManager->Update();
}


void GameCore::Render()
{
	screenManager->Render();
}


