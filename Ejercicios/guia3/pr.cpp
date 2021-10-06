#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    queue<int> cola, copia;
    size_t tam;

    for(size_t i = 0; i<26;i++)
        cola.push(i);
    copia = cola;
    tam = copia.length();
    cout<<"Tamaño: "<<copia.length()<<endl;
    for(size_t i = 0; i<tam; i++)
        cout<<copia.pull()<<endl;
    if(copia.vacia() == true)
        cout<<"Oki"<<endl;
}