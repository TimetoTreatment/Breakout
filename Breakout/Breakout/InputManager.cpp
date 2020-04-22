#include "InputManager.h"


InputManager* InputManager::s_instance = nullptr;

InputManager::InputManager()
{


}


InputManager::~InputManager()
{


}



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


bool InputManager::KeyPressed(sf::Keyboard::Key key)
{
	return sf::Keyboard::isKeyPressed(key);
}