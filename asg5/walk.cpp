//Lee Ho Kong 1155149106 1155149106@link.cuhk.edu.hk
#include <iostream>
#include "KnightsPath.h"
using namespace std;

int main() {
	int row;
	char col;
	bool canrun = false;
	bool isfinish = false;
	bool isfirst = false;
	while (!isfirst) {//the first run
		
		cout << "Enter starting position (col row): ";
		cin >> col >> row ;
		if ((int)(col - 65) >= 0 && (int)(col - 65) < KnightsPath::N && row >= 0 && row < KnightsPath::N) {
			canrun = true;
			isfirst = true;
		}
		else {
			cout << "Invalid. Try again!" << endl;
		}


	}
	
	KnightsPath gameboard(row, (int)col - 65);//set up the gameboard or the knighr move
	gameboard.print(); //print it


	while (!isfinish) {
		cout << "Move the knight (col row): ";
		cin >> col >> row;
		if (gameboard.move(row, (int)col - 65)) {//check if the move is valid
			gameboard.print();
		}
		else {
			cout << "Invalid move. Try again!" << endl;
		}
		if (!gameboard.hasMoreMoves()|| gameboard.getSteps() > ((KnightsPath::N * KnightsPath::N) / 2)) {
			isfinish = true;
			if (!gameboard.hasMoreMoves()) {//check if there has more moves
				
				cout << "Finished! No more moves!" << endl;
			}
			if (gameboard.getSteps()+1 > ((KnightsPath::N * KnightsPath::N) / 2)) {//check whether the knight has visited more than half of the board squares

				
				cout << "Well done!";
			}
			else {
				cout <<  "Still drunk ? Walk wiser!";
			}
			
		}
		
	}
	






}