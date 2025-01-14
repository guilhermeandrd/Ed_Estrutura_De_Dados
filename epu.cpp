#include <iostream>
#include <vector>

using namespace std;

void remove_all(){
    
}

void remove_at(vector <int> &fila, int index){
    //quero passar todos pra esquerda e depois dar um pop_back

    if(index==fila.size()-1){
        fila.pop_back();
    }else{
        for(int i=index;i<fila.size()-1;i++){
            fila[i]=fila[i+1];
        }
        fila.pop_back();
    }

}

//O(N)
void increas_at(vector<int>& fila, int index, int valor) {

    if(index<0 || index>fila.size()) {
        throw std::out_of_range("Índice fora do intervalo");
    }

    fila.resize(fila.size() + 1);

    for(int i=fila.size()-1; i>index; i--) {
        fila[i]=fila[i - 1];
    }

    fila[index]=valor;
}


int main() {
    vector <int> ex;

    ex.push_back(4);
    ex.push_back(5);
    ex.push_back(6);
    increas_at(ex, 1, 7);

    for(int i=0;i<ex.size();i++){
        cout << ex[i];
    }

    cout << endl;

    remove_at(ex, 0);

    for(int i=0;i<ex.size();i++){
        cout << ex[i];
    }

    return 0;
}