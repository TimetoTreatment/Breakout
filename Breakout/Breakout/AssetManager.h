#pragma once
#include <unordered_map>
#include "SFML/Audio.hpp"
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

	unordered_map<string, unique_ptr<Music>> _music;
	unordered_map<string, unique_ptr<SoundBuffer>> _sfx;
	unordered_map<string, unique_ptr<Layout>> _layout;

public:
	unique_ptr<Layout>& GetLayout(const string& fileOrString, const Coord& position, const string& textcolor = "default", const string& backcolor = "default");
	unique_ptr<Music>& GetMusic(const string& filename);
	unique_ptr<SoundBuffer>& GetSFX(const string& filename);






};

