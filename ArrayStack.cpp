#include "ArrayStack.h"
#include <iostream>

using namespace std;

ArrayStack::ArrayStack(int capacity){

    this->capacidad = capacity;
    this->ultimo = -1;
    this->stack = new int[capacity];
}

ArrayStack::~ArrayStack(){

    delete[] stack;
    delete stack;
}

void ArrayStack::push(int nuevo){

    if(size()==sizeof(stack)){

        int* newArray = new int[size()*2];

        for(int i=0;i<size();i++){
            newArray[i]=stack[i];
        }

        delete[] stack;

        stack = newArray;
    }

    ultimo++;
    stack[ultimo]=nuevo;
}

void ArrayStack::pop(){
    
    try{
        if(isEmpty()==true)
            throw "El stack esta vacio";

        else ultimo--;
    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

int ArrayStack::top(){

    try{
        if(isEmpty()==true)
            throw "El stack esta vacio, no tiene top";

        else return stack[ultimo];
    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }
}

bool ArrayStack::isEmpty(){

    if(ultimo>-1) return false;
    else return true;
}

int ArrayStack::size(){

    return ultimo+1;
}

   
    
    



