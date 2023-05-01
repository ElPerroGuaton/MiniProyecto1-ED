#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(int b, Node* padre){

    this->total = b;
    this->size = 0;
    this->parent = padre;      
}

Node::~Node(){

    delete this;
}

Node* Node::getParent(){

    return parent;
}

void Node::setParent(Node* padre){

    this->parent = padre;
}

int Node::getTotal(){

    return total;
}

void Node::setTotal(int b){

    total=b;
}

int Node::getSize(){

    return size;
}

void Node::setSize(int b){

    this->size=b;
}
