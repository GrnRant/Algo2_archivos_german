#include <iostream>
#include "List2.h"

using namespace std;

typedef lista2<int> listc_t;
typedef lista2<int>::iterador iterador_t;

int sumarDatos(listc_t &lista);

int main()
{
    listc_t l;
    iterador_t it;
    
    l.alta(1);
    l.alta(2);
    l.alta(3);
    l.iniciarIterador(it);
    l.alta(4, it);
    it.decrementar();
    l.alta(5,it);
    it.decrementar();
    l.baja(it);
      l.printDatos(cout);
    cout<<sumarDatos(l)<<endl;
   listc_t p(l);
   p.printDatos(cout);

}

int sumarDatos(listc_t &lista)
{
    int acum = 0;
    size_t i, j;
    iterador_t it;

    if(lista.vacia() == true)
        return acum;
    lista.iniciarIterador(it);
    for(i = 0, j = lista.getTam(); i<j; i++)
    {
        acum += it.getDato();
        it.incrementar();
    }
    return acum;
}