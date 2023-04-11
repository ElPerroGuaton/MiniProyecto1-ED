#include "LinkedListQueue.h"
#include <iostream>

using namespace std;

LinkedListQueue::LinkedListQueue(){

    head = nullptr;
    tail = nullptr;
    contador = 0;
}

LinkedListQueue::~LinkedListQueue(){

    Nodo* actual = head;
    while (actual != nullptr){

        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    
    delete head;
    delete tail;  
}

void LinkedListQueue::enqueue(int nuevo) {
    
    Nodo* nuevoNodo = new Nodo(nuevo,nullptr);

    if(contador==0){

        head = nuevoNodo;
        tail = nuevoNodo;
    }

    else{
        
        tail->siguiente= nuevoNodo;
        tail = nuevoNodo;
    }

    contador++;
}

void LinkedListQueue::dequeue() {
    
    try{
        if(isEmpty()==true)
            throw "El stack esta vacio";

        else{

            Nodo* next = head->siguiente;
            delete head;
            head = next;

            contador--;
        }

    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

int LinkedListQueue::front() {

    try{
        if(isEmpty()==true)
            throw "El stack esta vacio, no tiene front";

        else return head->valor;
    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

bool LinkedListQueue::isEmpty() {
    
    if(contador==0) return true;
    else return false;
}

int LinkedListQueue::size() {
    
    return contador;
}