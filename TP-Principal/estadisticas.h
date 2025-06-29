#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

using namespace std;

void mostrarEstadisticas(string nombres[], int puntajes[]);
void sinEstadisticas();
void mostrarMejoresJugadores(string nombres[], int puntajes[]);
bool hayTop5(int puntajes[]);
void ponerVectorCero (int v[], int t);
void actualizarPuntajes(string nombres[], int puntajes[], int t, string nombre, int puntaje);

#endif // ESTADISTICAS_H_INCLUDED
