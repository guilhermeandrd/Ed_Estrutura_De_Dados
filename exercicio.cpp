#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

    //ler string
    for(int i{1};i<=5;++i){
        string linha;
         /*string str;
         istringstream iss;*/
         //getline(cin, linha);
        cout << "Digite os numeros separados por espaços: " << endl;
        getline(cin, linha);
        istringstream iss(linha);
        float numero, soma=0;

        while(iss >> numero){
            soma += numero;
        }

        cout << "Soma: " << soma << "\n";
    }
   
    //quebrar a string com istringstream

    //somar os numeros

    //retornar a soma

    //str(string str);

    




    return 0;
}