#include <iostream>
#include "jugar.h"
#include "menu.h"
#include "estadisticas.h"
using namespace std;

///ELECCION DE MODO DE JUEGO
void ModoDeJuegoMenu(string nombres[], int puntajes[], int t) {
    int opcion;
    do {
        ModoDeJuegoOpciones();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                gameplayUnJugador(nombres, puntajes, t);
                system("pause");
                break;
            case 2:
                gameplayDosJugadores(nombres, puntajes, t);
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
    cout << "---------- MODO UN JUGADOR ----------\n" << endl;
}

void encabezadoDosJugadores() {
    cout << " ---------- MODO DOS JUGADORES ----------\n" << endl;
}

void mostrarTurno(int &turno, string &nombre, int &puntaje, int &tirada) {
    cout << "Turno " << turno << " de "  << nombre << endl;
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

void mostrarResultado(int puntaje, string combinacion, int puntajeTotal, int v[], int t) {
    cout << " * * * * * TURNO TERMINADO * * * * *" << endl;
    cout << "Tirada:" << endl;
    mostrarTirada(v, t);
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

void mostrarFinal2Jugadores (string nombres[], int puntajes[], int tamanio) {
    system("cls");
    cout << "---------- Fin del Juego ----------" << endl;
    for(int i = 0; i < tamanio; i++) {
        cout << "\nNombre del Jugador "<< i+1<<":  " << nombres[i] << endl;
        cout << "Puntaje Total:         " << puntajes[i] << endl;
    }
        cout << "\n\n\nVolviendo al menu de juego..." << endl;
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

void generarTiradaTurno(int v[], int tamanio) {
    for(int i = 0; i < tamanio; i++) {
        v[i] = obtenerRandom(6);
    }
}

void mostrarTiradaTurno(string nombres[], int v[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << "\nTirada de " << nombres[i] << ": " << v[i] << endl;
    }
}

void mostrarPrimerJugador(string nombre) {
    cout << "\n--------------------------------------------" << endl;
    cout << nombre << " comienza!" << endl;
    cout << "--------------------------------------------" << endl;
}

void opcionesRelanzamientos(int v[], int t) {
    string opcion;
    cout << "Desea relanzar un dado o todos? (O = uno, A = todos)" << endl;
    cin >> opcion;
    if((opcion == "O") || (opcion == "o")) {
        relanzarUnDado(v);
    }

    if((opcion == "A") || (opcion == "a")) {
        generarTirada(v, t);
    }
}

int relanzarUnDado(int v[]) {
    int posicion;
    cout << "Cual dado desea relanzar(indicar posicion del 1 al 5)?:" << endl;
    cin >> posicion;
    v[posicion-1] = obtenerRandom(6);
    cout << "Salio: " << v[posicion-1] << endl;
}

///COMBINACIONES

// Detectar la combinación de dados
string detectarCombinacion(int v[], int &puntos, int t) {
    bool hayTrio = esTrio(v, t, puntos);
    bool hayPoker = esPoker(v, t, puntos);
    bool hayEscaleraPequena = esEscaleraPequena(v, t);
    bool hayYahtico = esYahtico(v, t);

    if(hayTrio) {
        bool hayFull = esFull(v, t);
        if(hayFull) {
            puntos = 25;
            return "Full";
        }else {
            return "Trio";
        }
    }

    if(hayPoker) {
        return "Poker";
    }

    if(hayEscaleraPequena) {
        bool hayEscaleraGrande = esEscaleraGrande(v, t);
        if(hayEscaleraGrande) {
            puntos = 35;
            return "Escalera Grande";
        }else{
            puntos = 30;
            return "Escalera Pequeña";
        }
    }
    if(hayYahtico) {
        puntos = 50;
        return "Yahtico";
    }

    int mayor = 1;
    for(int i = 0; i < t; i++) {
        if(v[i] > mayor) {
            mayor = v[i];
        }
    }
    puntos = mayor;
    return "Change";
}

bool esTrio(int v[], int tamanio, int &puntaje) {
    bool trio = false;
    int contIgual = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < tamanio; j++) {
            if(v[j] == i) {
                contIgual++;
            }
        }
        if(contIgual == 3) {
            puntaje = i*3;
            trio = true;
        }
        contIgual = 0;
    }

    return trio;
}

bool esPoker(int v[], int t, int &puntaje) {
    bool poker = false;
    int contIgual = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < t; j++) {
            if(v[j] == i) {
                contIgual++;
            }
        }

        if(contIgual == 4) {
            for(int p = 0; p < t; p++) {
                puntaje += v[p];
            }
            poker = true;
            return poker;
        }
        contIgual = 0;
    }

    return poker;
}

