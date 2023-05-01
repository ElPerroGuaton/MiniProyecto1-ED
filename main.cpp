#include "ListArr.h"
#include "Arbol.h"
#include "LinkedList.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ListArr* lista = new ListArr(6);

    lista->insert_right(100);
    lista->insert_right(90);
    lista->insert_right(80);
    lista->insert_right(70);
    lista->insert_right(60);
    lista->insert_right(50);
    lista->insert_right(40);
    lista->insert_right(30);
    lista->insert_right(20);
    lista->insert_right(10);
    lista->insert_right(0);
    lista->insert_right(-10);
    lista->insert_right(-20);
    lista->insert_right(-30);
    lista->insert_right(-40);

    lista->insert_left(-1000);
    lista->insert_left(-2000);
    lista->insert_left(-3000);
    lista->insert_left(-4000);
    lista->insert_left(-5000);
    lista->insert_left(-9000);
    lista->insert_left(-100000);

    lista->insert_right(1001);
    lista->insert_right(901);
    lista->insert_right(801);
    lista->insert_right(701);
    lista->insert_right(601);
    lista->insert_right(501);
 
    lista->insert_right(-101);
    lista->insert_right(-201);
    lista->insert_right(-301);
    lista->insert_right(-401);

    lista->insert_left(-1001);
    lista->insert_left(-2001);
    lista->insert_left(-3001);

    lista->insert_left(-8001);
    lista->insert_left(-9001);
    lista->insert_left(-100001);


    lista->insert(420,6);

    cout<<endl;
    lista->print();
    cout<<lista->find(80);
    
}
