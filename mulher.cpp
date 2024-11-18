#include <iostream>
#include <string>

using namespace std;

struct Pessoa{
    string nome;
    int idade;
    char sexo;
};

void lerPessoa(Pessoa pessoas[], int tamanho){
    for(int i=0;i<tamanho;i++){
        cin >> pessoas[i].nome;
        cin >> pessoas[i].idade;
        cin.ignore();
        cin >> pessoas[i].sexo;
        cin.ignore();
    }
}

void procurarVelha(Pessoa pessoas[], int tamanho){
    int e=0;

    for(int i=0;i<tamanho;i++){
        if(pessoas[i].sexo=='f'){
            if(pessoas[i].idade>pessoas[e].idade){
                e=i;
            }
        }
    }

    cout << pessoas[e].nome << endl;
}

int main() {
    int tamanho;

    cin >> tamanho;

    Pessoa* pessoas = new Pessoa [tamanho];

    lerPessoa(pessoas, tamanho);

    procurarVelha(pessoas, tamanho);
    
    return 0;
}