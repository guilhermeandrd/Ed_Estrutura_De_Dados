#include <iostream>
#include <string>

using namespace std;

bool palindromo(string palavra, int ini, int fim){
    if(ini>=fim){
        return true;
    }else{
        if(palavra[ini]!=palavra[fim]){
            return false;
        }else{
            return palindromo(palavra, ini+1,fim-1);
        }
    }
}

int main() {
    string entrada;

    cin >> entrada;

    cout << boolalpha << palindromo(entrada, 0, entrada.length()-1) << endl;

    return 0;
}