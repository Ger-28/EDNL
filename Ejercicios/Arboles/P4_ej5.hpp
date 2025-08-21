#include "../../Algoritmos/ABB.hpp"

template <typename T>
Abb<T> restar_ui(const Abb<T>& A, const Abb<T>& B) {
    Abb<T> R;
    diferentes_b(A, B, R);
    diferentes_a(A, B, R);
    return R;
}

template <typename T>
void diferentes_b(const Abb<T>& A, const Abb<T>& B, Abb<T>& R) {
    if (!B.vacio()) {
        if (A.buscar(B.elemento()).vacio()) {
            R.insertar(B.elemento());
        }
        diferentes_b(A, B.izqdo(), R);
        diferentes_b(A, B.drcho(), R);
    }
}

template <typename T>
void diferentes_a(const Abb<T>& A, const Abb<T>& B, Abb<T>& R) {
    if (!A.vacio()) {
        if (B.buscar(A.elemento()).vacio()) {
            R.insertar(A.elemento());
        }
        diferentes_a(A.izqdo(), B, R);
        diferentes_a(A.drcho(), B, R);
    }
}