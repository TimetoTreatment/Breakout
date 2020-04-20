#pragma once

class Config
{
private:
	static Config* s_instance;

public:
	static Config* Instance();
	static void Release();

private:
	int _fps;
	int _width;
	int _height;


public:
	Config();

	int FPS()
	{
		return _fps;
	}

	int Width()
	{
		return _width;
	}

	int Height()
	{
		return _height;
	}





};
