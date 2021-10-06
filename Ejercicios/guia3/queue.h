#include <cstdlib>
#include <iostream>

#define ALLOC_SIZE 10

using namespace std;

template <class T>
class queue
{
    private:
        size_t tamv_;
        size_t tam_;
        T *pri_;
        T *ult_;
    
    public:
        queue();
        queue(const queue&);
        ~queue();
        void push(const T&);
        T pull();
        size_t length();
        bool vacia();
        const queue & operator=(const queue &);
};

template <class T>
queue<T>::queue()
{
    pri_ = NULL;
    ult_ = NULL;
    tam_ = 0;
    tamv_ = 0;
}

template <class T>
queue<T>::queue(const queue<T> &orig)
{
    pri_ = NULL;
    ult_ = NULL;
    tam_ = 0;
    tamv_ = 0;

    if(orig.pri_)
    {
        size_t i;

        pri_ = new T[tamv_ = orig.tamv_];
        for(i = 0; i<orig.tam_; i++)
            pri_[i] = orig.pri_[i];
        tam_ = orig.tam_;
        ult_ = &pri_[tam_ - 1];
    }
}

template <class T>
queue<T>::~queue()
{
    if(pri_)
        delete [] pri_;
    pri_ = NULL;
    ult_ = NULL;
}

template <class T>
void queue<T>::push(const T &nuevo)
{
    size_t i;

    if(tamv_ == tam_)
    {
        T *aux;
        
        aux = new T[tamv_ += ALLOC_SIZE];
        for(i = 0; i<tam_; i++)
            aux[i] = pri_[i];
        if(pri_)
            delete [] pri_;
        pri_ = aux;
    }
    for(i = tam_; i>0; i--)
        pri_[i] = pri_[i - 1];
    pri_[0] = nuevo;
    tam_++;
    ult_ = &pri_[tam_ - 1];
}

template <class T>
T queue<T>::pull()
{
    T dato(0);

    if(pri_)
    {
        dato = *ult_;
        tam_--;
        if(!tam_)
        {
            delete [] pri_;
            pri_ = NULL;
            ult_ = NULL;
            tamv_ = 0;
        }
        else
            ult_--;
    }
    return dato;
}

template <class T>
size_t queue<T>::length()
{
    return tam_;
}

template <class T>
bool queue<T>::vacia()
{
    return pri_? false:true;
}

template <class T>
const queue<T> & queue<T>::operator=(const queue<T> &orig)
{
    if(this != &orig)
    {
        if(pri_)
        {
            delete []pri_;
            pri_ = NULL;
            ult_ = NULL;
            tam_ = 0;
            tamv_ = 0;
        }
        if(orig.pri_)
        {
            size_t i;

            pri_ = new T[tamv_ = orig.tamv_];
            for(i = 0; i<orig.tam_; i++)
                pri_[i] = orig.pri_[i];
            tam_ = orig.tam_;
            ult_ = &pri_[tam_ - 1];
        }
    }
    return *this;
}