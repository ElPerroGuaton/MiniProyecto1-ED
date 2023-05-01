#ifndef LISTARR_H
#define LISTARR_H
#include "Arbol.h"
#include "LinkedList.h"

#pragma once

class ListArr{

public:

    int b; // Tamaño del arreglo
    LinkedList* listaArreglos;
    Arbol* arbolBinario;
    
public:

    ListArr(int tam);
    ~ListArr();

    int size(); //Retorna la cantidad de elementos almacenados en el ListArr, se obtiene del root del arbol
    void insert_left(int valor); //Inserta el valor v en el índice 0
    void insert_right(int valor); //Inserta el valor v en el índice size()-1
    void insert(int valor, int i); //Inserta un nuevo valor v en el índice i del ListArr.
    void print(); //Imprime por pantalla todos los valores almacenados en el ListArr.
    bool find(int valor); //Busca en el ListArr si el valor v se encuentra almacenado

};

#endif