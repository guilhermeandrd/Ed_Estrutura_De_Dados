#include <iostream>
#include <math.h>

using namespace std;

//isso foi até onde eu consegui chegar

void hanoi(int qte, char ini, char aux, char aux2, char fim, int &i){
  if(qte==1){
      cout << ini << "->" << fim << endl;
      i++;
  }else if(qte==2){
      cout << ini << "->" << aux << "\n";
      cout << ini << "->" << fim << "\n";
      cout << aux << "->" << fim << "\n";
      i++;
  }else{
    hanoi(qte-2, ini, fim, aux2, aux, i);
    cout << ini << "->" << aux2 << "\n";
    hanoi(qte-2, ini, aux2, aux, fim, i);
    cout << aux2 << "->" << fim << "\n";
    hanoi(qte-2, aux, ini, aux2, fim, i);
  }
}

int main(){
  int qte;
  int i=0;
  cin >> qte;
  hanoi(qte, 'A', 'B', 'C', 'D', i);
  cout << i;
  return 0;
}