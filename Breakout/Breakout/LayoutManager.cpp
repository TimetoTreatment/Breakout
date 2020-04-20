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
