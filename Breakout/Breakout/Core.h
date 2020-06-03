#pragma once
#include <string>
#include "Bar.h"


using namespace std;


class Core
{
private:
	static Core* s_instance;

	Core();
	~Core();

public:
	static Core* Instance();
	static void Release();

private:

	Bar* mBar;




	bool mGameOver;
	int mLife;
	string mItem;










public:


	bool GameOver();

	int Life();
	void Life(int life);

	void Item(string item);
	string Item();


	void Update();
	void Render();
};

