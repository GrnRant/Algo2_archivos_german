#include "stack.h"
#include <cassert>

template<class T>
void test_empty(const stack<T> &s)
{
    assert(s.length() == 0);
    assert(s.empty() == true);
}

template<class T>
void test_top_of_stack(const stack<T> &ss, int xx)
{
    int x;
    stack<T> s(ss);

    assert(s.empty() == false);
    assert(s.length() >= 1);
    s.pop(x);
    assert(x == xx);
}

void run_tests()
{
    stack<int> s;
    stack<int> t;

    test_empty(s);    
    s.push(1);
    test_top_of_stack(s, 1);
    s.pop();
    test_empty(s);

    for (int i = 0; i < 1000; ++i)
	s.push(i);

    t = s;

    for (int i = 0; i < 997; ++i)
	s.pop();

    test_top_of_stack(s, 2);
    s.pop();
    test_top_of_stack(s, 1);
    s.pop();
    test_top_of_stack(s, 0);
    s.pop();
    test_empty(s);

    test_top_of_stack(t, 999);
    while (t.length() > 1)
	t.pop();
    test_top_of_stack(t, 0);
    t.pop();
    test_empty(t);
}

int main()
{
    run_tests();
    return 0;
}
