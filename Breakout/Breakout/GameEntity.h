#pragma once
#include "CommonType.h"


class GameEntity
{
private:


	bool _active;
	GameEntity* _parent;
	Coord _position;



public:
	GameEntity(Coord position = COORD_ZERO);
	~GameEntity();

	void Position(Coord position);

	Coord& Position();

	void Active(bool active);

	bool Active();

	void Parent(GameEntity* parent);

	GameEntity* Parent();

	void Translate(Coord coord);

	virtual void Update();

	virtual void Render();

};