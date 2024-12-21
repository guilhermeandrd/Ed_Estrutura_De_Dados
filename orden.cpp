#include <iostream>

using namespace std;

 void OrganizarCrescente(int *vetor, int n){
    for(int e=0;e<n-1;e++){//c2  se vai repetir n+1
        for(int i=0;i<n-1-e;i++){//c3
            if(vetor[i]>vetor[i+1]){//c4
                int passo = vetor[i];//c5
                vetor[i] = vetor[i+1];//c6
                vetor[i+1] = passo;//c7
                //cout << "passou aqui \n";
            }
        }
    }
}
int main() {
    int n;
    int passo=0;
    cin >> n;
    int* vetor = new int[n];

    for(int i=0;i<n;i++){
        cin >> vetor[i];
    }
    OrganizarCrescente(vetor, n);
    for(int i=0;i<n;i++){
        cout << vetor[i] << " ";
    }

    return 0;
}