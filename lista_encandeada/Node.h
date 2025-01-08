#ifndef NODE_H//se node não foi definido
#define NODE_H//defina node

struct Node{
    int value;//variavel que guarda o valor
    Node *next;//ponteiro para o proximo elemento

    Node(int v, Node* nextptr){//construtor para node
        value = v;
        next = nextptr;
    }

    
};

#endif