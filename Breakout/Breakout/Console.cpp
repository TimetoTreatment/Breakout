#include "console.h"

using namespace std;


Console* Console::s_instance = nullptr;

Console* Console::Instance()
{
	if (s_instance == nullptr)
		s_instance = new Console;

	return s_instance;
}

void Console::Release()
{
	delete s_instance;
	s_instance = nullptr;
}


//////////////////////////////////
/* Change Color Name to Integer */
//////////////////////////////////
int Console::ColorNameToNumber(const string& colorName) const
{
	if (colorName == "default")
		return -1;

	if (colorName == "random")
	{
		int colorSet[5] = { 12,10,3,13,14 };
		return colorSet[rand() % 5];
	}
	else if (colorName == "red")	return 12;	// RED
	else if (colorName == "green")	return 10;	// GREEN
	else if (colorName == "blue")	return 3;	// BLUE
	else if (colorName == "purple")	return 13;	// PURPLE
	else if (colorName == "yellow")	return 14;	// YELLOW
	else if (colorName == "white")	return 15;	// WHITE
	else if (colorName == "black")	return 0;	// BLACK
	return -1;
}


///////////////////////
/* Clear CMD Console */
///////////////////////
void Console::clearConsole()
{
	cout << "\033[2J";
}


////////////////////
/* Set Text Color */
////////////////////
void Console::setColor(string foreground, string background)
{
	int colorForeground = ColorNameToNumber(foreground);
	int colorBackground = ColorNameToNumber(background);
	int colorValue;

	if (colorForeground == -1) colorForeground = 7;			// Defalut value is 7
	if (colorBackground == -1) colorBackground = 0;			// Defalut value is 0
	colorValue = (colorBackground * 16) + colorForeground;

	SetConsoleTextAttribute(hConsole, colorValue);
}


//////////////////////
/* Reset Text Color */
//////////////////////
void Console::setColorDefault()
{
	SetConsoleTextAttribute(hConsole, 7);
}


void Console::setCursorPosition(int x, int y)
{
	//std::cout.flush();
	SetConsoleCursorPosition(hConsole, { (short)x, (short)y });
}


void Console::setCursorPositionDefault()
{
	//std::cout.flush();
	SetConsoleCursorPosition(hConsole, { 0,0});
}