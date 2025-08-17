#include "../../Algoritmos/ABIN.hpp"

template <typename T>
Abin<T> reflejar(const Abin<T>& A) {
    Abin<T> B;
    if (A.arbolVacio()) {
        return B;
    } else {
        B.insertarRaiz(A.elemento(A.raiz()));
        return reflejar_rec(A.raiz(), B.raiz(), A, B);
    }
}

template <typename T>
void reflejar_rec(typename Abin<T>::nodo a, typename Abin<T>::nodo b, const Abin<T>& A, Abin<T>& B) {
    if (A.hijoIzqdo(a) != Abin<T>::NODO_NULO) {
        B.insertarHijoDrcho(b, A.elemento(A.hijoIzqdo(a)));
        reflejar_rec(A.hijoIzqdo(a), B.hijoDrcho(b), A, B);
    }
    if (A.hijoDrcho(a) != Abin<T>::NODO_NULO) {
        B.insertarHijoIzqdo(b, A.elemento(A.hijoDrcho(a)));
        reflejar_rec(A.hijoDrcho(a), B.hijoIzqdo(b), A, B);
    }
}