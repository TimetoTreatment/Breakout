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

	void Position(Coord position)
	{
		_position += position;
	}

	Coord& Position()
	{
		return _position;
	}

	void Active(bool active)
	{
		_active = active;
	}

	bool Active()
	{
		return _active;
	}

	void Parent(GameEntity* parent)
	{
		_position += parent->Position();
		_parent = parent;
	}

	GameEntity* Parent()
	{
		return _parent;
	}

	void Translate(Coord coord)
	{
		_position += coord;
	}

	virtual void Update()
	{

	}

	virtual void Render()
	{

	}

};