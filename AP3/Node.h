#ifndef NODE_H
#define NODE_H
#include <iostream>

typedef int Item;

class Node {
public:
    Item valor; // valor a ser guardado
    Node* next; // ponteiro para o próximo node
    Node* prev; // ponteiro para o node anterior

    // contrutor vazio
    Node() {
    }
    // construtor 
    Node(const Item &v, Node* next, Node* prev) {
        valor = v;
        this->next = next;
        this->prev = prev;
    }
    // destrutor
    ~Node() {
        //std::cout << "removido nó com valor: " << valor << std::endl;
    }
};

#endif 