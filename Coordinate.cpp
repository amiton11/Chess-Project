#include <iostream>
#include "Coordinate.h"

using namespace std;

Coordinate::Coordinate()
{
	_y = 0;
	_x = 0;
}
Coordinate::Coordinate(string coordinate)
{
	_y = '8' - coordinate[1];
	_x = coordinate[0] - 'a';
}
Coordinate::Coordinate(int y, int x)
{
	_y = y;
	_x = x;
}
void Coordinate::update(int y, int x)
{
	_y = y;
	_x = x;
}

bool Coordinate::operator==(const Coordinate &other)
{
	if (other._x == _x && other._y == _y)
		return true;
	return false;
}
int Coordinate::getY() const
{
	return _y;
}
int Coordinate::getX() const
{
	return _x;
}
void Coordinate::check() const
{
	if (_x < 0 || _x > 7)
		throw "Not a valid X value";
	if (_y < 0 || _y > 7)
		throw "Not a valid Y value";
}