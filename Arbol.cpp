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
    for(int i=0;i<contador;i++){

        hijos.push_back(actual);
        actual = actual->getSiguiente();
    }


    while(contador!=2){

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

void DestruirPadres(Node* nodo){

    Node* padre;

    if(nodo->getParent()!=nullptr){

        padre = nodo->getParent();
        delete nodo;

        DestruirPadres(padre);
    }

    else delete nodo;
}

Arbol::~Arbol(){

    Node* actual=leaves->getHead();
    Node* padre;

    for(int i=0;i<leaves->getSize();i++){

        padre = actual->getParent();
        
        if(padre!=nullptr){
            DestruirPadres(padre);
        }
    }

    delete this;
}



