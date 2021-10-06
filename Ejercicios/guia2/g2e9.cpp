#include <iostream>
#include "Array.h"
#include "List.h"

using namespace std;

typedef Array<int> array_t;
typedef lista<array_t> list_t;

void getSubj(array_t &v, const int& l, list_t &p);
void addSubj(array_t &v, const int &l, list_t &p);

int main()
{
    size_t i, j;
    array_t v(3), aux;
    list_t lista;

    for(i = 1; i<v.getSize(); i++)
        v[i - 1] = i;
    v[i - 1] = i;
    getSubj(v, v.getSize(), lista);
    j = lista.getTam();
    cout<<lista;
}

void getSubj(array_t &v, const int& l, list_t &p)
{
    if(l == 0)
        return;
    getSubj(v, l - 1, p);
    addSubj(v, l, p);
    return;
}

void addSubj(array_t &v, const int &l, list_t &p)
{
    size_t i, j;
    array_t aux1(1), aux3;

    if(l == 0)
        return;
    j = p.getTam();
    aux1[0] = v[l - 1];
    p.altafin(aux1);
    for(i = 0; i < j; i++)
    {
        array_t aux2(p.getDato(i));
        aux3 = aux1 + aux2;
        p.altafin(aux3);
    }
    return;
}