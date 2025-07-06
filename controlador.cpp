#include "controlador.h"
#include "historia.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "juego.h"
#include "utils.h"
#include <iostream>

using namespace std;

void iniciarJuego() {
    introduccion();  //  Historia inicial

    nivel1();        //  Primer nivel: búsqueda del cuchillo

    if (!nivel2()) { //  Segundo nivel: contraseña
        finalFallido("Fallaste la contraseña y fuiste arrestado.");
        return;
    }

    if (!nivel3()) { //  Tercer nivel: duelo de cartas
        finalFallido("Perdiste el duelo de cartas. Te expulsaron de la base.");
        return;
    }

    //  Último nivel: campo minado
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

    finalExitoso();  // 🏁 Final feliz
}