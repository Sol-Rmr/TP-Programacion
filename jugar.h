#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED


void ModoDeJuegoMenu();
void ModoDeJuegoOpciones();

void gameplayUnJugador();
void encabezadoUnJugador();


/// FUNCIONES DE LA CLASE
void gameplay();
int obtenerRandom(int tamanio);
void generarTirada(int v[], int tamanio);
void mostrarTirada(int v[], int tamanio);
int obtenerPuntos(int v[], int tamanio);

#endif // JUGAR_H_INCLUDED
