#ifndef UTILS_H
#define UTILS_H

#include <string>

// Pauses execution for the given milliseconds
void pause(int ms);

// Show a game over message and ends the program
void gameOver(const char* reason);

// Show a final message and waits for user input
void finalMessage(const char* msg);

// Prints text slowly with a default speed of 30 ms per character
void slowPrint(const std::string& text, int speed = 30);

#endif
