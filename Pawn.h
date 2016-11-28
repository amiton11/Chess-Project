#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Piece.h"

using namespace std;


class Pawn :public Piece
{
private:
	bool _moved;
public:
	Pawn(bool isWhite, Coordinate, Board*);
	virtual int movePossible(string coordinate);
	virtual int movePossible(Coordinate coordinate);
};