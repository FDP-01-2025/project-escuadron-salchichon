#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 5;
const int MINAS = 5;

vector<vector<char>> tablero(FILAS, vector<char>(COLUMNAS, '-'));
vector<vector<bool>> minas(FILAS, vector<bool>(COLUMNAS, false));

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
            if (nx >= 0 && nx < FILAS && ny >= 0 && ny < COLUMNAS && minas[nx][ny])
                contador++;
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
        cout << "¡Boom! Pisaste una mina." << endl;
        return false;
    } else {
        tablero[x][y] = '0' + contarMinasAlrededor(x, y);
        return true;
    }
}

int main() {
    colocarMinas();
    int x, y;
    bool sigueJugando = true;

    while (sigueJugando) {
        mostrarTablero();
        cout << "Ingrese coordenadas (fila columna): ";
        cin >> x >> y;
        if (x >= 0 && x < FILAS && y >= 0 && y < COLUMNAS) {
            sigueJugando = jugar(x, y);
        } else {
            cout << "Coordenadas fuera de rango, intenta de nuevo." << endl;
        }
    }

    cout << "Juego terminado." << endl;
    return 0;
}