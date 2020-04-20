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
		exit(-1);
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
		{
			width++;
		}

	}

	_contents.push_back('\n');

	_width = width;
	_height = height;
}




void Layout::Color(const string& textColor, const string& backColor)
{
	_textColor = textColor;
	_backColor = backColor;
}


void Layout::Render()
{
	int startX = Position().x - _width / 2;
	int startY = Position().y - _height / 2;



	console->setColor(_textColor, _backColor);
	console->setCursorPosition(startX, startY);

	cout << _contents;
}


