#include "nivel3.h"
#include "utils.h"
#include "gamestate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool level3(GameState& state) {
    slowPrint(" LEVEL 3: Card Duel\n", 40);
    pause(1000);
    slowPrint(state.playerName + ", after deciphering the word, enters...", 30);
    pause(1500);
    slowPrint("Only to discover that Cristiani was already waiting for him.", 30);
    pause(1500);
    slowPrint("Cristiani: Welcome,"  + state.playerName + ", it wasn't easy to get here, was it?", 30);
    pause(1500);
    slowPrint("You are close to the end... I like you, so we will do something... we will play 21.", 30);
    pause(1500);
    slowPrint("If you win... I will let you go. If I win... you will give me your weapon, and we will play the hunt...", 30);
    pause(1500);
    cout << "\nPress ENTER to start the duel...\n";
    cin.ignore();
    cin.get();

    srand(time(0));

    int player, computer, card;
    char option;
    int hands = 3;         // Number of rounds to play
    int playerwins = 0;    // Player win counter
    int computerwins = 0;  // Computer win counter
    int tie = 0;           // Tie counter

    for (int hand = 1; hand <= hands; hand++) {
        player = 0;
        computer = 0;

        cout << "Hand " << hand << "\n";

        // Player draws cards
        do {
            card = (rand() % 10) + 1;
            player += card;
            cout << "You drew a card: " << card << ". Total: " << player << "\n";
            if (player >= 21) break;

            cout << "Do you want another card? (y/n): ";
            cin >> option;
        } while (option == 'y' || option == 'Y');

        // Computer draws cards until 17 or more
        while (computer < 17) {
            card = (rand() % 10) + 1;
            computer += card;
        }

        cout << "Cristiani's points: " << computer << "\n";

        bool playerbust = (player > 21);
        bool computerbust = (computer > 21);

        // Determine winner of the hand
        if (playerbust && computerbust) {
            cout << "It is a draw: both players busted\n";
            tie++;
        } else if (playerbust) {
            cout << "Cristiani wins\n";
            computerwins++;
        } else if (computerbust) {
            cout << "You win\n";
            playerwins++;
        } else {
            if (player > computer) {
                cout << "You win\n";
                playerwins++;
            } else if (computer > player) {
                cout << "Cristiani wins\n";
                computerwins++;
            } else {
                cout << "Tie: same score\n";
                tie++;
            }
        }

        cout << "---------------------------\n";
    }

    // Show final results
    slowPrint("Final results:\n", 30);
    pause(1000);
    slowPrint(state.playerName +" wins: ", 30); cout << playerwins; slowPrint(" hands\n", 30);
    pause(1000);
    slowPrint("Cristiani wins: ",30); cout << computerwins; slowPrint(" hands\n", 30);
    pause(1000);
    slowPrint("Ties: ", 30); cout << tie; slowPrint("\n", 30);
    pause(1000);

    // Decide who wins and what happens
    if (playerwins > computerwins) {
        slowPrint( "You won!\n",30);
        slowPrint( "Cristiani: fine...you can go.",30);
        pause(1000);
        state.score += 15;
        state.honor += 15;
        state.currentStage = 3; // Mark level 3 completed
        saveProgress(state);
        finalMessage(" LEVEL 3 COMPLETED");
        return true;
    } else if (tie > 0){
        slowPrint("Cristiani: It was a tie ... you were lucky..but not enough.", 30);
        pause(1000);
        slowPrint("Cristiani takes your weapon while smiling with superiority.", 30);
        pause(1000);
        slowPrint("Cristiani: You will not die today... not yet. I will let you go...", 30);
        pause(1000);
        slowPrint("Cristiani: When you pick up a weapon again, I will come to find you.", 30);
        pause(1000);
        state.honor -= 15;
        saveProgress(state);
        finalMessage(" You lost the duel, but you are still alive. Continue your path.");
        return true; 
    } else {
        slowPrint("Cristiani: Just as I thought... you were lucky until now.", 30);
        pause(1000);
        slowPrint("Cristiani takes your weapon while smiling with superiority.", 30);
        pause(1000);
        slowPrint("Cristiani: You will not die today... not yet. I will let you go...", 30);
        pause(1000);
        slowPrint("Cristiani: When you pick up a weapon again, I will come to find you.", 30);
        pause(1000);
        state.honor -= 15;
        saveProgress(state);
        finalMessage(" You lost the duel, but you are still alive. Continue your path.");
        return true;
    }
}
