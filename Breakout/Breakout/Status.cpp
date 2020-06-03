#include "Status.h"

Status* Status::sInstance = nullptr;

Status* Status::Instance()
{
	if (sInstance == nullptr)
		sInstance = new Status;

	return sInstance;
}

void Status::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

Status::Status()
{
	mFPS = 240;
	mWidth = 130;
	mHeight = 45;
	mExitMenu = false;
}