#include <iostream>

using namespace std;

void imprimir(int quantidade){
    if(quantidade==0){
        return;
    }else{
        cout << "*" << endl;
        quantidade--;
        imprimir(quantidade);
    }
    
}

int fatorial(int numero, int resultado){
    
    if(numero==1){
        return resultado;
    }else{
        return resultado += numero*(numero-1);
        numero --;
        fatorial(numero, resultado);
    }
}

int main() {
    int entrada;
    int saida;

    cin >> entrada;

    imprimir(entrada);

    return 0;
}