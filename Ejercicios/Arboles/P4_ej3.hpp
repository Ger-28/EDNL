#include "../../Algoritmos/ABB.hpp"

template <typename T>
Abb<T> unir(const Abb<T>& A, const Abb<T>& B) {
    Abb<T> R;
    unir_a_rec(A, R);
    unir_b_rec(B, R);

    return R;
}

template <typename T>
void unir_a_rec(const Abb<T>& A, Abb<T>& R) {
    if (!A.vacio()) {
        R.insertar(A.elemento());
        unir_a_rec(A.izqdo(), R);
        unir_a_rec(A.drcho(), R);
    }
}

template <typename T>
void unir_b_rec(const Abb<T>& B, Abb<T>& R) {
    if (!B.vacio()) {
        if (R.buscar(B.elemento()).vacio()) {
            R.insertar(B.elemento());
        }
        unir_a_rec(B.izqdo(), R);
        unir_a_rec(B.drcho(), R);
    }
}