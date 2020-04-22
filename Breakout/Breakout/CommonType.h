#pragma once

class Coord
{
public:

	int x;
	int y;

	Coord(int inputX = 0, int inputY = 0) : x(inputX), y(inputY) {}

	Coord operator - () const
	{
		return Coord({ -x, -y });
	}

	Coord operator + (const Coord& rhs)
	{
		return Coord(x + rhs.x, y + rhs.y);
	}

	Coord operator - (const Coord& rhs)
	{
		return Coord(x - rhs.x, y - rhs.y);
	}

	void operator += (const Coord& rhs)
	{
		x += rhs.x;
		y += rhs.y;
	}

	void operator -= (const Coord& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
	}
};