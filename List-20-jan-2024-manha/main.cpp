#include <iostream>
#include "List.h"

using namespace std;

int main() {    
    //construtor inicializador
    List lista1 {1,2,3, 23,4,5,6,6,6,7};

    //construtor que recebe uma copia
   // List lista2(lista1);    
    
    //construtor default
    

    cout << lista1 << endl;
    return 0;
}