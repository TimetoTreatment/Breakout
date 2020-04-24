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
	bool mExit;


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
		return mExit;
	}

	void Exit(bool exit)
	{
		mExit = exit;
	}





};

