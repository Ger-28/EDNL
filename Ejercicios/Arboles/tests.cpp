#include <iostream>

#include "P1_ej1.hpp"
#include "P1_ej3.hpp"
#include "P1_ej7.hpp"  // && P1_ej2.hpp

#include "P2_ej1.hpp"

#include "P3_ej1.hpp"
#include "P3_ej3.hpp"

using namespace std;

int main() {
    Abin<int> A, B;
    Agen<int> C;

    A.insertarRaiz(1);
    A.insertarHijoDrcho(A.raiz(), 34);
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()), 2);
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()), 3);
    A.insertarHijoIzqdo(A.raiz(), 5);
    // A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 7);

    B.insertarRaiz(1);
    B.insertarHijoDrcho(B.raiz(), 34);
    B.insertarHijoDrcho(B.hijoDrcho(B.raiz()), 2);
    B.insertarHijoIzqdo(B.hijoDrcho(B.raiz()), 3);
    B.insertarHijoIzqdo(B.raiz(), 5);

    C.insertarRaiz(1);
    C.insertarHijoIzqdo(C.raiz(), 2);
    C.insertarHermDrcho(C.hijoIzqdo(C.raiz()), 3);
    C.insertarHermDrcho(C.hijoIzqdo(C.raiz()), 4);
    C.insertarHermDrcho(C.hijoIzqdo(C.raiz()), 5);
    C.insertarHijoIzqdo(C.hijoIzqdo(C.raiz()), 6);
    C.insertarHijoIzqdo(C.hijoIzqdo(C.hijoIzqdo(C.raiz())), 6);

    cout << "Número de hijos del árbol: " << contar_nodos_abin(A) << endl;
    cout << "Altura del arbol: " << calcular_altura_abin(A) << endl;
    cout << "Profundidad del nodo n: " << calcular_profundidad_abin(A.hijoDrcho(A.raiz()), A) << endl;
    if (es_pseudocompleto(A)) {
        cout << "El arbol es pseudocompleto." << endl;
    } else {
        cout << "El arbol no es pseudocompleto." << endl;
    }
    if (son_similares(A, B)) {
        cout << "A y B son similares" << endl;
    } else {
        cout << "A y B son distintos" << endl;
    }
    cout << "Grado del arbol general: " << calcular_grado(C) << endl;
    cout << "Desequilibrio del arbol general: " << calcular_desequilibrio_gen(C) << endl;

    return 0;
}