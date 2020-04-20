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
	assetManager->GetMusic(filename)->play();

	
}


void AudioManager::PauseMusic(string&& filename)
{
	assetManager->GetMusic(filename)->pause();
}


void AudioManager::StopMusic(string&& filename)
{
	assetManager->GetMusic(filename)->stop();
}


void AudioManager::PlaySFX(const string& filename)
{
	static array<sf::Sound, MAX_CHANNEL>::iterator channel = _channels.begin();

	if ((++channel) == _channels.end())
		channel = _channels.begin();

	channel->setBuffer(*assetManager->GetSFX(filename));
	channel->play();
}
