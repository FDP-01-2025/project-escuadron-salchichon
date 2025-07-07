#include "controlador.h"
#include "historia.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "juego.h"
#include "utils.h"
#include "gamestate.h"
#include <iostream>

using namespace std;

// This void controls a par the final game
void playMinefield(GameState& state) {
    initializeBoard();  // Sets the board
    putMines();        // Sets mines in the board

    slowPrint("You enter the minefield now. Cristiani is not a problem anymore...", 30);
    pause(1000);
    slowPrint("One wrong step could mean the end...", 30);
    pause(1000);
    slowPrint("It is... The Final Duty.", 30);
    pause(1000);

    bool stillPlaying = true;
    int revealedSafeCells = 0;
    const int totalSafeCells = (ROWS * COLUMNS) - MINES;

    while (stillPlaying) {
        showBoard();  // Shoow current board
        cout << "Enter the coordinates (Row, Column) or -1 -1 to quit: ";

        int row, column;
        if (!(cin >> row >> column)) {  // Valid entry
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid entry. Try again.\n";
            continue;
        }

        // Opción para salir del juego
        if (row == -1 && column == -1) {
            cout << "Exiting the minefield game.\n";
            break;
        }

        // Verification of coordenates
        if (row >= 0 && row < ROWS && column >= 0 && column < COLUMNS) {
            stillPlaying = play(row, column); 

            if (!stillPlaying) {  // Here  we see what happens if you step on a mine
                slowPrint("You stepped on a mine! Lost honor. Try again.", 30);
                state.honor -= 20;
                state.lives--;
                saveProgress(state);

                if (state.lives <= 0) {  // If you run out of lives, you  get the bad end
                    badFinal("You wasted all your lives.");
                    break;
                }

                // Restart of the board
                initializeBoard();
                putMines();
                stillPlaying = true;
                revealedSafeCells = 0;
            } else {
                revealedSafeCells++;
                if (revealedSafeCells >= totalSafeCells) {  // If all is clear, you win
                    slowPrint("Congratulations! You cleared all safe cells!", 30);
                    saveProgress(state);
                    goodFinal(state);
                    break;
                }
            }
        } else {
            cout << "Coordinates out of range. Try again.\n";
        }
    }
}

// This void starts the game and controls a part of the progress
void startGame() {
    GameState state;
    string playerName;
    string playerSurname;
    char confirmation;
    int loadChoice;

    cout << "Do you want to load the game? (1=Yes, 2=No): ";
    cin >> loadChoice;

    if (loadChoice == 1) {  // Load progress
        loadProgress(state);
        slowPrint("Game loaded. Continue...", 30);
    } else {  // The game starts here
        state = GameState();

        cout << "Do you want to enter a name or use the default name? (1=Enter / 2=Default): ";
        int nameChoice;
        cin >> nameChoice;

        switch (nameChoice) {
            case 1:
                do {
                    cout << "Enter the character's name: ";
                    cin >> playerName;
                    cout << "Enter the character's surname: ";
                    cin >> playerSurname;
                    cout << "Are you sure you want to use " << playerName << " " << playerSurname << "? (y/n): ";
                    cin >> confirmation;
                } while (confirmation != 'y' && confirmation != 'Y');
                break;
            case 2:
                playerName = "Chepe";
                playerSurname = "Buquele";
                cout << "You are " << playerName << " " << playerSurname << " now.\n";
                break;
            default:
                cout << "(INVALID OPTION). The default name will be used.\n";
                playerName = "Chepe";
                playerSurname = "Buquele";
                break;
        }

        state.playerName = playerName + " " + playerSurname;

        cout << "Welcome to the start of your story, " << state.playerName << ". Good luck in this big world!\n";
        saveProgress(state);
    }

    // Here all the information of progress is saved
    if (state.currentStage <= 0) {
        introduction(state);
        pause(1000);
        storyStart(state);
        pause(1500);
        state.currentStage = 0;
        saveProgress(state);
    }

    if (state.currentStage < 1) {
        if (level1(state)) {
            state.score += 20;
            state.weapon++;
            state.honor += 15;
            state.currentStage = 1;
        }
        saveProgress(state);
    }

    if (state.currentStage < 2) {
        storyContinuation(state);
        pause(1500);
        if (level2(state)) {
            state.currentStage = 2;
        } else {
            slowPrint("You failed level 2 and lost honor.", 30);
            pause(1000);
            slowPrint("But the door opens, and a soldier drags you in.", 30);
        }
        saveProgress(state);
    }

    if (state.currentStage < 3) {
        almostFinal(state);
        pause(1500);
        if (level3(state)) {
            state.currentStage = 3;
        } else {
            slowPrint("You failed level 3 and lost honor.", 30);
            state.honor -= 25;
        }
        saveProgress(state);
    }

    if (state.currentStage < 4) {
        Final(state);
        pause(1500);
        state.currentStage = 4;
        saveProgress(state);
    }

    // The start of our final game
    playMinefield(state);
}