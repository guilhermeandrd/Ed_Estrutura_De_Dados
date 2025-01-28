#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include <algorithm>
#include "Iterator.h"
#include "ConstIterator.h"
#include "Node.h"

class ForwardList {
private:
    Node* m_head; // ponteiro para o sentinela
    int m_size;   // numero de elementos na lista

public:
    // retorna um Iterator apontando 
    // para o primeiro elemento da lista
    Iterator begin() {
        return Iterator(m_head->next);
    }

    // retorna um Iterator apontando para a posicao 
    // anterior ao primeiro elemento da lista.
    Iterator before_begin() {
        return Iterator(m_head);
    }

    // retorna um Iterator para a posicao 
    // após o ultimo elemento

    Iterator before_end(){
        Node *aux = m_head;

        while(aux->next!=nullptr){
            aux = aux->next;
        }
        //aux ->next =nullptr;

        return Iterator(aux);
    }
    Iterator end() {
        return Iterator(nullptr);
    }

    // retorna um ConstIterator apontando 
    // para o primeiro elemento da lista
    ConstIterator begin() const {
        return ConstIterator(m_head->next);
    }

    // retorna um ConstIterator apontando para a posicao 
    // anterior ao primeiro elemento da lista.
    ConstIterator before_begin() const {
        return ConstIterator(m_head);
    }

    // retorna um ConstIterator para a posicao 
    // apos o ultimo elemento
    ConstIterator end() const {
        return ConstIterator(nullptr);
    }


    // Construtor default: cria lista vazia
    ForwardList() {
        m_head = new Node(0, nullptr);
        m_size = 0;
    }

    // Construtor de copia
    ForwardList(const ForwardList& lst) {
        m_head = new Node(0,nullptr);
        Node *ultimo = m_head;
        Node *aux = lst.m_head->next;
        while(aux != nullptr) {
            ultimo->next = new Node(aux->value,nullptr);
            ultimo = ultimo->next;
            aux = aux->next;
        }
        m_size = lst.m_size;
    }

    // Insere um elemento no inicio da lista
    void push_front(int val) {
        Node *aux = new Node(val, m_head->next);
        m_head->next = aux;
        m_size++;
    }

    // Funcao que remove o primeiro elemento da lista
    void pop_front() {
        if(m_head->next != nullptr) {
            // aponta para o primeiro elemento
            Node* aux1 = m_head->next; 
            // faz o sentinela apontar para o segundo
            m_head->next = aux1->next;
            // delete o primeiro elemento
            delete aux1;
            // decrementa m_size
            m_size--;
        }
    }

    // Funcao que retorna o tamanho da lista
    int size() const {
        return m_size;
    }

    // Funcao que diz se a lista esta vazia
    bool empty() const {
        return m_head->next == nullptr;
    }

    // Funcao que deixa a lista vazia, com 0 elementos
    void clear() {
        while(!empty()) {
            pop_front();
        }
    }    

    // Destrutor: libera todos os nos, inclusive o sentinela
    ~ForwardList() {
        clear();
        delete m_head;
    }

    // Sobercarga do operador de atribuicao
    // Faz uma copia da lista passada como entrada
    ForwardList& operator=(const ForwardList& lst) {
        this->clear(); // limpa a minha lista
        Node* atual = lst.m_head->next;
        Node* ultimo = this->m_head;
        while(atual != nullptr) {
            ultimo->next = new Node(atual->value, nullptr);
            ultimo = ultimo->next;
            atual= atual->next;
        }
        this->m_size = lst.m_size;
        return *this;
    }

    // Sobrecarga do operador<< 
    // Esse operador permite imprimir o conteudo da lista no terminal cout
    friend std::ostream& operator<<(std::ostream& out, const ForwardList& lst) {
        out << "[ ";
        for(auto it = lst.begin(); it != lst.end(); ++it) {
            out << *it << " ";
        }
        out << "]";
        return out;
    }


    // Essa funcao recebe como parametros um Iterator chamado 'position' 
    // apontando para um node, e recebe tambem um valor inteiro 'val'.
    // Essa funcao insere esse novo valor logo apos o node apontado por 'position'.
    // Ao final, ela retorna um novo iterador apontado para o node recem-inserido.
    // Se nenhum elemento for inserido, ela retorna o proprio iterador position.
    // Por exemplo, dada a lista [1,2,3,4,5,6] se voce chamar a funcao insert_after
    // com um iterador apontando para o elemento 3 e com o valor 999, essa funcao vai
    // inserir o 999 logo apos o elemento 3, resultando na lista: [1,2,3,999,4,5,6].
    // O retorno, neste exemplo, sera um novo iterador apontando para o node 999.
    Iterator insert_after(const Iterator position, int val){
        Node *aux = m_head;

        while(aux->next->value!=*position){
            aux = aux->next;
        }

        //caso geral

        //caso que for o ultimo elemento


        //ele para antes de onde eu tenho que inserir

        Node *aux2 = aux->next->next; //guardo o valor que to substituindo

        aux->next->next = new Node(val, aux2);

        return Iterator(aux->next->next);
    }

    // Remove o elemento apos o iterador position.
    // Retorna um iterador apontando para o elemento logo apos o
    // elemento que foi removido. Se a funcao apagou o ultimo elemento,
    // o valor retornado eh o iterador end(). Se nenhum elemento for
    // apagado, retorna position.
    Iterator erase_after(Iterator position){
        Node *aux = m_head; //ponteiro para o m_head

        while(aux->value!=*position){ //
            aux = aux->next;
        }
        
        if(aux->value==*position){
            //std::cout << "é isso";
        }

        Node* aux2 = aux->next;

        if(aux->next==nullptr){ 
            //std::cout<< "caiu nesse caso";
            return position;
        }else if(aux->next->next==nullptr){
            aux -> next = aux -> next ->next;
            delete aux2;
            //std::cout << "O problema é aqui";
            m_size--;
            return end();
        }else{
            aux->next = aux->next->next;
            delete aux2;
            m_size--;
            return aux->next->next;
        }
    }


};  





#endif // Fim da classe