#ifndef CIRCULARARRAYQUEUE_H
#define CIRCULARARRAYQUEUE_H
#include "QueueADT.h"
#include <iostream>

#pragma once

class CircularArrayQueue: public QueueADT{

private:
    int* queue;
    int head;
    int tail;
    int contador;

public:
    CircularArrayQueue(int capacity);
    ~CircularArrayQueue();
    void enqueue(int data);
    void dequeue();
    int front();
    bool isEmpty();
    int size();
};

#endif