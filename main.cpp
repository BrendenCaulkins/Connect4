#include "connect4.h"
using namespace std;



int main(int argc, char **argv){
	char c;
	srand(time(0));
	connect4 game;
	do{
		game.playGame();
		cout << "Play again?" << endl;
		cin >> c;
	}while(tolower(c) == 'y');

	return 0;
}
