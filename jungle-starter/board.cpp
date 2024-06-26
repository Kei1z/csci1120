
#include <iostream>
#include <cctype>
#include "game.h"
#include "board.h"
#include "piece.h"
#include "elephant.h"
#include "lion.h"
// TODO: include more necessary headers
#include "tiger.h"
#include "leopard.h"
#include "wolf.h"
#include "dog.h"
#include "cat.h"
#include "rat.h"
#include "fileman.h"

using namespace std;

Board::Board(Game* game, char* filename) : 
    game(game), cells() {  // initalize cells' elements to nullptr
    // Set up the initial game board
    if (filename != nullptr)
        loadFromFile(filename, this);
    else
        init();
}

// initial gameboard configuration
void Board::init() {
    // TODO:
    // set up the Jungle chess standard initial gameboard properly;
    // add Elephants, Lions, ..., Rats to the cells array at correct positions 
    cells[0][0] = new Lion(BLUE, 0, 0);
    getGame()->getPlayer(BLUE)->addPiece(cells[0][0]);

    cells[2][0] = new Rat(BLUE, 2, 0);
    getGame()->getPlayer(BLUE)->addPiece(cells[2][0]);

    cells[1][1] = new Dog(BLUE, 1, 1);
    getGame()->getPlayer(BLUE)->addPiece(cells[1][1]);

    cells[2][2] = new Leopard(BLUE, 2, 2);
    getGame()->getPlayer(BLUE)->addPiece(cells[2][2]);

    cells[0][6] = new Tiger(BLUE, 0, 6);
    getGame()->getPlayer(BLUE)->addPiece(cells[0][6]);

    cells[1][5] = new Cat(BLUE, 1, 5);
    getGame()->getPlayer(BLUE)->addPiece(cells[1][5]);

    cells[2][4] = new Wolf(BLUE, 2, 4);
    getGame()->getPlayer(BLUE)->addPiece(cells[2][4]);

    cells[2][6] = new Elephant(BLUE, 2, 6);
    getGame()->getPlayer(BLUE)->addPiece(cells[2][6]);



    cells[8][6] = new Lion(RED, 8, 6);
    getGame()->getPlayer(RED)->addPiece(cells[8][6]);

    cells[6][6] = new Rat(RED, 6, 6);
    getGame()->getPlayer(RED)->addPiece(cells[6][6]);

    cells[7][5] = new Dog(RED, 7, 5);
    getGame()->getPlayer(RED)->addPiece(cells[7][5]);

    cells[6][4] = new Leopard(RED, 6, 4);
    getGame()->getPlayer(RED)->addPiece(cells[6][4]);

    cells[8][0] = new Tiger(RED, 8, 0);
    getGame()->getPlayer(RED)->addPiece(cells[8][0]);

    cells[7][1] = new Cat(RED, 7, 1);
    getGame()->getPlayer(RED)->addPiece(cells[7][1]);

    cells[6][2] = new Wolf(RED, 6, 2);
    getGame()->getPlayer(RED)->addPiece(cells[6][2]);

    cells[6][0] = new Elephant(RED, 6, 0);
    getGame()->getPlayer(RED)->addPiece(cells[6][0]);

    // TODO: also add the created pieces to each player's vector of pieces
}

// Return true if (y, x) is an empty cell, and false otherwise
bool Board::isEmpty(int y, int x) {
    if (cells[y][x] == EMPTY)
        return true;
    return false;
}

// Return true if (y, x) is the den on the side of the specified color, 
// and false otherwise
bool Board::isDen(int y, int x, Color color) {
    if (color == BLUE) {
        if (y == 0 && x == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (color == RED) {
        if (y == 8 && x == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    // TODO: Add your code here
}

// Return true if (y, x) is a trap on the side of the specified color, 
// and false otherwise
bool Board::isTrap(int y, int x, Color color) {
    if (color == BLUE) {
        if (y == 0 && x == 2) {
            return true;
        }
        else if (y == 0 && x == 4){
            return true;
        }
        else if (y == 1 && x == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (color == RED) {
        if (y == 8 && x == 2) {
            return true;
        }
        else if (y == 8 && x == 4) {
            return true;
        }
        else if (y == 7 && x == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    // TODO: Add your code here
}

// Return true if (y, x) is a river cell, and false otherwise
bool Board::isRiver(int y, int x) {
    return y >= 3 && y <= 5 && (x >= 1 && x <= 2 || x >= 4 && x <= 5);
}

// Get a piece from the specified cell
Piece* Board::get(int y, int x){
    if (0 <= y && y < H && 0 <= x && x < W)
        return cells[y][x];
    return OUT_BOUND; // out of bound
}

// Put piece p onto the specified cell
void Board::put(int y, int x, Piece* p){
    cells[y][x] = p;
    if (p != EMPTY) {
        p->setY(y);
        p->setX(x);
    }
}

// Print the gameboard
void Board::print() {
    // TODO: Add code to print the HxW gameboard by looping over cells array
    // Hint: Make use of isEmpty(), isRiver(), isTrap(), isDen(), and 
    //       getLabel() of Piece to ease your work
    cout << "    ";
    for (int j = 0; j < 7; j++) {
        cout << (char)(j + 'A') << "   ";
    }
    cout << endl << "  +---+---+---+---+---+---+---+" << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 7; j++) {
            if (j == 0) {
                cout << i+1 << " |";
            }
            
            

            if (cells[i][j] == NULL) {
                if (isRiver(i, j)) {
                    cout << " * |";
                }

                else if (isTrap(i, j, RED) || isTrap(i, j, BLUE)) {

                    cout << " # |";

                }
                else if (isDen(i, j, RED) || isDen(i, j, BLUE)) {

                    cout << " X |";
                }
                else if (isEmpty(i, j)) {
                    cout << "   |";
                }
                
            }
            else if (cells[i][j] != NULL) {
                cout << " " << cells[i][j]->getLabel() << " |";
            }
            
            
                
 
            
        }
        cout << endl << "  +---+---+---+---+---+---+---+" << endl;
    }
    // Remember * for river cells, # for trap cells, X for den cells

}

// Check if the move from (y1, x1) to (y2, x2) is valid
bool Board::isMoveValid(int y1, int x1, int y2, int x2) {
    // TODO:
    // check against invalid cases, for example,
    // - the source is an empty cell
    if (isEmpty(y1, x1)) {
        return false;
    }
    else if (y1 == y2 && x1 == x2) {
        return false;
    }
    else if (cells[y2][x2] > OUT_BOUND) {
        return false;
    } 
    else if (getGame()->getTurn() != cells[y1][x1]->getColor()) {
        return false;
    }

    Piece* p = cells[y1][x1];
    if (p->isMoveValid(this, y2, x2) == false)
        return false;

    return true;

    
    // - the source and destination are the same position
    
    // - the destination is out of bound of the board (hint: use OUT_BOUND)
    
    // - the source piece is not of same color of current turn of the game
    
    
    // (... and anymore ?)
    // [Note: you can modify the following code if it doesn't fit your design]

    // Piece-specific validation

}

// Carry out the move from (y1, x1) to (y2, x2)
bool Board::move(int y1, int x1, int y2, int x2) {
    if (isMoveValid(y1, x1, y2, x2)) {
        get(y1, x1)->move(this, y2, x2);
        return true;
    }
    return false;
}

// Return the pointer to the Game object
Game* Board::getGame() const {
    return game;
}
