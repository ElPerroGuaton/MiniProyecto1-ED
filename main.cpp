#include <iostream>
#include "ArrayStack.h"
#include "LinkedListStack.h"

using namespace std;

int main() {
    // Crear ArrayStack y agregar elementos
    ArrayStack stack1(10);
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    // Imprimir tamaño y tope de la pila
    cout << "ArrayStack:" << endl;
    cout << "Size: " << stack1.size() << endl;
    cout << "Top: " << stack1.top() << endl;

    // Sacar elementos de la pila
    stack1.pop();
    stack1.pop();

    // Imprimir tamaño y tope de la pila actualizada
    cout << "Size: " << stack1.size() << endl;
    cout << "Top: " << stack1.top() << endl;

    // Crear LinkedListStack y agregar elementos
    LinkedListStack stack2;
    stack2.push(100);
    stack2.push(200);
    stack2.push(300);

    // Imprimir tamaño y tope de la pila
    cout << "LinkedListStack:" << endl;
    cout << "Size: " << stack2.size() << endl;
    cout << "Top: " << stack2.top() << endl;

    // Sacar elementos de la pila
    stack2.pop();
    stack2.pop();
    stack2.pop();

    // Imprimir tamaño y tope de la pila actualizada
    cout << "Size: " << stack2.size() << endl;
    cout << "Top: " << stack2.top() << endl;

    return 0;
}
