#include "../../Algoritmos/ABIN.hpp"
#include "P1_ej2.hpp"

struct expresion {
    char operador;
    float operando;
};

float resolver_expresion(Abin<expresion>& A) {
    if (A.arbolVacio()) {
        return 0;
    } else {
        return resolver_expresion_rec(A.raiz(), A);
    }
}

float resolver_expresion_rec(Abin<expresion>::nodo n, Abin<expresion>& A) {
    /*
    Alternativa más eficiente:
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO){
        return A.elemento(n).operando;
    }
    */
    if (calcular_altura_abin_rec(n, A) == 0) {
        return A.elemento(n).operando;
    } else {
        switch (A.elemento(n).operador) {
            case '+':
                return resolver_expresion_rec(A.hijoIzqdo(n), A) + resolver_expresion_rec(A.hijoDrcho(n), A);
                break;
            case '-':
                return resolver_expresion_rec(A.hijoIzqdo(n), A) - resolver_expresion_rec(A.hijoDrcho(n), A);
                break;
            case 'x':
                return resolver_expresion_rec(A.hijoIzqdo(n), A) * resolver_expresion_rec(A.hijoDrcho(n), A);
                break;
            case '/':
                return resolver_expresion_rec(A.hijoIzqdo(n), A) / resolver_expresion_rec(A.hijoDrcho(n), A);
                break;
        }
    }
}