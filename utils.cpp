#include "utils.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void pause(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void gameOver(const char* motivo) {
    cout << "\n--- GAME OVER: " << motivo << " ---\nPresiona ENTER para salir...";
    cin.ignore();
    cin.get();
    exit(0);
}

void mensajeFinal(const char* msg) {
    cout << msg << "\n\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
    clearScreen();
}

void imprimirLento(const string& texto, int velocidad) {
    for (char c : texto) {
        cout << c << flush;
        pause(velocidad);
    }
    cout << endl;
}