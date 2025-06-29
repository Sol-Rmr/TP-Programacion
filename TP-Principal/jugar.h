#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

using namespace std;

void ModoDeJuegoMenu();
void ModoDeJuegoOpciones();

string ingresarNombre();
void encabezadoUnJugador();
void mostrarTurno(int &turno, string &nombre, int &puntaje, int &tirada);
int preguntarFinalizarTurno();
void mostrarResultado(int puntaje, string combinacion);
void mostrarFinal (string nombre, int puntaje);

int contar(int dados[], int valor, int tamanio);
string detectarCombinacion(int dados[], int &puntos, int tamanio);


///MODO UN JUGADOR
void gameplayUnJugador();


/// FUNCIONES DE LA CLASE
void gameplay();
int obtenerRandom(int tamanio);
void generarTirada(int v[], int tamanio);
void mostrarTirada(int v[], int tamanio);
int obtenerPuntos(int v[], int tamanio);

#endif // JUGAR_H_INCLUDED
