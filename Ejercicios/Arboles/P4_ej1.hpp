#include "../../Algoritmos/ABB.hpp"

// Método fácil y efectivo:
template <typename T>
void podar_abb(const Abb<T>& A, const T& x) {
    A.buscar(x).~Abb();
}

// Sin el método buscar:
template <typename T>
void podar_abb_rec(const Abb<T>& A, const T& x) {
    if (A.elemento() < x) {
        podar_abb_rec(A.drcho(), x);
    } else if (A.elemento() > x) {
        podar_abb_rec(A.izqdo(), x);
    } else {
        A.~Abb();
    }
}