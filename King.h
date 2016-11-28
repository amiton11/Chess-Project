#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Piece.h"

using namespace std;


class King :public Piece
{
public:
	King(bool isWhite, Coordinate, Board*);
	virtual int movePossible(string coordinate);
	virtual int movePossible(Coordinate coordinate);
};