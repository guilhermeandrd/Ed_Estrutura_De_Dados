#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno{
    string nome;
    double n1, n2, n3;
    double media;
};

void lerAluno(Aluno alunos[], int tamanho){
    for(int i=0;i<tamanho;i++){
        cin.ignore();
        getline(cin, alunos[i].nome);
        cin >> alunos[i].n1 >> alunos[i].n2 >> alunos[i].n3;
    }
}

void calcularMedia(Aluno alunos[], int tamanho){
    for(int i=0;i<tamanho;i++){
        alunos[i].media = (alunos[i].n1 + alunos[i].n2 + alunos[i].n3)/3.0;
    }
}

void reorganizarTurma(Aluno alunos[], int tamanho){
    for(int i=0;i<tamanho;i++){
        int maiorIndex = i;
        
    
        //descobrir maior numero
        for(int j=i+1;j<tamanho;j++){
            if(alunos[j].media>alunos[maiorIndex].media){
                maiorIndex=j;
            }
        }

        if(maiorIndex != i){
            Aluno temp = alunos[i];
            alunos[i] = alunos[maiorIndex];
            alunos[maiorIndex] = temp;
        }
        
        
        //como eu vou saber qual o indice que tinha o valor maior?
    }
}

void imprimirAluno(Aluno alunos[], int tamanho){
    for(int i=0;i<tamanho;i++){
        cout<< i << ": " << alunos[i].nome<<  endl;
        cout << fixed << setprecision(2);
        cout << "Media: " << alunos[i].media << endl;
        cout << "N1: " << alunos[i].n1 << ", N2: "<< alunos[i].n2 << ", N3: " << alunos[i].n3<< endl;
    }
}


int main() {
    int tamanho;

    cin >> tamanho;

    Aluno* alunos = new Aluno [tamanho];

    lerAluno(alunos, tamanho);

    calcularMedia(alunos, tamanho);

    reorganizarTurma(alunos, tamanho);

    imprimirAluno(alunos, tamanho);

    delete[] alunos;
    return 0;
}