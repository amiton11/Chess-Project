#pragma once
#include <iostream>
#include "Knight.h"

using namespace std;

Knight::Knight(bool isWhite, Coordinate coordinate, Board* board) : Piece(isWhite, coordinate, board)
{
	if (isWhite)
		_type = 'N';
	else
		_type = 'n';
}
int Knight::movePossible(string coordinate)
{
	return movePossible(Coordinate(coordinate));
}
int Knight::movePossible(Coordinate coordinate)
{
	int dx = _coordinate.getX() - coordinate.getX();
	int dy = _coordinate.getY() - coordinate.getY();
	if ((abs(dx) == 1 && abs(dy) == 2) || (abs(dx) == 2 && abs(dy) == 1))
		return 0;
	return 6;
}