#include "../../Algoritmos/ABIN.hpp"

using namespace std;

template <typename T>
unsigned int contar_nodos_abin(Abin<T>& A){
    if(A.arbolVacio()){
        return 0;
    }
    else{
        return contar_nodos_abin_rec(A, A.raiz());
    }
}

template <typename T>
unsigned int contar_nodos_abin_rec(Abin<T>& A, typename Abin<T>::nodo n){
    if(n == Abin<T>::NODO_NULO){
        return 0;
    }
    else{
        return 1 + contar_nodos_abin_rec(A, A.hijoIzqdo(n)) + contar_nodos_abin_rec(A, A.hijoDrcho(n));
    }
}

