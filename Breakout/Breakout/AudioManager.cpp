#include "AudioManager.h"


/////////////
/* Private */
/////////////
AudioManager* AudioManager::s_instance = nullptr;

AudioManager::AudioManager()
{
;

}


AudioManager::~AudioManager()
{




}



////////////
/* Public */
////////////

AudioManager* AudioManager::Instance()
{
	if (s_instance == nullptr)
		s_instance = new AudioManager;

	return s_instance;
}


void AudioManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}



void AudioManager::PlayMusic(const string& filename)
{
	if (assetManager->GetMusic(filename)->getStatus() != sf::Music::Playing)
	{
		


		assetManager->GetMusic(filename)->play();
		_currentMusicFile = filename;
	}
}


void AudioManager::PauseMusic()
{
	assetManager->GetMusic(_currentMusicFile)->pause();
}


void AudioManager::StopMusic()
{
	assetManager->GetMusic(_currentMusicFile)->stop();
}


void AudioManager::PlaySFX(const string& filename)
{
	static array<sf::Sound, MAX_CHANNEL>::iterator channel = _channels.begin();

	if ((++channel) == _channels.end())
		channel = _channels.begin();

	channel->setBuffer(*assetManager->GetSFX(filename));
	channel->play();
}

bool AudioManager::isMusicPlayed()
{
	if (assetManager->GetMusic(_currentMusicFile)->getStatus() == sf::Music::Playing)
		return true;

	return false;
}