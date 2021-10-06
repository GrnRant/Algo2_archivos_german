#ifndef _STACK_H_
#define _STACK_H_

#include <cstdlib>

#define ALLOC_SIZE 10

using namespace std;

template<typename T>
class set {
public:
	set();
	set(const set &);
	set &operator=(const set &);
	~set();

	void add(T const &);
	void del(T const &);
	bool present(T const &) const;
	bool empty() const;
	size_t size() const;

	static set join(const set &, const set &);
private:
	size_t tam_;
	size_t tamv_;
	T *conj_;
};

template<typename T>
set<T>::set() 
{
	tam_ = 0;
	tamv_ = 0;
	conj_ = NULL;
}

template<typename T>
set<T>::set(const set &rhs)
{
	tam_ = 0;
	tamv_ = 0;
	conj_ = NULL;

	if(rhs.tamv_)
	{
		size_t i;
		conj_ = new T[tamv_ = rhs.tamv_];

		for(i = 0; i<rhs.tam_; i++)
			conj_[i] = rhs.conj_[i];
		tam_ = rhs.tam_;
	}
}

template<typename T>
set<T> &set<T>::operator=(const set<T> &rhs)
{
	if(this != &rhs)
	{
		delete [] conj_;
		tam_ = 0;
		tamv_ = 0;
		conj_ = NULL;

		if(rhs.tamv_)
		{
			size_t i;
			conj_ = new T[tamv_ = rhs.tamv_];

			for(i = 0; i<rhs.tam_; i++)
				conj_[i] = rhs.conj_[i];
			tam_ = rhs.tam_;
		}
	}
	return *this;
}

template<typename T>
set<T>::~set()
{
	delete [] conj_;
}

template<typename T>
void set<T>::add(const T &item)
{
	if(present(item) == false)
	{
		if(tamv_ == tam_)
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
}

template<typename T>
void set<T>::del(const T &item)
{
	if(!conj_ || !tam_)
		return;
	else
	{
		size_t i;
		T *aux = new T[tamv_];

		for(i = 0; conj_[i] != item && i<tam_; i++)
			aux[i] = conj_[i];
		for(i++; i<tam_; i++)
			aux[i - 1] = conj_[i];
		delete [] conj_;
		conj_ = aux;
		tam_--;
	}
}

template<typename T>
bool set<T>::present(const T &item) const
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
bool set<T>::empty() const
{
	return tam_? false:true;
}

template<typename T>
size_t set<T>::size() const
{
	return tam_;
}

template<typename T>
set<T> set<T>::join(const set<T> &s1, const set<T> &s2)
{
	set<T> res;
	size_t i;

	if(s1.tam_ && s2.tam_)
	{
		res = s1;
		for(i = 0; i<s2.tam_; i++)
			res.add(s2.conj_[i]);
	}
	else if(s2.tam_)
		res = s2;
	else if(s1.tam_)
		res = s1;
	return res;
}
#endif
