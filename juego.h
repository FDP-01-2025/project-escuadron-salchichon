#ifndef JUEGO_H
#define JUEGO_H

extern const int FILAS;
extern const int COLUMNAS;
extern const int MINAS;

void inicializarTablero();
void colocarMinas();
int contarMinasAlrededor(int x, int y);
void mostrarTablero();
bool jugar(int x, int y);

#endif