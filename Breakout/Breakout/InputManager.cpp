#include "InputManager.h"


InputManager* InputManager::s_instance = nullptr;

InputManager::InputManager()
{
	mLastKey = sf::Keyboard::Unknown;
	mContinued = false;
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


bool InputManager::KeyPressedOnce(sf::Keyboard::Key key)
{
	if (sf::Keyboard::isKeyPressed(key) && !mContinued)
	{
		mLastKey = key;
		return 1;
	}

	return 0;
}


void InputManager::Update()
{
	mContinued = sf::Keyboard::isKeyPressed(mLastKey);
}