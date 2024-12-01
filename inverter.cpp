#include <iostream>

using namespace std;

//quem sao os casos bases
//

void inverter(int N[], int i, int f){
    if(i>=f){
        return;
    }else{
        swap(N[i],N[f]);
        inverter(N, i+1, f-1);
    }
}

int main() {

    int tamanho=4;


    int numero[1,2,3,4];

    inverter(numero, 0, tamanho-1);

    cout << numero;
    return 0;
}