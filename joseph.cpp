#include <iostream>
#include <vector>

using namespace std;

//foda se vou fazer do meu jeito


void matar(vector <int> elementos, int size, int pos){
    int e=0;

    //achar contador
    for(int i=0;i<size;i++){
        if(elementos[i]==pos){
            e=i;
        }
    }

    //matar elemento que ta na frente
    elementos.erase(elementos.begin()+e, elementos.begin()+e+1);


}

int main() {

    vector <int> vet;
    int size, comeco,pos;

    for(int i=0;i<size;i++){
        int elem;
        cin >> elem;
        vet.push_back(elem);
    }

    while(pos!=0){
        matar(vet, size, pos);

        size-=1;

        pos = pos%size;
    }

    for(int i=0;i<size;i++){
        cout << vet[i];
    }

    return 0;
}