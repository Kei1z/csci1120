//Lee Ho Kong 1155149106 1155149106@link.cuhk.edu.hk
#include <iostream>
using namespace std;

class KnightsPath {
public:
	const static int N = 6;
	KnightsPath(int r, int c);
	void print() const;
	int getSteps() const;
	bool isValid(int r, int c) const;
	bool hasMoreMoves() const;
	bool move(int r, int c);
private:
	int board[N][N];
	int currentR, currentC;
	int steps;
	int previousR, previousC;
};