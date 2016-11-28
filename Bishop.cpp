#include "Bishop.h"

Bishop::Bishop(bool isWhite, Coordinate coordinate, Board * board):Piece(isWhite,coordinate,board)
{
	if (isWhite)
	{
		this->_type = 'B';
	}
	else
	{
		this->_type = 'b';
	}
}

int Bishop::movePossible(string coordinate)
{
	return movePossible(Coordinate(coordinate));
}
int Bishop::movePossible(Coordinate coordinate)
{
	int curr_x = this->_coordinate.getX();// to make the code more readable
	int curr_y = this->_coordinate.getY();
	int dx = coordinate.getX() - curr_x;
	int dy = coordinate.getY() - curr_y;
	if (abs(dx) != abs(dy))
	{
		return 6;
	} 
	for (int i = 1;i < abs(dx);i++)
	{
		if (this->_board->getPiece(Coordinate(dy>0 ? curr_y + i : curr_y - i, dx > 0 ? curr_x + i : curr_x - i)))
		{
			return 6;
		}
	}
	return 0;
}