#include <iostream>
#include <ctime>
using namespace std;

const int FILAS = 5;
const int COLUMNAS =5;
const int MINAS = 5;

char tablero [FILAS][COLUMNAS];
bool minas [FILAS][COLUMNAS];

void inicializartablero(){
for(int i=0; i < FILAS; i++){
    for(int j=0; j< COLUMNAS; j++){
        tablero[i][j]= '-';
        minas[i][j] = false;
    }
    
}

}

void colocarminas(){
srand(time(0));
int colocadas = 0;
while(colocadas < MINAS){
    int x = rand() % FILAS;
    int y = rand() % COLUMNAS;
    if(!minas[x][y]){
        minas[x][y] = true;
        colocadas++;
    }
}

}

int contarminasalrededor(int x, int y){
    int contador = 0;
    for (int i = -1; i <= 1; i++) {
        for(int j = -1; j<=1; j++){
            int nx = x + i, ny = y +j;
            if(nx >= 0 && nx < FILAS &&  ny < COLUMNAS && minas [nx][ny]){
contador++;
            }
        }
        
    }
    return contador;
}

void mostrartablero(){
    cout<<"";
    for(int i=0; i< COLUMNAS; i++) cout << i<< "";
        cout<<endl;
        for(int i=0; i<FILAS ; i++){
            cout << i << "";
            for(int j=0; j<COLUMNAS; j++){
                cout << tablero[i][j] << "";
            }
            cout<<endl;
        }
        
    }
    
bool jugar(int x, int y){
    if(minas[x][y]){
        cout <<"Pisaste una mina." <<endl;
        return false;
    }else{
        tablero[x][y]='0' + contarminasalrededor(x,y);
        return true;
    }
    
}

int main(){
    inicializartablero();
    colocarminas();
    int x, y;
    bool siguejugando = true;

    while(siguejugando){
        mostrartablero();
        cout << "ingrese coordenadas (fila columna):";
        cin >> x >> y;
        if(x >= 0 && x < FILAS && y >= 0 && y < COLUMNAS){
            siguejugando = jugar(x,y);
        }else{
            cout<<"coordenadas fuera de rango, intenta de nuevo." <<endl;
        }
        
    }
    cout <<"juego terminado." <<endl;
    return 0;
}