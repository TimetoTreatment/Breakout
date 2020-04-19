#include "GameCore.h"


GameCore::GameCore()
{
	audioManager = AudioManager::Instance();
	inputManager = InputManager::Instance();
	layoutManager = LayoutManager::Instance();
	timer = Timer::Instance();



}








void GameCore::MainLoop()
{

	


	for(;;)
	{
		if (timer->Get() >= 16)
		{
			Input();
			Update();
			Draw();

			printf("%d\n", timer->Get());
















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


void GameCore::Draw()
{



}


