#ifndef QUEEN_H
#define QUEEN_H

#include <iostream>
#include "Coordinate.h"
#include "Bishop.h"
#include "Rook.h"
using namespace std;


class Queen : public Piece
{
public:
	Queen(bool isWhite, Coordinate, Board*);
	virtual int movePossible(string coordinate);
	virtual int movePossible(Coordinate coordinate);
};

#endif