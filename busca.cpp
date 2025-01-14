#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> matchingStrings(vector <string> consultas, vector <string> buscas){
    vector <int> frequencias;

    for(int i=0;i<buscas.size();i++){
        frequencias.push_back(0);
    }

    for(int i=0;i<buscas.size();i++){
        //frequencias[i]=0;
        for(int e=0, j=0;e<consultas.size();e++){
            if(consultas.at(e)==buscas.at(i)){
                frequencias[i] ++;
            }
            
        }
    }

    return frequencias;
}

int main() {
    
    int sizeConsulta, sizeBusca;
    vector <string> consulta;
    vector <string> busca;
    //vector <int> frequencia;

    cin >> sizeConsulta;

    cin.clear();

    for(int i=0;i<sizeConsulta;i++){
        string elem;
        cin >> elem;
        consulta.push_back(elem);
    }

    /*for(int i=0;i<sizeConsulta;i++){
        cout << consulta.at(i) << " ";
    }*/

    //cout << "\n";

    cin >> sizeBusca;

    cin.clear();

    for(int i=0;i<sizeBusca;i++){
        string elem;
        cin >> elem;
        busca.push_back(elem);
    }

    /*for(int i=0;i<busca.size();i++){
        frequencia.push_back(0);
    }*/

    vector <int> frequencia(matchingStrings(consulta, busca));

    //frequencia[0]=0;


    for(int i=0;i<frequencia.size();i++){
        cout.clear();
        if(i==frequencia.size()-1){
            cout << frequencia.at(i);
        }else{
            cout << frequencia.at(i) << " ";
        }
    }

    cout << "\n";

    consulta.clear();
    busca.clear();
    frequencia.clear();

    return 0;
}