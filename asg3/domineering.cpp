// Lee Ho Kong 1155149106 leehokong@gmail.com
#include <iostream>

using namespace std;

/* function for checking the state of grid, whether 0,1,2*/
int gridstate(long long grid, int pos) {
    int currentpos;
    
    int state;

    currentpos = 16 - pos;
    for (int i = 0; i < currentpos; i++) {
        grid /= 10;
    }

    state = grid % 10;
    return state;

}


/* return true if domino is placeable. else return false*/
bool isPlaceable(long long grid, int pos, int p) {
    if (p == 1) {
        if (pos > 12 || pos < 1) {
            //cout << "checkpt1" << endl;
            return false;
        }
        if (gridstate(grid, pos) != 0) {
            //cout << "checkpt2" << endl;
            return false;
        }
        else if (gridstate(grid, pos + 4) != 0) {
            //cout << "checkpt3" << endl;
            return false;
        }
        else {
            //cout << "checkpt4" << endl;
            return true;
        }

    }

    if (p == 2) {
        if (pos > 15 || pos < 1) {
            return false;
        }
        else if (pos % 4 == 0) {
            return false;
        }

        if (gridstate(grid, pos) != 0) {
            return false;
        }
        else if (gridstate(grid, pos + 1) != 0) {
            return false;
        }
        else {
            return true;
        }

    }
}

/* print the grid*/
void printgrid(long long grid) {
    int counter = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (gridstate(grid, counter) == 0) {
                cout << ". ";
            }
            else if (gridstate(grid, counter) == 1) {
                cout << "A ";

            }
            else if (gridstate(grid, counter) == 2) {
                cout << "B ";
            }
            counter++;

        }
        cout << endl;
    }
}

/* put the grid into the position according to the player*/
void putToGrid(long long &grid, int pos, int p) {
    int pos2 = 16 - pos;
    long long currentcounter = 1;
    for (int i = 0; i < pos2; i++) {
        currentcounter *= 10;
    }
    if (p == 1) {
        int p1pos = 12 - pos;
        long long p1counter = 1;
        for (int i = 0; i < p1pos; i++) {
            p1counter *= 10;
        }
        //cout << p1counter;
        //cout << currentcounter;
        grid = grid + currentcounter + p1counter;

    }
    if (p == 2) {

        int p2pos = 15 - pos;
        long long p2counter = 1;
        for (int i = 0; i < p2pos; i++) {
            p2counter *= 10;
        }
        
        grid = grid + currentcounter * 2 + p2counter * 2;


    }

}



int main()
{
    
    long long gridcode = 0; /*declare grid*/
    int input;
    int playercounter = 1;
    printgrid(gridcode);
    while (true) { //infinite loop, stop only when there are break
        int count = 0;
        
        cout << "Player " << playercounter << "'s move: ";
        cin >> input;
        if (isPlaceable(gridcode, input, playercounter)) {
            putToGrid(gridcode, input, playercounter);
            printgrid(gridcode);
            //considering 16 cases, if there are one postion is placeable, break out this for loop, else count ++
            for (int i = 1; i <= 16; i++) { 
                if (playercounter == 1) { // situation for player 1 just placed a domino
                    if (isPlaceable(gridcode, i, 2) ) {
                        playercounter = 2;
                        count = 0;
                        break;

                    }
                    else {
                        count++;
                    }
                    
                }
                else if (playercounter == 2) { // situation for player 1 just placed a domino
                    if (isPlaceable(gridcode, i, 1) ) {
                        playercounter = 1;
                        count = 0;
                        break;

                    }
                    else {
                        count++;
                    }
                }
            }

        }
        else {
            cout << "Invalid! Try again." << endl; // let the user try again if input is not placeable
            continue;
        }
        
        if (count == 16 && playercounter == 1) {  //if plater 1 win
            cout << "Player 1 wins!";
            break;
        } else if (count == 16 && playercounter == 2) {  //if player 2 win
            cout << "Player 2 wins!";
            break;
        }
        
    }

    return 0;
}