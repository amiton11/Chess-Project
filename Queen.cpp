#include "Queen.h"

Queen::Queen(bool isWhite, Coordinate coordinate, Board * board) : Piece(isWhite,coordinate,board)
{
	if (isWhite)
	{
		this->_type = 'Q';
	}
	else
	{
		this->_type = 'q';
	}
}

int Queen::movePossible(string coordinate)
{
	return this->movePossible(Coordinate(coordinate));
}

int Queen::movePossible(Coordinate coordinate)
{
	Rook tempRook = Rook(this->_isWhite, this->_coordinate, this->_board);
	Bishop tempBishop = Bishop(this->_isWhite, this->_coordinate, this->_board);
	if (tempRook.movePossible(coordinate) == 0 || tempBishop.movePossible(coordinate) == 0)
	{
		return 0;
	}
	return 6;
}