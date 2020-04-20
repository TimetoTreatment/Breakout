#pragma once
#include <map>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Layout.h"


using namespace std;	// C++ Standard
using namespace sf;		// SFML


class AssetManager
{
private:
	static AssetManager* s_instance;

public:
	static AssetManager* Instance();
	static void Release();

private:

	AssetManager();
	~AssetManager();

	map<string, Music*> _music;
	map<string, SoundBuffer*> _sfx;
	map<string, Layout*> _layout;

public:
	Layout* GetLayout(const string& filename, const Coord& position, const string& textcolor = "default", const string& backcolor = "default");
	Music* GetMusic(const string& filename);
	SoundBuffer* GetSFX(const string& filename);






};

