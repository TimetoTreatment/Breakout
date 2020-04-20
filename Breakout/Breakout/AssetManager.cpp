#include "AssetManager.h"

AssetManager* AssetManager::s_instance = nullptr;

AssetManager* AssetManager::Instance()
{
	if (s_instance == nullptr)
		s_instance = new AssetManager;

	return s_instance;
}

void AssetManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{
	
}




Layout* AssetManager::GetLayout(const string& filename, const Coord& position,const string& textColor, const string& backColor)
{
	string path = "Assets/layout/" + filename;
	string key = path + textColor + backColor;

	if (_layout[key] == nullptr)
	{
		_layout[key] = new Layout;
		_layout[key]->OpenFromFile(path);
		_layout[key]->Color(textColor, backColor);
		_layout[key]->Position(position);
	}

	return _layout[key];
}


sf::Music* AssetManager::GetMusic(const string& filename)
{
	string path = "assets/music/" + filename;

	if (_music[path] == nullptr)
	{
		_music[path] = new sf::Music;
		_music[path]->openFromFile(path);
	}

	return _music[path];
}


sf::SoundBuffer* AssetManager::GetSFX(const string& filename)
{
	string path = "assets/sfx/" + filename;

	if (_sfx[path] == nullptr)
	{
		_sfx[path] = new sf::SoundBuffer;
		_sfx[path]->loadFromFile(path);
	}

	return _sfx[path];
}