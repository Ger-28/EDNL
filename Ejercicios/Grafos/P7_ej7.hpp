#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
void tre_bus_y_taxi(GrafoP<tCoste>& T, GrafoP<tCoste>& B, typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2,
                    typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    std::vector<vertice> P;

    std::vector<tCoste> D = Dijkstra(T, origen, P);
    std::vector<tCoste> Dinv = DijkstraInv(B, destino, P);

    tCoste min = std::min(D[cambio1] + Dinv[cambio1], D[cambio2] + Dinv[cambio2]);
}