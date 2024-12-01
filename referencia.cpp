#include <iostream>

using namespace std;

//funcao que troca

int main() {
    int x=76;

    int& ref = x; //ela ta apontando pra variavel x, pode alterar x usando ela, outro nome pra x

    ref = 4;
    int& ref2 = ref;

    ref2 = 5;
    cout << x << endl;

    cout << &ref2 << "\n" << &x << endl;

    return 0;
}