bool esFull(int v[], int t) {
    // 3 dados iguales + 2 dados iguales
    bool full = false;
    int contIgual = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < t; j++) {
            if(v[j] == i) {
                contIgual++;
            }
        }
        if(contIgual == 2) {
            full = true;
            return full;
        }
        contIgual = 0;
    }
    return full;
}

bool esEscaleraPequena(int v[], int t) {
    bool escalera = false;

    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < t; j++) {
            bool tiene1 = false;
            bool tiene2 = false;
            bool tiene3 = false;
            bool tiene4 = false;

            if(v[j] == i) {
                tiene1 = true;
            }
            if(v[j+1] == i + 1) {
                tiene2 = true;
            }
            if(v[j+2] == i + 2) {
                tiene3 = true;
            }
            if(v[j+3] == i + 3) {
                tiene4 = true;
            }
            if(tiene1 && tiene2 && tiene3 && tiene4) {
                escalera = true;
                return escalera;
            }
        }
    }
    return escalera;
}

bool esEscaleraGrande(int v[], int t) {
    bool escalera = false;

    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < t; j++) {
            bool tiene1 = false;
            bool tiene2 = false;
            bool tiene3 = false;
            bool tiene4 = false;
            bool tiene5 = false;

            if(v[j] == i) {
                tiene1 = true;
            }
            if(v[j+1] == i + 1) {
                tiene2 = true;
            }
            if(v[j+2] == i + 2) {
                tiene3 = true;
            }
            if(v[j+3] == i + 3) {
                tiene4 = true;
            }
            if(v[j+4] == i + 4) {
                tiene5 = true;
            }

            if(tiene1 && tiene2 && tiene3 && tiene4 && tiene5) {
                escalera = true;
                return escalera;
            }
        }
    }
    return escalera;
}

bool esYahtico (int v[], int t) {
    bool yahtico = false;
    int contIgual = 0;

    for (int i = 1; i <= 6; i++) {
        for (int j = 0; j < t; j++) {
            if(v[j] == i) {
                contIgual++;
            }
        }

        if(contIgual == 5) {
            yahtico = true;
            return yahtico;
        }
        contIgual = 0;
    }

    return yahtico;
}

void definirTurno(string nombres[], int v[], int tamanio) {
    encabezadoDosJugadores();
    cout << "|          Definicion de Turnos          |" << endl;
    generarTiradaTurno(v, tamanio);
    mostrarTiradaTurno(nombres, v, tamanio);
    cout << "\n\n";

    if(v[0] == v[1]) {
        bool empate = true;
        while (empate) {
            cout << "\n\n--------------------------------------------" << endl;
            cout << "Empate! Comienza de nuevo..." << endl;
            cout << "--------------------------------------------" << endl;
            system("pause");
            system("cls");
            encabezadoDosJugadores();
            cout << "|          Definicion de Turnos          |" << endl;
            generarTiradaTurno(v, tamanio);
            mostrarTiradaTurno(nombres, v, tamanio);
            cout << "\n\n";
            if(v[0] != v[1]) {
                empate = false;
            }
        }
    }
    if(v[0] > v[1]) {
        mostrarPrimerJugador(nombres[0]);
    }else {
        mostrarPrimerJugador(nombres[1]);
        string auxiliar = nombres[0];
        nombres[0] = nombres[1];
        nombres[1] = auxiliar;
    }
}

/// MODO UN JUGADOR
void gameplayUnJugador(string nombres[], int puntajes[], int t) {
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
        int opcion;

        //Vueltas de TIRADAS
        while(turnoTerminado == false) {
            system("cls");
            encabezadoUnJugador();
            mostrarTurno(nroTurno, nombreJugador,puntajeTotal,nroTirada);
            if(nroTirada < totalTiradas) {
                if(nroTirada == 1) {
                    generarTirada(tirada,TAM);
                }
                mostrarTirada(tirada,TAM);
                opcion = preguntarFinalizarTurno();
                if(opcion == 1) {
                    //Relanzar Dados
                    opcionesRelanzamientos(tirada, TAM);
                    system("pause");
                }

                if(opcion == 2) {
                    //Terminar Turno
                    system("cls");
                    combinacion = detectarCombinacion(tirada,puntaje, TAM);
                    puntajeTotal += puntaje;
                    mostrarResultado(puntaje, combinacion, puntajeTotal, tirada, TAM);
                    turnoTerminado = true;
                    system("pause");
                }

                nroTirada++;

            }else{
                system("cls");
                combinacion = detectarCombinacion(tirada,puntaje, TAM);
                puntajeTotal += puntaje;
                mostrarResultado(puntaje, combinacion, puntajeTotal, tirada, TAM);
                turnoTerminado = true;
                system("pause");
            }
        }
    }
    mostrarFinal(nombreJugador,puntajeTotal);
    actualizarPuntajes(nombres, puntajes, t, nombreJugador, puntajeTotal);

}

