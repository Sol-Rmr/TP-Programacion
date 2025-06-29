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
    cout << "-------------------------" << endl;
}

string ingresarNombre() {
    string nombre;
    cout << "Ingrese su nombre: ";
    cin >> nombre;
    return nombre;
}

void encabezadoUnJugador() {
    cout << "---------- MODO UN JUGADOR ----------" << endl;
}

void mostrarTurno(int &turno, string &nombre, int &puntaje, int &tirada) {
    cout << "\nTurno " << turno << " de "  << nombre << endl;
    cout << "Puntaje Total: " << puntaje << endl;
    cout << "\nTirada #" << tirada << endl;

}

int preguntarFinalizarTurno() {
    int opcion;
    cout << "\n-------------------------------------------" << endl;
    cout << "¿Desea relanzar dados o finalizar turno?" << endl;
    cout << "1 - Relanzar Dados" << endl;
    cout << "2 - Terminar Turno" << endl;
    cout << "\nIngrese una opcion: ";
    cin >> opcion;
    return opcion;
}

void mostrarResultado(int puntaje, string combinacion, int puntajeTotal) {
    cout << "\n\n * * * * * TURNO TERMINADO * * * * *" << endl;
    cout << "Combinacion final: " << combinacion << endl;
    cout << "Puntaje de combinacion: " << puntaje << endl;
    cout << "------------------------------" << endl;
    cout << "Puntaje TOTAL: " << puntajeTotal << endl;
    cout << "\n";

}

void mostrarFinal (string nombre, int puntaje) {
    system("cls");
    cout << "---------- Fin del Juego ----------" << endl;
    cout << "\nNombre del Jugador:  " << nombre << endl;
    cout << "Puntaje Total:       " << puntaje << endl;
    cout << "\n\n\nVolviendo al menu de juego..." << endl;
}

///COMBINACIONES
// Contar cuántas veces aparece un número
int contar(int dados[], int valor, int tamanio) {
    int c = 0;
    for (int i = 0; i < tamanio; i++) {
        if (dados[i] == valor) c++;
    }
    return c;
}

// Detectar la combinación de dados
string detectarCombinacion(int dados[], int &puntos, int tamanio) {
    int cantidades[7] = {0}; // índices del 1 al 6

    // Contar ocurrencias de cada valor
    for (int i = 0; i < tamanio; i++) {
        cantidades[dados[i]]++;
    }

    // Banderas para cada combinación
    bool hayTrio = false;
    bool hayPoker = false;
    bool hayFull = false;
    bool hayPar = false;
    bool hayEscPeq = false;
    bool hayEscGra = false;
    bool hayYahtico = false;

    int cantidad3 = 0, cantidad2 = 0;
    int maxVal = dados[0];
    for (int i = 1; i < tamanio; i++) {
        if (dados[i] > maxVal) maxVal = dados[i];
    }

    for (int i = 1; i <= 6; i++) {
        if (cantidades[i] == 5) hayYahtico = true;
        if (cantidades[i] == 4) hayPoker = true;
        if (cantidades[i] == 3) {
            hayTrio = true;
            cantidad3++;
        }
        if (cantidades[i] == 2) {
            hayPar = true;
            cantidad2++;
        }
    }

    if (cantidad3 == 1 && cantidad2 == 1) hayFull = true;

    // Escaleras
    bool hay1 = cantidades[1] > 0;
    bool hay2 = cantidades[2] > 0;
    bool hay3 = cantidades[3] > 0;
    bool hay4 = cantidades[4] > 0;
    bool hay5 = cantidades[5] > 0;
    bool hay6 = cantidades[6] > 0;

    if ((hay1 && hay2 && hay3 && hay4) ||
        (hay2 && hay3 && hay4 && hay5) ||
        (hay3 && hay4 && hay5 && hay6)) {
        hayEscPeq = true;
    }

    if ((hay1 && hay2 && hay3 && hay4 && hay5) ||
        (hay2 && hay3 && hay4 && hay5 && hay6)) {
        hayEscGra = true;
    }

    // Evaluación según prioridad
    if (hayYahtico) {
        puntos = 50;
        return "Yahtico";
    }
    if (hayPoker) {
        for (int i = 1; i <= 6; i++) {
            if (cantidades[i] == 4) {
                puntos = i * 4;
                return "Póker";
            }
        }
    }
    if (hayFull) {
        puntos = 25;
        return "Full";
    }
    if (hayEscGra) {
        puntos = 35;
        return "Escalera Grande";
    }
    if (hayEscPeq) {
        puntos = 30;
        return "Escalera Pequeña";
    }
    if (hayTrio) {
        for (int i = 1; i <= 6; i++) {
            if (cantidades[i] == 3) {
                puntos = i * 3;
                return "Trío";
            }
        }
    }

    puntos = maxVal;
    return "Change";
}


/// MODO UN JUGADOR
void gameplayUnJugador() {
    //Ingreso de nombre
    system("cls");
    encabezadoUnJugador();
    string nombreJugador = ingresarNombre();

    const int TAM = 5;
    int tirada [TAM];
    int totalTurnos = 3, totalTiradas = 3;
    int puntaje = 0;
    int puntajeTotal = 0;
    string combinacion;

    // Vueltas de TURNOS
    for(int nroTurno = 1; nroTurno <= totalTurnos; nroTurno++) {
        bool turnoTerminado = false;
        int nroTirada = 1;

        //Vueltas de TIRADAS
        while(turnoTerminado == false) {
            system("cls");
            encabezadoUnJugador();
            mostrarTurno(nroTurno, nombreJugador,puntajeTotal,nroTirada);

            generarTirada(tirada,TAM);
            mostrarTirada(tirada,TAM);

            if(nroTirada < totalTiradas) {

                int opcion = preguntarFinalizarTurno();

                if(opcion == 2) {
                    combinacion = detectarCombinacion(tirada,puntaje, TAM);
                    puntajeTotal += puntaje;
                    mostrarResultado(puntaje, combinacion, puntajeTotal);
                    turnoTerminado = true;
                    system("pause");
                }

                nroTirada++;

            }else {
                combinacion = detectarCombinacion(tirada,puntaje, TAM);
                puntajeTotal += puntaje;
                mostrarResultado(puntaje, combinacion, puntajeTotal);
                turnoTerminado = true;
                system("pause");
            }
        }
    }

    mostrarFinal(nombreJugador,puntajeTotal);

}

/// FUNCIONES DE LA CLASE
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
