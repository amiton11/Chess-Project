#include "Board.h"
/*
Piece* _sqares[8 * 8 + 8];
char _boardStr[66];
bool _whiteTurn;
*/

Board::Board()
{
	_whiteTurn = true;
	strcpy_s(_boardStr,sizeof(char)*66, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1");
	strToSquares();
}
Board::Board(char boardstr[66], bool isWhite)
{
	strcpy_s(_boardStr, sizeof(char) * 66, boardstr);
	_whiteTurn = isWhite;
	strToSquares();
}
Board::~Board()
{
	for (int i = 0; i < 64; i++)
		delete _sqares[i];
}
void Board::squaresToStr()
{
	for (int i = 0; i < 64; i++)
	{
		if (_sqares[i] == nullptr)
			_boardStr[i] = '#';
		else
			_boardStr[i] = _sqares[i]->getType();
	}
}
void Board::strToSquares()
{
	for (int i = 0; i<64;i++)
	{
		switch (_boardStr[i])
		{
		case '#':
			_sqares[i] = nullptr;
			break;
		case 'k':
			_sqares[i] = new King(false, Coordinate(i / 8, i % 8), this);
			break;
		case 'K':
			_sqares[i] = new King(true, Coordinate(i / 8, i % 8), this);
			break;
		case 'r':
			_sqares[i] = new Rook(false, Coordinate(i / 8, i % 8), this);
			break;
		case 'R':
			_sqares[i] = new Rook(true, Coordinate(i / 8, i % 8), this);
			break;
		case 'B':
			_sqares[i] = new Bishop(true, Coordinate(i / 8, i % 8), this);
			break;
		case 'b':
			_sqares[i] = new Bishop(false, Coordinate(i / 8, i % 8), this);
			break;
		case 'Q':
			_sqares[i] = new Queen(true, Coordinate(i / 8, i % 8), this);
			break;
		case 'q':
			_sqares[i] = new Queen(false, Coordinate(i / 8, i % 8), this);
			break;
		case 'n':
			_sqares[i] = new Knight(false, Coordinate(i / 8, i % 8), this);
			break;
		case 'N':
			_sqares[i] = new Knight(true, Coordinate(i / 8, i % 8), this);
			break;
		case 'P':
			_sqares[i] = new Pawn(true, Coordinate(i / 8, i % 8), this);
			break;
		case 'p':
			_sqares[i] = new Pawn(false, Coordinate(i / 8, i % 8), this);
			break;
		default:
			_sqares[i] = nullptr;
			break;
		}
	}
}


char Board::update(string command)
{
	Coordinate sourceCord(command.substr(0, 2));
	Coordinate destCord(command.substr(2, 2));
	try
	{
		sourceCord.check();
		destCord.check();
	}
	catch (...)
	{
		return '5'; //not valid indexes
	}
	if (sourceCord == destCord)
		return '7'; //source sqare and dest sqare are the same
	if (_sqares[sourceCord.getY() * 8 + sourceCord.getX()] == nullptr)
		return '2'; //no piece in source sqare
	if (_sqares[sourceCord.getY() * 8 + sourceCord.getX()]->getIsWhite() != _whiteTurn)
		return '2'; //no piece from the current player's color in source sqare
	if (_sqares[destCord.getY() * 8 + destCord.getX()] != nullptr)
		if (_sqares[destCord.getY() * 8 + destCord.getX()]->getIsWhite() == _whiteTurn)
			return '3'; //there is a piece from the current player's color in dest sqare
	char tempRtrnVal = _sqares[sourceCord.getY() * 8 + sourceCord.getX()]->movePossible(destCord);
	if (tempRtrnVal == 6)
		return '6'; //unvalid movement of this piece type
	Board tempBoard(_boardStr, _whiteTurn);
	tempBoard.setPiece(destCord, tempBoard._sqares[sourceCord.getY() * 8 + sourceCord.getX()]);
	tempBoard._sqares[sourceCord.getY() * 8 + sourceCord.getX()] = nullptr;
	for (int i = 0; i < 64; i++)
	{
		if (tempBoard._sqares[i] != nullptr)
			tempBoard._sqares[i]->setBoard(&tempBoard);
	}
	int chess = tempBoard.checkChess();
	switch (chess)
	{
	case 0:
		setPiece(destCord, _sqares[sourceCord.getY() * 8 + sourceCord.getX()]);
		_sqares[sourceCord.getY() * 8 + sourceCord.getX()] = nullptr;
		_whiteTurn = !_whiteTurn;
		squaresToStr();
		return '0'; // lagitimate move without chess
		break; 
	case 3:
		return '3'; //chess on both players
		break;
	case 1:
		if (_whiteTurn)
			return '4'; //will bring to chess on yourself
		else
		{
			setPiece(destCord, _sqares[sourceCord.getY() * 8 + sourceCord.getX()]);
			_sqares[sourceCord.getY() * 8 + sourceCord.getX()] = nullptr;
			_whiteTurn = !_whiteTurn;
			squaresToStr();
			return '1'; //chess on other player
		}
		break;
	case 2:
		if (!_whiteTurn)
			return '4'; //will bring to chess on yourself
		else
		{
			setPiece(destCord, _sqares[sourceCord.getY() * 8 + sourceCord.getX()]);
			_sqares[sourceCord.getY() * 8 + sourceCord.getX()] = nullptr;
			_whiteTurn = !_whiteTurn;
			squaresToStr();
			return '1'; //chess on other player		
		}
		break;
	default:
		return '0' + tempRtrnVal;
		break;
	}
}

Piece* Board::getPiece(string coordinate)
{
	return getPiece(Coordinate(coordinate));
}

Piece* Board::getPiece(Coordinate coordinate)
{
	return _sqares[coordinate.getY() * 8 + coordinate.getX()];
}
void Board::setPiece(string coordinate, Piece* piece)
{
	this->setPiece(Coordinate(coordinate), piece);
}
void Board::setPiece(Coordinate coordinate, Piece* piece)
{
	if (_sqares[coordinate.getY() * 8 + coordinate.getX()] != nullptr)
	{
		try
		{
			delete _sqares[coordinate.getY() * 8 + coordinate.getX()];
			_sqares[coordinate.getY() * 8 + coordinate.getX()] = nullptr;
		}
		catch (exception){} //in case the sqare wasn't dynamicly assigned, we don't want delete to collapse the program 
	}
	_sqares[coordinate.getY() * 8 + coordinate.getX()] = piece;
	_sqares[coordinate.getY() * 8 + coordinate.getX()]->setCoordinate(coordinate);
}
void Board::setBoardStr(char* inputBoardStr)
{
	for (int i = 0; i < 64; i++)
		_boardStr[i] = inputBoardStr[i];
}
void Board::getBoardStr(char* outputBoardStr)
{
	for (int i = 0; i < 64; i++)
		outputBoardStr[i] = _boardStr[i];
	outputBoardStr[64] = '0' + (!_whiteTurn);
	outputBoardStr[65] = NULL;
}

int Board::checkChess()
{
	int status = 0; //0 - no chess, 1 - chess on white, 2 - chess on black, 3 - chess on both players
	for (int i = 0; i < 64; i++)
	{
		if (_sqares[i / 8 * 8 + i % 8] != nullptr && (_sqares[i / 8 * 8 + i % 8]->getType() == 'k' || _sqares[i / 8 * 8 + i % 8]->getType() == 'K'))
		{
			for (int j = 0; j < 64; j++)
			{
				if (_sqares[j / 8 * 8 + j % 8] != nullptr)
				{
					if (_sqares[j / 8 * 8 + j % 8]->getIsWhite() != _sqares[i / 8 * 8 + i % 8]->getIsWhite() && _sqares[j / 8 * 8 + j % 8]->movePossible(Coordinate(i / 8, i % 8)) == 0)
					{
						if (status == 0)
						{
							if (_sqares[i / 8 * 8 + i % 8]->getIsWhite())
								status = 1;
							else
								status = 2;
						}
						else if (status == 1 && _sqares[i / 8 * 8 + i % 8]->getIsWhite() == false)
							return 3;
						else if (status == 2 && _sqares[i / 8 * 8 + i % 8]->getIsWhite())
							return 3;
					}
				}
			}
		}
	}
	return status;
}
