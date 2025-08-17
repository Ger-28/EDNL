#include "../../Algoritmos/ABIN.hpp"

template <typename T>
bool son_similares(const Abin<T>& A, const Abin<T>& B) {
    return son_similares_rec(A.raiz(), B.raiz(), A, B);
}

template <typename T>
bool son_similares_rec(typename Abin<T>::nodo a, typename Abin<T>::nodo b, const Abin<T>& A, const Abin<T>& B) {
    if (a == Abin<T>::NODO_NULO && b == Abin<T>::NODO_NULO) {
        return true;
    } else if (a == Abin<T>::NODO_NULO || b == Abin<T>::NODO_NULO) {
        return false;
    } else {
        return son_similares_rec(A.hijoIzqdo(a), B.hijoIzqdo(b), A, B) && son_similares_rec(A.hijoDrcho(a), B.hijoDrcho(b), A, B);
    }
}