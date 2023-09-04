/* Lee Ho Kong      1155149106  1155149106@link.cuhk.edu.hk*/


#include <iostream>

using namespace std;

const int N = 6;
const int P = 8;
const int L = 3;

void print(char board[][N]) {
    //print A to char(A+N-1)
    for (int i = 0; i <= N; i++) {
        if (i == 0) {
            cout << "   ";
        }
        else {
            cout << char(64 + i) << " ";
        }
    }
    cout << endl;
    //print the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0) {
                cout << ' ' << i + 1 << ' ';
            }

            cout << board[i][j] << ' ';

        }
        cout << endl;
    }

}

int pieces_on_board(char board[][N], char player) {
    int count = 0;
    for (int i = 0; i < N; i++) { // count the X and O
        for (int j = 0; j < N; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
    }
    return count;
}

/* direction explain :  i-1, j-1 => 1;
                     :  i-1 => 2;
                     :  i-1, j+1 => 3;
                     :  j+1 => 4;
                     :  i+1,j+1 => 5;
                     :  i+1 => 6;
                     :  i+1,j-1 => 7;
                     :  j-1 => 8;

*/
bool positioncheck(char board[][N], int y, int x, char player, int direction) { //check whether the m direction of board[y][x] contain the "player" character
    

    
    if (direction == 1) {
        if (y - 1 < 0) {
            return false;
        }
        if (x - 1 < 0) {
            return false;
        }

        if (board[y - 1][x - 1] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 2) {
        if (y - 1 < 0) {
            return false;
        }

        if (board[y - 1][x] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 3) {
        if (y - 1 < 0) {
            return false;
        }
        if (x + 1 > N-1) {
            return false;
        }
        if (board[y - 1][x + 1] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 4) {
        if (x + 1 > N-1) {
            return false;
        }
        if (board[y][x + 1] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 5) {
        if (y + 1 > N-1) {
            return false;
        }
        if (x + 1 > N-1) {
            return false;
        }
        if (board[y + 1][x + 1] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 6) {
        if (y + 1 > N - 1) {
            return false;
        }
        if (board[y + 1][x] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 7) {
        if (y + 1 > N - 1) {
            return false;
        }
        if (x - 1 < 0) {
            return false;
        }
        if (board[y + 1][x - 1] == player) {
            return true;
        }
        else { return false; }
    }
    else if (direction == 8) {
        if (x - 1 < 0) {
            return false;
        }
        if (board[y][x - 1] == player) {
            return true;
        }
        else { return false; }
    }
}

bool pieces_in_line(char board[][N], char player) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == player) {
                count = 1 ;

                for (int m = 1; m <= 8; m++) {//check for the 8 direction
                    int y = i;
                    int x = j;
                    while (positioncheck(board, y, x, player, m) == true) {
                        count++;
                        if (m == 1) {
                            y--;
                            x--;
                        }
                        else if (m == 2) {
                            y--;
                        }
                        else if (m == 3) {
                            y--;
                            x++;
                        }
                        else if (m == 4) {
                            x++;
                        }
                        else if (m == 5) {
                            y++;
                            x++;
                        }
                        else if (m == 6) {
                            y++;
                        }
                        else if (m == 7) {
                            y++;
                            x--;
                        }
                        else if (m == 8) {
                            x--;
                        }
                        if (count == L) {
                            return true;

                        }
                    }
                    count = 1;
                }



            }
        }
    }
    return false;
}

bool is_valid_move(char board[][N], char player, int y, int x) {
    int check = 0;
    if (y >= 0 && y <= N - 1 && x >= 0 && x <= N - 1) { //check for valid input
        if (board[y][x] == '.') {//check whether board[y][x] is empty or not
            check = 1;
            return true;
            
        }
    }
    if (check == 0) {
        return false;
    }
    
}

void move(char board[][N], char player, int y, int x) {
    
        board[y][x] = player;
        for (int m = 1; m <= 8; m++) {
            if (positioncheck(board, y, x, 'X', m) == true || positioncheck(board, y, x, 'O', m) == true) {//check whether there is a chess in 8 direction
                int a = y;
                int b = x;
                if (m == 1) {
                    a--;
                    b--;
                }
                else if (m == 2) {
                    a--;
                }
                else if (m == 3) {
                    a--;
                    b++;
                }
                else if (m == 4) {
                    b++;
                }
                else if (m == 5) {
                    a++;
                    b++;
                }
                else if (m == 6) {
                    a++;
                }
                else if (m == 7) {
                    a++;
                    b--;
                }
                else if (m == 8) {
                    b--;
                }
                //cout << a << "," << b << endl;
                if (positioncheck(board, a, b, '.', m) == true) { //check whether there are open space for the chess to repel
                    char container = board[a][b];
                    board[a][b] = '.';
                    if (m == 1) {
                        a--;
                        b--;
                    }
                    else if (m == 2) {
                        a--;
                    }
                    else if (m == 3) {
                    a--;
                    b++;
                    }
                    else if (m == 4) {
                    b++;
                    }
                    else if (m == 5) {
                    a++;
                    b++;
                    }
                    else if (m == 6) {
                    a++;
                    }
                    else if (m == 7) {
                    a++;
                    b--;
                    }
                    else if (m == 8) {
                    b--;
                    }
                    board[a][b] = container;
                    //cout << positioncheck(board,a,b,NULL,m) << endl;

                }
                else if (positioncheck(board, a, b, '.', m) != true && positioncheck(board, a, b, 'X', m) != true && positioncheck(board, a, b, 'O', m) != true) {
                //cout << a << "," << b << endl;
                board[a][b] = '.';
                }
            }
        }
    


}

int main()
{
    char playerX = 'X';
    char playerO = 'O';
    char gameboard[N][N];
    char inputrow;
    int inputcolumn;
    int inputxint = -100;
    int roundcount = 0;
    int turncount = 1;
    // declare the board with '.'
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            gameboard[i][j] = '.';
        }
    }
    //cout << is_valid_move(gameboard, playerO, 2, 7) << endl;

    //cout << (int)'a' << (int)'A' << endl;
    roundcount++;
    cout << "Round " << roundcount << ":" << endl;
    print(gameboard);

    //check whether the game is end or not 
    while (pieces_in_line(gameboard, playerO) == false && pieces_in_line(gameboard, playerX) == false && pieces_on_board(gameboard, playerO) != P && pieces_on_board(gameboard, playerX) != P) {
        int validcheck = 0;//check whether the move is valid 
        if (turncount == 0) {//for player O to move
            cout << "player " << playerO << "'s turn: ";
            cin >> inputrow >> inputcolumn;
            if ((int)inputrow >= 65 && (int)inputrow <= 90) {// for upper case alphabet
                inputxint = (int)inputrow - 65;
                //cout << inputcolumn - 1 << ", " << inputxint << endl;
            }
            else if ((int)inputrow >= 97 && (int)inputrow <= 122) {// for lower case alphabet
                inputxint = (int)inputrow - 97;
                //cout << inputcolumn - 1 << ", " << inputxint << endl;
            }
            //if (inputxint >= 0 && inputxint <= N - 1 && inputcolumn >= 1 && inputcolumn <= N) {
                if (is_valid_move(gameboard, playerO, inputcolumn - 1, inputxint)) {//check whether the move is valid or not
                    //cout << inputcolumn - 1 << ", " << inputxint << endl;
                    move(gameboard, playerO, inputcolumn - 1, inputxint);
                    turncount = 1;
                    validcheck = 1;
                } 
            //}

        }
        else if (turncount == 1) { // for player X to move
            cout << "player " << playerX << "'s turn: ";
            cin >> inputrow >> inputcolumn;
            if ((int)inputrow >= 65 && (int)inputrow <= 90) {// for upper case alphabet
                inputxint = (int)inputrow - 65;
                //cout << inputcolumn - 1 << ", " << inputxint << endl;
            }
            else if ((int)inputrow >= 97 && (int)inputrow <= 122) {// for lower case alphabet
                inputxint = (int)inputrow - 97;
                //cout << inputcolumn - 1 << ", " << inputxint << endl;
            }

            if (is_valid_move(gameboard, playerX, inputcolumn - 1, inputxint)) { //check whether the move is valid or not
                //cout << inputcolumn - 1 << ", " << inputxint << endl;
                move(gameboard, playerX, inputcolumn - 1, inputxint);
                turncount = 0;
                validcheck = 1;
            }

        }

        if (validcheck == 1) {
            if (pieces_in_line(gameboard, playerO) == true && pieces_in_line(gameboard, playerX) == true) {//draw game situation
                cout << "Game Over :" << endl;
                print(gameboard);
                cout << "Draw Game!";
            }

            else if (pieces_in_line(gameboard, playerO) == true || pieces_on_board(gameboard,playerO) == P) { //playerO win situation
                cout << "Game Over :" << endl;
                print(gameboard);
                cout << "Player O wins!";
            }
            else if (pieces_in_line(gameboard, playerX) == true || pieces_on_board(gameboard, playerX) == P) { //playerX win situation
                cout << "Game Over :" << endl;
                print(gameboard);
                cout << "Player X wins!";
            }
            else { // normal situation
                roundcount++;
                cout << "Round " << roundcount << ":" << endl;
                print(gameboard);
            }

        }
        else if(validcheck == 0){
            cout << "Invalid move!" << endl; 
        }
        

    }



    return 0;
}
            
        
    