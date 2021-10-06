#ifndef STACK_H
#define STACK_H

#include <iostream>

#define MEM_MULT 2

using namespace std;
 

template <class T>
class stack
{
    private:
        T *pri_;
        T *tope_;
        size_t tam_;
        size_t tamv_;

    public:
        stack();
        stack(const stack &);
        ~stack();
        void push(const T &);
        T pull();
        bool vacia();
        size_t getTam();
};

template <class T>
stack<T>::stack()
{
    pri_ = NULL;
    tope_ = NULL;
    tam_ = 0;
    tamv_ = 0;
}

template <class T>
stack<T>::stack(const stack<T> &orig)
{
    pri_ = NULL;
    tope_ = NULL;
    tam_ = 0;
    tamv_ = 0;
    if(orig.pri_)
    {
        pri_ = new T[orig.tamv_];
        tamv_ = orig.tamv_;
        for(int i = 0; i<orig.tam_; i++)
            pri_[i] = orig.pri_[i];
        tam_ = orig.tam_;
    }
}

template <class T>
stack<T>::~stack()
{
    if(pri_)
        delete [] pri_;
}

template <class T>
void stack<T>::push(const T &dato)
{
    if(!pri_)
    {
        tamv_ = MEM_MULT;
        pri_ = new T[tamv_];
        tope_ = pri_;
    }
    else if(tam_ == tamv_)
    {
        T *aux = new T[tamv_*MEM_MULT];
        for(size_t i = 0; i<tam_; i++)
            aux[i] = pri_[i];
        tamv_ = tamv_*MEM_MULT;
    }
    tope_++;
    *tope_ = dato;
    tam_++;
}

template <class T>
T stack<T>::pull()
{
    T aux;

    if(!pri_)
        return 0;
    aux = *tope_;
    tope_--;
    return aux;
}

template <class T>
bool stack<T>::vacia()
{
    return pri_? false:true;
}

template <class T>
size_t stack<T>::getTam()
{
    return tam_;
}





#endif