#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Aluno{
    int matricula;
    string nome;
    double media;
};

void lerAluno(Aluno aluno[], int tamanho){

    for(int i=0;i<tamanho;i++){
        cin >> aluno[i].matricula;
        cin.ignore();
        getline(cin, aluno[i].nome);
        cin >> aluno[i].media;
    }

}

void verificarTurma(Aluno aluno[], int tamanho, int matricula){
    for(int i=0;i<tamanho;i++){
        if(aluno[i].matricula==matricula){
            cout << aluno[i].nome << "\n" << fixed << setprecision(1) << aluno[i].media << endl;
        }else if(i==tamanho-1&&aluno[i].matricula!=matricula){
            cout << "NAO ENCONTRADA" << endl;
        }
    }
}

int main() {
    int tamanho;
    int matricula;

    cin >> tamanho;

    Aluno* alunos = new Aluno [tamanho];

    lerAluno(alunos, tamanho);

    cin >> matricula;

    verificarTurma(alunos, tamanho, matricula);

    delete[] alunos;
    return 0;
}