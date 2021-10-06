#include "List.h"
#include <cassert>
#include <iostream>

using namespace std;

template<class T>
void test_empty(const List<T> &l)
{
    assert(l.length() == 0);
    assert(l.empty() == true);
}

template<class T>
void test_length(const List <T> &l, size_t len)
{
    assert(l.length() == len);
    assert(l.empty() == (len == 0 ? true : false));
}

template<class T>
void test_present(const List<T> &l, const T &item, bool result = true)
{
    assert(l.present(item) == result);
    if (result == true) {
        assert(l.empty() == false);
        assert(l.length() != 0);
    }
}

// Primer conjunto de pruebas, incluyendo:
// 
// o Constructor por defecto.
// o Operador de asignación.
// o empty(), length()
// o push_back()
// o remove_back();
// o present().
// o destructor.
//
// En este juego de regresiones no se ponen a prueba los métodos push_front()
// ni remove_front(), como así tampoco el constructor de copia. Es decir, estas
// operaciones no son necesarias para satisfacer este primer conjunto de casos
// de prueba.
//
void run_tests_1()
{
    List<int> *L1 = new List<int>;
    List<int>  L2;

    L1->push_back(0); // Agrego el 0 al final
    L1->push_back(1); // Agrego el 1 al final
    test_length(*L1, 2);
    test_present(*L1, 0, true);
    test_present(*L1, 1, true);

    L1->push_back(2); // Agrego el 2 al final
    test_length(*L1, 3);
    test_present(*L1, 0, true);
    test_present(*L1, 1, true);
    test_present(*L1, 2, true);

    L1->push_back(3); // Agrego el 3 al final
    test_length(*L1, 4);
    test_present(*L1, 0, true);
    test_present(*L1, 1, true);
    test_present(*L1, 2, true);
    test_present(*L1, 3, true);

    // En este punto, *L1 debería contener 4 elementos: 0, 1, 2 y 3 (en ese
    // orden). A continuación, vamos a hacer una copia de el contenido de la
    // lista en L2 y luego borramos el contenido completo de *L1. De allí en
    // más, todas las regresiones restantes estarán definidas sobre el 
    // contenido de L2.
    //
    L2 = *L1;
    delete L1;

    // De aquí en más, todas las regresiones están definidas sobre L2.
    //
    test_present(L2, 1, true);
    test_present(L2, 2, true);
    test_present(L2, 3, true);
    test_present(L2, 0, true);
    test_length(L2, 4);

    // Ahora vamos eliminando de a uno hasta que L2 quede vacía. En este punto
    // de la ejecución de los casos, el contenido debería ser así:
    //
    // Frente de L2 -> 0, 1, 2, 3 <- Final de L2
    //
    L2.remove_back(); // Elimina el 3
    test_present(L2, 0, true);
    test_present(L2, 1, true);
    test_present(L2, 2, true);
    test_present(L2, 3, false);
    test_length(L2, 3);

    L2.remove_back(); // Debería eliminar el 2
    L2.remove_back(); // Debería eliminar el 1
    test_present(L2, 1, false);
    test_present(L2, 2, false);
    test_present(L2, 3, false);
    test_present(L2, 0, true);
    test_length(L2, 1);

    L2.remove_back(); // Debería eliminar el 0
    test_present(L2, 1, false);
    test_present(L2, 2, false);
    test_present(L2, 3, false);
    test_present(L2, 0, false);

    // Verificamos que L2 haya quedado sin elementos.
    //
    test_length(L2, 0);
    test_empty(L2);

    cerr << "test 1: OK\n";
}

// Segundo conjunto de pruebas:
//
// o Todas las operaciones de la pruba anterior.
// o Constructor por copia.
// o Operador de asignación.
// o push_front();
// o remove_front();
//
void run_tests_2()
{
    List<int> L1;
    List<int> L2;

    test_empty(L1);
    test_empty(L2);

    L1.push_back(1);
    test_length(L1, 1);
    test_present(L1, 1, true);

    L1.push_back(2);
    test_length(L1, 2);
    test_present(L1, 1, true);
    test_present(L1, 2, true);

    L1.push_back(3);
    test_length(L1, 3);
    test_present(L1, 1, true);
    test_present(L1, 2, true);
    test_present(L1, 3, true);
    test_present(L1, 0, false);

    L1.push_front(0);
    test_length(L1, 4);
    test_present(L1, 1, true);
    test_present(L1, 2, true);
    test_present(L1, 3, true);
    test_present(L1, 0, true);

    // Copiamos los 4 valores.
    L2 = L2 = L2 = L2 = L2 = L1;
    List<int> L3(L2);

    L1.remove_back();
    test_present(L1, 1, true);
    test_present(L1, 2, true);
    test_present(L1, 3, false);
    test_present(L1, 0, true);

    L1.remove_back();
    test_present(L1, 1, true);
    test_present(L1, 2, false);
    test_present(L1, 3, false);
    test_present(L1, 0, true);

    L1.remove_front();
    test_present(L1, 1, true);
    test_present(L1, 2, false);
    test_present(L1, 3, false);
    test_present(L1, 0, false);

    L1.remove_front();
    test_present(L1, 1, false);
    test_present(L1, 2, false);
    test_present(L1, 3, false);
    test_present(L1, 0, false);
    test_empty(L1);

    test_present(L2, 1, true);
    test_present(L2, 2, true);
    test_present(L2, 3, true);
    test_present(L2, 0, true);

    test_present(L3, 1, true);
    test_present(L3, 2, true);
    test_present(L3, 3, true);
    test_present(L3, 0, true);

    while (L3.length() != 0)
        L3.remove_front();

    test_present(L3, 1, false);
    test_present(L3, 2, false);
    test_present(L3, 3, false);
    test_present(L3, 0, false);
    test_empty(L3);

    cerr << "test 2: OK\n";
}

int main()
{
    run_tests_1();
    run_tests_2();
}
