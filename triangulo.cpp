
#include <iostream>

using namespace std;



void trianguloSoma(int *A, int i){
    
    
    if(i==0){//qual o caso base? quando só tiver um elemento ou quando o indice for o limite
            cout << "[" << A[0] << "] ";
            cout << endl;
            return;
    }//caso geral
        int* aux =  new int[i];
        for(int k=0;k<i;k++ ){
            aux[k]=A[k];
        }
        for(int e=0;e<i;e++){
            A[e] += A[e+1];
        }
        trianguloSoma(A, i-1);
        for(int e=0;e<=i;e++){
            cout << "[" << aux[e] << "] "; //modulo //o topo esta sendo imprimido agora so falta o restante 
        }
        cout << "\n";
        delete[] aux;
    
    
}

int main() {
    int n;

    cin >> n;

    int* vetor = new int[n];

    for(int i=0;i<n;i++){
        cin >> vetor[i];
    }


    trianguloSoma(vetor, n-1);

    delete[] vetor;

    return 0;
}