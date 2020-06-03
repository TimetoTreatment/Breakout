#pragma once

#include <SFML/System/Clock.hpp>

class Timer
{
private:
	sf::Clock mTimer;

	bool mTriggeredOnce;
	unsigned int mCurrentTime;
	unsigned int mIntervalTime;
	unsigned int mNextTriggerTime;
	unsigned int mTriggerCount;

public:
	Timer();
	~Timer();

	void SetInterval(unsigned int intervalTime);
	bool Trigger();
	unsigned int TriggerCount() const;
	unsigned int GetDeltaTime() const;
	void Reset();
};