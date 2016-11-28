#include "Pawn.h"
#include "Board.h"
Pawn::Pawn(bool isWhite, Coordinate coordinate, Board *board):Piece(isWhite,coordinate,board)
{
	this->_moved = false;
	if (isWhite)
	{
		this->_type = 'P';
	}
	else
	{
		this->_type = 'p';
	}
}

int Pawn::movePossible(string coordinate)
{
	return movePossible(Coordinate(coordinate));
}

int Pawn::movePossible(Coordinate coordinate)
{
	int dx = coordinate.getX() - this->_coordinate.getX();
	int dy = coordinate.getY() - this->_coordinate.getY();
	if (!((this->_isWhite && dy < 0) || (!(this->_isWhite) && dy > 0))) //we check if its white and go up or black and down, to immune double code
	{
		return 6;
	}
	if (dx == 0)//normal move case
	{
		if ((abs(dy) == 1) && !this->_board->getPiece(Coordinate(coordinate.getY() , coordinate.getX())))
		{
			_moved = true;
			return 0;
		}
		if (!(_moved) && abs(dy) == 2 && !this->_board->getPiece(Coordinate(coordinate.getY() - (dy>0?1:-1), coordinate.getX())) && !this->_board->getPiece(coordinate))// we want to move twice
		{
			_moved = true;
			return 0;
		}
	}
	if (abs(dx) == 1 && abs(dy) == 1 && _board->getPiece(coordinate) &&_board->getPiece(coordinate)->getIsWhite() != this->_isWhite)// for eat case
	{
		return 0;
	}
	return 6;
}
