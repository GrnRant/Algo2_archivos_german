#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Array.h"

using namespace std;

typedef Array<int> array_t;
typedef lista<array_t> list_t;

void getComb(array_t &v, size_t n, list_t &l);
void swap(int &a, int &b);

int main()
{
    size_t i;
    array_t v(3), aux;
    list_t lista;

    for(i = 1; i<v.getSize(); i++)
        v[i - 1] = i;
    v[i - 1] = i;
    getComb(v, v.getSize(), lista);
    cout<<lista;
    swap(v[1], v[2]);
    cout<<"Vector original: "<<v<<endl;
}

void getComb(array_t &v, size_t n, list_t &l)
{
    size_t i;

    if(n == 1)
    {
        l.altafin(v);
        return;
    }
    for(i = 0; i<n; i++)
    {
        getComb(v, n - 1, l);
        if(i != (n - 1))
            swap(v[n - 2], v[n - 1]);
    }
    return;
}

void swap(int &a, int &b)
{
    int aux;

    aux = a;
    a = b;
    b = aux;
}