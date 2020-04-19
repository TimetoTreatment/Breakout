#pragma once
#include <map>
#include <SFML/Audio.hpp>


using namespace std;



class AssetManager
{
private:

	static AssetManager* s_instance;

	AssetManager();
	~AssetManager();

	//map<string, Layout*> _layout;
	map<string, sf::Music> _music;
	map<string, sf::Sound> _SFX;
	


public:

	static AssetManager* Instance();
	static void Release();











};

