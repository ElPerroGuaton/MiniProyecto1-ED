#ifndef NODEARRAY_H
#define NODEARRAY_H
#include "Node.h"

#pragma once

class NodeArray: public Node
{

private:

    int* array;
    NodeArray* siguiente;

public:
    
    NodeArray(int b, NodeArray* next, Node* padre);
    ~NodeArray();

    int getElement(int pos);
    void addElement(int valor); //Inserta un valor en size()-1, no mueve el arreglo.
    void addElementAt(int valor, int pos); //Inserta un valor en la posición dada, no mueve el arreglo.
    NodeArray* getSiguiente();
    void setSiguiente(NodeArray* next);

};

#endif