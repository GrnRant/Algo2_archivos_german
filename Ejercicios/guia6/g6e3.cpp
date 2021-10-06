#include <iostream>
#include "Array.h"

using namespace std;

typedef struct{
                double x;
                double y;
                } par_t;

typedef Array<par_t> pares_t;

int main()
{
    pares_t c;
}

size_t contarRepetidos(pares_t a, pares_t b)
{
    if(!a.getSize() || !b.getSize())
        return 0;
    if(a.getSize() < b.getSize())
        return _contarRepetidos(a, b, 0, b.getSize() - 1);
    return _contarRepetidos(b, a, 0, a.getSize() - 1);
}

size_t _contarRepetidos(pares_t c1, pares_t c2, size_t inic2, size_t fin2)
{
    size_t l = c1.getSize();
    size_t acum = 0;

    if(fin2 == inic2)
        return 0;
    acum = _contarRepetidos(c1, c2, inic2, fin2/2) + _contarRepetidos(c1, c2, fin2/2 + 1, fin2);
    for(size_t i = 0; i < l; i++)
        if(c2[inic2].x == c1[i].x && c2[inic2].y == c1[i].y)
            acum++;
    return acum;
}