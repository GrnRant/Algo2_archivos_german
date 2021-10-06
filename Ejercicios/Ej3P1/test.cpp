#include "set.h"
#include <cassert>

template<class T>
void test_empty(const set<T> &s)
{
    assert(s.size() == 0);
    assert(s.empty() == true);
}

template<class T>
void test_size(const set<T> &s, size_t sz)
{
    assert(s.size() == sz);
    assert(s.empty() == (sz == 0 ? true : false));
}

template<class T>
void test_present(const set<T> &s, const T &item, bool result = true)
{
    assert(s.present(item) == result);
    if (result == true) {
	    assert(s.empty() == false);
	    assert(s.size() != 0);
    }
}

void run_tests()
{
	set<int> s1;
	set<int> s2;

	test_empty(s1);
	test_size(s1, 0);
	s1.add(1);
	test_present(s1, 1);
	test_size(s1, 1);
	s1.del(1);
	test_present(s1, 1, false);
	test_size(s1, 0);
	test_empty(s1);

	s1.del(5);
	test_present(s1, 5, false);
	test_present(s1, 1, false);
	test_size(s1, 0);
	test_empty(s1);

	s1.add(-3);
	s1.add(-2);
	s1.add(-1);
	test_size(s1, 3);
	test_present(s1, -1, true);
	test_present(s1, -2, true);
	test_present(s1, -3, true);

	s2 = s1;

	s1.del(-2);
	s1.del(-3);
	s1.del(-1);
	test_size(s1, 0);
	test_present(s1, -1, false);
	test_present(s1, -2, false);
	test_present(s1, -3, false);

	test_present(s2, -1);
	test_present(s2, -2);
	test_present(s2, -3);

	for (int i = 0; i < 1000; ++i) {
		test_present(s1, i, false);
		s1.add(i);
		test_present(s1, i, true);
	}

	set<int> s3(set<int>::join(s1, s2));
	test_size(s3, 1003);

	for (int i = 999; i >= -3; --i)
		test_present(s3, i);

	set<int> s4;
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
}

int main()
{
	run_tests();
}
