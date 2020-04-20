#include "GameEntity.h"





GameEntity::GameEntity(Coord position)
{
	_position = position;
	_active = true;
	_parent = nullptr;
}

GameEntity::~GameEntity()
{
	_parent = nullptr;
}


