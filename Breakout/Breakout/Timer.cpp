#include "Timer.h"


Timer::Timer()
{
	_timer.restart();
	_interval = 0;
	_lastTrigger = 0;
}

Timer::~Timer()
{
	
}


void Timer::SetInterval(int interval)
{
	_interval = interval;
}


bool Timer::Trigger()
{
	if (GetDeltaTime() - _lastTrigger >= _interval)
	{
		_lastTrigger = GetDeltaTime();
		return true;
	}

	return false;
}


int Timer::GetDeltaTime()
{
	return _timer.getElapsedTime().asMilliseconds();
}


void Timer::Reset()
{
	_timer.restart();
}