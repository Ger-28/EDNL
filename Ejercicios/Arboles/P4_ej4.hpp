#include "../../Algoritmos/ABB.hpp"

template <typename T>
Abb<T> interseccionar(const Abb<T>& A, const Abb<T>& B) {
    Abb<T> R;
    interseccionar_rec(A, B, R);
    return R;
}

template <typename T>
void interseccionar_rec(const Abb<T>& A, const Abb<T>& B, Abb<T>& R) {
    if (!A.vacio() && !B.vacio()) {
        if (!A.buscar(B.elemento()).vacio()) {
            R.insertar(B.elemento());
        }
        interseccionar_rec(A, B.izqdo(), R);
        interseccionar_rec(A, B.drcho(), R);
    }
}