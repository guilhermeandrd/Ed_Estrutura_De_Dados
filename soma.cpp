#include <iostream>

using namespace std;

int soma(int n){
    if(n==10){
        return 1;
    }else{
        return n + soma(n-1);
    }
}

int main() {

    int numero=5;

    int resultado = soma(numero);
    
    cout << resultado;

    return 0;
}