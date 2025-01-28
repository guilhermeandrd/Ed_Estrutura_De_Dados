#ifndef NODE_H
#define NODE_H

struct Node {
    Node* next;
    Node* prev;
    double value;

    Node(Node* next, Node* prev, double value){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

#endif //NODE_H