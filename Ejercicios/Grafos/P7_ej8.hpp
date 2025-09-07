#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
tCoste solo_un_transbordo(GrafoP<tCoste>& T, GrafoP<tCoste>& B, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    std::vector<vertice> P;

    std::vector<tCoste> DT = Dijkstra(T, origen, P);
    std::vector<tCoste> DinvT = DijkstraInv(T, destino, P);
    std::vector<tCoste> DB = Dijkstra(B, origen, P);
    std::vector<tCoste> DinvB = DijkstraInv(B, destino, P);

    tCoste min_tren_bus = GrafoP<tCoste>::INFINITO;
    tCoste min_bus_tren = GrafoP<tCoste>::INFINITO;

    for (vertice i = 0; i < DT.size(); i++) {
        if (i != origen && i != destino) {
            if (DinvB[i] + DT[i] < min_tren_bus) {
                min_tren_bus = DT[i] + DinvB[i];
            }
            if (DinvT[i] + DB[i] < min_bus_tren) {
                min_bus_tren = DB[i] + DinvT[i];
            }
        }
    }

    return std::min(std::min(DT[destino], DB[destino]), std::min(min_bus_tren, min_tren_bus));
}