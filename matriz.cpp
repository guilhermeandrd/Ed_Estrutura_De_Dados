#include <iostream>

using namespace std;

void lerMatriz(int **M, int nlin, int ncol){
    for(int i=0;i<nlin;i++)
        for(int j=0;j<ncol;j++)
            cin >> M[i][j];
}

void verificarQuadradoMagico(int **M, int nlin, int ncol){


    int somaD=0, somaL1=0, somaL2=0, somaL3=0, somaC1=0, somaC2=0, somaC3=0;
    //fazer um vetor para as somas e depois ver se os elementos "as somas" são iguais
    //soma das linhas
    for(int i=0;i<nlin;i++){
        for(int j=0;j<ncol;j++){
            if(i==0){
                somaC1 += M[i][j];
            }else if(i==1){
                somaC2 += M[i][j];
            }else if(i==2){
                somaC3 += M[i][j];
            }
        }
    }

    //soma das colunas
    for(int j=0;j<ncol;j++){
        for(int i=0;i<nlin;i++){
            if(j==0){
                somaL1 += M[i][j];
            }else if(j==1){
                somaL2 += M[i][j];

            }else if(j==2){
                somaL3 += M[i][j];

            }
        }
    }

    //soma das diagonais
    for(int i=0;i<nlin;i++){
        for(int j=0;j<ncol;j++){
            if(i==j){
                    somaD += M[i][j];
            }
        }
    }



    if(somaD==somaC1&&somaC1==somaC2&&somaC2==somaC3&&somaC3==somaL1&&somaL1==somaL2&&somaL2==somaL3){
        cout << "sim" << endl;
    }else{
        cout << "nao" << endl;
    }

}


int main() {
    int **M;

    int nlin = 3, ncol=3;

    M = (int **) malloc(nlin*sizeof(int *));

    if(M){
        for(int i =0;i<nlin;i++){
            M[i] = (int *) malloc(ncol*sizeof(int));
        }
    }

    lerMatriz(M, nlin, ncol);

    verificarQuadradoMagico(M, nlin, ncol);

    return 0;
}