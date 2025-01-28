#ifndef NODE.H
#define NODE.H

struct Node{
    Node *next;
    Node *previous;
    int value;

    Node(Node *proximo, Node *previous, int value){
       this->next = proximo;
        this->previous = previous;
        this->value = value;
    }

};

#endif