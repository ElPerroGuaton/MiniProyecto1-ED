#include <iostream>
#include "CircularArrayQueue.h"
#include "LinkedListQueue.h"

using namespace std;

int main() {
    // Crear ArrayQueue y agregar elementos
    CircularArrayQueue queue1(1);
    queue1.enqueue(10);
    queue1.enqueue(20);
    queue1.enqueue(30);

    // Imprimir tamaño y tope de la cola
    cout << "ArrayQueue:" << endl;
    cout << "Size: " << queue1.size() << endl;
    cout << "Front: " << queue1.front() << endl;

    // Sacar elementos de la cola
    queue1.dequeue();
    queue1.dequeue();

    // Imprimir tamaño y tope de la cola actualizada
    cout << "Size: " << queue1.size() << endl;
    cout << "Front: " << queue1.front() << endl;

    // Crear LinkedListQueue y agregar elementos
    LinkedListQueue queue2;
    queue2.enqueue(100);
    queue2.enqueue(200);
    queue2.enqueue(300);

    // Imprimir tamaño y tope de la cola
    cout << "LinkedListQueue:" << endl;
    cout << "Size: " << queue2.size() << endl;
    cout << "Front: " << queue2.front() << endl;

    // Sacar elementos de la cola
    queue2.dequeue();
    queue2.dequeue();

    // Imprimir tamaño y tope de la cola actualizada
    cout << "Size: " << queue2.size() << endl;
    cout << "Top: " << queue2.front() << endl;

    return 0;
}
