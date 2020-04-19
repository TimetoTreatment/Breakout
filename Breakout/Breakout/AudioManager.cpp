#include "AudioManager.h"


/////////////
/* Private */
/////////////
AudioManager* AudioManager::s_instance = nullptr;

AudioManager::AudioManager()
{


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


void  AudioManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}