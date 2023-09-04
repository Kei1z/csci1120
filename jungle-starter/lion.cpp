#include "lion.h"
#include <iostream>

using namespace std;

Lion::Lion(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[LION - 1]);
    setRank(LION);
}

bool Lion::isMoveValid(Board* board, int y, int x) {
    if (isJumpable(board, this, y, x, 2) || isJumpable(board, this, y, x, 3)) {
        return Piece::isMoveValid(board, y, x);
    }
    else if (abs(getY() - y) + abs(getX() - x) == 1) { // move other than 1 square
        return Piece::isMoveValid(board, y, x);
    }
    return false;
}
