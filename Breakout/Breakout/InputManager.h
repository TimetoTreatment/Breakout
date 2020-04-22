#pragma once
#include "SFML/Window/Keyboard.hpp"
#include <string>


using namespace std;


class InputManager
{
private:
	static InputManager* s_instance;
	InputManager();
	~InputManager();

public:
	static InputManager* Instance();
	static void Release();

private:





public:
	bool KeyPressed(sf::Keyboard::Key key);






};

