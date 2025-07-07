#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Pause execution for given milliseconds
void pause(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Show game over message and exit program if you lose in the mine field
void gameOver(const char* reason) {
    cout << "\n--- GAME OVER: " << reason << " ---\nPress ENTER to exit...";
    cin.ignore();
    cin.get();
    exit(0);
}

// Show a final message and wait for user to press ENTER
void finalMessage(const char* msg) {
    cout << msg << "\n\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

// Print text slowly, character by character, with delay in milliseconds
void slowPrint(const string& text, int speed) {
    for (char c : text) {
        cout << c << flush;
        pause(speed);
    }
    cout << endl;
}
