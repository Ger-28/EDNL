#include "../../Algoritmos/AGEN.hpp"

void podar_rama_rec(typename Agen<int>::nodo n, Agen<int>& A);
void podar_agen_rec(typename Agen<int>::nodo n, Agen<int>& A, int x);

void podar_agen(Agen<int>& A, int x) {
    podar_agen_rec(A.raiz(), A, x);
}

void podar_agen_rec(typename Agen<int>::nodo n, Agen<int>& A, int x) {
    if (n != Agen<int>::NODO_NULO) {
        if (A.elemento(n) == x) {
            podar_rama_rec(n, A);
        } else {
            typename Agen<int>::nodo hijo = A.hijoIzqdo(n);

            while (hijo != Agen<int>::NODO_NULO) {
                podar_agen_rec(hijo, A, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void podar_rama_rec(typename Agen<int>::nodo n, Agen<int>& A) {
    typename Agen<int>::nodo hijo = A.hijoIzqdo(n);

    /*
    Lucía:


    */

    while (hijo != Agen<int>::NODO_NULO) {
        if (A.hijoIzqdo(hijo) != Agen<int>::NODO_NULO) {
            podar_rama_rec(A.hijoIzqdo(n), A);
        } else {
            A.eliminarHijoIzqdo(n);
            hijo = A.hijoIzqdo(n);
        }
    }
}