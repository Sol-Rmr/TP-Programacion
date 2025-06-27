#include <iostream>
#include "jugar.h"
using namespace std;

///ELECCION DE MODO DE JUEGO
void ModoDeJuegoMenu() {
    int opcion;
    do {
        ModoDeJuegoOpciones();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                gameplayUnJugador();
                system("pause");
                break;
            case 2:
                cout << "MODO DOS JUGADORES GAMEPLAY" << endl;
                system("pause");
                break;
            case 0:
                return;
                break;
            default:
                cout << " // Opcion invalida //" << endl;
                system("pause");
                break;
        }
    }
    while(true);
}

void ModoDeJuegoOpciones() {
    system("cls");
    cout << "-------------------------" << endl;
    cout << "      MODO DE JUEGO" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - UN JUGADOR" << endl;
    cout << "2 - DOS JUGADORES" << endl;
    cout << "\n0 - Volver al menu" << endl;
}

///MODO 1 JUGADOR
void gameplayUnJugador() {
    //Ingreso de nombre
    system("cls");
    encabezadoUnJugador();
    string nombreJugador1;
    cout << "Ingrese su nombre: ";
    cin >> nombreJugador1;

    //Gameplay
    int puntaje = 0;

    const int TAM = 5;
    int tirada [TAM];
    int totalTurnos = 3;
    int totalTiradas = 3;

    for(int nroTurno = 1; nroTurno <= totalTurnos; nroTurno++) {
        bool turnoTerminado = false;
        int nroTirada = 1;

        while(turnoTerminado == false) {
            system("cls");
            encabezadoUnJugador();
            cout << "\nTurno " << nroTurno << " de "  << nombreJugador1 << endl;
            cout << "Puntaje Total: " << puntaje << endl;
            cout << "\nTirada #" << nroTirada << endl;

            generarTirada(tirada,TAM);
            mostrarTirada(tirada,TAM);

            cout << "\n-------------------------------------------" << endl;
            if(nroTirada < totalTiradas) {
                cout << "¿Desea relanzar dados o finalizar turno?" << endl;
                cout << "1 - Relanzar Dados" << endl;
                cout << "2 - Terminar Turno" << endl;

                int opcion;
                cout << "Ingrese una opcion: ";
                cin >> opcion;

                if(opcion == 2) {
                    turnoTerminado = true;
                }

                nroTirada++;

            }else {
                cout << "Turno Terminado" << endl;
                cout << "Combinacion final: COLOCAR COMBINACION" << endl;
                cout << "Puntaje: COLOCAR Puntaje" << endl;
                turnoTerminado = true;
                system("pause");
            }
        }
    }


}

void encabezadoUnJugador() {
    cout << "---------- MODO UN JUGADOR ----------" << endl;
}





/// FUNCIONES DE LA CLASE
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
