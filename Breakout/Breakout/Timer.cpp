#include "Timer.h"


Timer::Timer()
{
	mTimer.restart();

	mTriggeredOnce = false;
	mIntervalTime = 0;
	mTriggerCount = 0;
	mNextTriggerTime = 0;
}

Timer::~Timer()
{

}


void Timer::SetInterval(unsigned int intervalTime)
{
	mIntervalTime = intervalTime;
}


bool Timer::Trigger()
{
	if (GetDeltaTime() >= mNextTriggerTime)
	{
		if (mTriggeredOnce == false)
		{
			mTimer.restart();
			mTriggeredOnce = true;
		}

		mTriggerCount++;
		mNextTriggerTime = mIntervalTime * mTriggerCount;

		return true;
	}

	return false;
}


unsigned int Timer::TriggerCount() const
{
	return mTriggerCount;
}


unsigned int Timer::GetDeltaTime() const
{
	return mTimer.getElapsedTime().asMilliseconds();
}


void Timer::Reset()
{
	mTimer.restart();
}