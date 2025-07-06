#include "historia.h"
#include "utils.h"
#include <iostream>

using namespace std;

void introduccion() {
    clearScreen();
    imprimirLento(" HISTORIA DE CHEPE DUTY\n", 40);
    pause(1000);
    imprimirLento("Chepe Buquele, líder de la guerrilla de Apopa, ha sido acusado injustamente...", 30);
    pause(2000);
    imprimirLento("El presidente Cristiani lo culpa de una masacre contra obreros.", 30);
    pause(2000);
    imprimirLento("Ahora, Chepe debe escapar, recuperar pruebas y limpiar su nombre.", 30);
    pause(2000);
    cout << "\nPresiona ENTER para comenzar...";
    cin.ignore();
    cin.get();
    clearScreen();
}

void finalExitoso() {
    clearScreen();
    imprimirLento("🎉 ¡Felicidades!", 40);
    imprimirLento("Chepe logró cruzar el campo minado y encontró los documentos que prueban su inocencia.", 30);
    imprimirLento("El pueblo conoce la verdad. ¡La justicia ha triunfado!", 30);
    pause(3000);
}

void finalFallido(const string& razon) {
    gameOver(("Fallaste: " + razon).c_str());
}