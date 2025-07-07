#ifndef HISTORIA_H
#define HISTORIA_H

#include <string>  
#include "gamestate.h"
using namespace std;
//All the fuction for the story parts commented in each .cpp
void introduction(GameState& state);
void goodFinal(GameState& state);
void badFinal(const string & reazon);
void storyStart(GameState& state);
void storyContinuation(GameState& state);
void almostFinal(GameState& state);
void Final(GameState& state);

#endif