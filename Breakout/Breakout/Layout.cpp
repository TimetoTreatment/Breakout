#include "Layout.h"

Layout::Layout()
{
	_width = 0;
	_height = 0;
}


Layout::~Layout()
{

}





void Layout::OpenFromFile(const string& path)
{
	int width = 0;
	int height = 1;
	ifstream file(path, ios::in);

	if (!file.is_open())
	{
		cout << "Cannot find " << path << endl;
		return;
	}

	for (; !file.eof();)
	{
		_contents += file.get();

		if (_contents.back() == '\n')
		{
			if (_width < width)
				_width = width;

			height++;
			width = 0;
		}
		else
			width++;
	}

	_contents.push_back('\n');

	_width = width;
	_height = height;
}


void Layout::LoadFromString(const string& str)
{
	int width = 0;
	int height = 1;

	for (char ch : str)
	{
		_contents += ch;

		if (ch == '\n')
		{
			if (_width < width)
				_width = width;

			height++;
			width = 0;
		}
		else
			width++;
	}

	_contents.push_back('\n');

	_width = width;
	_height = height;
}



void Layout::Color(const string& textColor, const string& backColor)
{
	Drawed(false);

	_textColor = textColor;
	_backColor = backColor;
}


void Layout::Render()
{
	if (Drawed() == Visible())
		return;

	int startX = Position().x - _width / 2;
	int startY = Position().y - _height / 2;

	if (Drawed()==false && Visible()==true)
	{
		console->setColor(_textColor, _backColor);

		for (size_t index = 0; index < _contents.size(); index++)
		{
			console->setCursorPosition(startX, startY);
			startY++;

			for (; _contents[index] != '\n'; index++)
				cout << _contents[index];
		}

		Drawed(true);
	}
	else
	{
		for (size_t index = 0; index < _contents.size(); index++)
		{
			console->setCursorPosition(startX, startY);
			startY++;

			for (; _contents[index] != '\n'; index++)
					cout << ' ';
		}

		Drawed(false);
	}

	
}
