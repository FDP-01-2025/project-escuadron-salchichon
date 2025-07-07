#include "gamestate.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveProgress(const GameState& state) {
    ofstream file("savegame.txt");
    if (file.is_open()) {
        file << state.honor << " "
             << state.score << " "
             << state.lives << " "
             << state.currentStage << endl;
        file.close();
        cout << "Saved progress.\n";
    } else {
        cout << "The progress could not be saved.\n";
    }
}

void loadProgress(GameState& state) {
    ifstream file("savegame.txt");
    if (file.is_open()) {
        file >> state.honor >> state.score >> state.lives >> state.currentStage;
        file.close();
        cout << "Progress loaded.\n";
    } else {
        cout << "Progress not found.\n";
    }
}