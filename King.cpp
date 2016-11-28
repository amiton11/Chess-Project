#include "king.h"


King::King(bool isWhite, Coordinate coordinate, Board* board) : Piece(isWhite, coordinate, board)
{
	if (isWhite)
		_type = 'K';
	else
		_type = 'k';
}
int King::movePossible(string coordinate)
{
	return movePossible(Coordinate(coordinate));
}
int King::movePossible(Coordinate coordinate)
{
	int dx = coordinate.getX() - _coordinate.getX();
	int dy = coordinate.getY() - _coordinate.getY();

	if ((dx == 1 || dx == 0 || dx == -1) && (dy == 1 || dy == 0 || dy == -1)) // we check in the board dx and dy != 0
	{
		return 0;
	}
	return 6;
}
