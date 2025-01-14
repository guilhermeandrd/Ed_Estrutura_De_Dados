#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Iterator.h"
#include <iostream>

class List{
    private:
        Node* m_head;//ponteiro para o sentinela
        int m_size;//numero de elementos na lista

        Node* clear_recursivo(Node *node){
            if(node==nullptr){
                return nullptr;
            }else{
                node->next = clear_recursivo(node->next);
                delete node;
                m_size--;
                return nullptr;
            }
        }

    public:
        Iterator beforeBegin(){
            return Iterator(m_head);
        }
        Iterator begin(){
            return Iterator(m_head->next);
        }
        Iterator end(){
            return Iterator(nullptr);
        }


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
        
        void pop_front(){
            if(m_head->next != nullptr){
                //aponta para o primeiro elemento
                Node *aux1 = m_head->next;
                //faz o sentinela aponta para o segundo
                m_head->next = aux1->next;
                //delete o primero elemento
                delete aux1;
                //decrementa o m_size
                m_size--;
            }
        }

        //função que diz que a lista está vazia
        bool empty(){
            return m_head->next == nullptr;
        }

        //tentar fazer recursiva em casa
        void clear(){ //função que deixa a lista vazia com 0 elementos
            while(!empty()){
                pop_front();
            }
        }

        void clear_recursivo(){
            m_head->next = clear_recursivo(m_head->next);
        }

        int size(){
            return m_size;
        }

        //Destrutor: libera todos os nós, inclusive o sentinela
        ~List(){//tenho que pegar depois
            clear();
            delete m_head;
        }

        //sobrecarga do operador de atribuicao
        List& operator=(const List &lst){
            this->clear();
            Node* atual = lst.m_head->next;
            Node* ultimo = this->m_head;
            while(atual != nullptr){
                ultimo->next = new Node(atual->value, nullptr);
                ultimo = ultimo ->next;
                atual = atual->next;
            } 
            this -> m_size = lst.m_size;

            return *this;
        }

       void botaAtras(int v){
            //caminhar até o final
            //como que caminha até o final?
            
            Node* atual = m_head;

            while(atual->next!=nullptr){
                atual=atual->next;
            }
            
            Node* value = new Node (v,nullptr );

            value->next=nullptr;
            atual->next;

            atual->next=value;


            m_size++;
            //ligar o ultimo elemento ao ponteiro
        }
        void pop_back(){};

        void swap(){};

        void back(){};

        //essa função recebe um interador apontar para o nó e um valor
        //insere o novo valor após o nó apontado
        //ao final ela retorna um novo iterador apontando para o nó recém-inserido
        Iterator adicionarElementoDepois( const Iterator position, int val){

        }

        //recebe um iterador e remove um elemento após ele
        //ao final retorna um iterador para o elemento após o que foi deletado
        Iterator remove_after(Iterator position){

        }

        void acessarElemento(){};
};

#endif