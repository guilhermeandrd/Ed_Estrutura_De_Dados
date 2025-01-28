#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"

//classe que implementa um iterador para uma forward list
class Iterator{
private:
    Node* m_pointer; //ponteiro para nó

public:
    //constructor default
    //ja ta feito c++ vai colocar um nulo, porem fds
    Iterator() : m_pointer{nullptr} {}

    //construtor que recebe um ponteiro
    Iterator(Node *ptr) : m_pointer{ptr} {};

    //sobrecarga do operador asterisco
    //retornar o valor de nó que está sendo apontado
    int& operator*(){
        return m_pointer->value;
    }

    //caminhar para frente
    //sobrecarregar o x++ pre incremento


    //x=5

    //++x
    //retorna x=6

    //ele vai 
    //x++
    //ele retorna 5 e depois x=6


    //ele soma primeiro
    //e depois atribui
    //++x
    Iterator& operator++(){
        m_pointer = m_pointer->next;
        return *this;
    }    
    //e o ++x
    //ele atribui
    //e depois soma
    //x++
    Iterator operator++(int){
        Iterator temp(m_pointer); //interador apontando para onde mpoint aponta
        m_pointer = m_pointer->next;
        return temp;
    }

    //comparar dois iteradores

    bool operator==(const Iterator& it){
        return m_pointer == it.m_pointer;
    }

    bool operator!=(const Iterator& it){
        //return m_point != it.m_pointer;
        return !(*this==it);//ponteiro para objeto
    }

  //operador de atribuicao e destructor ja tem
};

#endif