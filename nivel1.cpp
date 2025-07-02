#include "nivel1.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

void nivel1() {
    clearScreen();
    imprimirLento(" NIVEL 1: Búsqueda del cuchillo\n", 40);
    pause(1000);
    imprimirLento("Chepe se entera de que ha sido acusado injustamente...", 30);
    pause(1500);
    imprimirLento("Decide ir al campo a buscar un arma escondida para defenderse.", 30);
    pause(1500);
    cout << "\nPresiona una tecla para buscar el arma...\n";
    getch();
    clearScreen();

    srand(time(0));
    int correcto = rand() % 3 + 1;
    int lugar;

    cout << "¿Dónde buscas?\n"
         << "1) Debajo de un árbol\n"
         << "2) Tras una roca grande\n"
         << "3) En la entrada de una cueva\n"
         << "Elige 1, 2 o 3: ";
    cin >> lugar;

    if (lugar == correcto) {
        cout << "\n¡Excelente! Has encontrado el cuchillo.\n";
        mensajeFinal(" NIVEL 1 COMPLETADO");
    } else {
        gameOver("Elegiste mal y fuiste capturado por patrullas militares.");
    }
}