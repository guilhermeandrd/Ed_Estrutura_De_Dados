#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main(){
    forward_list<int> lista {1,2,3,4,5,6,7};

    for(auto it = lista.begin(); it!=lista.end(); it++){//auto é uma palavra chave para inicilizador{}
        cout << *it << " "; 
    }

    return 0;
}