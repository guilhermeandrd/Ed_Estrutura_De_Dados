#include "fogo.hpp"

using namespace std;

void tocar_fogo(std::vector<std::string> &mat, int l, int c) {
    int nl = mat.size();     // numero de linhas
    int nc = mat[0].size();  // numero de colunas
    
    // Terminar de escrever essa funcao .....
    if(l>=nl||c>=nc||l<0||c<0){//se for fora da matriz//zerando quando chegar na ultima linha daquela coluna
        return;//condição de parada
    }else if(mat[l][c]!='#'){//se nao for uma arvore
        return;
    }else{//se for uma arvore
        mat[l][c]='o';
        tocar_fogo(mat, l+1, c);
        tocar_fogo(mat, l-1, c);
        tocar_fogo(mat, l, c+1);
        tocar_fogo(mat, l, c-1);
    }
}