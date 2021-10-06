#ifndef LISTA2_H
#define LISTA2_H

#include <iostream>
#include <cstdlib>


using namespace std;

template <class T>
class lista2
{
    private:
    class nodo
    {
        private:
        friend class lista2;
        nodo *sig_;
        nodo *ant_;
        T dato_;

        public:
        nodo();
        nodo(nodo &);
        ~nodo();
    };
    friend class nodo;
    nodo *pri_;
    size_t tam_;

    public:
    class iterador
    {
        private:
        nodo *act_;
        iterador(nodo *);
        friend class lista2;

        public:
        iterador();
        iterador(const iterador &);
        ~iterador();
        void incrementar();
        void decrementar();
        T getDato() const;
    };
    lista2();
    lista2(const lista2 &);
    ~lista2();
    void alta(const T &);
    void alta(const T &, iterador &);
    void baja();
    void baja(iterador &);
    bool vacia();
    size_t getTam();
    void iniciarIterador(iterador &);
    void printDatos(ostream &);
};

//NODO
//Constructoes
template <class T>
lista2<T>::nodo::nodo()
{
    sig_ = NULL;
    ant_ = NULL;
}

template <class T>
lista2<T>::nodo::nodo(nodo &orig)
{
    sig_ = orig.sig_;
    ant_ = orig.ant_;
    dato_ = orig.dato_;
}

//Destructor
template <class T>
lista2<T>::nodo::~nodo()
{

}

/*template <class TT>
ostream & operator<<(ostream &os, const nodo &n)
{
    return os;
}*/

//ITERADOR
//Constrcutores
template <class T>
lista2<T>::iterador::iterador(nodo *n)
{
    act_ = n;
}

template <class T>
lista2<T>::iterador::iterador()
{
    act_ = NULL;
}

//Destructor
template <class T>
lista2<T>::iterador::~iterador()
{

}

//Otros
template <class T>
T lista2<T>::iterador::getDato() const
{
    return act_? act_->dato_:0;
}

template <class T>
void lista2<T>::iterador::incrementar()
{
    act_ = act_->sig_;
}

template <class T>
void lista2<T>::iterador::decrementar()
{
    act_ = act_->ant_;
}

//LISTA2
//Constructores
template <class T>
lista2<T>::lista2()
{
    pri_ = NULL;
    tam_ = 0;
}

template <class T>
lista2<T>::lista2(const lista2<T> &orig)
{
    nodo *aux1, *aux2;

    pri_ = NULL;
    tam_ = 0;
    if(!orig.pri_)
        return;
    pri_ = new nodo();
    pri_->dato_ = orig.pri_->dato_;
    pri_->ant_ = pri_;
    pri_->sig_ = pri_;
    aux1 = orig.pri_->sig_;
    aux2 = pri_->sig_;
    while(aux1 != orig.pri_)
    {
        nodo *aux3 = new nodo();
        aux3->dato_ = aux1->dato_;
        aux3->sig_ = pri_;
        aux3->ant_ = aux2;
        aux2->sig_ = aux3;
        pri_->ant_ = aux3;
        tam_++;
        aux1 = aux1->sig_;
        aux2 = aux2->sig_;
    }
    aux2->sig_ = pri_;
    pri_->ant_ = aux2;
}

//Destructor
template <class T>
lista2<T>::~lista2()
{
    nodo *aux1, *aux2;

    for(aux1 = pri_->sig_; aux1 != pri_; aux1 = aux2)
    {
        aux2 = aux1->sig_;
        delete aux1;
    }
    delete pri_;
}


//Otros
template <class T>
void lista2<T>::alta(const T &dato)
{
    nodo *aux1, *aux2;

    aux1 = new nodo;
    aux1->dato_ = dato;
    if(pri_)
    {
        aux1->sig_ = pri_;
        aux1->ant_ = pri_->ant_;
        aux2 = aux1->ant_;
        pri_->ant_ = aux1;
        aux2->sig_ = aux1;
    }
    else
    {
        aux1->ant_ = aux1;
        aux1->sig_ = aux1;
    }
    pri_ = aux1;
    tam_++;
}

template <class T>
void lista2<T>::alta(const T &dato, iterador &it)
{
    nodo *aux1, *aux2;

    if(!it.act_)
        return;
    aux1 = new nodo;
    aux1->dato_ = dato;
    aux1->sig_ = it.act_;
    aux1->ant_ = it.act_->ant_;
    aux2 = aux1->ant_;
    it.act_->ant_ = aux1;
    aux2->sig_ = aux1;
    it.act_ = aux1;
    tam_++;
}

template <class T>
void lista2<T>::baja()
{
    nodo *aux;

    if(!pri_)
        return;
    aux = pri_->ant_;
    aux->sig_ = pri_->sig_;
    aux = pri_->sig_;
    aux->ant_ = pri_->ant_;
    delete pri_;
    pri_ = aux;
    tam_--;
}

template <class T>
void lista2<T>::baja(iterador &it)
{
    nodo *aux;

    if(!it.act_)
        return;
    aux = it.act_->ant_;
    aux->sig_ = it.act_->sig_;
    aux = it.act_->sig_;
    aux->ant_ = it.act_->ant_;
    delete it.act_;
    it.act_ = aux;
    tam_--;
}

template <class T>
bool lista2<T>::vacia()
{
    return pri_? false:true;
}

template <class T>
size_t lista2<T>::getTam()
{
    return tam_;
}

template <class T>
void lista2<T>::iniciarIterador(iterador &it)
{
    it.act_ = pri_;
}

template <class T>
void lista2<T>::printDatos(ostream &os)
{
    nodo *aux;

    if(!pri_)
        return;
    os<<pri_->dato_<<"\t";
    aux = pri_->sig_;
    while(aux != pri_)
    {
        os<<aux->dato_<<"\t";
        aux = aux->sig_;
    }
    os<<endl;
    return;
}




#endif