#ifndef CONNECT4_H
#define CONNECT4_H

#include<vector>
#include<string>
#include<iostream>
#include "computeropponent.h"

class connect4 {
	private:
	std::string green = " G ", red = " R ", space = "   ";
	int numRow = 6, numCol = 7, turn = 0;
	std::vector<std::vector<std::string>> board;//7acrossx6deep board
	computeropponent cpu;
	public:
	connect4() : board(numRow, std::vector<std::string>(numCol)) {newGame(); cpu.loadBrain();};
	void newGame();
	void playGame();
	void outputBoard();
	void makeMove(int move);
	int getTurn() {return turn;}
	bool allFull();
	bool isFull(int move);
	bool isWon();
	
};

#endif