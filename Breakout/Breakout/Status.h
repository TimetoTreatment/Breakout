#pragma once

class Status
{
private:
	static Status* sInstance;

public:
	static Status* Instance();
	static void Release();

private:
	int mFPS;
	int mWidth;
	int mHeight;
	bool mExitMenu;


public:
	Status();

	int FPS()
	{
		return mFPS;
	}

	int Width()
	{
		return mWidth;
	}

	int Height()
	{
		return mHeight;
	}

	bool Exit()
	{
		return mExitMenu;
	}

	void Exit(bool exit)
	{
		mExitMenu = exit;
	}





};

