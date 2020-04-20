#include "LayoutManager.h"

LayoutManager* LayoutManager::s_instance = nullptr;

LayoutManager* LayoutManager::Instance()
{
	if (s_instance == nullptr)
		s_instance = new LayoutManager;

	return s_instance;
}

void LayoutManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}


LayoutManager::LayoutManager()
{

}


LayoutManager::~LayoutManager()
{

}


Layout* LayoutManager::New(const string& filename, const Coord& position, const string& textColor, const string& backColor)
{
	return AssetManager::Instance()->GetLayout(filename, position, textColor, backColor).get();
}