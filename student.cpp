#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
    //tenho que colocar o ultimo no primeiro nrot vezes
    for(int i=0;i<nrot;i++){
        int passo= vet.at(vet.size()-1);
        vet.insert(vet.begin(), passo);
        vet.pop_back();
    }
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

