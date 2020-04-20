#pragma once
#include <iostream>
#include <fstream>
#include "GameEntity.h"
#include "Console.h"
#include "Config.h"



using namespace std;


class Layout : public GameEntity
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


	void Color(const string& textColor = "default", const string& backColor = "default");

	void Render();





};

