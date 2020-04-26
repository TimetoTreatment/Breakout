#pragma once

#include <SFML/System/Clock.hpp>

class Timer
{
private:
	sf::Clock mTimer;

	bool mTriggeredOnce;
	unsigned int mIntervalTime;
	unsigned int mTriggerCount;
	unsigned int mNextTriggerTime;

public:
	Timer();
	~Timer();

	void SetInterval(unsigned int intervalTime);
	bool Trigger();
	unsigned int TriggerCount() const;
	unsigned int GetDeltaTime() const;
	void Reset();
};