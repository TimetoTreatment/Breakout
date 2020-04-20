#include "Timer.h"


Timer::Timer()
{
	_timer.restart();
	
}


Timer::~Timer()
{
	
}


int Timer::GetDeltaTime()
{
	return _timer.getElapsedTime().asMilliseconds();
}


void Timer::Reset()
{
	_timer.restart();
}