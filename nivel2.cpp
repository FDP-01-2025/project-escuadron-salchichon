#include "nivel2.h"
#include "utils.h"
#include "gamestate.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

// Level 2: Guess the password
bool level2(GameState& state) {
    slowPrint(" LEVEL 2: The password\n", 40);
    pause(1000);
    slowPrint("Now... in front of the door, the soldiers do not recognize you.", 30);
    pause(1500);
    slowPrint("You know you cannot just walk in and they will not just open... you need a password.", 30);
    pause(1500);
    slowPrint("While you think about a password that would fit for Cristiani... you hear two soldiers...", 30);
    pause(1500);
    slowPrint("Soldier 1: How long will it take to return to PEACE...?", 30);
    pause(1500);
    slowPrint("Soldier 2: You know it is not going to be any time soon...", 30);
    pause(1500);

    string word = "Peace";  // Correct password
    string attempt;
    int attempts = 3;       // Number of tries allowed

    while (attempts--) {
        cout << "Password: ";
        cin >> attempt;
        if (attempt == word) {
            slowPrint("Correct password. Welcome, commander.", 30);
            pause(1000);
            state.score = 15;
            state.honor += 20;
            state.currentStage = 2;  // Mark level 2 as completed
            saveProgress(state);
            return true;  // Success
        } else {
            slowPrint("Incorrect. You have ", 30);
            cout << attempts;
            slowPrint(" attempts left.\n", 30);
            pause(1000);
        }
    }

    // Failed to guess password
    state.honor -= 20;
    saveProgress(state);
    return false;
}