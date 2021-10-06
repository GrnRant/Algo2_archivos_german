#ifndef _STACK_H_
#define _STACK_H_

#include <cstdlib>

#define ALLOC_SIZE 10

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
	T *pri_;
    T *tope_;
    size_t tamv_;
    size_t tam_;
};

template<typename T>
stack<T>::stack() 
{
	pri_ = NULL;
    tope_ = NULL;
    tamv_ = 0;
    tam_ = 0;
}

template<typename T>
stack<T>::stack(size_t len) 
{
	pri_ = new T[tamv_ = len];
    tope_ = NULL;
    tam_ = 0;
}

template<typename T>
stack<T>::stack(const stack &st)
{
	pri_ = NULL;
    tamv_ = 0;
    tam_ = 0;
    tope_ = NULL;
    
    if(st.tamv_)
    {
        pri_ = new T[tamv_ = st.tamv_];
        if(st.tope_)
        {
            size_t i;

            for(i = 0; &st.pri_[i] != st.tope_; i++)
                pri_[i] = st.pri_[i];
            pri_[i] = *st.tope_;
            tope_ = &pri_[i];
            tam_ = st.tam_;
        }
    }
}

template<typename T>
stack<T> &stack<T>::operator=(const stack<T> &rhs)
{
	if(this != &rhs)
    {
        size_t i;

        if(pri_)
            delete [] pri_;
        pri_ = new T[tamv_ = rhs.tamv_];
        for(i = 0; &rhs.pri_[i] != rhs.tope_; i++)
            pri_[i] = rhs.pri_[i];
        pri_[i] = *rhs.tope_;
        tope_ = &pri_[i];
        tam_ = rhs.tam_;
    }
	return *this;
}

template<typename T>
stack<T>::~stack()
{
	delete [] pri_;
}

template<typename T>
void stack<T>::pop()
{
	if(tope_)
    {
        tam_--;
        if(tam_ == 0)
            tope_ = NULL;
        else
            tope_--;
    }
}

template<typename T>
void stack<T>::pop(T &ref)
{
    if(tope_)
    {
        ref = *tope_;
        tam_--;
        if(tam_ == 0)
            tope_ = NULL;
        else
            tope_--;
    }
}

template<typename T>
void stack<T>::push(const T &top)
{
	if(pri_ == NULL)
        pri_ = new T[tamv_ = ALLOC_SIZE];
    else if(tope_ == &pri_[tamv_ - 1])
    {
        size_t i;
        T *aux = new T[tamv_ += ALLOC_SIZE];

        for(i = 0; &pri_[i] != tope_; i++)
            aux[i] = pri_[i];
        aux[i] = *tope_;
        tope_ = &aux[i];
        delete [] pri_;
        pri_ = aux;
    }
    if(tope_ == NULL)
        tope_ = pri_;
    else
        tope_++;
    *tope_ = top;
    tam_++;
}

template<typename T>
bool stack<T>::empty() const
{
	return tope_? false:true;
}

template<typename T>
size_t stack<T>::length() const
{
	return tam_;
}
#endif
