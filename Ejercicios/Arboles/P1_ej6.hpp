#include "../../Algoritmos/ABIN.hpp"
#include "P1_ej2.hpp"

using namespace std;

template <typename T>
int calcular_desequilibrio_abin(Abin<T>& A) {
    return calcular_desequilibrio_abin_rec(A.raiz(), A);
}

template <typename T>
int calcular_desequilibrio_abin_rec(typename Abin<T>::nodo n, Abin<T>& A) {
    if (n == Abin<T>::NODO_NULO) {
        return 0;
    } else {
        return max(abs(calcular_altura_abin_rec(A.hijoIzqdo(n), A) - calcular_altura_abin_rec(A.hijoDrcho(n), A)),
                   max(calcular_desequilibrio_abin_rec(A.hijoIzqdo(n), A), calcular_desequilibrio_abin_rec(A.hijoDrcho(n), A)));
    }
}