#include <iostream>
using namespace std;

bool EsTrio(int v[], int tamanio);
void mostrarTirada (int v[], int tamanio);

int main() {

    const int TAM = 5;
    int dados[TAM] = {3,3,2,1,3}; ///Modificar a conveniencia para testear

    cout << "Tirada: ";
    mostrarTirada(dados, TAM);


    bool bandera;
    bandera = EsTrio(dados, TAM);

    if(bandera) {
        cout << "Es trio" << endl;

    }else {
        cout << "NO es trio" << endl;
    }

    return 0;
}


bool EsTrio(int v[], int tamanio) {
    ///3 DADOS IGUALES

    bool trio = false;
    int contIgual = 0;

    for (int i = 1; i <= 6; i++) { //Vueltas del valor vector | Dado
        for (int j = 0; j < tamanio; j++) { //Vueltas del vector | Posicion del dado
            if(v[j] == i) {
                contIgual++;
            }
        }

        if(contIgual == 3) {
            trio = true;
        }
        contIgual = 0;
    }

    return trio;
}

void mostrarTirada (int v[], int tamanio) {
    for(int i = 0; i < tamanio; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
