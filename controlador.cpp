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

void startGame() {
    GameState state;

    cout << "Do you want to load the game? (1=Yes, 2=No): ";
    int option;
    cin >> option;

    if (option == 1) {
        loadProgress(state);
        slowPrint("Game loaded. Continue...", 30);
    } else {
        state = GameState();
        saveProgress(state);
    }

    // No siempre necesitas correr introducción y storyStart, si ya pasaste ese punto, revisa currentStage.
    if (state.currentStage <= 0) {
        introduction();
        pause(1000);
        storyStart(state);
        pause(1500);
        state.currentStage = 0;  // O el valor que quieras para inicio
        saveProgress(state);
    }

    if (state.currentStage < 1) {
        if (!level1(state)) {
            slowPrint("You failed level 1 and lost honor.", 30);
            state.honor -= 15;
            saveProgress(state);
        } else {
            state.currentStage = 1;  // Marca que superaste nivel 1
            saveProgress(state);
        }
    }

    if (state.currentStage < 2) {
        storyContinuation(state);
        pause(1500);
        if (!level2(state)) {
            slowPrint("You failed level 2 and lost honor.", 30);
            state.honor -= 20;
            saveProgress(state);
        } else {
            state.currentStage = 2;  // Marca que superaste nivel 2
            saveProgress(state);
        }
    }

    if (state.currentStage < 3) {
        almostFinal(state);
        pause(1500);
        if (!level3(state)) {
            slowPrint("You failed level 3 and lost honor.", 30);
            state.honor -= 25;
            saveProgress(state);
        } else {
            state.currentStage = 3;  // Marca que superaste nivel 3
            saveProgress(state);
        }
    }

    // Juego minas solo si llegaste aquí
    initializeBoard();
    putMines();

    bool stillPlaying = true;
    int x, y;

    while (stillPlaying) {
        showBoard();
        cout << "Enter the coordinates (Row, Column): ";
        if (!(cin >> x >> y)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid entry. Try again.\n";
            continue;
        }

        if (x >= 0 && x < ROWS && y >= 0 && y < COLUMNS) {
            stillPlaying = play(x, y);
            if (!stillPlaying) {
                slowPrint("You stepped on a mine! Lost honor. Try again.", 30);
                state.honor -= 20;
                saveProgress(state);
                initializeBoard();
                putMines();
                stillPlaying = true;
            }
        } else {
            cout << "Coordinates out of range. Try again.\n";
        }
    }

    saveProgress(state);
    goodFinal();
}