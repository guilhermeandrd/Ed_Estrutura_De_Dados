#include <iostream>

using namespace std;

void lerMatriz(int **M, int nlin, int ncol){
    for(int i=0;i<nlin;i++)
        for(int j=0;j<ncol;j++)
            cin >> M[i][j];
}

void contarFila(int **M, int nlin, int ncol){

    int resultado =0;

    for(int i=0;i<ncol;i++){
        for(int j=0;j<nlin;j++){
            if(i>0){
                if(M[i][j]<M[i-1][j]){
                    resultado += 1;
                }   
            }
        }
    }

    cout << resultado << endl;
}

int main() {
    int **M;

    int nlin=3, ncol=3;

    M = (int **) malloc(nlin*sizeof(int*));

    if(M){
        for(int i=0;i<nlin;i++){
            M[i] = (int *) malloc(ncol*sizeof(int));
        }
    }   

    lerMatriz(M, nlin, ncol);

    contarFila(M, nlin, ncol);

    return 0;
}