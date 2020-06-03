#pragma once
#include <random>

class Random
{
private:

	static std::random_device mDevice;
	static std::mt19937 mEngine;

public:

	static int GetInteger(int rangeStart, int rangeEnd);
	static double GetReal(double rangeStart, double rangeEnd);

};
