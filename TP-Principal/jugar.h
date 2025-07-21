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
void mostrarResultado(int puntaje, string combinacion, int puntajeTotal, int v[], int t);
void mostrarFinal (string nombre, int puntaje);
int obtenerRandom(int tamanio);
void generarTirada(int v[], int tamanio);
void mostrarTirada(int v[], int tamanio);
void generarTiradaTurno(int v[], int tamanio);
void mostrarTiradaTurno(string nombres[], int v[], int tamanio);
void mostrarPrimerJugador(string nombre);
void opcionesRelanzamientos(int v[], int t);
int relanzarUnDado(int v[]);

///COMBINACIONES
string detectarCombinacion(int dados[], int &puntos, int tamanio);
bool esTrio(int v[], int tamanio, int &puntaje);
bool esPoker(int v[], int t, int &puntaje);
bool esFull(int v[], int t);
bool esEscaleraPequena(int v[], int t);
bool esEscaleraGrande(int v[], int t);
bool esYahtico (int v[], int t);


void definirTurno(string nombres[], int v[], int tamanio);

///MODO UN JUGADOR
void gameplayUnJugador(string nombres[], int puntajes[], int t);

///MODO DOS JUGADORES
void gameplayDosJugadores(string nombres[], int puntajes[], int t);


#endif // JUGAR_H_INCLUDED
