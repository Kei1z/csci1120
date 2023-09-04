//Lee Ho Kong 1155149106 1155149106@link.cuhk.edu.hk
#include <iostream>
#include"KnightsPath.h"
using namespace std;


KnightsPath::KnightsPath(int r, int c) {
	currentC = c;
	currentR = r;
	steps = 0;
	previousC = -1;
	previousR = -1;
	for (int i = 0; i < N; i++) {//setup the board
		for (int j = 0; j < N; j++) {
			if (i == c && j == r) {
				board[i][j] = 0;
			}
			else {
				board[i][j] = -1;

			}

		}
	}

}

void KnightsPath::print() const {// print the board
	cout << "   ";
	for (int i = 0; i < N; i++) {
		cout << char(65 + i) << "  ";

	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == 0) {
				cout << i << "  ";
			}
			if (board[j][i] == -1) {
				cout << ".  ";
			}
			else if (board[j][i] == 0) {
				cout << "k  ";
			}
			else if (board[j][i] == getSteps()) {
				cout << "K  ";
			}
			else {
				if (board[j][i] >= 10) {// if the number is bigger or equal to 10,we need to delete one space
					cout << board[j][i] << " ";
				}
				else {
					cout << board[j][i] << "  ";
				}
				
			}

		}
		cout << endl;
	}
	cout << "Steps: " << getSteps() << endl;
}
int KnightsPath::getSteps() const {//to get the private int steps
	return steps;
}
bool KnightsPath::isValid(int r, int c) const {
	if (r >= 0 && r < N && c >= 0 && c < N) {//check whether the input is within 0 to N-1

	}
	else {
		
		return false;
	}
	if (board[c][r] != -1) {// check whether that location is gone or not
		
		return false;
	}
	if ((int)(currentC - c) == -2 || (int)(currentC - c) == 2) {
		if ((int)(currentR - r) != 1 && (int)(currentR - r) != -1) {
			
			return false;
		}

	}
	else if ((int)(currentC - c) == -1 || ((int)(currentC - c) == 1)) {// check whether it is walked as a horse
		if ((int)(currentR - r) != 2 && (int)(currentR - r) != -2) {
			
			return false;
		}

	}
	else {
		//cout << "checkpt5";
		return false;
	}
	//cout << abs(c - previousC) + abs(r - previousR) << endl;
	if (abs(c - previousC) + abs(r - previousR) <= 2) {//check whether it is turning back
		
		
		return false;
	} return true;
}
bool KnightsPath::hasMoreMoves() const {
	if (isValid(currentR + 2, currentC + 1)) {//consider all the 8 cases that it can move
		return true;
	}
	else if (isValid(currentR + 2, currentC - 1)) {
		return true;
	}
	else if (isValid(currentR + 1, currentC + 2)) {
		return true;
	}
	else if (isValid(currentR + 1, currentC - 2)) {
		return true;
	}
	else if (isValid(currentR - 1, currentC + 2)) {
		return true;
	}
	else if (isValid(currentR - 1, currentC - 2)) {
		return true;
	}
	else if (isValid(currentR - 2, currentC + 1)) {
		return true;
	}
	else if (isValid(currentR - 2, currentC - 1)) {
		return true;
	}
	else {
		return false;
	}

}
bool KnightsPath::move(int r, int c) {
	if (isValid(r, c)) {//the knighs will move only if it is valid
		steps++;
		board[c][r] = steps;
		previousC = currentC;
		previousR = currentR;
		currentC = c;
		currentR = r;

		return true;
	}
	else { return false; }
}
