#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct ALUNOS{
  string nome;
  double nota[3];
  double media=0;
};

ALUNOS Leraluno(){
    ALUNOS aluno;
    cin.ignore();
    getline(cin, aluno.nome);
    for(int i=0; i<3; i++){
        cin>>aluno.nota[i];
        aluno.media+=aluno.nota[i];
    }
    aluno.media=aluno.media/3;
    
    return aluno;
}

int main(){
    int tantodealunos;
    cin>>tantodealunos;
    
    ALUNOS* aluno=new ALUNOS[tantodealunos];
    
    for(int i=0; i<tantodealunos; i++){
        aluno[i]=Leraluno();
    }
    
    ALUNOS reserva;
    
    
    for(int i=0; i<tantodealunos; i++){
        for(int j=1; j<tantodealunos; j++){
            if(aluno[j].media>aluno[j-1].media){
                reserva=aluno[j-1];
                aluno[j-1]=aluno[j];
                aluno[j]=reserva;
            }
        }
    }
    
    cout<<fixed<<setprecision(2)<<endl;
    for(int i=0; i<tantodealunos; i++){
        cout<<i<<": "<<aluno[i].nome<<endl<<
        "   Media: "<< aluno[i].media<<endl<<
        "   N1: "<<aluno[i].nota[0] <<","<<" N2: "<<
        aluno[i].nota[1]<<", "<<"N3: "<< aluno[i].nota[2]<<endl;
    }
    
    delete [] aluno;
    return 0;
}