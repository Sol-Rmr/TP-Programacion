#include <iostream>
#include <ctime> //PARA GENERAR LA SEMILLA
#include "menu.h"

using namespace std;

int main(){

    srand(time(nullptr));

    menu();

    return 0;
}
