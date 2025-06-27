#include <iostream>
#include "jugar.h"
using namespace std;

void gameplay() {

    cout << "ARRANCA EL JUEGO" << endl;
    int puntosTotalesJugador1 = 0;
    int puntosTotalesJugador2 = 0;

    const int TAM = 5;
    int tirada[TAM];
    int totalRondas = 2;

    system("cls");
    for(int i = 1; i <=totalRondas; i++)
    {
        cout << "RONDA " << i << endl;
        cout << "-------------" << endl;
        for(int j = 1; j <= 2; j++)
        {
            if(j==1){
            cout << "JUGADOR #" << j << endl;
            generarTirada(tirada,TAM);
            mostrarTirada(tirada,TAM);
            puntosTotalesJugador1 += obtenerPuntos(tirada,TAM);
            }
            if(j==2){
            cout << "\nJUGADOR #" << j << endl;
            generarTirada(tirada,TAM);
            mostrarTirada(tirada,TAM);
            puntosTotalesJugador2 += obtenerPuntos(tirada,TAM);
            }
        }
        system("pause");
        system("cls");
    }

    cout << "Jugador 1: " << puntosTotalesJugador1 << " puntos" << endl;
    cout << "Jugador 2: " << puntosTotalesJugador2 << " puntos" << endl;

}

int obtenerRandom(int tamanio){
    return rand()%tamanio + 1;
}

void generarTirada(int v[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        v[i] = obtenerRandom(6);
    }
}

void mostrarTirada(int v[], int tamanio){
    for(int i = 0; i < tamanio; i++){
        cout << v[i] << " ";
    }

    cout << endl;
}

int obtenerPuntos(int v[], int tamanio){
    int puntos = 0;

    for(int i = 0; i < tamanio; i++){
        puntos += v[i];
    }
    return puntos;
}
