#include "utils.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <string>  

using namespace std;


bool nivel2() {
    clearScreen();
    imprimirLento(" NIVEL 2: La Contraseña\n", 40);
    pause(1000);
    imprimirLento("Chepe llega a la base guerrillera, pero los guardias no lo reconocen.", 30);
    pause(1500);
    imprimirLento("Debe decir la contraseña secreta para que lo dejen entrar.", 30);
    pause(1500);
    imprimirLento("Uno de los guardias murmura: 'La palabra clave siempre ha sido nuestra causa...'", 30);
    pause(1500);
    imprimirLento("¿Podria ser acaso.......?", 30);
    pause(1500);
    cout << "\nPresiona una tecla para intentar ingresar...\n";
    getch();
    clearScreen();

    string palabra = "resistencia";
    string intento;
    int intentos = 3;

    while (intentos--) {
        cout << "Contraseña: ";
        cin >> intento;
        if (intento == palabra) {
            mensajeFinal(" Contraseña correcta. Bienvenido, comandante.");
            return true;
        } else {
            cout << " Incorrecto. Te quedan " << intentos << " intentos.\n";
        }
    }

    return false;
}