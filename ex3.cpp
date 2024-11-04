#include <iostream>

using namespace std;

int main() {
    int n;

    //tem que limpar o buffer tambem

    cin >> n;

    int pontosPrimeiro = 0, pontosSegundo = 0;

    float* vetor=new float[n];
    float* chutesPrimeiro=new float[n];
    char* chutesSegundo=new char[n];


    for(int i=0;i<n;i++){
        cin >> vetor[i];
    }

    for(int i=0;i<n;i++){
        cin >> chutesPrimeiro[i];
    }

    for(int i=0;i<n;i++){
        cin >> chutesSegundo[i];
    }

    for(int i=0;i<n;i++){
        if(chutesPrimeiro[i]==vetor[i]){
            pontosPrimeiro +=1;
        }else{
            if(chutesPrimeiro[i]<vetor[i]&&*chutesSegundo=='M'){

            }
        }
    }

    return 0;
}