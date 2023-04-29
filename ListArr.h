#ifndef LISTARR_H
#define LISTARR_H
#pragma once

class ListArr{

private:
    int b; // Tamaño del arreglo
    
  

public:
    ListArr(int tam);
    ~ListArr();
    int size(); 
    void insert_left(int v); 
    void insert_right(int v); 
    void insert(int v, int i);
    void print();
    bool find(int v);
};

#endif