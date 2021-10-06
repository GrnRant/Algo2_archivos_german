#include <iostream>
#include "ArbolB.h"

using namespace std;

typedef ArbolB<double> arbol_t;

int main()
{
    arbol_t t;

    t.alta(2.2, 0);
    t.printDatos(cout);
}