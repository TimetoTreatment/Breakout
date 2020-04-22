#pragma once
#include "CommonType.h"


class GameObject
{
private:


	bool _active;
	bool _visible;
	bool _drawed;
	GameObject* _parent;
	Coord _position;



public:
	GameObject(Coord position = { 0, 0 });
	~GameObject();

	void Position(Coord position);
	Coord& Position();

	void Active(bool active);
	bool Active();

	void Visible(bool visible);
	bool Visible();

	void Drawed(bool drawed);
	bool Drawed();

	void Parent(GameObject* parent);
	GameObject* Parent();

	void Translate(Coord coord);

	virtual void Update();
	virtual void Render();
};