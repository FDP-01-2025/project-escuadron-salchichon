#ifndef JUEGO_H
#define JUEGO_H

extern const int ROWS;
extern const int COLUMNS;
extern const int MINES;
//All the fuctions used in the final game
void initializeBoard();
void putMines();
int countNearbyMines(int x, int y);
void showBoard();
bool play(int x, int y);

#endif