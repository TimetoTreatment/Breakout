#include "GameCore.h"
#include "IntroScreen.h"

GameCore::GameCore()
{
	config = Config::Instance();
	audioManager = AudioManager::Instance();
	inputManager = InputManager::Instance();
	timer = Timer::Instance();
}


GameCore::~GameCore()
{
	Config::Release();
	AudioManager::Release();
	AssetManager::Release();
	InputManager::Release();
	Timer::Release();
}





void GameCore::MainLoop()
{

	IntroScreen intro;
	intro.Render();


	for (int i=0;i<=100000&&!config->Exit();i++)
	{
		AudioManager::Instance()->PlaySFX("music.wav");

		if (timer->GetDeltaTime() >= 70000/config->FPS() )
		{
			Input();
			Update();
			Render();
	

			timer->Reset();
		}
	}



	Config::Release();
	AudioManager::Release();
	AssetManager::Release();
	InputManager::Release();
	Timer::Release();

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


