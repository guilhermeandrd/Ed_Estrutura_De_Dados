#include <iostream>

using namespace std;

struct Ponto{
    float x;
    float y;

    void troca(Ponto *p1, Ponto *p2){
    Ponto ref = *p1; //comecar logo pela admissao com um dos valores que sera trocado
    //trocar os valores das variáveis p1 e p2 pelo ponteiro
    Ponto ref = *p1;
    *p1 = *p2;
    *p2 = ref;
    *p1 = *this;
    }
};



void dobra(Ponto *p1){
    5;
}

int main() {

    Ponto p1 {2,3}, p2 {4,5};



    return 0;
}