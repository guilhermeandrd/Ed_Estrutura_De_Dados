#include <iostream>
#include "Vector.h"

Vector::Vector(const Vector& vec){
    capacity = vec.capacity; //em poo - porque to recebendo um objeto da mesma classe eu tenho acesso a atributo privado
    size = vec.size;
    array = new int[capacity];//criação de um novo array
    for(int i=0;i<size;i++){
        array[i]=vec.array[i];
    }
}

Vector::Vector() {
    capacity = 1;
    size = 0;
    array = new int[capacity];
}

Vector::~Vector() {
    delete[] array;
}

void  Vector::reserve ( int n ){
    if(n>capacity){
        capacity = n;
        int* aux = new int[capacity];
        //copiar o vetor
        for(int i= 0;i<size;i++){
            aux[i] = array[i];
        }
        delete array;
        array = aux;
    }
}

void Vector::push_back (const int &value){
    if(size==capacity){//se estiver cheio
        reserve(capacity*2);//dobra a capacidade O(n)
    }
    array[size]=value;//o size funciona como indice O(n)
    size++;
}

int& Vector::at(int k){
    if(k>=0 && k<size){
        return array[k];
    }else{
        throw std::out_of_range("erro: indice fora do intervalo!!");//lançar esse objeto
    }
} ; // O (1)
//saber o size
//
//o que caralhos é análise amortizada
//assintoticamente o tempo médio de push_back é O(n)

int Vector::getSize() const{//nao pode chamar nada que nao seja const dentro de uma func const
    return size;//funcao get basica
}

bool Vector::empty() const{
    return size==0;
}

int Vector::getCapacity() const{
    return capacity;
}

int& Vector::operator[] (int k){
    return array[k];
}

void Vector::pop_back(){
    if(size>0){
        size--;
    }
}