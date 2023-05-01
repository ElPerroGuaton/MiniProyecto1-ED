#include "NodeTree.h"
#include <iostream>

using namespace std;


NodeTree::NodeTree(int b, Node* izq, Node* der,Node* padre):Node(b,padre){

    this->hijoIzquierda = izq;
    this->hijoDerecha = der;
}

NodeTree::~NodeTree(){

}

Node* NodeTree::getHijoIzquierda(){

    return hijoIzquierda;
}

Node* NodeTree::getHijoDerecha(){

    return hijoDerecha;
}

void NodeTree::setHijoIzquierda(Node* izq){

    this->hijoIzquierda = izq;
}

void NodeTree::setHijoDerecha(Node* der){

    this->hijoDerecha = der;
}




