#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iomanip>
#include <iostream>

template <typename K>

class Stack{
private:
    Node <K> * m_top; //ponteiro para o topo da pilha
    int m_size; //tamanho da pilha

public:
    //construtor defaultr
    Stack(){
        m_top = nullptr;
        m_size = 0;
    };

    Stack(const Stack& stack): Stack(){ //!eu vou apanhar pra  vitoria entender isso aqui
        Node <K> *atual = stack.m_top;
        Node <K> *ultimo = this->m_top;

        while(atual != nullptr){
            if(m_top==nullptr){
                m_top = new Node<K>(nullptr,atual->valor);
                ultimo = m_top;
            }else{
                ultimo->abaixo = new Node<K>(nullptr, atual->valor);
                ultimo = ultimo->abaixo;
            }
        }

        this->m_size= m_size;

    }

    bool empty() const{
        return this->m_size==0;
    }

    int size () const{
        return this->m_size;
    }

    K& top(){
        if(empty()){
            throw std::underflow_error("pilha vazia");
        }
        return m_top->value;
    }

    const K& top() const{
         if(empty()){
            throw std::underflow_error("pilha vazia");
        }
        return m_top->value;
    }

    void push(const K& value){
        m_top = new  Node<K>(m_top, value);
        m_size++;
    }

    void pop(){
        if(!empty()){
            Node <K> *aux = nullptr;
            m_top = m_top->next;
            aux->next = nullptr;
            delete aux;
            m_size--;
        }

        //throw std::underflow_error("pilha vazia");
    }

    void clear(){
        delete m_top;
        m_top = nullptr;
        m_size = 0;
    }

    ~Stack(){
        delete m_top;
    }

    //sobrecarga do operador de atribuicao

    Stack& operator=(const Stack& stack){
        clear();

        Node <K> *atual = m_top;
        Node <K> *ultimo = m_top->abaixo;

        while(atual != nullptr){
            if(m_top==nullptr){
                m_top = new Node<K>(nullptr,atual->valor);
                ultimo = m_top;
            }else{
                ultimo->abaixo = new Node<K>(nullptr, atual->valor);
                ultimo = ultimo->abaixo;
            }
        }

        this->m_size= m_size;


        return *this;
    }

};

#endif