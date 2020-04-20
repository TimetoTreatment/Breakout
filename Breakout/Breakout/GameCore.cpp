#include "GameCore.h"
#include "IntroScreen.h"

GameCore::GameCore()
{
	config = Config::Instance();
	audioManager = AudioManager::Instance();
	inputManager = InputManager::Instance();
	timer = Timer::Instance();
}








void GameCore::MainLoop()
{

	IntroScreen intro;
	intro.Render();


	//for (;;)
	{


		if (timer->GetDeltaTime() >= 70000/config->FPS() )
		{
			Input();
			Update();
			Render();
	

			timer->Reset();
		}
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


