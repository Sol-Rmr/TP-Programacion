#include <iostream>
#include "estadisticas.h"
using namespace std;

void mostrarEstadisticas(string nombres[], int puntajes[]) {
    system("cls");
    cout << "---------------- ESTADISTICAS ----------------" << endl;
    mostrarMejoresJugadores(nombres, puntajes);
    if(puntajes[0] == 0) {
        sinEstadisticas();
    }
    cout << "\n----------------------------------------------" << endl;
}

void sinEstadisticas() {
    cout << "\nNo hay registro de jugadores actualmente..." << endl;
}

void mostrarMejoresJugadores(string nombres[], int puntajes[]) {
    cout << "TOP 5: " << endl;
    cout << "Posicion    Puntos              Jugador" << endl;
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        cout << "#" << i+1 << "          " << puntajes[i] << "                  " << nombres[i] << endl;
    }
}

bool hayTop5(int puntajes[]) {
    bool hayPuntos = true;
    for(int i = 0; i < 5; i++) {
        if(puntajes[i] == 0) {
            hayPuntos = false;
        }
    }
    return hayPuntos;
}

void ponerVectorCero (int v[], int t) {
    for(int i = 0; i < t; i++) {
        v[i] = 0;
    }
}

void actualizarPuntajes(string nombres[], int puntajes[], int t, string nombre, int puntaje) {
    bool actualizado = false;

    for(int i = 0; i < t; i++) {
        if(actualizado == false) {
            if(puntajes[0] == 0) { ///ES EL PRIMER NRO
                nombres[0] = nombre;
                puntajes[0] = puntaje;
                actualizado = true;
            }else if(puntaje > puntajes[i]) {
                for(int j = t; j > i; j--) {
                    puntajes[j] = puntajes[j-1];
                    nombres[j] = nombres[j-1];
                }
                //Nuevo puntaje
                    puntajes[i] = puntaje;
                    nombres[i] = nombre;
                    actualizado = true;
            }

        }
    }

}

