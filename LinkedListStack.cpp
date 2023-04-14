#include "LinkedListStack.h"
#include <iostream>

using namespace std;

LinkedListStack::LinkedListStack()
{
    ultimo = nullptr;
    contador = 0;
}

LinkedListStack::~LinkedListStack()
{
    Nodo* actual = ultimo;
    while (actual != nullptr){
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    ultimo = nullptr;
    contador = 0;   
}

void LinkedListStack::push(int nuevo) {
    
    Nodo* nuevoNodo = new Nodo(nuevo,ultimo);
    ultimo = nuevoNodo;
    contador++;
}

void LinkedListStack::pop() {
    
    try{
        if(isEmpty()==true)
            throw "El stack esta vacio";

        else{
            Nodo* siguiente = ultimo->siguiente;
            delete ultimo;
            ultimo = siguiente;
            contador--;
        }
    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

int LinkedListStack::top() {

    try{
        if(isEmpty()==true)
            throw "El stack esta vacio, no tiene top";

        else return ultimo->valor;
    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

bool LinkedListStack::isEmpty() {
    
    if(ultimo==nullptr) return true;
    else return false;
}

int LinkedListStack::size() {
    
    return contador;
}