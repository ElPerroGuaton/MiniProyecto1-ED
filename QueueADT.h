#pragma once

class QueueADT{

public:
    virtual void enqueue(int val)=0;
    virtual void dequeue()=0;
    virtual int front() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};