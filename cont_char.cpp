#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c, int quantidade, int indice){
    // fazer
    //quando tem so um caractere
    if(n==1&&str[indice]==c){
        return quantidade +=1;
    }else if(n>1&&n>indice){
        if(str[indice]==c){
            return contaCaracteres(str, n, c, quantidade+1, indice+1);
        }else{
            return contaCaracteres(str, n, c, quantidade, indice+1);
        }
    }else{
        return quantidade;
    }
}

int main(){
    string str;
    char c=' ';
    getline(cin, str);

    cin >> c;

    int n = str.length(), quantidade=0, indice=0, resultado=0;

    resultado = contaCaracteres(str, n, c, quantidade, indice);

    cout << resultado << endl;

   // fazer
}