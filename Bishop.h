#pragma once
#include <iostream>
#include "Board.h"
#include "Coordinate.h"
#include "Piece.h"

using namespace std;

class Bishop : public Piece
{
public:
	Bishop(bool isWhite, Coordinate, Board*);
	virtual int movePossible(string coordinate);
	virtual int movePossible(Coordinate coordinate);
};