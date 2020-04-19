#pragma once
#include <time.h>

class Timer
{
private:

	static Timer* s_instance;
	Timer();
	~Timer();

	clock_t _start;




public:

	static Timer* Instance();
	static void Release();

	unsigned int Get();


	void Reset();


};

