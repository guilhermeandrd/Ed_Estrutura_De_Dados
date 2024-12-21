#include <iostream>
#include "Vector.h"
using namespace std;

void print(Vector vector){
    for(int i=0;i<vector.getSize();i++){
        cout << vector[i] << " ";
    }
    cout << endl;
}

int main() {
    Vector meu_vector; // cria um objeto da classe Vector

    for(int i=1;i<=20;++i){
        meu_vector.push_back(i);
    }

   Vector vector2(meu_vector);
    print(vector2);
    print(meu_vector);

    vector2[3]=999;
   
    print(vector2);
    print(meu_vector);

    vector2.pop_back();

    print(vector2);
}