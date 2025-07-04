#ifndef NODE_H
#define NODE_H

template <typename T>

struct Node{
    T value;
    Node *next;

    Node(const T& val, Node*next){
        this->value = val;

        this->next = next;
    }

    ~Node(){
        delete next;
    }


};
#endif