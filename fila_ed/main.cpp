#include <iostream>
#include "Node.h"
#include <string.h>
#include <vector>
#include "Queue.h"

using namespace std;

/*
Number deve ser do tipo numeric*/

template <typename Number>

Number soma(Number a, Number b){
    return a+b;
}

//ordena um vetor de inteiros
template <typename Tipo>
//tem que ser um tipo comparavel
void ordenar(vector<Tipo>&vec){
    for(int i=vec.size()-1;i>=0;--i){
        for(int j=0;j<i;++j){
            if(vec[j]>vec[j+1]){
                Tipo passo = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = passo;
            }
        }
    }
}

int main() {
    Queue <int> minhaFila;


    for(int i=9;i>0;i--){
        minhaFila.push(i);
    }

    while(!minhaFila.empty()){
        cout <<  minhaFila.front() << " ";
        minhaFila.pop();
    }
    
    /*cout << soma <int>(4, 5) << endl;
    cout << soma <double>(4.5, 4.5) << endl;
    cout << soma <float> (9.0,8.8)<< endl;*/


    // minhaFila.clear();

    return 0;
}