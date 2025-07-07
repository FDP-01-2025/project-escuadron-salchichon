#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>

// Struct for the game state
struct GameState {
    int honor = 0;
    int score = 0;
    int lives = 3;
    int currentStage = 0;
    std::string playerName;
    int friendship = 0;
    int weapon = 0;
    float health = 5.0f;
    int food = 0;
};

// Declaration of a fuction for the save and load
void saveProgress(const GameState& state);
void loadProgress(GameState& state);

#endif
