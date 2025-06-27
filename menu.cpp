#include <iostream>
#include "menu.h"
#include "jugar.h"
using namespace std;

void menu() {
    int opcion;

    do{
        opciones(); // -> Void opciones();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ModoDeJuegoMenu();
                system("pause");
                break;
            case 2:
                cout << "PANTALLA ESTADISTICAS" << endl;
                system("pause");
                break;
            case 3:
                cout << "PANTALLA CREDITOS" << endl;
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
