#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
bool es_aciclico(const GrafoP<tCoste>& G) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> matriz_vertices(G.numVert());
    matriz<tCoste> matriz_costes = FloydInv(G, matriz_vertices);

    bool es_aciclico = true;
    for (vertice i = 0; i < G.numVert() && es_aciclico; i++) {
        if (matriz_costes[i][i] != GrafoP<tCoste>::INFINITO) {
            es_aciclico = false;
        }
    }

    return es_aciclico;
}