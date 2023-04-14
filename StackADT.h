#include<iostream>

#pragma once

class StackADT{
public:
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual int top() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};