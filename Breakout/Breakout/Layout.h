#pragma once
#include <iostream>
#include <fstream>
#include "GameObject.h"
#include "Console.h"




using namespace std;


class Layout : public GameObject
{
private:

	string mContents;
	string mTextColor;
	string mBackColor;

	int mWidth;
	int mHeight;

	Console* mConsole = Console::Instance();




public:
	Layout();
	~Layout();

	void OpenFromFile(const string& path);
	void LoadFromString(const string& str);
	void Color(const string& textColor = "default", const string& backColor = "default");
	void Render();
	void Erase();



};

