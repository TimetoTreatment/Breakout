#include "Timer.h"


Timer* Timer::s_instance = nullptr;


Timer::Timer()
{
	_start = clock();
}


Timer::~Timer()
{

	

}


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


unsigned int Timer::Get()
{
	return clock() - _start;
}


void Timer::Reset()
{
	_start = clock();
}