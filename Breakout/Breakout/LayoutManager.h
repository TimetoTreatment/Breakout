#pragma once
#include "AssetManager.h"


class LayoutManager
{

private:
	static LayoutManager* s_instance;

public:
	static LayoutManager* Instance();
	static void Release();

private:

	LayoutManager();
	~LayoutManager();


public:

	Layout* New(const string& filename, const Coord& position = COORD_ZERO, const string& textColor = "default", const string& backColor = "default");
};

