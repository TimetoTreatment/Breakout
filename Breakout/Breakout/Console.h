#pragma once
#include <windows.h>
#include <iostream>

using namespace std;

class Console
{
private:
	static Console* s_instance;

public:
	static Console* Instance();
	static void Release();


private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	/* Change Color Name to Integer */
	int ColorNameToNumber(const string& colorName) const;

public:
	/* Set Console Cursor Position */
	void setCursorPosition(int x, int y);

	/* Set Console Cursor Position to Dafault */
	void setCursorPositionDefault();

	/* Clear CMD Console */
	void clearConsole();

	/* Set Text Color */
	void setColor(string foreground = "default", string background = "default");
	void setColorDefault();
};
