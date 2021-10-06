#ifndef _QUEUE_H_
#define _QUEUE_H_

#define ALLOC_SIZE 10

#include <cstdlib>

using namespace std;

template <typename T>
class Queue {
public:
    Queue();
    Queue(const Queue &);
    Queue &operator=(const Queue &);
    ~Queue();

    void enqueue(const T &, int);
    void dequeue(T &);
    bool empty() const;
    int length() const;

private:
    class datos
    {
        private:
            size_t prior_;
            T valor_;
            friend class Queue;

        public:
            datos();
            datos(const  datos &);
            datos(const size_t &, const T &);
            ~datos();
    };
    datos *arr_;
    size_t tamv_;
    size_t tam_;

    friend class datos;    
};


template <typename T>
Queue<T>::datos::datos()
{

}

template <typename T>
Queue<T>::datos::datos(const size_t &prior, const T &valor)
{
    prior_ = prior;
    valor_ = valor;
}

template <typename T>
Queue<T>::datos::datos(const datos &orig)
{
    prior_ = orig.prior_;
    valor_ = orig.valor_;
}

template <typename T>
Queue<T>::datos::~datos()
{
}

template<typename T>
Queue<T>::Queue()
{
    tamv_ = 0;
    tam_ = 0;
    arr_ = NULL;
}

template<typename T>
Queue<T>::Queue(const Queue &rhs)
{
    tamv_ = 0;
    tam_ = 0;
    arr_ = NULL;

    if(rhs.tamv_)
    {
        tamv_ = rhs.tamv_;
        arr_ = new datos[tamv_];

        if(rhs.tam_)
        {
            size_t i;

            for(i = 0; i<rhs.tam_; i++)
            {
                arr_[i].valor_ = rhs.arr_[i].valor_;
                arr_[i].prior_ = rhs.arr_[i].prior_;
            }
            tam_ = rhs.tam_;
        }
    }
}

template<typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
    if(&rhs != this)
    {
        delete [] arr_;
        tamv_ = 0;
        tam_ = 0;
        arr_ = NULL;

        if(rhs.tamv_)
    {
        tamv_ = rhs.tamv_;
        arr_ = new datos[tamv_];

        if(rhs.tam_)
        {
            size_t i;

            for(i = 0; i<rhs.tam_; i++)
            {
                arr_[i].valor_ = rhs.arr_[i].valor_;
                arr_[i].prior_ = rhs.arr_[i].prior_;
            }
            tam_ = rhs.tam_;
        }
    }
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue()
{
    delete [] arr_;
}

template<typename T>
void Queue<T>::enqueue(const T &data, int prio)
{
    if(tam_ == tamv_)
    {
        size_t i;

        tamv_ += ALLOC_SIZE;
        datos *aux = new datos[tamv_];

        for(i = 0; i<tam_; i++)
        {
            aux[i].valor_ = arr_[i].valor_;
            aux[i].prior_ = arr_[i].prior_;
        }
        arr_ = aux;
    }
    arr_[tam_].valor_ = data;
    arr_[tam_].prior_ = prio;
    tam_++;
}

template<typename T>
void Queue<T>::dequeue(T &data)
{
    if(tam_)
    {
        size_t i, pos = 0;

        for(i = 0; i<tam_; i++)
        {
            size_t prio = arr_[i].prior_;

            if(prio > arr_[pos].prior_)
                pos = i;
        }

        data = arr_[pos].valor_;

        datos *aux = new datos[tamv_];

        for(i = 0; i < tam_ && i != pos; i++)
        {
            aux[i].valor_ = arr_[i].valor_;
            aux[i].prior_ = arr_[i].prior_;
        }
        for(i++; i < tam_; i++)
        {
            aux[i - 1].valor_ = arr_[i].valor_;
            aux[i - 1].prior_ = arr_[i].prior_;
        }
        delete [] arr_;
        arr_ = aux;
        tam_--;
    }
}

template<typename T>
bool Queue<T>::empty() const
{
    return tam_? false:true;
}

template<typename T>
int Queue<T>::length() const
{
    return tam_;
}
#endif
