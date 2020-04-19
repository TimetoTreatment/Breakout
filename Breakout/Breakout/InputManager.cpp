#include "InputManager.h"


/////////////
/* Private */
/////////////
InputManager* InputManager::s_instance = nullptr;

InputManager::InputManager()
{


}


InputManager::~InputManager()
{


}



////////////
/* Public */
////////////

InputManager* InputManager::Instance()
{
	if (s_instance == nullptr)
		s_instance = new InputManager;

	return s_instance;
}


void  InputManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}