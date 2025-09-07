#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
void tren_bus_taxi_2(GrafoP<tCoste>& T, GrafoP<tCoste>& B, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
                     tCoste coste_taxi) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> G(T.numVert() + B.numVert());

    for (vertice i = 0; i < T.numVert(); i++) {
        for (vertice j = 0; j < T.numVert(); j++) {
            G[i][j] = T[i][j];
        }
    }

    for (vertice i = B.numVert(), k = 0; i < G.numVert(); i++, k++) {
        for (vertice j = B.numVert(), z = 0; j < G.numVert(); j++, z++) {
            G[i][j] = B[k][z];
        }
    }

    for (vertice i = 0; i < T.numVert(); i++) {
        for (vertice j = T.numVert(); j < G.numVert(); j++) {
            if (i != j - T.numVert()) {
                G[i][j] = GrafoP<tCoste>::INFINITO;
            } else {
                G[i][j] = coste_taxi;
            }
        }
    }

    for (vertice i = T.numVert(); i < G.numVert(); i++) {
        for (vertice j = 0; j < T.numVert(); j++) {
            if (j != i - T.numVert()) {
                G[i][j] = GrafoP<tCoste>::INFINITO;
            } else {
                G[i][j] = coste_taxi;
            }
        }
    }

    std::vector<vertice> P;
    std::vector<tCoste> DT = Dijkstra(G, origen, P);
    std::vector<tCoste> DB = Dijkstra(G, origen + B.numVert(), P);

    tCoste min = std::min(DT[destino], DB[destino]);
    min = std::min(std::min(DT[destino + T.numVert()], DB[destino + T.numVert()]), min);
}