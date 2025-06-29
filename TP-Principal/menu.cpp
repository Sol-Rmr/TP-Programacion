#include <iostream>
#include "menu.h"
#include "jugar.h"
#include "creditos.h"
#include "estadisticas.h"
using namespace std;

void menu() {

    const int TAM_JUGADORES = 5;
    string mejoresJugadores[TAM_JUGADORES];
    int mejoresPuntajes[TAM_JUGADORES];

    ponerVectorCero(mejoresPuntajes, TAM_JUGADORES);

    int opcion;

    do{
        opciones(); // -> Void opciones();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ModoDeJuegoMenu(mejoresJugadores, mejoresPuntajes, TAM_JUGADORES);
                system("pause");
                break;
            case 2:
                mostrarEstadisticas(mejoresJugadores,mejoresPuntajes);
                system("pause");
                break;
            case 3:
                MostrarCreditos();
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

void opciones() {
    system("cls");
    cout << "\n+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "     Y  A  H  T  I  C  O" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------" << endl;
}
