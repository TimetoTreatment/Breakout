#include "Timer.h"


Timer* Timer::s_instance = nullptr;


Timer* Timer::Instance()
{
	if (s_instance == nullptr)
		s_instance = new Timer;

	return s_instance;
}


void Timer::Release()
{
	delete s_instance;
	s_instance = nullptr;
}


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