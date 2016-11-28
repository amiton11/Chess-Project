#pragma once
#include <iostream>
#include "Rook.h"

using namespace std;

Rook::Rook(bool isWhite, Coordinate coordinate, Board* board) : Piece(isWhite, coordinate, board)
{
	if (isWhite)
		_type = 'R';
	else
		_type = 'r';
}
int Rook::movePossible(string coordinate)
{
	return movePossible(Coordinate(coordinate));
}
int Rook::movePossible(Coordinate coordinate)
{
	Piece* check = _board->getPiece(_coordinate);
	Piece* check2 = this;
	Piece* check3 = _board->getPiece(coordinate);
	if (coordinate.getX() != _coordinate.getX() && coordinate.getY() == _coordinate.getY())
	{
		if (coordinate.getX() >= _coordinate.getX())
		{
			for (int i = _coordinate.getX() + 1; i < coordinate.getX(); i++)
				if (_board->getPiece(Coordinate(_coordinate.getY(), i)) != nullptr)
					return 6;
		}
		else
		{
			for (int i = _coordinate.getX() - 1; i > coordinate.getX(); i--)
				if (_board->getPiece(Coordinate(_coordinate.getY(), i)) != nullptr)
					return 6;
		}
		return 0;
	}
	else if (coordinate.getX() == _coordinate.getX() && coordinate.getY() != _coordinate.getY())
	{
		if (coordinate.getY() >= _coordinate.getY())
		{
			for (int i = _coordinate.getY() + 1; i < coordinate.getY(); i++)
				if (_board->getPiece(Coordinate(i, _coordinate.getX())) != nullptr)
					return 6;
		}
		else
		{
			for (int i = _coordinate.getY() - 1; i > coordinate.getY(); i--)
				if (_board->getPiece(Coordinate(i, _coordinate.getX())) != nullptr)
					return 6;
		}
		return 0;
	}
	else 
		return 6;
}