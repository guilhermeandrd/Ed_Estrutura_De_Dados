#include <iostream>
#include <iomanip>

using namespace std;

void trocarValor(int &n, int &m){
    int passa=0;
    int passa = n;
    n = m;
    m = passa;
}

int main() {
    /*int* ptr;
    int * ptr;
    int *ptr;
    int x, *ptr;
    int *x, ptr;
    int x;
    cout << x;
    cout << &x;
    int *ptr = &x;*/
    int *p1, *p2;
    int x = 100, *ptr;
    ptr = &x;
    cout << x << endl;
    cout << *ptr << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    cout << sizeof(ptr) << endl;
    cout << sizeof(*ptr) << endl;

    swap(*p1,*p2); //funcão para trocar os valores das variáveis
    //toda funçao em c++ recebe o argumento por copia;

    *ptr+2;//ponteiro avanca duas casas

    int n=5;

    for( int i=0;i<n;i++){
        cout << *(ptr+i);
    }


    return 0;
}