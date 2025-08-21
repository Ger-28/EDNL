#include "../../Algoritmos/AGEN.hpp"

void podar_rama_rec(typename Agen<int>::nodo n, Agen<int>& A);
void podar_agen_rec(typename Agen<int>::nodo n, Agen<int>& A, int x);

void podar_agen(Agen<int>& A, int x) {
    podar_agen_rec(A.raiz(), A, x);
}

void podar_agen_rec(typename Agen<int>::nodo n, Agen<int>& A, int x) {
    if (n != Agen<int>::NODO_NULO) {
        if (A.elemento(n) == x) {
            podar_rama_rec(n, A);
            // Si se necesita borrar también el nodo del elemento X:

            // Se comprueba si n es la raíz, ya que no se puede acceder al hijo izquierdo de un nodo nulo.
            if (A.raiz() == n) {
                A.eliminarRaiz();
            } else {
                // Si es el hijo izquierdo de un nodo que no es la raíz, se elimina con el propio método.
                if (A.hijoIzqdo(A.padre(n)) == n) {
                    A.eliminarHijoIzqdo(A.padre(n));
                }
                // Si no, se busca entre sus hermanos.
                else {
                    typename Agen<int>::nodo aux = A.hijoIzqdo(A.padre(n));
                    while (aux != Agen<int>::NODO_NULO) {
                        if (A.hermDrcho(aux) == n) {
                            A.eliminarHermDrcho(aux);
                            aux = Agen<int>::NODO_NULO;
                        }
                    }
                }
            }
            // Esto de aquí arriba es una parafernalia pero no encuentro otra forma
            // ya que no existe un método para que un nodo se borre a sí mismo.

        } else {
            typename Agen<int>::nodo hijo = A.hijoIzqdo(n);

            while (hijo != Agen<int>::NODO_NULO) {
                podar_agen_rec(hijo, A, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void podar_rama_rec(typename Agen<int>::nodo n, Agen<int>& A) {
    typename Agen<int>::nodo hijo = A.hijoIzqdo(n);

    while (hijo != Agen<int>::NODO_NULO) {
        if (A.hijoIzqdo(hijo) != Agen<int>::NODO_NULO) {
            podar_rama_rec(A.hijoIzqdo(n), A);
        } else {
            A.eliminarHijoIzqdo(n);
            hijo = A.hijoIzqdo(n);
        }
    }
}