/// MODO DOS JUGADORES
void gameplayDosJugadores(string nombres[], int puntajes[], int t) {
    system("cls");

    // Ingreso de nombres
    encabezadoDosJugadores();
    cout << "JUGADOR 1" << endl;
    string nombreJugador1 = ingresarNombre();
    cout << "\n\nJUGADOR 2" << endl;
    string nombreJugador2 = ingresarNombre();

    // Definir turnos
    const int TAM_JUGADORES = 2;
    int dados[TAM_JUGADORES];
    string jugadores[TAM_JUGADORES] = {nombreJugador1, nombreJugador2};
    system("cls");
    definirTurno(jugadores, dados, TAM_JUGADORES);
    system("pause");

    /// GAMEPLAY
    system("cls");
    int puntajesJugadores[TAM_JUGADORES] = {};
    int puntajesTotales[TAM_JUGADORES] = {};
    int totalTurnos = 3, totalTiradas = 3;
    const int TAM = 5;
    int tirada [TAM];
    string combinacion;

    // Vueltas de TURNOS
    for(int nroTurno = 1; nroTurno <= totalTurnos; nroTurno++) {
        bool turnoTerminadoJugador1 = false;
        bool turnoTerminadoJugador2 = false;
        int nroTirada = 1;

        //Vueltas de TIRADAS DE JUGADOR 1
        while(turnoTerminadoJugador1 == false) {
            system("cls");
            encabezadoDosJugadores();
            mostrarTurno(nroTurno, jugadores[0],puntajesTotales[0],nroTirada);
            if(nroTirada < totalTiradas) {
                if(nroTirada == 1) {
                    generarTirada(tirada,TAM);
                }
                mostrarTirada(tirada,TAM);
                int opcion = preguntarFinalizarTurno();
                if(opcion == 1) {
                    //Relanzar Dados
                    opcionesRelanzamientos(tirada, TAM);
                    system("pause");
                }
                if(opcion == 2) {
                    system("cls");
                    combinacion = detectarCombinacion(tirada,puntajesJugadores[0], TAM);
                    puntajesTotales[0] += puntajesJugadores[0];
                    mostrarResultado(puntajesJugadores[0], combinacion, puntajesTotales[0], tirada, TAM);
                    turnoTerminadoJugador1 = true;
                    system("pause");
                }
                nroTirada++;
            }else {
                system("cls");
                combinacion = detectarCombinacion(tirada,puntajesJugadores[0], TAM);
                puntajesTotales[0] += puntajesJugadores[0];
                mostrarResultado(puntajesJugadores[0], combinacion, puntajesTotales[0], tirada, TAM);
                turnoTerminadoJugador1 = true;
                system("pause");
            }
        }

        nroTirada = 1;
        //Vueltas de TIRADAS DE JUGADOR 2
        while(turnoTerminadoJugador2 == false) {
            system("cls");
            encabezadoDosJugadores();
            mostrarTurno(nroTurno, jugadores[1],puntajesTotales[1],nroTirada);

            if(nroTirada < totalTiradas) {
                if(nroTirada == 1) {
                    generarTirada(tirada,TAM);
                }
                mostrarTirada(tirada,TAM);
                int opcion = preguntarFinalizarTurno();
                if(opcion == 1) {
                    //Relanzar Dados
                    opcionesRelanzamientos(tirada, TAM);
                    system("pause");
                }
                if(opcion == 2) {
                    system("cls");
                    combinacion = detectarCombinacion(tirada,puntajesJugadores[1], TAM);
                    puntajesTotales[1] += puntajesJugadores[1];
                    mostrarResultado(puntajesJugadores[1], combinacion, puntajesTotales[1], tirada, TAM);
                    turnoTerminadoJugador2 = true;
                    system("pause");
                }
                nroTirada++;
            }else {
                system("cls");
                combinacion = detectarCombinacion(tirada,puntajesJugadores[1], TAM);
                puntajesTotales[1] += puntajesJugadores[1];
                mostrarResultado(puntajesJugadores[1], combinacion, puntajesTotales[1], tirada, TAM);
                turnoTerminadoJugador2 = true;
                system("pause");
            }
        }

    }
    mostrarFinal2Jugadores(jugadores,puntajesTotales,TAM_JUGADORES);
    for(int i = 0; i < TAM_JUGADORES; i++) {
        actualizarPuntajes(nombres, puntajes, t, jugadores[i], puntajesTotales[i]);
    }
}
