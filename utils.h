#ifndef UTILS_H
#define UTILS_H

#include <string>

void clearScreen();
void pause(int ms);
void gameOver(const char* motivo);
void mensajeFinal(const char* msg);
void imprimirLento(const std::string& texto, int velocidad = 30);

#endif