#define JUGAR_H_INCLUDED

using namespace std;

void ModoDeJuegoMenu(string nombres[], int puntajes[], int t);
void ModoDeJuegoOpciones();

string ingresarNombre();
void encabezadoUnJugador();
void mostrarTurno(int &turno, string &nombre, int &puntaje, int &tirada);
int preguntarFinalizarTurno();
void mostrarResultado(int puntaje, string combinacion);
void mostrarFinal (string nombre, int puntaje);
int obtenerRandom(int tamanio);
void generarTirada(int v[], int tamanio);
void mostrarTirada(int v[], int tamanio);

///COMBINACIONES
int contar(int dados[], int valor, int tamanio);
string detectarCombinacion(int dados[], int &puntos, int tamanio);

///MODO UN JUGADOR
void gameplayUnJugador(string nombres[], int puntajes[], int t);


#endif // JUGAR_H_INCLUDED
