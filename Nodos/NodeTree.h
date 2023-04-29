#ifndef NODETREE_H
#define NODETREE_H
#include "Node.h"

#pragma once

class NodeTree: public Node{

private:

    Node* hijoIzquierda;
    Node* hijoDerecha;

public:
    
    NodeTree(int b, Node* der, Node* izq,Node* padre);
    ~NodeTree();
    Node* getHijoIzquierda();
    Node* getHijoDerecha();
    void setHijoDerecha(Node* izq);
    void setHijoIzquierda(Node* der);

};

#endif