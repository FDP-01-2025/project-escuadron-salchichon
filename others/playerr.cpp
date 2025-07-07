#include "player.h"

using namespace std;

void initializePlayer(Player &player) {
    player.score = 0;
    player.lives = 3;
}

void updateScore(Player &player, int points) {
    player.score += points;
}

void loseLife(Player &player) {
    player.lives--;
}
