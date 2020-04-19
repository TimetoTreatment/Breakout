#pragma once
#include <SFML/Audio.hpp>

class AudioManager
{
private:

	static AudioManager* s_instance;

	AudioManager();
	~AudioManager();








public:

	static AudioManager* Instance();
	static void Release();
};

