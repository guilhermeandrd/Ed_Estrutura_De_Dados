#include <iostream>
#include <string>

using namespace std;

struct Aluno{
    string nome;
    int matricula;
    string disciplina;
    double nota;
};

void lerAluno(Aluno aluno){
    cin >> aluno.nome;
    cin >> aluno.matricula;
    cin.ignore();
    cin >> aluno.disciplina;
    cin >> aluno.nota;
    cin.ignore();
}

void imprimirMaior(Aluno aluno, Aluno alunodois){
    if(aluno.nota>alunodois.nota){
        cout << aluno.nome << " , " << aluno.nota << endl;
    }else if(aluno.nota<alunodois.nota){
        cout << alunodois.nome << " , " << alunodois.nota << endl;
    }else{
        cout << aluno.nome << " e " << alunodois.nome << " , " << aluno.nota;
    }
}


int main() {

    Aluno aluno1, aluno2;

    lerAluno(aluno1);
    lerAluno(aluno2);

    imprimirMaior(aluno1, aluno2);

    return 0;
}