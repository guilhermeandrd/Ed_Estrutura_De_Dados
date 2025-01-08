#ifndef LIST_H
#define LIST_H
#include <Node.h>
#include <iostream>

class List{
    private:
        Node* m_head;//ponteiro para o sentinela
        int m_size;//numero de elementos na lista

    public:
        //construtor default: cria lista vazia
        List(){
            m_head = new Node(0, nullptr);
            m_size = 0;
        }
        
        void push_front(int val){
            Node *aux = new Node(val, m_head->next); //ele vai ser o ultimo elemento então ele vai apontar pra null ptr
            m_head->next= aux;
            m_size++;
            //m_head aponta pra onde ? - pro 3
        }

        void print(){
            Node *atual = m_head->next;
            while(atual!= nullptr){
                std::cout << atual->value << " ";
                atual = atual->next;
            }
            std::cout << std::endl;
        }
};

#endif LIST_H