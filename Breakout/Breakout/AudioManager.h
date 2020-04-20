#pragma once
#include <SFML/Audio.hpp>
#include "AssetManager.h"
#include "Config.h"
#include <array>

constexpr int MAX_CHANNEL = 256;

class AudioManager
{
private:
	static AudioManager* s_instance;

public:
	static AudioManager* Instance();
	static void Release();


private:

	AudioManager();
	~AudioManager();

	AssetManager* assetManager = AssetManager::Instance();
	array<sf::Sound, MAX_CHANNEL> _channels;

public:

	void PlayMusic(const string& filename);
	void PauseMusic(string&& filename);
	void StopMusic(string&& filename);
	void PlaySFX(const string& filename);



};

