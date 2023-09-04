#include "jumper.h"
#include <algorithm>

using namespace std;

Jumper::Jumper() {
}

/* Check if animal p can jump over a river
   The 'steps' argument is used to control how many river cells to test.
   Call isJumpable(board, p, y, x, 2) to test if p can do a horizontal river jump (2 steps)
   Call isJumpable(board, p, y, x, 3) to test if p can do a vertical river jump (3 steps)
   Return true if p can jump and false otherwise (e.g. due to blocking by a Rat in river)
 */
bool Jumper::isJumpable(Board* board, Piece* p, int y, int x, int steps) {

    /* TODO: Add code to check if p can jump over 'steps' river squares
             to the destination(y, x) */
    bool valid = false;
    if (p->getName() == "Lion" || p->getName() == "Tiger") {
        if (((abs)(p->getY() - y) == steps + 1 && (p->getX() - x == 0)) || ((abs)(p->getX() - x) == steps + 1 && (p->getY() - y == 0))) {
            if (steps == 3) {
                if (y == 2 || y == 6) {
                    if (x == 1 || x == 2 || x == 4 || x == 5) {
                        valid = true;
                    }
                }
            }

            else if (steps == 2) {
                if (x == 0 || x == 3 || x == 6) {
                    if (y == 3 || y == 4 || y == 5) {
                        valid = true;
                    }
                }

            }
        }

    }
    if (valid) {
        if (steps == 3) {
            if (!board->isEmpty(3, p->getX())) {
                if (board->get(3, p->getX())->getRank() == 1) {
                    return false;
                }
            }
            else if (!board->isEmpty(4, p->getX())) {
                if (board->get(4, p->getX())->getRank() == 1) {
                    return false;
                }
            }
            else if (!board->isEmpty(5, p->getX())) {
                if (board->get(5, p->getX())->getRank() == 1) {
                    return false;
                }
            }
            else {
                return true;
            }



        }
        else if (steps == 2) {
            if (p->getX() == 0) {
                if (!board->isEmpty(p->getY(), 1)) {
                    if (board->get(p->getY(), 1)->getRank() == 1) {
                        return false;
                    }
                } 
                else if (!board->isEmpty(p->getY(), 2)) {
                    if (board->get(p->getY(), 2)->getRank() == 1) {
                        return false;
                    }
                }
                else {
                    return true;
                }

            }
            if (p->getX() == 3 && x == 0) {
                if (!board->isEmpty(p->getY(), 1)) {
                    if (board->get(p->getY(), 1)->getRank() == 1) {
                        return false;
                    }
                }
                else if (!board->isEmpty(p->getY(), 2)) {
                    if (board->get(p->getY(), 2)->getRank() == 1) {
                        return false;
                    }
                }
                else {
                    return true;
                }
            }
            if (p->getX() == 3 && x == 6) {
                if (!board->isEmpty(p->getY(), 4)) {
                    if (board->get(p->getY(), 4)->getRank() == 1) {
                        return false;
                    }
                }
                else if (!board->isEmpty(p->getY(), 5)) {
                    if (board->get(p->getY(), 5)->getRank() == 1) {
                        return false;
                    }
                }
                else {
                    return true;
                }
            }
            if (p->getX() == 6) {
                if (!board->isEmpty(p->getY(), 4)) {
                    if (board->get(p->getY(), 4)->getRank() == 1) {
                        return false;
                    }
                }
                else if (!board->isEmpty(p->getY(), 5)) {
                    if (board->get(p->getY(), 5)->getRank() == 1) {
                        return false;
                    }
                }
                else {
                    return true;
                }
            }

        }
            
    }

    return false;
}