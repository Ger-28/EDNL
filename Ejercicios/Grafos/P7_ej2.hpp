#include <vector>
#include "../../Algoritmos/alg_grafoPMC.h"

struct pared {
    typename GrafoP<unsigned>::vertice c1, c2;
};

struct casilla {
    int f, c;
};

struct caminoSolucion {
    GrafoP<unsigned>::tCamino recorrido;
    unsigned coste;
};

casilla nodo_a_casilla(unsigned nodo, unsigned n) {
    casilla aux;
    aux.f = nodo / n;
    aux.c = nodo % n;
}

unsigned casilla_a_nodo(casilla c, unsigned n) {
    return c.f * n + c.c;
}

bool adyacentes(casilla c1, casilla c2) {
    return (abs(c1.f - c2.f) + abs(c1.c - c2.f)) == 1;
}

caminoSolucion resolver_laberinto(unsigned n, std::vector<pared> paredes, casilla c_entrada, casilla c_salida) {
    GrafoP<unsigned> G(n * n);
    typename GrafoP<unsigned>::vertice n_entrada = casilla_a_nodo(c_entrada, n);
    typename GrafoP<unsigned>::vertice n_salida = casilla_a_nodo(c_salida, n);

    for (unsigned i = 0; i < n * n; i++) {
        for (unsigned j = 0; j < n * n; j++) {
            if (i == j) {
                G[i][j] = 0;
            } else if (adyacentes(nodo_a_casilla(i, n), nodo_a_casilla(j, n))) {
                G[i][j] = 1;
                G[j][i] = 1;
            } else {
                G[i][j] = GrafoP<unsigned>::INFINITO;
                G[j][i] = GrafoP<unsigned>::INFINITO;
            }
        }
    }

    for (unsigned i = 0; i < paredes.size(); i++) {
        G[paredes[i].c1][paredes[i].c2] = GrafoP<unsigned>::INFINITO;
        G[paredes[i].c1][paredes[i].c2] = GrafoP<unsigned>::INFINITO;
    }

    std::vector<typename GrafoP<unsigned>::vertice> P;
    std::vector<unsigned> D = Dijkstra(G, n_entrada, P);
    GrafoP<unsigned>::tCamino ruta = camino<GrafoP<unsigned>::vertice>(n_entrada, n_salida, P);

    caminoSolucion s;
    s.recorrido = ruta;
    s.coste = ruta.tama() - 1;

    return s;
}