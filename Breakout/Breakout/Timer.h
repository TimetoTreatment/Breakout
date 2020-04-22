#pragma once

#include <SFML/System/Clock.hpp>

class Timer
{
private:
	sf::Clock _timer;

public:
	Timer();
	~Timer();

	int GetDeltaTime();
	void Reset();
};