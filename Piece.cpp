#pragma once
#include <iostream>
#include "Piece.h"
#include "Coordinate.h"
#include "Board.h"

using namespace std;

Piece::Piece() : _coordinate()
{
	_board = nullptr;
	_type = 0;
	_isWhite = false;
}
Piece::Piece(bool isWhite, Coordinate coordinate, Board* board, char type)
{
	_type = type;
	_isWhite = isWhite;
	_coordinate = coordinate;
	_board = board;
}
bool Piece::getIsWhite()
{
	return _isWhite;
}
char Piece::getType()
{
	return _type;
}
void Piece::setCoordinate(string coordinate)
{
	setCoordinate(Coordinate(coordinate));
}
void Piece::setCoordinate(Coordinate coordinate)
{
	_coordinate = coordinate;
}
void Piece::setBoard(Board* board)
{
	_board = board;
}