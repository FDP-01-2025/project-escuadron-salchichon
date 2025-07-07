#ifndef GAMESTATE_H
#define GAMESTATE_H

struct GameState {
    int honor = 0;
    int score = 0;
    int lives = 3;
    int currentStage = 0;
};

void saveProgress(const GameState& state);
void loadProgress(GameState& state);

#endif
