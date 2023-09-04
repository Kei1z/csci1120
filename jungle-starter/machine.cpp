#include <iostream>
#include <ctime>
#include <cstdlib>
#include "machine.h"
#include "game.h"
#include "board.h"

using namespace std;

Machine::Machine(string name, Color color) : Player(name, color) {
    // TODO: randomize the seed of random number generator 
    //       using the current time
    std::srand(std::time(0));
    

}

// a sample machine that makes random valid moves
void Machine::makeMove(Board* board) {
    // TODO: make a random but valid move of a randomly picked piece on a board
    // Hint: there exist many ways to do so, one way is as follows:
    // - generate a random integer for picking a piece r from the player's pieces vector
    // - set y1, x1 to r->getY(), r->getX()
    // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
    //   [or better in the y, x range of the 4 neighboring cells around (y1, x1), note to
    //    handle jumpable cells, 2 or 3 cells away, as well for Tiger and Lion]
    // - call board's move(y1, x1, y2, x2)
    // - once a valid move is returned, print the from and to cell addresses 
    //   and exit this function
    // Note: it can happen that no valid move can be found despite repeated picks.
    //       For example, only a Rat remains alive at a corner of the board while 
    //       the two cells it may go have been occupied by a Cat and a Dog.
    //       In this case, the player must surrender (set the opponent as winner).
    while (true) {
        
        Piece* r = this->getPiece(std::rand() % (this->getPieceCount()));
        int y1 = r->getY();
        int x1 = r->getX();
        
        int y2 = std::rand() % (board->H);
        int x2 = std::rand() % (board->W);
        
        if (this->getPieceCount() == 1) {
            int check = 0;
            if (r->getName() != "Lion" || r->getName() != "Tiger") {
                while (check < 4) {
                    if (board->isMoveValid(y1, x1, y1 + 1, x1)) {
                        break;
                    }
                    else {
                        check++;
                    }
                    if (board->isMoveValid(y1, x1, y1 - 1, x1)) {
                        break;
                    }
                    else {
                        check++;
                    }
                    if (board->isMoveValid(y1, x1, y1, x1 + 1)) {
                        break;
                    }
                    else {
                        check++;
                    }
                    if (board->isMoveValid(y1, x1, y1, x1 - 1)) {
                        break;
                    }
                    else {
                        check++;
                    }
                }
                if (check == 4) {
                    cout << this->getName() << "'s turn: ";
                    cout << "Z0 Z0" << endl;
                    board->getGame()->setState(GAME_OVER);
                    board->getGame()->setTurn(Color(1 - (int)(board->getGame()->getTurn())));
                    return;
                }
            }
            
        }
        bool valid = board->move(y1, x1, y2, x2);
        if (valid) {
            cout << this->getName() << "'s turn: ";
            int outputy2 = (int)(y2 + 1);
            int outputy1 = (int)(y1 + 1);
            int outputx2 = (int)(x2 + 'A');
            int outputx1 = (int)(x1 + 'A');
            cout << (char)outputx1 << outputy1 << " " << (char)outputx2 << outputy2 << endl;
            break;
        }

    }

}
