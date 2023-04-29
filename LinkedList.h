#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "NodeArray.h"

#pragma once

class LinkedList
{

private:
    
    int b; //Tamaño que tendran los array de NodeArray;
    NodeArray* head;
    NodeArray* tail;
    int size;

public:
    
    LinkedList(int b);
    ~LinkedList();
    NodeArray* getHead();
    void insertNode(); //Inserta un nuevo NodeArray al final de la lista.
    void insertNodeAt(int pos); //Inserta un nuevo NodeArray en una posición.
    int getSize();

};

#endif