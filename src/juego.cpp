#include "juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 5;
const int COLUMNS = 5;
const int MINES = 5;

char board[ROWS][COLUMNS];    // Player's visible board
bool mines[ROWS][COLUMNS];    // True if mine present at position

// This nitialize the board with no mines
void initializeBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = '-';    // Unrevealed cell
            mines[i][j] = false;  // No mine initially
        }
    }
}

// This one place a mine in a random place
void putMines() {
    srand(time(0));   // Generates a random seed with real time
    int put = 0;
    while (put < MINES) {
        int x = rand() % ROWS;
        int y = rand() % COLUMNS;
        if (!mines[x][y]) {  // Only place mine if none there yet
            mines[x][y] = true;
            put++;
        }
    }
}

// Count how many mines are adjacent to cell (x,y)
int countNearbyMines(int x, int y) {
    int counter = 0;
    for (int i = -1; i <= 1; i++) {         // Check neighbors in 3x3 grid
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLUMNS && mines[nx][ny]) {
                counter++;
            }
        }
    }
    return counter;
}

// Display the current visible board
void showBoard() {
    cout << "  ";
    for (int i = 0; i < COLUMNS; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << i << " ";
        for (int j = 0; j < COLUMNS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Process a player's move at (x,y), returns false if stepped on mine
bool play(int x, int y) {
    if (mines[x][y]) {
        cout << " You stepped on a mine." << endl;
        return false;  // Player lost
    } else {
        board[x][y] = '0' + countNearbyMines(x, y);  // Reveal nearby mine count
        return true;   // Safe move
    }
}

