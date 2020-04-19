#pragma once
class InputManager
{

	static InputManager* s_instance;

	InputManager();
	~InputManager();








public:

	static InputManager* Instance();
	static void Release();





};

