#include "NodeArray.h"
#include <iostream>

using namespace std;

NodeArray::NodeArray(int b, NodeArray* next,Node* padre):Node(b,padre){

    this->array = new int[b];
    this->siguiente = next;
}

NodeArray::~NodeArray(){

    delete array;
    delete this;

}

int NodeArray::getElement(int pos){

    try{
        if(pos>Node::size-1 || pos<0)
            throw "No hay elemento en esa posición";

        else{

            return array[pos];
        }

    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

void NodeArray::addElement(int valor){

    if(Node::size<Node::total){

        array[Node::size]=valor;
        Node::size++;
    }

    else{
        
        array[Node::size-1]=valor;
    }

}

void NodeArray::addElementAt(int valor, int pos){

    try{
        if(pos>Node::total-1 || pos<0)
            throw "No existe la posición en el arreglo";

        else{

            if(pos>Node::size-1){

                array[pos]=valor;
                Node::size++;
            }

            else{
                array[pos]=valor;
            }

        }

    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }

}

NodeArray* NodeArray::getSiguiente(){

    return siguiente;
}

void NodeArray::setSiguiente(NodeArray* next){

    this->siguiente = next;
}
