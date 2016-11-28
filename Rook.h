#pragma once
#include <iostream>
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"

using namespace std;

class Rook : public Piece
{
public:
	Rook(bool isWhite, Coordinate, Board*);
	virtual int movePossible(string coordinate);
	virtual int movePossible(Coordinate coordinate);
};