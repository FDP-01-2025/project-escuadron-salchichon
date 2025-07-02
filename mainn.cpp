#include "historia.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "juego.h"
#include "utils.h"
#include <iostream>
using namespace std;

int main() {
    introduccion();

    nivel1();

    if (!nivel2()) {
        finalFallido("Fallaste la contraseña y fuiste arrestado.");
        return 0;
    }

    if (!nivel3()) {
        finalFallido("Perdiste el duelo de cartas. Te expulsaron de la base.");
        return 0;
    }

    inicializarTablero();
    colocarMinas();

    int x, y;
    bool sigueJugando = true;

    while (sigueJugando) {
        mostrarTablero();
        cout << "Ingrese coordenadas (fila columna): ";
        if (!(cin >> x >> y)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Entrada inválida. Intenta de nuevo.\n";
            continue;
        }

        if (x >= 0 && x < FILAS && y >= 0 && y < COLUMNAS) {
            sigueJugando = jugar(x, y);
        } else {
            cout << "Coordenadas fuera de rango. Intenta de nuevo.\n";
        }
    }

    finalExitoso();
    return 0;
}