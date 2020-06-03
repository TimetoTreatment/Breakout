#include "Random.h"

std::random_device Random::mDevice;
std::mt19937 Random::mEngine(Random::mDevice());


int Random::GetInteger(int rangeStart, int rangeEnd)
{
	std::uniform_int_distribution<int> distribution(rangeStart, rangeEnd);
	return distribution(mEngine);
}


double Random::GetReal(double rangeStart, double rangeEnd)
{
	std::uniform_real_distribution<double> distribution(rangeStart, rangeEnd);
	return distribution(mEngine);
}