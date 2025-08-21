#include <iostream>
#include <vector>
#include "../../Algoritmos/ABB.hpp"

template <typename T>
void equilibrar(const Abb<T>& A, Abb<T>& B) {
    std::vector<T> elementos_ordenados;
    rellenar_vector(A, elementos_ordenados);
    std::sort(elementos_ordenados.begin(), elementos_ordenados.end());
    equilibrar_rec(A, B, elementos_ordenados, elementos_ordenados.size(), 0);
}

template <typename T>
void rellenar_vector(const Abb<T>& A, std::vector<T>& elementos_ordenados) {
    if (!A.vacio()) {
        elementos_ordenados.push_back(A.elemento());
        rellenar_vector(A.izqdo(), elementos_ordenados);
        rellenar_vector(A.drcho(), elementos_ordenados);
    }
}

template <typename T>
void equilibrar_rec(const Abb<T>& A, Abb<T>& B, std::vector<T> elementos_ordenados, unsigned fin, unsigned ini) {
    if (fin != ini) {
        unsigned pos = (fin - ini) / 2 + ini;
        B.insertar(elementos_ordenados[pos]);
        equilibrar_rec(A, B, elementos_ordenados, pos, ini);
        equilibrar_rec(A, B, elementos_ordenados, fin, pos + 1);
    }
}

template <typename T>
void imprimir_rec(const Abb<T>& A) {
    if (!A.vacio()) {
        imprimir_rec(A.izqdo());
        std::cout << A.elemento() << " ";
        imprimir_rec(A.drcho());
    }
}