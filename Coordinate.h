#pragma once
#include <iostream>

using namespace std;

class Coordinate
{
private:
	int _y;
	int _x;
public:
	Coordinate();
	Coordinate(string coordinate);
	Coordinate(int y, int x);
	bool operator==(const Coordinate &other);
	void update(int y, int x);
	int getY() const;
	int getX() const;
	void check() const;
};