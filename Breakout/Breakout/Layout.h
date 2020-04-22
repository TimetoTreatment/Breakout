#pragma once
#include <iostream>
#include <fstream>
#include "GameObject.h"
#include "Console.h"




using namespace std;


class Layout : public GameObject
{
private:

	string _contents;
	string _textColor;
	string _backColor;

	int _width;
	int _height;

	Console* console = Console::Instance();




public:
	Layout();
	~Layout();

	void OpenFromFile(const string& path);
	void LoadFromString(const string& str);
	void Color(const string& textColor = "default", const string& backColor = "default");
	void Render();
	void Erase();



};

