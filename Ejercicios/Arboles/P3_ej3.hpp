#include <algorithm>
#include "../../Algoritmos/AGEN.hpp"

template <typename T>
int calcular_desequilibrio_gen(Agen<T>& A) {
    return calcular_desequilibrio_gen_rec(A.raiz(), A);
}

template <typename T>
int calcular_desequilibrio_gen_rec(typename Agen<T>::nodo n, Agen<T>& A) {
    if (n == Agen<T>::NODO_NULO) {
        return 0;
    } else {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int desequilibrio = calcular_altura_gen_rec(n, A) - calcular_altura_min_gen_rec(n, A);

        while (hijo != Agen<T>::NODO_NULO) {
            desequilibrio = std::max(desequilibrio, calcular_desequilibrio_gen_rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return desequilibrio;
    }
}

template <typename T>
int calcular_altura_gen_rec(typename Agen<T>::nodo n, Agen<T>& A) {
    if (n == Agen<T>::NODO_NULO) {
        return -1;
    } else {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int cont = -1;

        while (hijo != Agen<T>::NODO_NULO) {
            cont = std::max(calcular_altura_gen_rec(hijo, A), cont);
            hijo = A.hermDrcho(hijo);
        }
        return 1 + cont;
    }
}

template <typename T>
int calcular_altura_min_gen_rec(typename Agen<T>::nodo n, Agen<T>& A) {
    if (n == Agen<T>::NODO_NULO) {
        return -1;
    } else {
        int cont = INT_MAX;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        if (hijo == Agen<T>::NODO_NULO) {
            return 0;
        }

        while (hijo != Agen<T>::NODO_NULO) {
            cont = std::min(cont, calcular_altura_min_gen_rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return 1 + cont;
    }
}