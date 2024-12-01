#include <iostream>

using namespace std;

int subirDegrau(int n, int quantSubidas){
    
    if(n==1||n==2){
        return quantSubidas += 1;
    }else if(n==3){
        return quantSubidas += 2;
    }else{
        return quantSubidas += subirDegrau(n-1, quantSubidas) + subirDegrau(n-3, quantSubidas);
    }
}

int main() {
    int n;

    cin >> n;

    int quantSubidas = 0;
    int resultado=0;

    resultado = subirDegrau(n, quantSubidas);

    cout << resultado;


    return 0;
}