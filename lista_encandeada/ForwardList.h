#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.h"
#include "Iterator.h"
#include <iostream>

class ForwardList{
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
        
        Iterator beforeEnd(){
            Node* atual= m_head;

            while(atual->next!=nullptr){
                atual = atual->next;
            }

            return Iterator(atual);
        }

        Iterator end(){
            return Iterator(nullptr);
        }

        //construtor default: cria lista vazia
        ForwardList(){
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
        ~ForwardList(){//tenho que pegar depois
            clear();
            delete m_head;
        }

        //sobrecarga do operador de atribuicao
        ForwardList& operator=(const ForwardList &lst){
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

        void pushBack(int v){
            Node* atual = m_head;

            while(atual->next!=nullptr){
                atual=atual->next;
            }
            
            atual->next = new Node(v, nullptr);//nullptr

            m_size++;
        }

        void pop_back(){
            if(empty())
            return;
            
            Node* atual = m_head;

            while(atual->next && atual->next->next != nullptr){
                atual=atual->next;
            }
                
            Node* ultimo = atual->next;
            atual->next = nullptr;

            delete ultimo;

            m_size--;
        } 



        //essa função recebe um interador apontar para o nó e um valor
        //insere o novo valor após o nó apontado
        //ao final ela retorna um novo iterador apontando para o nó recém-inserido
        /*Iterator adicionarElementoDepois( const Iterator position, int val){
            //pecorre até o position
            Node* aux = m_head;
            //Iterator aux3;
            Iterator aux2;
            
            while(aux2!=position){
                Iterator aux2(aux->next);
            }

            //cria o novo node

            Node* colocado = new Node(val,aux->next);

            //conecta o position ao novo node
            

            //conecta novo node ao position->next

            //retorna o node criado

        }*/


        
        int& front(){
            return m_head->next->value;
        }

        const int& front() const{
            return m_head->next->value;
        }


        int& back(){
            Node *aux =  m_head;

            while(aux!=nullptr){
                aux=aux->next;
            }

            return aux->value;
        }

        const int& back() const{
            Node *aux =  m_head;

            while(aux!=nullptr){
                aux = aux->next;
            }

            return aux->value;
        }

        // Construtor de copia: recebe uma referencia para uma ForwardList
        // lst e inicializa a nova lista com os elementos de lst.
        ForwardList(const ForwardList& lst){
            m_head = new Node(0, nullptr);

            m_size=0;
            
            Node* ponteiro = lst.m_head->next;

            Node* auxiliar = m_head;

            while(ponteiro!=nullptr){
                auxiliar->next = new Node(ponteiro->value, nullptr);
                ponteiro = ponteiro->next;
                auxiliar = auxiliar->next;
            }

            m_size = lst.m_size;
        }

        void acessarElemento(){};
        //void swap(){};

        //recebe um iterador e remove um elemento após ele
        //ao final retorna um iterador para o elemento após o que foi deletado
        //Iterator remove_after(Iterator position){};

        // Sobrecarga do operador de igualdade: retorna true
        // se e somente se duas listas sao iguais
        bool operator==(const ForwardList& lst){
            //todo tem que ver se eles apontam para o mesmo elemento que tem o mesmo valor
            //entao fica tipo

            Node *aux = m_head;
            Node *aux2 = lst.m_head;

            if(m_size==lst.m_size){
                while(aux->next && aux2->next != nullptr){
                    if(aux->next->value != aux2->next->value){
                        return false;
                    }
                    aux = aux->next;
                    aux2 = aux2->next;
                }
            }else{
                return false;
            }

            return true;
        }

        // Sobrecarga do operador de diferenca: retorna true
        // se e somente se duas listas sao diferentes
        bool operator!=(const ForwardList& lst){
            return !(*this==lst);
        }

        // Troca o conteudo da lista pelo conteudo de lst, 
        // que eh outro objeto ForwardList do mesmo tipo. 
        // Os tamanhos das listas podem ser diferentes.
        // Apos a chamada para esta funcao membro, os elementos 
        // nesta lista sao aqueles que estavam em lst antes da chamada, 
        // e os elementos de lst sao aqueles que estavam nesta lista. 
        void swap(ForwardList& lst){
            //fazer o m_head do *this apontar para onde o m_head do lst aponta
            Node *passo = m_head;

            m_head = lst.m_head ;

            lst.m_head = passo;
        }

        // Remove todas as ocorrencias do valor 'val' da sua lista.
        // Por exemplo, se voce tiver a lista [4,1,2,4,4,3,4,4] e chamar 
        // essa funcao com o valor 4, a lista resultante sera [1,2,3].
        // Nao esqueca de liberar os nos.
        void remove(int value){
            Node *aux=m_head;

            //tenho que melhorar essa condição
            //o que acontece quando m_head aponta pra um elemento pra que contem esse valor?
            //
            while(aux!= nullptr && aux->next!=nullptr){
                if(aux->next->value==value){
                    Node *atual = aux->next;
                    aux = aux->next->next; //por que eu to deletando o que eu to apontando?
                    delete aux->next;
                    aux->next = nullptr; //quando aux for o nó que eu eliminei iai?
                    aux = aux->next; // isso aqui ta certo? ta nao
                }else{
                    aux = aux->next;
                }
            }
        }

        // Esta funcao concatena a lista atual com a lista lst passada por parametro. 
        // A lista lst fica vazia apos a chamada dessa funcao.
        // Exemplo: dadas as listas a = [1,2,3] e b = [7,8,9,10], apos chamar o comando
        // a.concat(b) as listas terao os seguintes conteudos: a = [1,2,3,7,8,9,10] e b = [].
        // Nao esqueca de ajustar o valor do m_size das duas listas.
        void concat(ForwardList& lst){
            //m_head
            Node *aux = m_head;

            while(aux->next!=nullptr){
                aux=aux->next;
            }

            //aux->next = new Node(lst.m_head->next->value,lst.m_head->next); //to alocando um novo node
            aux->next = lst.m_head->next;

            lst.m_head->next = nullptr;
            
            m_size+=lst.m_size;

            lst.m_size=0;
        }

        // Reverte a ordem dos elementos na lista.
        // Por exemplo, se voce tiver a lista [10,30,40,50], entao apos
        // chamar essa funcao a sua lista torna-se [50,40,30,10].
        // A complexidade dessa funcao deve ser O(n). Alem disso, faca essa 
        // funcao SEM ALOCAR NOVOS NODES. Eh possivel fazer essa funcao sem 
        // alocar novos nos. Voce precisara apenas de tres ponteiros adicionais 
        // para te ajudar a reverter a sua lista.
        void reverse(){ 
            if(m_size==1||empty()){
                return;
            }


            Node *atual= m_head->next;
            Node *anterior= nullptr;
            Node *proximo = nullptr;
            
            /*if(m_size==2){
                aux->next = aux->next->next;
                aux->next->next = aux2;
                aux2->next = nullptr;
                return;
            }*/

            //acho que tenho que usar o iterador
            //deu erro de memoria
            while(atual!=nullptr){
                proximo = atual->next;
                atual -> next = anterior;
                anterior = atual;
                atual = proximo;
            }   
            m_head = anterior;
            //a logica

            //guardar m_head

            //inverter os nós

            //fazer m_head apontar para o novo começo

            //fazer fim apontar para o null
        }
};

#endif