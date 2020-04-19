#pragma once

struct Coord
{
	int x;
	int y;

	Coord(int inputX, int inputY) : x(inputX), y(inputY) {}

	




};


Coord operator + (Coord& lhs, Coord& rhs)
{
	return Coord(lhs.x + rhs.x, lhs.y + rhs.y);
}

Coord operator - (Coord& lhs, Coord& rhs)
{
	return Coord(lhs.x - rhs.x, lhs.y - rhs.y);
}

void operator += (Coord& lhs, Coord& rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
}

void operator -= (Coord& lhs, Coord& rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
}