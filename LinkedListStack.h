#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#include "StackADT.h"
#include <iostream>

#pragma once

class LinkedListStack: public StackADT{
private:

    struct Nodo{
        int valor;
        Nodo* siguiente;
        Nodo(int val, Nodo* nodo){
            this->valor = val;
            this->siguiente = nodo;
        }

    };

    Nodo* ultimo;
    int contador;

public:
    LinkedListStack();
    ~LinkedListStack();
    void push(int data);
    void pop();
    int top();
    bool isEmpty();
    int size();
};
#endif