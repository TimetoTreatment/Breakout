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



void GameEntity::Position(Coord position)
{
	_position += position;
}

Coord& GameEntity::Position()
{
	return _position;
}

void GameEntity::Active(bool active)
{
	_active = active;
}

bool GameEntity::Active()
{
	return _active;
}

void GameEntity::Parent(GameEntity* parent)
{
	_position += parent->Position();
	_parent = parent;
}

GameEntity* GameEntity::Parent()
{
	return _parent;
}

void GameEntity::Translate(Coord coord)
{
	_position += coord;
}

void GameEntity::Update()
{

}

void GameEntity::Render()
{

}