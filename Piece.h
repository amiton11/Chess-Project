#pragma once
#include <iostream>

#include "Coordinate.h"

using namespace std;

class Board;


class Piece
{
protected:
	bool _isWhite;// owner
	Coordinate _coordinate;// location on the board
	Board* _board;// pointer to the board this piece on
	char _type;// piece type, match the char the fronthead want to get ('K' for white king for example)
public:
	Piece();
	Piece(bool isWhite, Coordinate, Board*, char type = 0);

	// if this piece can move to the given coordinate on the board
	virtual int movePossible(string coordinate) = 0;
	virtual int movePossible(Coordinate coordinate) = 0;
	
	//getters and setters
	bool getIsWhite();
	char getType();
	void setCoordinate(string coordinate);
	void setCoordinate(Coordinate coordinate);
	void setBoard(Board* board);
};