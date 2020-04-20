#pragma once

struct Coord
{
	int x;
	int y;

	Coord(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}
};


inline Coord operator + (Coord& lhs, Coord& rhs)
{
	return Coord(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Coord operator - (Coord& lhs, Coord& rhs)
{
	return Coord(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline void operator += (Coord& lhs, Coord& rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
}

inline void operator -= (Coord& lhs, Coord& rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
}

const Coord COORD_ZERO = { 0, 0 };
const Coord COORD_UP = { 0, 1 };
const Coord COORD_RIGHT = { 1, 0 };