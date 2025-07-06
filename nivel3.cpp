#include "nivel3.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool nivel3() {
    clearScreen();
    imprimirLento(" NIVEL 3: Duelo de Cartas\n", 40);
    pause(1000);
    imprimirLento("Para probar su lealtad, Chepe debe vencer al comandante en un duelo de cartas.", 30);
    pause(1500);
    imprimirLento("Cada jugador saca una carta (1 al 13). El más alto gana 2 de 3 rondas.", 30);
    pause(1500);
    cout << "\nPresiona ENTER para comenzar el duelo...\n";
    cin.ignore();
    cin.get();
    clearScreen();

    srand(time(0));
    int victorias = 0;

    for (int ronda = 1; ronda <= 3; ronda++) {
        int chepe = rand() % 13 + 1;
        int enemigo = rand() % 13 + 1;

        cout << "Ronda " << ronda << ": Chepe [" << chepe << "] vs Comandante [" << enemigo << "]\n";
        if (chepe > enemigo) {
            cout << " Chepe gana la ronda.\n";
            victorias++;
        } else {
            cout << " Chepe pierde la ronda.\n";
        }
        pause(1000);
    }

    if (victorias >= 2) {
        mensajeFinal("🃏 Has ganado el duelo de cartas.");
        return true;
    } else {
        return false;
    }
}