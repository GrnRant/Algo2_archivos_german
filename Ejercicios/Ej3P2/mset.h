#ifndef _MSET_H_
#define _MSET_H_

#define ALLOC_SIZE 1

#include <cstdlib>
#include <iostream>

using namespace std;

template<typename T>
class mset {
public:
	mset();
	mset(const mset &);
	mset &operator=(const mset &);
	~mset();

	void add(T const &);
	void del(T const &);
	bool present(T const &) const;
	bool empty() const;
	size_t size() const;

	static mset mset_union(const mset &, const mset &);
	static mset mset_intersect(const mset &, const mset &);
private:
	T *conj_;
    size_t tam_;
    size_t tamv_;
};

template<typename T>
mset<T>::mset() 
{
	conj_ = NULL;
    tamv_ = 0;
    tam_ = 0;  
}

template<typename T>
mset<T>::mset(const mset &rhs)
{
    conj_ = NULL;
    tam_ = 0;
    tamv_ = 0;

    if(rhs.tamv_)
    {
        conj_ = new T[tamv_ = rhs.tamv_];
        if(rhs.tam_)
        {
            size_t i;

            for(i = 0; i<rhs.tam_; i++)
                conj_[i] = rhs.conj_[i];
            tam_ = rhs.tam_;
        }
    }
}

template<typename T>
mset<T> &mset<T>::operator=(const mset<T> &rhs)
{
    if(&rhs != this)
    {
        delete [] conj_;
        conj_ = NULL;
        tam_ = 0;
        tamv_ = 0;

        if(rhs.tamv_)
        {
            conj_ = new T[tamv_ = rhs.tamv_];
            if(rhs.tam_)
            {
                size_t i;

                for(i = 0; i<rhs.tam_; i++)
                    conj_[i] = rhs.conj_[i];
                tam_ = rhs.tam_;
            }
        }
    }
	return *this;
}

template<typename T>
mset<T>::~mset()
{
	delete [] conj_;
}

template<typename T>
void mset<T>::add(const T &item)
{
	if(tam_ == tamv_)
    {
        size_t i;
        T *aux = new T[tamv_ += ALLOC_SIZE];

        for(i = 0; i<tam_; i++)
            aux[i] = conj_[i];
        delete [] conj_;
        conj_ = aux;
    }
    conj_[tam_] = item;
    tam_++;
}

template<typename T>
void mset<T>::del(const T &item)
{
    if(tam_)
    {
	    size_t i;
        T * aux = new T[tamv_];

        for(i = 0; conj_[i] != item && i<tam_; i++)
            aux[i] = conj_[i];
        if(i < tam_)
        {
            for(i++; i<tam_; i++)
                aux[i - 1] = conj_[i];
            tam_--;
        }
        delete [] conj_;
        conj_ = aux;
    }
}

template<typename T>
bool mset<T>::present(const T &item) const
{
	size_t i;

    for(i = 0; i<tam_; i++)
    {
        if(conj_[i] == item)
            return true;
    }
	return false;
}

template<typename T>
bool mset<T>::empty() const
{
	return tam_? false:true;
}

template<typename T>
size_t mset<T>::size() const
{
	return tam_;
}

template<typename T>
mset<T> mset<T>::mset_union(const mset<T> &s1, const mset<T> &s2)
{
    size_t i, j;
	mset<T> res;
    
    if(s1.tamv_ || s2.tamv_)
        res.conj_ = new T[res.tamv_ = s1.tamv_ + s2.tamv_];
    for(i = 0; i<s1.tam_; i++)
        res.conj_[i] = s1.conj_[i];
    for(j = 0; j<s2.tam_; j++, i++)
        res.conj_[i] = s2.conj_[j];
    res.tam_ = s1.tam_ + s2.tam_;

	return res;
}

template<typename T>
mset<T> mset<T>::mset_intersect(const mset<T> &s1, const mset<T> &s2)
{
	mset<T> res;
	// ...
	return res;
}
#endif
