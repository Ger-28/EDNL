#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
void tren_avion_bus(GrafoP<tCoste>& T, GrafoP<tCoste>& B, GrafoP<tCoste>& A, typename GrafoP<tCoste>::vertice origen,
                    typename GrafoP<tCoste>::vertice destino, tCoste taxi_tb, tCoste taxi_a) {
    typedef typename GrafoP<tCoste>::vertice vertice;

    GrafoP<tCoste> G(T.numVert() * 3);

    // Tren
    for (vertice i = 0; i < T.numVert(); i++) {
        for (vertice j = 0; j < T.numVert(); j++) {
            G[i][j] = T[i][j];
        }
    }

    // Bus
    for (vertice i = T.numVert(), k = 0; i < T.numVert() * 2; i++, k++) {
        for (vertice j = T.numVert, z = 0; j < T.numVert() * 2; j++, z++) {
            G[i][j] = B[k][z];
        }
    }

    // Avión
    for (vertice i = T.numVert() * 2, k = 0; i < G.numVert(); i++, k++) {
        for (vertice j = T.numVert() * 2, z = 0; j < G.numVert(); j++, z++) {
            G[i][j] = A[k][z];
        }
    }

    // Tren - Bus
    for (vertice i = 0; i < T.numVert(); i++) {
        for (vertice j = T.numVert(); j < T.numVert() * 2; j++) {
            if (i == j - T.numVert()) {
                G[i][j] = taxi_tb;
            }
        }
    }

    // Tren - Avión
    for (vertice i = 0; i < T.numVert(); i++) {
        for (vertice j = T.numVert() * 2; j < G.numVert(); j++) {
            if (i == j - T.numVert() * 2) {
                G[i][j] = taxi_a;
            }
        }
    }

    // Bus - Tren
    for (vertice i = T.numVert(); i < T.numVert() * 2; i++) {
        for (vertice j = 0; j < T.numVert(); j++) {
            if (j == i - T.numVert()) {
                G[i][j] = taxi_tb;
            }
        }
    }

    // Bus - Avión
    for (vertice i = T.numVert(); i < T.numVert() * 2; i++) {
        for (vertice j = T.numVert() * 2; j < G.numVert(); j++) {
            if (i == j - T.numVert()) {
                G[i][j] = taxi_a;
            }
        }
    }

    // Avión - Tren
    for (vertice i = T.numVert() * 2; i < G.numVert(); i++) {
        for (vertice j = 0; j < T.numVert(); j++) {
            if (j == i - T.numVert() * 2) {
                G[i][j] = taxi_a;
            }
        }
    }

    // Avión - Bus
    for (vertice i = T.numVert() * 2; i < G.numVert(); i++) {
        for (vertice j = T.numVert(); j < T.numVert() * 2; j++) {
            if (j == i - T.numVert()) {
                G[i][j] = taxi_a;
            }
        }
    }

    std::vector<vertice> P;
    std::vector<tCoste> DT, DB, DA, DinvT, DinvB, DinvA;

    DT = Dijkstra(G, origen, P);
    DB = Dijkstra(G, origen + T.numVert(), P);
    DA = Dijkstra(G, origen + T.numVert() * 2, P);

    tCoste min_tren = std::min(DT[destino], std::min(DT[destino + T.numVert()], DT[destino + T.numVert() * 2]));
    tCoste min_bus = std::min(DB[destino], std::min(DB[destino + T.numVert()], DB[destino + T.numVert() * 2]));
    tCoste min_avion = std::min(DA[destino], std::min(DA[destino + T.numVert()], DA[destino + T.numVert() * 2]));

    tCoste min_total = std::min(min_tren, std::min(min_bus, min_avion));
}