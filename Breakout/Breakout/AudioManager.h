#pragma once
#include <SFML/Audio.hpp>
#include <array>
#include "AssetManager.h"
#include "Status.h"

constexpr int MAX_CHANNEL = 128;

class AudioManager
{
private:
	static AudioManager* s_instance;

public:
	static AudioManager* Instance();
	static void Release();


	string _currentMusicFile;

private:

	AudioManager();
	~AudioManager();

	AssetManager* assetManager;
	array<sf::Sound, MAX_CHANNEL> mChannels;
	array<sf::Sound, MAX_CHANNEL>::iterator mChannel;
	

public:

	void PlayMusic(const string& filename);
	void PauseMusic();
	void StopMusic();
	void PlaySFX(const string& filename);

	bool isMusicPlayed();
};