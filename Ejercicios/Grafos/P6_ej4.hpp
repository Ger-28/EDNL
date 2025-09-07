#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
struct carretera {
    typename GrafoP<tCoste>::vertice c1, c2;
};

template <typename tCoste>
GrafoP<tCoste> Zuelandia(const GrafoP<tCoste>& G, vector<typename GrafoP<tCoste>::vertice> c_tomadas, vector<carretera<tCoste>> c_cortadas,
                         typename GrafoP<tCoste>::vertice capital) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    unsigned n = G.numVert();
    GrafoP<tCoste> matriz_costes = G;

    for (unsigned int i = 0; i < c_cortadas.size(); i++) {
        matriz_costes[c_cortadas[i].c1][c_cortadas[i].c2] = GrafoP<tCoste> INFINITO;
    }

    for (unsigned int i = 0; i < c_tomadas.size(); i++) {
        vertice c = c_tomadas[i];
        for (vertice j = 0; j < n; j++) {
            matriz_costes[c][j] = GrafoP<tCoste>::INFINITO;
            matriz_costes[j][c] = GrafoP<tCoste>::INFINITO;
        }
    }

    vector<tCoste> Dinv(n);
    vector<tCoste> D(n);
    vector<vertice> P(n);

    Dinv = DijkstraInv(matriz_costes, capital, P);
    D = Dijkstra(matriz_costes, capital, P);

    for (vertice i = 0; i < n; i++) {
        for (vertice j = 0; j < n; j++) {
            matriz_costes[i][j] = suma(Dinv[i], D[j]);
        }
    }

    return matriz_costes;
}