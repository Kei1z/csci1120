#include "rat.h"
#include <iostream>

using namespace std;

Rat::Rat(Color color, int y, int x) : Piece(color, y, x) {
    setName(PIECE_NAME[RAT-1]);
    setRank(RAT);
}

bool Rat::isMoveValid(Board* board, int y, int x) {
    // TODO: Override the superclass version of valid move checks
    // e.g., to allow a Rat to move into a square occuppied by an Elephant 
    //       to allow a Rat to enter a water square
    if (abs(getY() - y) + abs(getX() - x) == 1) { //moved only 1 square
        if (isOpponent(board->get(y, x)) && canCapture(board->get(y, x))) {
            if (board->isRiver(getY(), getX()) && !board->isRiver(y, x)) {
                return false;
            }
            else if (!board->isRiver(getY(), getX()) && board->isRiver(y, x)) {
                return false;
            }
            else {
                return true;
            }

        }
        else if (board->isRiver(y, x)) {
            return true;
        }
        else {
            return Piece::isMoveValid(board, y, x);
        }

    }
    else {
        return false;
    }
    



    
}

bool Rat::canCapture(Piece* p) {
    // TODO: Override the superclass version of capture checks
    // A Rat can capture an Elephant
    if (p->isTrapped()) {

        return true;
    }
    
    if (p->getRank()==8) {

        return true;
    }
    else if (this->getRank() >= p->getRank()) {
        return true;
    }
    else {

        return false;
    }
    
}