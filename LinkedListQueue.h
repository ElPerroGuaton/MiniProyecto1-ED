#ifndef LINKEDLISTQUEUE_H
#define LINKEDLISTQUEUE_H
#include "QueueADT.h"
#include <iostream>

#pragma once

class LinkedListQueue: public QueueADT{
private:

    struct Nodo{

        int valor;
        Nodo* siguiente;
        Nodo(int val, Nodo* nodo){
            
            this->valor = val;
            this->siguiente = nodo;
        }

    };

    Nodo* head;
    Nodo* tail;
    int contador;

public:
    LinkedListQueue();
    ~LinkedListQueue();
    void enqueue(int data);
    void dequeue();
    int front();
    bool isEmpty();
    int size();
};
#endif