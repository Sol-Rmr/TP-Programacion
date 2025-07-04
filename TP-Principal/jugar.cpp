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

            generarTirada(tirada,TAM);
            mostrarTirada(tirada,TAM);

            if(nroTirada < totalTiradas) {
                int opcion = preguntarFinalizarTurno();
                if(opcion == 2) {
                    combinacion = detectarCombinacion(tirada,puntajesJugadores[0], TAM);
                    puntajesTotales[0] += puntajesJugadores[0];
                    mostrarResultado(puntajesJugadores[0], combinacion, puntajesTotales[0]);
                    turnoTerminadoJugador1 = true;
                    system("pause");
                }
                nroTirada++;
            }else {
                combinacion = detectarCombinacion(tirada,puntajesJugadores[0], TAM);
                puntajesTotales[0] += puntajesJugadores[0];
                mostrarResultado(puntajesJugadores[0], combinacion, puntajesTotales[0]);
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

            generarTirada(tirada,TAM);
            mostrarTirada(tirada,TAM);

            if(nroTirada < totalTiradas) {
                int opcion = preguntarFinalizarTurno();
                if(opcion == 2) {
                    combinacion = detectarCombinacion(tirada,puntajesJugadores[1], TAM);
                    puntajesTotales[1] += puntajesJugadores[1];
                    mostrarResultado(puntajesJugadores[1], combinacion, puntajesTotales[1]);
                    turnoTerminadoJugador2 = true;
                    system("pause");
                }
                nroTirada++;
            }else {
                combinacion = detectarCombinacion(tirada,puntajesJugadores[1], TAM);
                puntajesTotales[1] += puntajesJugadores[1];
                mostrarResultado(puntajesJugadores[1], combinacion, puntajesTotales[1]);
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
