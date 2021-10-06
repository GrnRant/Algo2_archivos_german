#ifndef _STACK_H_
#define _STACK_H_

#include <cstdlib>

#define CHOP_SIZE 10

template<typename T>
class stack {
public:
	stack();
	stack(size_t);
	stack(const stack &);
	stack &operator=(const stack &);
	~stack();

	void pop();
	void pop(T &);
	void push(const T &);
	bool empty() const;
	size_t length() const;

private:
	T *tope_;
    T *arr_;
    size_t tam_;
    size_t tamv_;
};

template<typename T>
stack<T>::stack(): tope_(0), arr_(0), tam_(0), tamv_(0)
{
	
}

template<typename T>
stack<T>::stack(size_t len) 
{
	tope_ = NULL;
    arr_ = 0;
    tam_ = 0;
    if(len)
    {
        arr_ = new T[len];
        tamv_ = len;
        tope_ = arr_;
    }
}

template<typename T>
stack<T>::stack(const stack &st)
{
    tope_ = NULL;
    arr_ = 0;
    tam_ = 0;
    tamv_ = 0;
    
	if(st.tam_)
    {
        size_t i;

        arr_ = new T[st.tamv_];
        tam_ = st.tam_;
        tamv_ = st.tamv_;
        for(i = 0; i < st.tam_; i++)
            arr_[i] = st.arr_[i];
        tope_ = &arr_[tam_ - 1];
    }
}

template<typename T>
stack<T> &stack<T>::operator=(const stack<T> &rhs)
{
	if(this != &rhs)
    {
        if(arr_)
            delete []arr_;
        tamv_ = 0;
        tam_ = 0;
        arr_ = NULL;
        tope_ = NULL;

        if(rhs.tope_)
        {
            size_t i;

            arr_ = new T[rhs.tamv_];
            tamv_ = rhs.tamv_;
            for(i = 0; i<rhs.tam_; i++)
                arr_[i] = rhs.arr_[i];
            tam_ = rhs.tam_;
            tope_ = &arr_[tam_ - 1];
        }

    }
	return *this;
}

template<typename T>
stack<T>::~stack()
{
	delete []arr_;
}

template<typename T>
void stack<T>::pop()
{
    tope_--;
	tam_--;
}

template<typename T>
void stack<T>::pop(T &ref)
{
	if(tope_)
    {
        ref = *tope_;
        tope_--;
        tam_--;
    }
}

template<typename T>
void stack<T>::push(const T &top)
{
	if(tam_ == tamv_)
    {
        T *aux;
        size_t i;

        aux = new T[tamv_ + CHOP_SIZE];
        for(i = 0; i<tam_; i++)
            aux[i] = arr_[i];
        if(arr_)
            delete [] arr_;
        arr_ = aux;
        tamv_ += CHOP_SIZE; 
        tope_ = &arr_[tam_ - 1];
    }
    arr_[tam_] = top;
    tam_++;
    tope_++;
}

template<typename T>
bool stack<T>::empty() const
{
	return tam_? false:true;
}

template<typename T>
size_t stack<T>::length() const
{
	return tam_;
}

#endif
