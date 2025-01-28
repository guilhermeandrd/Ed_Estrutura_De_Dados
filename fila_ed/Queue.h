#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include <iostream>
#include <stdexcept>
#include <initializer_list>


template <typename K>

class Queue{
private:
    Node<K>* m_head;
    Node<K>* m_tail;
    int m_size;

public:
    //construtor de uma fila vazia
    Queue(){
        m_head = m_tail = nullptr;
        m_size=0;
    }

    Queue(const std::initializer_list<K>& lista):Queue(){
        for(K elemento : lista){
            push_back(elemento);
        }
    }

    bool empty() const{
        return m_size == 0;
    }

    int size() const{
        return m_size;
    }

    K& front(){
        if(empty()){
            throw std::out_of_range("empty queue !! ");
        }

        return m_head->value;
    }

    //para valores constantes
    const K& front() const{
        if(empty()){
            throw std::out_of_range("empty queue!!");
        }

        return m_head->value;
    }

    K& back(){
        if(empty()){
            throw std::out_of_range("empty queue!!");
        }
        return m_tail->value;
    }

    const K& back () const{
        if(empty()){
            throw std::out_of_range("empty queue!!");
        }
        return m_tail->value;
    }

    void push(K& valor){
        if(empty()){
            m_head = m_tail = new Node<K>(valor, nullptr);
        }else{
            m_tail-> next = new Node<K> (valor, nullptr);
            m_tail=m_tail->next;
        }
        m_size++;
    }

    //REMOVE O PRIMEIRO DA FILA
    void pop(){
        if(empty()){
            m_tail = nullptr;
            return;
        }

        Node <K> *aux = m_head->next;

        m_head->next = nullptr;

        delete m_head;

        m_head = aux;

        m_size--;

        if(m_size==0){
            m_tail = nullptr;
        }
    }

    ~Queue(){
        delete m_head;
    }
};

#endif