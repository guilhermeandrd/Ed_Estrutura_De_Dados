#include <iostream>
#include <math.h>

using namespace std;

//mudei algo
//tem que mover do ini pro aux, qte-1
//ini -> aux2
//tem que mover do aux1, pro aux2, qte-1
//aux1->fim
//tem que mover do aux pro fim, qte-1

void hanoi(int qte, char ini, char aux, char fim){
  if(qte==1){
      cout << ini << "->" << fim << endl;//caso basico 
  }else{
    hanoi(qte-1, ini, aux, fim);//-1 disco
    cout << ini << "->" << fim << "\n";
    hanoi(qte-1, aux, ini, fim);
  }
}

int main(){
  int qte;
  cin >> qte;
  hanoi(qte, 'A', 'B', 'C');
  return 0;
}