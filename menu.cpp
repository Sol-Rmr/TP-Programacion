#include <iostream>
#include "menu.h"
#include "jugar.h"
using namespace std;

void menu() {
    int opcion;

    do{
        opciones(); // -> Void opciones();
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                gameplay();
                system("pause");
                break;

            case 2:
                cout << "PANTALLA ESTADISTICAS" << endl;
                system("pause");
                break;

            case 3:
                cout << "PANTALLA SALIR" << endl;
                system("pause");
                return;
                break;

            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    }
    while(true);

}

void opciones() {
    system("cls");
    cout << "------------------------" << endl;
    cout << "| 1 - JUGAR            |" << endl;
    cout << "| 2 - ESTADISTICAS     |" << endl;
    cout << "| 3 - SALIR            |" << endl;
    cout << "------------------------" << endl;


}
