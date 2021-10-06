#include "Queue.h"
#include <cassert>
#include <iostream>

using namespace std;

template<class T>
void test_empty(const Queue<T> &q)
{
    assert(q.length() == 0);
    assert(q.empty() == true);
}

template<class T>
void test_length(const Queue <T> &q, int len)
{
    assert(q.length() == len);
    assert(q.empty() == (len == 0 ? true : false));
}

template<class T>
void test_dequeue(Queue <T> &q, const T &t)
{
    T tt;
    q.dequeue(tt);
    assert(tt == t);
}

// Primer conjunto de pruebas, incluyendo:
// 
// o Constructor por defecto;
// o empty(), length();
// o enqueue();
// o dequeue();
// o destructor.
//
void run_test_1()
{
    Queue<char> q;

    // Comienza vacía.
    //
    test_empty(q);

    // Insertamos un elemento y luego quitamos.
    //
    q.enqueue('a', 1);
    test_length(q, 1);
    test_dequeue(q, 'a');

    // En este punto, debería estar vacía.
    //
    test_empty(q);

    // Insertamos dos elementos de igual prioridad.
    //
    q.enqueue('y', 1);
    q.enqueue('o', 1);
    test_length(q, 2);
 
    test_dequeue(q, 'y');
    test_dequeue(q, 'o');

    // En este punto, debería estar vacía nuevamente.
    //
    test_empty(q);

    // Ahora probamos con dos elementos de diferente prioridad.
    //
    q.enqueue('a', 1);
    q.enqueue('b', 2);
    test_length(q, 2);

    test_dequeue(q, 'b');
    test_dequeue(q, 'a');

    // En este punto, debería estar vacía nuevamente.
    //
    test_empty(q);

    // Misma prueba que la anterior, pero con prioridades invertidas.
    //
    q.enqueue('a', 2);
    q.enqueue('b', 1);
    test_length(q, 2);

    test_dequeue(q, 'a');
    test_dequeue(q, 'b');

    // En este punto, debería estar vacía nuevamente.
    //
    test_empty(q);

    // Prueba con 4 elementos.
    //
    q.enqueue('w', 10);
    q.enqueue('x', 1);
    q.enqueue('b', 1);
    q.enqueue('b', 1);

    test_dequeue(q, 'w');
    test_dequeue(q, 'x');
    test_dequeue(q, 'b');
    test_dequeue(q, 'b');

    // Verificamos que haya quedado vacía una vez más.
    //
    test_empty(q);

    cerr << "test 1: OK\n";
}

// Segundo conjunto de pruebas:
//
// o Todas las operaciones de la prueba #1.
// o Operador de asignación.
//
void run_test_2()
{
    Queue<char> *p = new Queue<char>;
    Queue<char>  q;

    // Comienza vacía.
    //
    test_empty(*p);

    // Prueba con 4 elementos.
    //
    p->enqueue('w', 10);
    p->enqueue('x', 1);
    p->enqueue('b', 1);
    p->enqueue('b', 1);

    // Generamos una copia profunda de la cola *p y luego borramos.
    //
    q = q = *p;
    delete p;

    test_dequeue(q, 'w');
    test_dequeue(q, 'x');
    test_dequeue(q, 'b');
    test_dequeue(q, 'b');

    // Verificamos que haya quedado vacía una vez más.
    //
    test_empty(q);

    cerr << "test 2: OK\n";
}

// Tercer conjunto de pruebas:
//
// o Todas las operaciones de la prueba #1.
// o Constructor de copia.
//
void run_test_3()
{
    Queue<char> *p = new Queue<char>;

    // Comienza vacía.
    //
    test_empty(*p);

    // Prueba con 4 elementos.
    //
    p->enqueue('x', 1);
    p->enqueue('w', 10);
    p->enqueue('b', 1);
    p->enqueue('b', 1);

    // Generamos una copia profunda de la cola *p y luego borramos.
    //
    Queue<char> q(*p);
    delete p;

    test_dequeue(q, 'w');
    test_dequeue(q, 'x');
    test_dequeue(q, 'b');
    test_dequeue(q, 'b');

    // Verificamos que haya quedado vacía una vez más.
    //
    test_empty(q);

    cerr << "test 3: OK\n";
}

void run_test_4()
{
    Queue<char> *p = new Queue<char>;
    Queue<char>  q;
    char c;

    // Encolamos 1000 elementos 'a' con prioridad creciente.
    //
    for (int i = 0; i < 1000; ++i)
        p->enqueue('a', i);

    // A continuación, encolamos el 1001-ésimo elemento, con mayor
    // prioridad que todos los anteriores.
    //
    test_length(*p, 1000);
    p->enqueue('x', 1000);
    test_length(*p, 1001);

    // Y luego encolamos otros 1000 elementos 'b', con prioridad 
    // decreciente, de tal forma que además tengan menos prioridad 
    // que el elemento 1001-ésimo del paso anterior.
    //
    for (int i = 999; i >= 0; --i)
        p->enqueue('b', i);

    test_length(*p, 2001);

    // Ahora transferimos el contenido completo de *p a q, y luego 
    // eliminamos *p para asegurarnos que el contenido transiferido
    // a q no se haya alterado.
    //
    q = q = q = q = q = q = q = q = *p;
    while (p->empty() == false)
        p->dequeue(c);
    test_empty(*p);
    delete p;

    // Recordemos que el elemento 1001-ésimo 'x' (que insertamos en *p
    // antes) es el de mayor prioridad: debería ser el primero en el 
    // momento de desacolar.
    //
    test_dequeue(q, 'x');

    // Desencolamos los elementos restantes, validando que a igual 
    // prioridad éstos salgan en el orden esperado (FIFO).
    //
    for (int i = 0; i < 1000; ++i) {
        test_dequeue(q, 'a');
        test_dequeue(q, 'b');
    }

    // En este punto del programa, tanto *p como q deberían estar vacías.
    //
    test_empty(q);

    cerr << "test 4: OK\n";
}

int main()
{
    run_test_1();
    run_test_2();
    run_test_3();
    run_test_4();
}
