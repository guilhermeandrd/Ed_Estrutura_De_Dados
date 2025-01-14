#include <iostream>
#include <vector>

using namespace std;


int procurarContador(vector <int> filas, int valor){
    int contador;

    for(int i=0;i<filas.size();i++){
        if(filas.at(i)==valor){
            return i;
        }
    }

    return -1;
}

/*void remove_at(vector <int> &filas, int value){
    int contador;

    //acho o indice do valor
    for(int i=0;i<filas.size();i++){
        if(filas.at(i)==value){
            //filas.push_back(value);
            int contador = i;
        }

    }
    vector <int> aux(filas);
    int passo = filas[filas.size()-1];
    filas[filas.size()-1] = value;

    for(int i=contador;i<filas.size();i++){
        aux[i] = filas[i+1];
    }

    aux.push_back(passo);
    aux.pop_back();
    filas = aux;

    delete[] aux;
}*/

int main() {

    int size, deixaramSize;
    vector <int> fila;
    //vector <int> deixaramFila;

    cin >>size;

    for(int i=0;i<size;i++){
        int elem;
        cin >> elem;
        fila.push_back(elem);
    }

    cin >> deixaramSize;

    //vector <int> aux(fila);


    for(int i=0;i<deixaramSize;i++){
        int elem;
        cin >> elem;
        int contador = procurarContador(fila, elem);
        if(contador>-1){
            fila.erase(fila.begin()+contador);
        }
    }

    for(int i=0;i<fila.size();i++){
        cout << fila.at(i) << " ";
    }
    cout << endl;
    fila.clear();

    return 0;
}