#include "../../Algoritmos/ABIN.hpp"

using namespace std;

template <typename T>
unsigned int calcular_profundidad_abin(typename Abin<T>::nodo n, Abin<T>&A){
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }
    else{
        return 1 + calcular_profundidad_abin(A.padre(n), A);
    }
}