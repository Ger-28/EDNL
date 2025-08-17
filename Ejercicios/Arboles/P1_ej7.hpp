#include "../../Algoritmos/ABIN.hpp"
#include "P1_ej2.hpp"

using namespace std;

template <typename T>
bool es_pseudocompleto(Abin<T>& A) {
    return es_pseudocompleto_rec(A.raiz(), A);
}

template <typename T>
bool es_pseudocompleto_rec(typename Abin<T>::nodo n, Abin<T>& A) {
    if (n == Abin<T>::NODO_NULO) {
        return true;
    } else if (calcular_altura_abin_rec(n, A) == 0) {
        return true;
    } else if (calcular_altura_abin_rec(n, A) == 1 && (A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO ||
                                                       A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO)) {
        return false;
    } else if (calcular_altura_abin_rec(A.hijoIzqdo(n), A) == calcular_altura_abin_rec(A.hijoDrcho(n), A)) {
        return es_pseudocompleto_rec(A.hijoIzqdo(n), A) && es_pseudocompleto_rec(A.hijoDrcho(n), A);
    } else if (calcular_altura_abin_rec(A.hijoIzqdo(n), A) > calcular_altura_abin_rec(A.hijoDrcho(n), A)) {
        return es_pseudocompleto_rec(A.hijoIzqdo(n), A);
    } else {
        return es_pseudocompleto_rec(A.hijoDrcho(n), A);
    }
}