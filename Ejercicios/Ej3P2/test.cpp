#include "mset.h"
#include <cassert>

template<class T>
void test_empty(const mset<T> &s)
{
    assert(s.size() == 0);
    assert(s.empty() == true);
}

template<class T>
void test_size(const mset<T> &s, size_t sz)
{
    assert(s.size() == sz);
    assert(s.empty() == (sz == 0 ? true : false));
}

template<class T>
void test_present(const mset<T> &s, const T &item, bool result = true)
{
    assert(s.present(item) == result);
    if (result == true) {
	    assert(s.empty() == false);
	    assert(s.size() != 0);
    }
}

void run_tests()
{
	mset<int> s1;
	mset<int> s2;
	int i = 0;

	cout<<i<<endl;
	i++;
	test_empty(s1);
	test_size(s1, 0);
	s1.add(1);
	test_present(s1, 1);
	test_size(s1, 1);
	s1.del(1);
	test_present(s1, 1, false);
	test_size(s1, 0);
	test_empty(s1);

	cout<<i<<endl;
		i++;
	s1.del(5);
	test_present(s1, 5, false);
	test_present(s1, 1, false);
	test_size(s1, 0);
	test_empty(s1);

	cout<<i<<endl;
		i++;
	s1.add(-3);
	s1.add(-2);
	s1.add(-1);
	test_size(s1, 3);
	test_present(s1, -1, true);
	test_present(s1, -2, true);
	test_present(s1, -3, true);

	cout<<i<<endl;
		i++;
	s2 = s1;

	s1.del(-2);
	s1.del(-3);
	s1.del(-1);
	test_size(s1, 0);
	test_present(s1, -1, false);
	test_present(s1, -2, false);
	test_present(s1, -3, false);

	cout<<i<<endl;
		i++;
	test_present(s2, -1);
	test_present(s2, -2);
	test_present(s2, -3);

	for (int i = 0; i < 1000; ++i) {
		test_present(s1, i, false);
		s1.add(i);
		test_present(s1, i, true);
	}

	cout<<i<<endl;
	i++;
	mset<int> s3(mset<int>::mset_union(s1, s2));
	test_size(s3, 1003);

	for (int i = 999; i >= -3; --i)
		test_present(s3, i);

	mset<int> s4;
	s1 = s2 = s4;

	for (int i = 999; i >= -3; i -= 2) {
		test_present(s3, i, true);
		s3.del(i);
		test_present(s3, i, false);
	}

	for (int i = 998; i >= -3; i -= 2) {
		test_present(s3, i, true);
		s3.del(i);
		test_present(s3, i, false);
	}

	test_empty(s4);
	test_empty(s3);
	test_empty(s2);
	test_empty(s1);

	// Para la siguiente regresión, generamos dos conjuntos:
	//
	// * s1 contiene los elementos 1, 2, 3 (tres valores).
	// * s2 contiene los elementos 1, 2, 2, 3, 3, 3 (seis valores).
	//
	s1.add(1);
	s1.add(2);
	s1.add(3);

	s2.add(1);
	s2.add(2);
	s2.add(2);
	s2.add(3);
	s2.add(3);
	s2.add(3);

	// Ahora, calculamos la unión de s1 y s2 en s3.
	//
	// Recordemos que:
	//
	// s1 = {1, 2, 3}
	// s2 = {1, 2, 2, 3, 3, 3}
	//
	// Por ende, debería ser:
	//
	// s3 = s1 U s2 = {1, 1, 2, 2, 2, 3, 3, 3, 3}
	//
	s3 = mset<int>::mset_union(s1, s2);
	test_present(s3, 1);
	test_present(s3, 2);
	test_present(s3, 3);

	// Deberíamos poder borrar 2 veces el 1.
	//
	s3.del(1);
	test_present(s3, 1);
	s3.del(1);
	test_present(s3, 1, false);

	// En este punto del programa, s3 debería contener 3 repeticiones
	// del entero 2: vamos a validar si esto es cierto eliminando uno
	// a uno cada una de estas 3 copias.
	//
	test_present(s3, 2);
	s3.del(2);
	test_present(s3, 2);
	s3.del(2);
	test_present(s3, 2);
	s3.del(2);
	test_present(s3, 2, false);

	// Misma idea para el enterio 3 (4 repeticiones).
	//
	test_present(s3, 3);
	s3.del(3);
	test_present(s3, 3);
	s3.del(3);
	test_present(s3, 3);
	s3.del(3);
	test_present(s3, 3);
	s3.del(3);
	test_present(s3, 3, false);
	test_empty(s3);

	s1 = mset<int>();
	s2 = mset<int>();
	s4 = mset<int>();
}

int main()
{
	run_tests();
	cout<<":)"<<endl;
}
