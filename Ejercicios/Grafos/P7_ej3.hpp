#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
std::vector<tCoste> distribuir_stock(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice centro, std::vector<tCoste> capacidades,
                                     std::vector<float> subvenciones, tCoste cantidad) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> D = G;

    for (vertice i = 0; i < D.numVert(); i++) {
        for (vertice j = 0; j < D.numVert(); j++) {
            D[i][j] -= subvenciones[j] / 100 * D[i][j];
        }
    }

    std::vector<vertice> P;
    std::vector<tCoste> D = Dijkstra(D, centro, P);
    std::vector<tCoste> sol(G.numVert(), 0);

    while (cantidad > 0) {
        tCoste min = GrafoP<tCoste>::INFINITO;
        vertice c_min = centro;

        for (vertice i = 0; i < D.size(); i++) {
            if (i != centro && D[i] < min && sol[i] == 0 && capacidades[i] > 0) {
                min = D[i];
                c_min = i;
            }
        }

        if (capacidades[min] >= cantidad) {
            sol[min] = cantidad;
            cantidad = 0;
        }

        else {
            sol[min] = capacidades[min];
            cantidad -= capacidades[min];
        }
    }

    return sol;
}
