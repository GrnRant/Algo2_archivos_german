#ifndef _LIST_H_
#define _LIST_H_

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class List {
public:
    List();
    List(const List &);
    List &operator=(const List &);
    ~List();

    T remove_front();
    T remove_back();
    void push_front(const T &);
    void push_back(const T &);
    bool present(const T &) const;

    bool empty() const;
    size_t length() const;
private:
    class nodo
    {
        private:
            nodo *sig_;
            nodo *ant_;
            T dato_;
            friend class List;

        public:
            nodo();
            nodo(const T &);
            ~nodo();
    };
    friend class nodo;

    nodo *pri_;
    nodo *ult_;
    size_t tam_;
};

template<typename T>
List<T>::nodo::nodo()
{

}

template<typename T>
List<T>::nodo::nodo(const T &dato)
{
    dato_ = dato;
}

template<typename T>
List<T>::nodo::~nodo()
{

}


template<typename T>
List<T>::List()
{
    pri_ = NULL;
    ult_ = NULL;
    tam_ = 0;
}

template<typename T>
List<T>::List(const List &rhs)
{
    pri_ = NULL;
    ult_ = NULL;
    tam_ = 0;

    if(rhs.pri_)
    {
        nodo *ant, *sig, *aux;

        pri_ = new nodo(rhs.pri_->dato_);
        pri_->ant_ = NULL;

        for(ant = pri_, aux = rhs.pri_->sig_; aux; aux = aux->sig_, ant = sig)
        {
            ant->sig_ = new nodo(aux->dato_);
            sig = ant->sig_;
            sig->ant_ = ant;
            sig->sig_ = NULL;
        }
        ult_ = ant;
        ult_->sig_ = NULL;
        tam_ = rhs.tam_;
    }
}

template<typename T>
List<T> &List<T>::operator=(const List<T> &rhs)
{
    nodo *sig, *ant, *aux;
    if(this != &rhs)
    {
        if(empty() == false)
        {
            for(ant = pri_, sig = pri_->sig_; sig; sig = sig->sig_, ant = ant->sig_)
                delete ant;
            delete ant;
            pri_ = NULL;
            ult_ = NULL;
            tam_ = 0;
        }
        if(rhs.empty() == false)
        {
            pri_ = new nodo(rhs.pri_->dato_);
            pri_->ant_ = NULL;

            for(ant = pri_, aux = rhs.pri_->sig_; aux; aux = aux->sig_, ant = sig)
            {
                ant->sig_ = new nodo(aux->dato_);
                sig = ant->sig_;
                sig->ant_ = ant;
                sig->sig_ = NULL;
            }
            ult_ = ant;
            ult_->sig_ = NULL;
            tam_ = rhs.tam_;
        }
    }
    return *this;
}

template<typename T>
List<T>::~List()
{
    if(empty() == false)
    {
        nodo *ant, *sig;

        for(ant = pri_, sig = pri_->sig_; sig; sig = sig->sig_)
        {
            delete ant;
            ant = sig;
        }
        delete ant;
    }
}

template<typename T>
T List<T>::remove_front()
{
    T dato(0);
    if(empty() == false)
    {
        nodo *aux = pri_;

        dato = pri_->dato_;
        pri_ = pri_->sig_;
        delete aux;
        if(pri_)
            pri_->ant_ = NULL;
        else
            ult_ = NULL;
        tam_--;
    }
    return dato;
}

template<typename T>
T List<T>::remove_back()
{
   T dato(0);
    if(empty() == false)
    {
        nodo *aux = ult_;

        dato = ult_->dato_;
        ult_ = ult_->ant_;
        delete aux;
        if(ult_)
            ult_->sig_ = NULL;
        else
            pri_ = NULL;
        tam_--;
    }
    return dato;
}

template<typename T>
void List<T>::push_front(const T &item)
{
    if(empty() == true)
    {
        pri_ = new nodo(item);
        pri_->ant_ = NULL;
        pri_->sig_ = NULL;
        ult_ = pri_;
    }
    else
    {
        nodo *aux = new nodo(item);
        aux->ant_ = NULL;
        aux->sig_ = pri_;
        pri_->ant_ = aux;
        pri_ = aux;
    }
    tam_++;
}

template<typename T>
void List<T>::push_back(const T &item)
{
    
    if(empty() == true)
    {
        pri_ = new nodo(item);
        pri_->ant_ = NULL;
        pri_->sig_ = NULL;
        ult_ = pri_;
    }
    else
    {
        nodo *aux = new nodo(item);
        aux->sig_ = NULL;
        aux->ant_ = ult_;
        ult_->sig_ = aux;
        ult_ = aux;
    }
    tam_++;
}

template<typename T>
bool List<T>::present(const T &item) const
{
    nodo *aux;

    if(empty() == false)
    {
        for(aux = pri_; aux; aux = aux->sig_)
        {
            if(aux->dato_ == item)
                return true;
        }
    }
    return false;
}

template<typename T>
bool List<T>::empty() const
{
    return pri_? false:true;
}

template<typename T>
size_t List<T>::length() const
{
    return tam_;
}
#endif
