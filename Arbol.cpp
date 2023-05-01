#include "Arbol.h"
#include <iostream>
#include <vector>

using namespace std;

Arbol::Arbol(LinkedList* hojas){

    this->leaves = hojas;

    int contador=leaves->getSize();
    vector<NodeTree*> padres;
    vector<Node*> hijos;


    NodeArray* actual= leaves->getHead();
    NodeArray* siguiente;

    for(int i=0;i<contador;i++){

        hijos.push_back(actual);
        siguiente = actual->getSiguiente();
        actual = siguiente;
    }

    while(contador!=2 && contador>2){

        int pos = 0;
        padres.clear();

        if(contador%2!=0){
            contador=(contador/2)+1;
        }

        else{
            contador=contador/2;
        }

        for(int i=0;i<contador;i++){
            
            padres.push_back(new NodeTree(0,nullptr,nullptr,nullptr));
        }

        for(int i=0;i<contador;i++){

            padres[i]->setHijoIzquierda(hijos[pos]);
            padres[i]->setSize(hijos[pos]->getSize());
            padres[i]->setTotal(hijos[pos]->getTotal());
            hijos[pos]->setParent(padres[i]);
            pos++;

            if(pos<hijos.size()){
                
                padres[i]->setHijoDerecha(hijos[pos]);
                padres[i]->setSize(padres[i]->getSize()+hijos[pos]->getSize());
                padres[i]->setTotal(padres[i]->getTotal()+hijos[pos]->getTotal());
                hijos[pos]->setParent(padres[i]);
                pos++;
            }
        }
        
        hijos.clear();

        for(int i=0;i<contador;i++){

            hijos.push_back(padres[i]);
        }

    }

    if(hijos.size()==2){

        this-> root = new NodeTree(0,hijos[0],hijos[1],nullptr);

        hijos[0]->setParent(root);
        hijos[1]->setParent(root);

        root->setSize(hijos[0]->getSize()+hijos[1]->getSize());
        root->setTotal(hijos[0]->getTotal()+hijos[1]->getTotal());
    }

    else{

        this-> root = new NodeTree(0,hijos[0],nullptr,nullptr);

        hijos[0]->setParent(root);

        root->setSize(hijos[0]->getSize());
        root->setTotal(hijos[0]->getTotal());
    }

    padres.clear();
    hijos.clear();

}

NodeTree* Arbol::getRoot(){

    return root;
}

void Arbol::sumaRecursivaPadres(Node* nodo){

    if(nodo->getParent()!=nullptr){

        nodo->setSize(nodo->getSize()+1);
        sumaRecursivaPadres(nodo->getParent());
    }

    else nodo->setSize(nodo->getSize()+1);
}

void Arbol::destructorRecursivo(Node* nodo){

    if(nodo!=nullptr){

        NodeTree* nodoBorrar = static_cast<NodeTree*>(nodo);
    
        destructorRecursivo(nodoBorrar->getHijoIzquierda());
        destructorRecursivo(nodoBorrar->getHijoDerecha());
        
        delete nodo;
    }
}

Arbol::~Arbol(){ 

    NodeArray* actual = leaves->getHead();
    NodeArray* siguiente;
    NodeTree* padre;

    for(int i=1;i<leaves->getSize()+1;i++){

        siguiente = actual->getSiguiente();

        if(i%2!=0){

            padre = static_cast<NodeTree*>(actual->getParent());

            padre->setHijoIzquierda(nullptr);
            padre->setHijoDerecha(nullptr);
            actual->setParent(nullptr);
        }

        actual = siguiente;
    }

    destructorRecursivo(root);
}


