#include "gamestate.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Saves the game state in a txt
void saveProgress(const GameState& state) {
    ofstream file("savegame.txt");
    if (file.is_open()) {
        // Writes all the parts that want to be saved
        file << "PlayerName: " << state.playerName << "\n"
             << "Honor: " << state.honor << "\n"
             << "Score: " << state.score << "\n"
             << "Lives: " << state.lives << "\n"
             << "CurrentStage: " << state.currentStage << "\n"
             << "Friendship: " << state.friendship << "\n"
             << "Weapon: " << state.weapon << "\n"
             << "Health: " << state.health << "\n"
             << "Food: " << state.food << "\n";
        file.close();
        cout << "Progress saved successfully.\n";
    } else {
        cerr << "Error: Could not save progress.\n";
    }
}

// Load the game state from the txt
void loadProgress(GameState& state) {
    ifstream file("savegame.txt");
    if (file.is_open()) {
        string dummy;
        file.ignore(50, ':'); getline(file, state.playerName);   // Reads complete name (with space)
        file.ignore(50, ':'); file >> state.honor;
        file.ignore(50, ':'); file >> state.score;
        file.ignore(50, ':'); file >> state.lives;
        file.ignore(50, ':'); file >> state.currentStage;
        file.ignore(50, ':'); file >> state.friendship;
        file.ignore(50, ':'); file >> state.weapon;
        file.ignore(50, ':'); file >> state.health;
        file.ignore(50, ':'); file >> state.food;
        file.close();
        cout << "Progress loaded successfully.\n";
    } else {
        cerr << "No saved progress found.\n";
    }
}
