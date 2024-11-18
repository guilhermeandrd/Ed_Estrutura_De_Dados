#include <iostream>
#include <string>

using namespace std;

struct Aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

void lerAluno(Aluno &aluno){
    cin >> aluno.nome;
    cin >> aluno.matricula;
    cin.ignore();
    cin >> aluno.disciplina;
    cin >> aluno.nota;
    cin.ignore();
}

void verificarAluno(Aluno aluno){
    if(aluno.nota>=7){
        cout << aluno.nota << " aprovado(a) em " << aluno.disciplina << endl;
    }else {
        cout << aluno.nota << " reprovado(a) em " << aluno.disciplina;
    }
}

int main() {

    Aluno aluno;

    lerAluno(aluno);
    verificarAluno(aluno);

    return 0;
}