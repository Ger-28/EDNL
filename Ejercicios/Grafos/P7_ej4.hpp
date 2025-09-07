#include "../../Algoritmos/alg_grafoPMC.h"

struct parte {
    unsigned ciudad;
    size_t carga;
};

template <typename tCoste>
tCoste calcular_distancia(GrafoP<tCoste>& G, std::vector<parte> partes, typename GrafoP<tCoste>::vertice capital) {
    typedef typename GrafoP<tCoste>::vertice vertice;

    vector<vertice> P;
    vector<tCoste> D = Dijkstra(G, capital, P);
    vector<tCoste> Dinv = DijkstraInv(G, capital, P);

    tCoste total;

    for (unsigned i = 0; i < partes.size(); i++) {
        total += D[partes[i].ciudad] + Dinv[partes[i].ciudad];
    }

    return total;
}