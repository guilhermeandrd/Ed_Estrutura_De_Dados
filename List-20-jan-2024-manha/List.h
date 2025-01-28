#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <iostream>
/**
 * @brief Classe que implementa uma lista 
 * duplamente encadeada circular com nó sentinela
 */
class List {
private: 
    Node* m_head; // ponteiro para o nó sentinela
    int m_size;   // número de elementos na lista
public: 
    //construtor de copia
    List(const List &lst)
    :List()
    {
        Node *atual = lst.m_head->next;
    }


    //construtor que recebe uma lista de inicializador
    List(const std::initializer_list<int> &lst)
    : List() //pra inicializar a lista vazia
    { // usa o inicializador lista como auxilio
        //agora aqui
        auto it_ini = lst.begin();
        auto it_end = lst.end();
        while(it_ini!=it_end){
            push_back(*it_ini);
            it_ini++;
        }

    }
    List(){
        m_head = new Node(nullptr, nullptr, 0);
        m_head->next = m_head;
        m_head->prev = m_head;
        m_size = 0;
    }
    void push_front(double value){
        Node *aux = new Node(m_head->next, m_head, value);
        m_head->next = aux;
        aux->next->prev = aux;
        m_size++;
    }

    void pop_front() {
        if(m_size) {
            m_head->next->next->prev = m_head;
            Node *aux = m_head->next;
            m_head->next = m_head->next->next;
            delete aux;
            m_size--;
        }
    }

    void push_back(double value) {
        Node* aux = new Node(m_head, m_head->prev, value);
        m_head->prev->next = aux;
        m_head->prev = aux;
        m_size++;
    }

    int size(){
        return m_size;
    }
    

    friend std::ostream &operator <<(std::ostream &out, const List lst){
        Node *atual = lst.m_head->next;
        while(atual != lst.m_head){
            out << atual->value;
            atual = atual->next;
        }
        return out;
    }

    bool empty(){
        return m_size==0;
    }

    void clear(){
        while(!empty()){
            pop_front();
        }
    }

    ~List(){
        clear();
        delete m_head;
    }

    void pop_back(){
        if(!empty()){
            Node *aux = m_head->prev;
            m_head->prev = aux->prev;
            delete aux;
            m_size--;
        }
    }
};



#endif // end of LIST_H