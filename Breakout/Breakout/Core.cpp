#include "Core.h"



Core* Core::s_instance = nullptr;

Core* Core::Instance()
{
	if (s_instance == nullptr)
		s_instance = new Core;

	return s_instance;
}

void Core::Release()
{
	delete s_instance;
	s_instance = nullptr;
}




Core::Core()
{
	mBar = new Bar;

	mGameOver = false;
	mLife = 4;
}


Core::~Core()
{
	delete mBar;


}

bool Core::GameOver()
{
	return mGameOver;
}


int Core::Life()
{
	return mLife;
}


void Core::Life(int life)
{
	mLife = life;
}


void Core::Item(string item)
{
	mItem = item;
}


string Core::Item()
{
	return mItem;
}



void Core::Update()
{
	if (mLife == 0)
		mGameOver = true;

	mBar->Update();

}

void Core::Render()
{
	mBar->Render();





}