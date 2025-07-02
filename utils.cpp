#include "utils.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

void clearScreen() {
    system("cls");
}

void pause(int ms) {
    Sleep(ms);
}

void gameOver(const char* motivo) {
    std::cout << "\n--- GAME OVER: " << motivo << " ---\nPresiona cualquier tecla para salir...";
    getch();
    exit(0);
}

void mensajeFinal(const char* msg) {
    std::cout << msg << "\n\nPresiona cualquier tecla para continuar... ";
    getch();
    clearScreen();
}

void imprimirLento(const std::string& texto, int velocidad) {
    for (char c : texto) {
        std::cout << c << std::flush;
        Sleep(velocidad);
    }
    std::cout << std::endl;
}