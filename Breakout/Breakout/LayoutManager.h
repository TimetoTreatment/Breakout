#pragma once

class LayoutManager
{
private:

	static LayoutManager* s_instance;

	LayoutManager();
	~LayoutManager();








public:

	static LayoutManager* Instance();
	static void Release();




};

