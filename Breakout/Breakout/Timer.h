#pragma once

#include <SFML/System/Clock.hpp>

class Timer
{
private:
	sf::Clock _timer;
	unsigned int _interval;
	unsigned int _lastTrigger;

public:
	Timer();
	~Timer();

	void SetInterval(int interval);
	bool Trigger();
	int GetDeltaTime();
	void Reset();
};