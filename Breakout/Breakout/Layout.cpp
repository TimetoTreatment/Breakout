#include "Layout.h"

Layout::Layout()
{
	mTextColor = "default";
	mBackColor = "default";

	mWidth = 0;
	mHeight = 0;
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
		mContents += file.get();

		if (mContents.back() == '\n')
		{
			if (mWidth < width)
				mWidth = width;

			height++;
			width = 0;
		}
		else
			width++;
	}

	mContents.push_back('\n');

	mWidth = width;
	mHeight = height;
	file.close();
}


void Layout::LoadFromString(const string& str)
{
	int width = 0;
	int height = 1;

	for (char ch : str)
	{
		mContents += ch;

		if (ch == '\n')
		{
			if (mWidth < width)
				mWidth = width;

			height++;
			width = 0;
		}
		else
			width++;
	}

	mContents.push_back('\n');

	mWidth = width;
	mHeight = height;
}



void Layout::Color(const string& textColor, const string& backColor)
{
	if (mTextColor != textColor || mBackColor != backColor)
		Drawed(false);

	mTextColor = textColor;
	mBackColor = backColor;
}


void Layout::Render()
{
	if (Drawed() == Visible())
		return;

	int startX = Position().x - mWidth / 2;
	int startY = Position().y - mHeight / 2;

	if (Drawed() == false && Visible() == true)
	{
		mConsole->setColor(mTextColor, mBackColor);

		for (size_t index = 0; index < mContents.size(); index++)
		{
			mConsole->setCursorPosition(startX, startY);
			startY++;

			cout << flush;

			for (; mContents[index] != '\n'; index++)
				cout << mContents[index];
		}

		Drawed(true);
	}
	else
	{
		for (size_t index = 0; index < mContents.size(); index++)
		{
			mConsole->setCursorPosition(startX, startY);
			startY++;

			for (; mContents[index] != '\n'; index++)
				cout << ' ';
		}

		Drawed(false);
	}


}
