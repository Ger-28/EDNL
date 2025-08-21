#include <iostream>

#include "../../Algoritmos/ABIN_E-S.hpp"
#include "../../Algoritmos/AGEN_E-S.hpp"

#include "P1_ej1.hpp"
#include "P1_ej3.hpp"
#include "P1_ej7.hpp"  // && P1_ej2.hpp

#include "P2_ej1.hpp"

#include "P3_ej1.hpp"
#include "P3_ej3.hpp"
#include "P3_ej4.hpp"

#include "P4_ej1.hpp"
#include "P4_ej2.hpp"

#include "P4_ej3.hpp"
#include "P4_ej4.hpp"
#include "P4_ej5.hpp"

using namespace std;

int main() {
    Abin<int> A, B;
    Agen<int> C;
    Abb<int> D;

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
    C.insertarHijoIzqdo(C.hijoIzqdo(C.hijoIzqdo(C.raiz())), 7);
    C.insertarHermDrcho(C.hijoIzqdo(C.hijoIzqdo(C.hijoIzqdo(C.raiz()))), 8);

    D.insertar(7);
    D.insertar(5);
    D.insertar(12);
    D.insertar(9);
    D.insertar(17);
    D.insertar(8);
    D.insertar(11);
    D.insertar(10);

    Abb<int> E = D;
    Abb<int> F;
    cout << endl;
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
    cout << endl;

    cout << "Grado del arbol general: " << calcular_grado(C) << endl;
    cout << "Desequilibrio del arbol general: " << calcular_desequilibrio_gen(C) << endl;

    cout << endl;

    cout << "Arbol general antes de podar: " << endl;
    imprimirAgen(C);

    cout << endl;

    cout << "Arbol general despues de podar desde 2" << endl;
    podar_agen(C, 1);
    imprimirAgen(C);

    cout << endl;

    cout << "ABB antes de podar: " << endl;
    imprimirAbb(D);

    cout << endl;

    cout << "ABB despues de podar desde 9" << endl;
    podar_abb_rec(D, 9);
    imprimirAbb(D);

    cout << endl;

    cout << "ABB antes de equilibrar: " << endl;
    imprimirAbb(E);

    cout << endl;

    cout << "ABB despues de equilibrar: " << endl;
    equilibrar(E, F);
    imprimirAbb(F);

    cout << endl;

    cout << "Elementos ordenados del ABB equilibrado: ";
    imprimir_rec(F);
    cout << endl << endl;

    Abb<int> G;
    G.insertar(18);
    G.insertar(5);
    G.insertar(9);

    cout << "Abb G: " << endl;
    imprimirAbb(G);

    cout << endl;

    cout << "Unión de F y G: " << endl;
    imprimirAbb(unir(F, G));

    cout << endl;

    cout << "Interseccion de F y G: " << endl;
    imprimirAbb(interseccionar(F, G));

    cout << endl;

    cout << "Resta de la unión e intersección de F y G: " << endl;
    imprimirAbb(restar_ui(F, G));

    cout << endl;

    return 0;
}