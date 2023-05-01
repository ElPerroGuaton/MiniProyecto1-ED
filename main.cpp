#include "ListArr.h"
#include "Arbol.h"
#include "LinkedList.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {

    ListArr* lista = new ListArr(3);

    lista->insert_right(10);
    lista->insert_right(9);
    lista->insert_right(8);
    lista->insert_right(7);
    lista->insert_right(6);
    lista->insert_right(5);
    lista->insert_right(4);
    lista->insert_right(3);
    lista->insert_right(2);
    lista->insert_right(1);
    lista->insert_right(0);
    lista->insert_right(-1);
    lista->insert_right(-2);
    lista->insert_right(-3);
    lista->insert_right(-4);

    lista->insert(80,8);

    lista->print();
    

}