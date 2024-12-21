#include <iostream>
#include "Box.h"
using namespace std;

int main() {
    // Cria um objeto por meio de alocacao dinamica
    Box *ptr = new Box(3.0, 5.0, 1.0);
    cout << "volume da caixa = " << ptr->volume() << endl;
    ptr->set_length(1);
    ptr->set_height(9);
    ptr->set_width(4);
    cout << "volume da caixa = " << ptr->volume() << endl;
    delete ptr;

    cout << "----------------------------------\n";

    // Cria um objeto por meio de alocacao estatica
    Box caixa;
    caixa.set_height(10).set_width(10).set_length(10); // observe aqui o jeito encadeado que foi usado
    cout << "altura: " << caixa.get_height() << endl;
    cout << "comprimento: " << caixa.get_length() << endl;
    cout << "largura: " << caixa.get_width() << endl;
    cout << "volume da caixa = " << caixa.volume() << endl;
}
