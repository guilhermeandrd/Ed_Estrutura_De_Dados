#include <iostream>

using namespace std;

//fazer o for iterativo
//tem que repetir n vezes
//quando n for 1 é 1

int fib_iterativo ( int n ) {
    int ant=0, atual=1, prox=0, i=0;

    for (i=2;i<=n;i++){
        prox = ant + atual ;
        
        ant = atual ;
        atual = prox ;
    }

    return (n > 0) ? atual : ant;
}

int main() {
    int n;

    cin >> n;

    int r = fib_iterativo(n);

    cout << r;

    return 0;
}