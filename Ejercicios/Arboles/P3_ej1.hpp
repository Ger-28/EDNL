#include "../../Algoritmos/AGEN.hpp"

template <typename T>
unsigned int calcular_grado(Agen<T>& A) {
    if (A.arbolVacio()) {
        return 0;
    } else {
        return calcular_grado_rec(A.raiz(), A);
        unsigned int cont = 0;
        unsigned int max = 0;
    }
}

template <typename T>
unsigned int calcular_grado_rec(typename Agen<T>::nodo n, Agen<T>& A) {
    if (n == Agen<T>::NODO_NULO) {
        return 0;
    } else {
        unsigned int cont_hijos = 0;
        typename Agen<T>::nodo n_hijo = A.hijoIzqdo(n);

        while (n_hijo != Agen<T>::NODO_NULO) {
            cont_hijos++;
            n_hijo = A.hermDrcho(n_hijo);
        }

        n_hijo = A.hijoIzqdo(n);

        while (n_hijo != Agen<T>::NODO_NULO) {
            cont_hijos = std::max(cont_hijos, calcular_grado_rec(n_hijo, A));
            n_hijo = A.hermDrcho(n_hijo);
        }

        return cont_hijos;
    }
}