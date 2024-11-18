#include <iostream>

using namespace std;

void imprimir(int quantidade){
    if(quantidade==0){
        return;
    }
    cout << "*" << endl;
    quantidade--;
    if(quantidade>0){
        imprimir(quantidade);
    }
}

int main() {
    int entrada;

    cin >> entrada;

    imprimir(entrada);

    return 0;
}