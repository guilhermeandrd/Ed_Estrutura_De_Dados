#include <iostream>
#include <iomanip>

using namespace std;

double fatorial(int n){

    int n2 = 1;
    double resulFatorial = 1;

    while(n>0){
        resulFatorial *=n;
        n-=1;
    }

    return resulFatorial;
}

double euler(int n){

    double e=1;

    for(int i=1;i<(n+1);i++){
        e += 1/fatorial(i);
    }    

    return e;
}

int main() {

    int n;

    cin >> n;

    double resultado;

    resultado = euler(n);

    cout << fixed << setprecision(6) << resultado << endl;

    return 0;
}