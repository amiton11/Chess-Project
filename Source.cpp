#include "Pipe.h"
#include <iostream>
#include <thread>
#include "Board.h"

using namespace std;
void main()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	Board *mainBoard = new Board();
	mainBoard->getBoardStr(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		char answer = mainBoard->update(string(msgFromGraphics));

		msgToGraphics[0] = answer;
		msgToGraphics[1] = NULL;

		char boardStr[66];
		mainBoard->getBoardStr(boardStr);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << boardStr[i * 8 + j];
			cout << endl;
		}
		cout << endl;

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
	delete mainBoard;
}