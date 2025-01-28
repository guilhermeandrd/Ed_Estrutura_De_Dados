#ifndef NODE_H
#define NODE_H

template <typename K>

struct Node{
    K valor;
    Node* abaixo;

    Node(const K& value, Node* ptr){
        this->valor=value;
        this->abaixo=ptr;
    }

    ~Node(){
        delete abaixo;
    }

    //seria interessante um destrutor 

};

#endif