#include "nivel1.h"
#include "utils.h"
#include "gamestate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Level 1: Search of a hidden knife
bool level1(GameState& state) {
    slowPrint(" LEVEL 1: Knife Search\n", 40);
    pause(1000);
    slowPrint(state.playerName + " finds out he has been falsely accused...", 30);
    pause(1500);
    slowPrint("He decides to go to the field to look for a hidden weapon to defend himself.", 30);
    pause(1500);
    
    cout << "\nPress ENTER to search for the weapon...\n";
    cin.ignore();
    cin.get();

    srand(time(0));  // Seed random number generator
    int correct = rand() % 3 + 1;  // Randomly decide the correct hiding place 
    int place;

    cout << "Where do you search?\n"
         << "1) Under a tree\n"
         << "2) Behind a big rock\n"
         << "3) At the entrance of a cave\n"
         << "Choose 1, 2 or 3: ";
    cin >> place;

    if (place == correct) {
        slowPrint("\nExcellent! You found the knife... but while hiding it, you were captured.\n", 30);
        pause(1000);
        state.currentStage = 1;  // Mark level 1 as completed
        saveProgress(state);
        finalMessage(" LEVEL 1 COMPLETED");
        return true;  // Success
    } else {
        slowPrint("\nYou chose wrong and were captured by military patrols.\n", 30);
        pause(1000);
        state.honor -= 15;  // Penalize honor for failure
        saveProgress(state);
        return false;  // Failure
    }
}
