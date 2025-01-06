#include <iostream>
#include "Fraction.h"

using namespace std;

int main(){
    Fraction f(2,4), g(1,3), h;

    cout<< "imprima uma fração: ";
    Fraction frac;

    cin >> frac; //---> 4/1

    cout << frac << endl;

    frac+= f;//9/2

    cout << frac << endl;

    if(frac==f){
        cout << "são iguais" << endl;
    }else{
        cout << "nao são iguais" << endl;//esse
    }
    
    frac-=f;//9/2-2/4=36-4/8=32/8=4/1

    cout << frac << endl;//4/1

    if(frac>=f){//4/1>2/4
        cout << "frac é maior ou igual" << endl;//esse
    }else{
        cout << "frac é menor" << endl;
    }

    g=frac*f;//4/1*2/4=8/4=2/1

    cout << g << endl; //2/1

    if(g<=frac){//2/1 é menor do que 4/1? sim
        cout << "g é menor ou igual" << endl;//esse
        if(g<frac){
            cout << "g é menor" << endl;//esse
        }
    }else{
        cout << "g é maior" << endl;
    }

    h=g/f;//2/1 divido por 2/4 = 2*4/1*2 = 8/2 = 4/1

    cout << h << endl;//4/1

    if(h!=frac){//4/1 é diferente de 4/1? nao
        cout << "são diferentes";
    }else{
        cout << "são iguais";//esse
    }


}