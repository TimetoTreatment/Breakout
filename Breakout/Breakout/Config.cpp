#include "Config.h"

Config* Config::s_instance = nullptr;

Config* Config::Instance()
{
	if (s_instance == nullptr)
		s_instance = new Config;

	return s_instance;
}

void Config::Release()
{
	delete s_instance;
	s_instance = nullptr;
}

Config::Config()
{
	_fps = 60;
	_width = 5;
	_height = 5;
	_isExit = false;
}