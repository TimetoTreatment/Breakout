#pragma once

#include <SFML/Window.hpp>

class Timer
{
private:
	static Timer* s_instance;

public:
	static Timer* Instance();
	static void Release();

private:
	Timer();
	~Timer();

	sf::Clock _timer;


public:
	int GetDeltaTime();
	void Reset();
};

