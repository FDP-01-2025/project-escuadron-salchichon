#include "utils.h" 
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

void clearscreen(){
    system("cls");
}

void pause (int ms){
    sleep(ms);
}

void gameover(const char* motivo){
    cout<<"\n--- GAME OVER:" << motivo << "---\n" << "Presiona cualquier tecla para salir...";
    getch();
    exit(0);
}

void mensajefinal(const char* msg){
    cout<< msg << "\n\n presiona cualquier tecla para continuar... ";
    getch();
    clearscreen();
}