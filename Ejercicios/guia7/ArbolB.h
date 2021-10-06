#include <iostream>

using namespace std;

template <class T>
class ArbolB
{
    private:
        class nodo
        {
            private:
                nodo *der_;
                nodo *izq_;
                nodo *padre_;
                size_t clave_;
                T dato_;
                friend class ArbolB;

            public:
                nodo();
                nodo(const T &);
                ~nodo();
        };
        nodo *raiz_;
        size_t tam_;
        void _deleteNodos(nodo *&);
        void _copiarNodos(nodo *, nodo *&, nodo *&);
        void _printDatos(ostream &, nodo *&);

        friend class nodo;
        public:
            ArbolB();
            ArbolB(const ArbolB &);
            ~ArbolB();
            T Dato(const size_t &);        
            void alta(const T &, const size_t &);
            void baja(const size_t &);
            void printDatos(ostream &);
};

//CLASE NODO
//Constructores
template <class T>
ArbolB<T>::nodo::nodo()
{
    der_ = NULL;
    izq_ = NULL;
    padre_ = NULL;
}

template <class T>
ArbolB<T>::nodo::nodo(const T &dato)
{
    der_ = NULL;
    izq_ = NULL;
    padre_ = NULL;
    dato_ = dato;
}

//Destrcutor
template <class T>
ArbolB<T>::nodo::~nodo()
{

}

//CLASE ARBOLB
//Constructores
template <class T>
ArbolB<T>::ArbolB()
{
    raiz_ = NULL;
    tam_ = 0;
}


template <class T>
void ArbolB<T>::_copiarNodos(nodo *padre, nodo *&act, nodo *&copia)
{
    if(!copia)
    {
        act = NULL;
        return;
    }
    act = new nodo(copia->dato_);
    act->padre_ = padre;
    _copiarNodos(act, act->izq_, copia->izq_);
    _copiarNodos(act, act->der_, copia->der_);
    
}

template <class T>
ArbolB<T>::ArbolB(const ArbolB<T> &orig)
{
    _copiarNodos(raiz_, orig.raiz_);
}

//Destructor
template <class T>
void ArbolB<T>::_deleteNodos(nodo *&p)
{
    if(!p)
        return;
    _deleteNodos(p->izq_);
    _deleteNodos(p->der_);
    delete p;
}

//Destructor
template <class T>
ArbolB<T>::~ArbolB()
{
    _deleteNodos(raiz_);
}

//Otros
template <class T>
T ArbolB<T>::Dato(const size_t & clave)
{
    nodo *aux = raiz_;

    while(aux)
    {
        if(aux->clave_ == clave)
            return aux->dato_;
        else if(aux->clave_ > clave)
            aux = aux->der_;
        else if(aux->clave_ < clave)
            aux = aux->izq_;
    }
    return 0;
}

template <class T>
void ArbolB<T>::alta(const T &dato, const size_t &clave)
{
    nodo *next = raiz_;
    nodo *ant  = NULL;
    nodo *aux;
    nodo *nuevo = new nodo(dato);

    while(next)
    {
        aux = next;
        ant = aux->padre_;
        if(next->clave_ == clave)
        {
            next->dato_ = dato;
            return;
        }
        else if(next->clave_ > clave)
            next = next->der_;
        else if(aux->clave_ < clave)
            next = next->izq_;  
    }
    next = new nodo(dato);
    next->clave_ = clave;
    next->padre_ = ant;
    tam_++;
    return;
}

//Otros
template <class T>
void ArbolB<T>::baja(const size_t & clave)
{
    nodo *next = raiz_;
    nodo *ant, *aux;

    while(next)
    {
        if(next->clave_ == clave)
        {
            ant = next->padre_;
            if(next->der_ && next->izq_)
            {
                aux = next->izq_;
                while(aux->der_)
                    aux = aux->der_;
                next->dato_ = aux->dato_;
                next->clave_ = aux->clave_;
                next = aux;
                ant = next->padre;
                ant->der_ = next->izq_;
                ant->der_->padre_ = ant;
                delete next = NULL;
            }
            else if(next->der_)
            {
                if(ant->der_ == next)
                    ant->der_ = next->der_;
                else
                    ant->izq_ = next->der_;
                delete next;
                next = NULL;
            }
            else if(next->izq_)
            {
                if(ant->izq_ == next)
                    ant->izq_ = next->der_;
                else
                    ant->izq_ = next->der_;
                delete next;
                next = NULL;
            }
            else
            {
                delete next;
                next = NULL;
            }
            return;
        }
        else if(aux->clave_ > clave)
            aux = aux->der_;
        else if(aux->clave_ < clave)
            aux = aux->izq_;
    }
    return;
}

template <class T>
void ArbolB<T>::_printDatos(ostream &os, nodo *&orig)
{
    if(!orig)
        return;
    _printDatos(os, orig->der_);
    _printDatos(os, orig->izq_);
    cout<<"oki"<<endl;
    os<<orig->dato_<<'\t';
}

template <class T>
void ArbolB<T>::printDatos(ostream &os)
{
    _printDatos(os, raiz_);
}