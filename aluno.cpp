#include <iostream>
#include <string>

using namespace std;

struct Aluno{
    string matricula;
    string nome;
    float notas[3];
    float media;
};

void lerAluno(Aluno& aluno){
    cout << "Digite matricula" << "\n";
    getline(cin, aluno.matricula);
    cout << "Digite nome" << "\n";
    getline(cin, aluno.nome);
    aluno.media = 0;
    cout << "Digite notas" << "\n";   
    for(int i=0;i<3;i++){
        cin >> aluno.notas[i];
        aluno.media += aluno.notas[i];
    }
    aluno.media = aluno.media/3;
    cin.ignore();
}

void imprimirAluno(Aluno aluno[], int tamanho){
    int indiceMaiorMedia = 0;

    for(int i=0;i<5;i++){

        if(aluno[i].media>aluno[indiceMaiorMedia].media){
            indiceMaiorMedia = i;
        }

    }

    cout << aluno[indiceMaiorMedia].nome << "\n"
    << aluno[indiceMaiorMedia].matricula << "\n"
    << aluno[indiceMaiorMedia].media << "\n";
    for(int i=0;i<3;i++){
        cout << aluno[indiceMaiorMedia].notas[i]<<"\n";
    }
}

int main() {
    Aluno alunos[5];

    for(int i=0;i<5;i++){
        lerAluno(alunos[i]);
    }

    imprimirAluno(alunos, 5);
    
    return 0;
}