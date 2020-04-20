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
	_width = 130;
	_height = 45;
	_isExit = false;
}