#include "juego.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 5;
const int MINAS = 5;

char tablero[FILAS][COLUMNAS];
bool minas[FILAS][COLUMNAS];

void inicializarTablero() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j] = '-';
            minas[i][j] = false;
        }
    }
}

void colocarMinas() {
    srand(time(0));
    int colocadas = 0;
    while (colocadas < MINAS) {
        int x = rand() % FILAS;
        int y = rand() % COLUMNAS;
        if (!minas[x][y]) {
            minas[x][y] = true;
            colocadas++;
        }
    }
}

int contarMinasAlrededor(int x, int y) {
    int contador = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < FILAS && ny >= 0 && ny < COLUMNAS && minas[nx][ny]) {
                contador++;
            }
        }
    }
    return contador;
}

void mostrarTablero() {
    cout << "  ";
    for (int i = 0; i < COLUMNAS; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < FILAS; i++) {
        cout << i << " ";
        for (int j = 0; j < COLUMNAS; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool jugar(int x, int y) {
    if (minas[x][y]) {
        cout << " Pisaste una mina." << endl;
        return false;
    } else {
        tablero[x][y] = '0' + contarMinasAlrededor(x, y);
        return true;
    }
}

