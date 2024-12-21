#ifndef data_h
#define data_h

#include <iostream>

class Data{
private:
    //Os atributos da classe data
    int dia;
    int mes;
    int ano;

public:

    //construtror padrao, pq nao recebe parametros
    Data(){
        dia = 0;
        mes = 0;
        ano = 0;
    }

    //Construtor q sempre é chamado, assim q o objeto é instanciado
    Data(int d, int m, int a){
        if(dataEhValida(d, m, a)){
            dia = d;
            mes = m;
            ano = a;
        }else{
            dia = 0;
            mes = 0;
            ano = 0;
        }
    }

    void incializarData(int d, int m, int a){
        if(dataEhValida(d, m, a)){
            dia = d;
            mes = m;
            ano = a;
        }else{
            dia = 0;
            mes = 0;
            ano = 0;
        }
    }
    
    bool dataEhValida(int d, int m, int a){
        if(d>=1&&d<=31&&m>=1&&m<=12){
            return true;
        }else{
            return false;
        }
    }

    void mostraData(){
        std::cout << dia << "/" << mes << "/" << ano << std::endl;
    }

    int getDia(Data& data){
        return dia;
    }

    int getMes(Data& data){
        return mes;
    }

    int getAno(Data& data){
        return ano;
    }

    void setDia(Data& data, int dia2){
        dia = dia2;
    }

    void setMes(Data& data, int mes2){
        mes = mes2;
    }

    void setAno(Data& data, int ano2){
        ano = ano2;
    }
};

#endif