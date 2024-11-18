#include <iostream>

using namespace std;

void preencheArray(int *p, int n){

    for(int i=0;i<n;i++){
        cin >> p[i];
    }
}

void imprimeArray(int *p, int n){

    for(int i=0;i<n;i++){
        cout << p[i];
    }

}

int main() {

    int n;

    cin >> n;
    int *p = new int [n];
    preencheArray(p, n);
    imprimeArray(p, n);
    delete[] p;
    return 0;
}