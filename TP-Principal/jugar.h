#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

using namespace std;

void ModoDeJuegoMenu(string nombres[], int puntajes[], int t);
void ModoDeJuegoOpciones();

string ingresarNombre();
void encabezadoUnJugador();
void encabezadoDosJugadores();
void mostrarTurno(int &turno, string &nombre, int &puntaje, int &tirada);
int preguntarFinalizarTurno();
void mostrarResultado(int puntaje, string combinacion);
void mostrarFinal (string nombre, int puntaje);
int obtenerRandom(int tamanio);
void generarTirada(int v[], int tamanio);
void mostrarTirada(int v[], int tamanio);
void generarTiradaTurno(int v[], int tamanio);
void mostrarTiradaTurno(string nombres[], int v[], int tamanio);
void mostrarPrimerJugador(string nombre);

///COMBINACIONES
int contar(int dados[], int valor, int tamanio);
string detectarCombinacion(int dados[], int &puntos, int tamanio);

void definirTurno(string nombres[], int v[], int tamanio);

///MODO UN JUGADOR
void gameplayUnJugador(string nombres[], int puntajes[], int t);

///MODO DOS JUGADORES
void gameplayDosJugadores(string nombres[], int puntajes[], int t);


#endif // JUGAR_H_INCLUDED
