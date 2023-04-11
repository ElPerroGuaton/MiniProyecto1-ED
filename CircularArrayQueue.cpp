#include "CircularArrayQueue.h"
#include <iostream>

using namespace std;

CircularArrayQueue::CircularArrayQueue(int capacity){

    this->queue = new int[capacity];
    this->head=0;
    this->tail=1;
    this->contador=0;
}

CircularArrayQueue::~CircularArrayQueue(){

    delete[] queue;
    delete queue;
}

void CircularArrayQueue::enqueue(int data){

    if(contador!=sizeof(queue)){
        
        if(isEmpty()==true){
            queue[0]=data;
            head=0;
            tail=1;
        }

        else{
            
            queue[tail]=data;
            tail = (tail+1) % (sizeof(queue)-1);
        }
    }

    else{
        
        int* newQueue = new int[sizeof(queue)*2];
        
        for(int i=0;i<sizeof(queue);i++){
            newQueue[i]=queue[i];
        }
        
        delete[] queue;
        queue = newQueue;

        queue[tail]=data;
        tail = (tail+1) % (sizeof(queue)-1);
    }

    contador++;

}
void CircularArrayQueue::dequeue(){

    try{
        if(isEmpty()==true)
            throw "El stack esta vacio";

        else{
            head++;
            contador--;
        } 

    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }

}

int CircularArrayQueue::front(){
    
    try{
        if(isEmpty()==true)
            throw "El stack esta vacio, no tiene front";

        else return queue[head];
        
    }catch(const char* message){
        cout<<endl;
        cerr<<message<<endl;
        exit(EXIT_FAILURE);
    }

}

bool CircularArrayQueue::isEmpty(){
    
    if(contador==0) return true;
    else return false;
}

int CircularArrayQueue::size(){

    return contador;
}