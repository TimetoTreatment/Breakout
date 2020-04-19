#include "LayoutManager.h"


/////////////
/* Private */
/////////////
LayoutManager* LayoutManager::s_instance = nullptr;

LayoutManager::LayoutManager()
{


}


LayoutManager::~LayoutManager()
{


}



////////////
/* Public */
////////////

LayoutManager* LayoutManager::Instance()
{
	if (s_instance == nullptr)
		s_instance = new LayoutManager;

	return s_instance;
}


void  LayoutManager::Release()
{
	delete s_instance;
	s_instance = nullptr;
}