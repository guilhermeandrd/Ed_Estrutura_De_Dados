#include <iostream>
#include "data.h"

using namespace std;

const int MAX = 3;

int main(){
    Data dataNiver(28,11, 2005);

    //dataNiver.dia = 3;
    //dataNiver.mes = 4;
    //dataNiver.ano = 2021;

    dataNiver.setDia(dataNiver, 3);
    dataNiver.setMes(dataNiver, 4);
    dataNiver.setAno(dataNiver, 2021);

    dataNiver.mostraData();

    /*Dinamicamente
    Data *ptrData = new Data();
    prtData->inicializaData(10,12,2024);
    ptrData->mostraData();
    delete ptrData;
    ptrData= null;
    */

    //criação por array estatico
    Data arrayData[10];

    int d, m, a;
    int i=0;
    while(i<MAX){
        cout << "digite uma data d/m/a ";
        cin >> d;
        cin >> m;
        cin >> a;
        arrayData[i];
        i++;
    }

    //criacao normal
    /*Data d;
    d.inicializaData(13, 12, 2024);
    d.mostraData();

    Data d2;
    d2.inicializaData(14,12,2024);
    d2.mostraData();*/

    return 0;
}