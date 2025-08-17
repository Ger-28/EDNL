#include "../../Algoritmos/ABIN.hpp"
#include <algorithm>

using namespace std;

template <typename T>
int calcular_altura_abin(Abin<T>& A){
    return calcular_altura_abin_rec(A.raiz(), A);
}

template <typename T>
int calcular_altura_abin_rec(typename Abin<T>::nodo n, Abin<T>& A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else{
        return 1 + max(calcular_altura_abin_rec(A.hijoIzqdo(n), A), calcular_altura_abin_rec(A.hijoDrcho(n), A));
    }
}