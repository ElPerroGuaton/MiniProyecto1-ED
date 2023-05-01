#include "ListArr.h"
#include <iostream>

using namespace std;

ListArr::ListArr(int tam){

    this->b = tam;
    this->listaArreglos = new LinkedList(b);
    this->arbolBinario = new Arbol(listaArreglos);   
}

int ListArr::size(){

    return arbolBinario->getRoot()->getSize();
}

void ListArr::insert_left(int v){ 
    
    NodeArray* cabeza = listaArreglos->getHead();

    if(cabeza->getSize()==b){

        listaArreglos->insertNodeAt(2);
        cabeza->getSiguiente()->addElement(cabeza->getElement(b-1));
        
        arbolBinario = new Arbol(listaArreglos);  
    }

    else{

        arbolBinario->sumaRecursivaPadres(cabeza->getParent());
    }

    if(cabeza->getSize()==1){

        cabeza->addElement(cabeza->getElement(0));
    }

    else if(cabeza->getSize()>1 && cabeza->getSize()!=cabeza->getTotal()){

        for(int i=cabeza->getSize()-1;i>-1;i--){

            cabeza->addElementAt(cabeza->getElement(i),i+1);
        }
    }

    else if(cabeza->getSize()==cabeza->getTotal()){

        for(int i=cabeza->getSize()-2;i>-1;i--){

            cabeza->addElementAt(cabeza->getElement(i),i+1);
        }
    }

    cabeza->addElementAt(v,0);
} 

void ListArr::insert_right(int v){ 

    if(listaArreglos->getTail()->getSize()==b){

        listaArreglos->insertNode();

        arbolBinario = new Arbol(listaArreglos);  
    }
    
    listaArreglos->getTail()->addElement(v);
    arbolBinario->sumaRecursivaPadres(listaArreglos->getTail()->getParent());
}

void ListArr::insert(int v, int i){ //Revisar despues de arreglar arbol

    try{
        if(i<0 || i>arbolBinario->getRoot()->getSize())
            throw "No existe el indice en la ListArr";

        else{

            if(i==0){
                
                insert_left(v);
            }

            else if(i==arbolBinario->getRoot()->getSize()){
                
                insert_right(v);
            }

            else{
                
                int pos = i;
                Node* actual = arbolBinario->getRoot();
                NodeTree* cast;
                NodeArray* nodoIndice;

                while(actual->getTotal()!=b){

                    cast = static_cast<NodeTree*>(actual);

                    if(pos>cast->getHijoIzquierda()->getSize()){

                        actual = cast->getHijoDerecha();
                        pos = pos - cast->getHijoIzquierda()->getSize();
                    }

                    else{

                        actual = cast->getHijoIzquierda();
                    }
                    
                }

                nodoIndice = static_cast<NodeArray*>(actual);

                if(nodoIndice->getSize()==b){

                    listaArreglos->insertNodeAfter(nodoIndice);
                    nodoIndice->getSiguiente()->addElement(nodoIndice->getElement(b-1));

                    arbolBinario->~Arbol();
                    arbolBinario = new Arbol(listaArreglos);
                }

                else{
                    
                    arbolBinario->sumaRecursivaPadres(nodoIndice->getParent());
                }

                for(int i=nodoIndice->getSize()-2;i>pos-1;i--){

                    nodoIndice->addElementAt(nodoIndice->getElement(i),i+1);
                }

                nodoIndice->addElementAt(v,pos);
                
            }
        }

    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }

}

void ListArr::print(){

    NodeArray* actual = listaArreglos->getHead();
    NodeArray* siguiente;

    for(int i=1;i<listaArreglos->getSize()+1;i++){

        siguiente = actual->getSiguiente();

        for(int j=0;j<actual->getSize();j++){

            cout<<actual->getElement(j);
            cout<<" ";
        }

        actual = siguiente;
    }
}

bool ListArr::find(int v){

    NodeArray* actual = listaArreglos->getHead();
    NodeArray* siguiente;

    for(int i=1;i<listaArreglos->getSize()+1;i++){

        siguiente = actual->getSiguiente();

        for(int j=0;j<actual->getSize();j++){

            if(actual->getElement(j)==v){
                return true;
            }
        }

        actual = siguiente;
    }

    return false;
}

ListArr::~ListArr(){

    arbolBinario->~Arbol();
    listaArreglos->~LinkedList();

    delete this;
}