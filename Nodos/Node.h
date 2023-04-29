#pragma once

class Node{

protected:

    int total;
    int size;
    Node* parent;

public:
    
    Node(int b, Node* padre);
    ~Node();
    Node* getParent();
    void setParent(Node* padre);
    int getTotal();
    void setTotal(int b);
    int getSize();
    void setSize(int b);

};