#include <iostream>

using namespace std;

int main() {
    int n;

    //tem que limpar o buffer tambem

    cin >> n;

    cin.ignore();

    int pontosPrimeiro = 0, pontosSegundo = 0;

    float* vetor=new float[n];
    float* chutesPrimeiro=new float[n];
    char* chutesSegundo=new char[n];


    for(int i=0;i<n;i++){
        cin >> vetor[i];
        cin.ignore();
    }

    for(int i=0;i<n;i++){
        cin >> chutesPrimeiro[i];
        cin.ignore();
    }

    for(int i=0;i<n;i++){
        cin >> chutesSegundo[i];
    }

    for(int i=0;i<n;i++){
        if(chutesPrimeiro[i]==vetor[i]){
            pontosPrimeiro +=1;
        }else{
            //ta maior que o original
            if(chutesPrimeiro[i]>vetor[i]&&*chutesSegundo=='M'){
                pontosSegundo +=1;
                break;
            //ta menor que o original
            }else if(chutesPrimeiro[i]<vetor[i]&&*chutesSegundo=='m'){
                pontosSegundo +=1;
                break;
            }
        }
    }


    if(pontosPrimeiro>pontosSegundo){
        cout << "primeiro" << endl;
    }else if(pontosPrimeiro<pontosSegundo){
        cout << "segundo" << endl;
    }else{
        cout << "empate" << endl;
    }

    return 0;
}