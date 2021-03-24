#include "connect4.h"

void connect4::newGame(){
	for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            board.at(i).at(j) = space;
        }
	}
}

void connect4::playGame(){
    newGame();
	turn = rand()%2;//randomizes who starts
	int move;
	do{
		std::cout << "Player " << turn+1 << "'s turn" << std::endl;//output
		outputBoard();
		std::cout << "Please choose what column to play in: " << std::flush;
		do{
			std::cin >> move;
			if(std::cin.fail()){//makes sure the player only inputs integers
				std::cin.clear();
				std::cin.ignore(50000, '\n');
			}
		}while(std::cin.fail() || move < 1 || move > numCol || isFull(move-1));//makes sure that the move is valid
		makeMove(move-1);
		turn = (++turn)%2;//switches who's turn it is
	}while(!isWon() && !allFull());//makes sure no ones won
	outputBoard();
	cpu.saveGame();
	if(allFull() && !isWon()){
		std::cout << "NO ONE WINS!!!" << std::endl;
		return;
	}
	std::cout << "Congrats Player" << turn +1<< std::endl;
	
}


void connect4::outputBoard(){
	std::string boardstring = "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
 	boardstring += "-----------------------------\n";
   for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            boardstring+= "|" + board.at(i).at(j);
        }
            boardstring += "|\n";
	boardstring += "-----------------------------\n";
	}
	std::cout  << boardstring << std::endl;//loads the board into a single string variable and outputs it
	
}

void connect4::makeMove(int move){
	if(isFull(move)){//error checking
// 		std::cout << "ERROR: CHECK PLAY GAME" << std::endl;
		exit(0);
	}
    std::cout << "turn: " << turn << std::endl;
	for(int i = numRow-1; i >=0; --i){//places character at the next available space, starting at the bottom of a column and heads upwards, or heads from the largest index to the smallest
		if(board.at(i).at(move) == space){
			if(turn == 1){
				board.at(i).at(move) = red;
                break;
			}
			else{
				board.at(i).at(move) = green;
                break;
			}
		}
	}
}

bool connect4::allFull(){
	for(unsigned i = 0; i < numCol; ++i){
		if(!isFull(i)){
			return false;
		}
	}
	return true;
}

bool connect4::isFull(int move){
	if(board.at(0).at(move) == red || board.at(0).at(move) == green){
		return true;
	}
	return false;
}

bool connect4::isWon(){//checks board for 4 in a row
	for(int i = 0; i < numRow; ++i){
        for(int j = 0; j < numCol; ++j){
            if(i < numRow - 3){//check vertically
				if(board.at(i).at(j) != space && (board.at(i).at(j) == board.at(i+1).at(j)) && (board.at(i+1).at(j) == board.at(i+2).at(j)) && (board.at(i+2).at(j) == board.at(i+3).at(j))){
// 					outputBoard();
					return true;
				}
			}
			if(j < numCol - 3){//check horizontally
				if(board.at(i).at(j) != space && (board.at(i).at(j) == board.at(i).at(j+1)) && (board.at(i).at(j+1) == board.at(i).at(j+2)) && (board.at(i).at(j+2) == board.at(i).at(j+3))){
// 					std::cout << "second" << std::endl;
					return true;
				}
			}
			if(i < numRow-3 && j < numCol - 3){//check diagonally downards
				if(board.at(i).at(j) != space && (board.at(i).at(j) == board.at(i+1).at(j+1)) && (board.at(i+1).at(j+1) == board.at(i+2).at(j+2)) && (board.at(i+2).at(j+2) == board.at(i+3).at(j+3))){
// 					std::cout << "third" << std::endl;
					return true;
				}
			}
			if(i > 2 && j < numCol - 3){//check diagonally upwards
				if(board.at(i).at(j) != space && (board.at(i).at(j) == board.at(i-1).at(j+1)) && (board.at(i-1).at(j+1) == board.at(i-2).at(j+2)) && (board.at(i-2).at(j+2) == board.at(i-3).at(j+3))){
// 					std::cout << "third" << std::endl;
					return true;
				}
			}
        }
	}
	return false;
}
