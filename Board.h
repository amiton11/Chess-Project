#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Piece.h"
#include "Coordinate.h"
#include "King.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"

using namespace std;

class Board
{
private:
	Piece* _sqares[64];
	char _boardStr[66];
	bool _whiteTurn;
	void squaresToStr(); //updating the boardstr accornig to the squares array
	void strToSquares();//creating a pieces according to the string, dont delete previos memory, this function made only for initialization
	int checkChess();// checking for chess in both sides, made to support update function


public:
	Board(); // the default c'tor for normal chess game
	Board(char[66], bool isWhite = true); // ctor for a custom game
	char Board::update(string command);// doing all the checkings, return a number(as char) to the fonthead(0-7) 

	// getters and setters
	Piece* getPiece(Coordinate coordinate);
	Piece* getPiece(string coordinate);
	void setPiece(Coordinate coordinate, Piece* piece);
	void setPiece(string coordinate, Piece* piece);
	void setBoardStr(char* inputBoardStr);
	void getBoardStr(char* outputBoardStr);
	~Board();
};
#endif