#ifndef ARBOL_H
#define ARBOL_H
#include "NodeTree.h"
#include "LinkedList.h"

#pragma once

class Arbol
{

private:

    NodeTree* root;
    LinkedList* leaves;

public:

    Arbol(LinkedList* hojas);
    ~Arbol();
    void sumaRecursivaPadres(Node* nodo);
    NodeTree* getRoot();

};

#endif