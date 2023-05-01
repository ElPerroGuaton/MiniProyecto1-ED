#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList(int tam){

    this->b = tam;
    NodeArray* nuevo = new NodeArray(b,nullptr,nullptr);
    this->tail = nuevo;
    this->head = nuevo;
    this->size = 1;
}

LinkedList::~LinkedList(){

    NodeArray* actual = head;
    while (actual != nullptr){

        NodeArray* siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
    
    delete head;
    delete tail; 
}

NodeArray* LinkedList::getHead(){

    return head;
}

NodeArray* LinkedList::getTail(){

    return tail;
}

void LinkedList::insertNode(){

    NodeArray* swap = tail;
    NodeArray* final = new NodeArray(b,nullptr,nullptr);

    swap->setSiguiente(final);
    tail = final;

    size++; 
}

void LinkedList::insertNodeAt(int pos){

    try{
        if(pos>size+1 || pos <1)
            throw "No existe esa posición en la lista";

        else{

            if(pos==size+1){
                insertNode();
            }
            
            else if(pos==1){

                NodeArray* primero = head;
                NodeArray* nuevo = new NodeArray(b,primero,nullptr);

                head = nuevo;
                size++;
            }

            else{

                NodeArray* anterior = head;
                NodeArray* posicion = head;
              
                for(int i=1;i<pos;i++){

                    anterior = posicion;
                    posicion = posicion->getSiguiente();
                }

                NodeArray* nuevo = new NodeArray(b,posicion,nullptr);
                anterior->setSiguiente(nuevo);
                size++;
            }

        }

    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

void LinkedList::insertNodeAfter(NodeArray* nodo){

    if(nodo->getSiguiente()==nullptr){
        insertNode();
    }

    else{
        NodeArray* primero = nodo;
        NodeArray* segundo = primero->getSiguiente();
        NodeArray* nuevo = new NodeArray(b,segundo,nullptr);

        primero->setSiguiente(nuevo);
    }

    size++;
}

int LinkedList::getSize(){

    return size;
}