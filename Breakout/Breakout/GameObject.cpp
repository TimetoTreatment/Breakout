#include "GameObject.h"





GameObject::GameObject(Coord position)
{
	_position = position;
	_active = true;
	_visible = true;
	_parent = nullptr;
	_drawed = false;
}

GameObject::~GameObject()
{
	_parent = nullptr;
}


void GameObject::Position(Coord position)
{
	_position += position;
}

Coord& GameObject::Position()
{
	return _position;
}


void GameObject::Direction(Coord direction)
{
	_direction = direction;
}

Coord& GameObject::Direction()
{
	return _direction;
}


void GameObject::Active(bool active)
{
	_active = active;
}

bool GameObject::Active()
{
	return _active;
}


void GameObject::Visible(bool visible)
{
	_visible = visible;
}


bool GameObject::Visible()
{
	return _visible;
}


void GameObject::Drawed(bool drawed)
{
	_drawed = drawed;
}


bool GameObject::Drawed()
{
	return _drawed;
}


void GameObject::Parent(GameObject* parent)
{
	_position += parent->Position();
	_parent = parent;
}

GameObject* GameObject::Parent()
{
	return _parent;
}


void GameObject::Translate(Coord coord)
{
	_position += coord;
}


void GameObject::Update()
{

}

void GameObject::Render()
{

}