#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "StackADT.h"
#include <iostream>

#pragma once

class ArrayStack: public StackADT{
private:
    int* stack;
    int capacidad;
    int ultimo;

public:
    ArrayStack(int capacity);
    ~ArrayStack();
    void push(int nuevo);
    void pop();
    int top();
    bool isEmpty();
    int size();
};
#endif