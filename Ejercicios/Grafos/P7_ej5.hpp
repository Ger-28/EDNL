#include "../../Algoritmos/alg_grafoPMC.h"

enum alergias { Coche, Tren, Avion };

template <typename tCoste>
std::vector<tCoste> calcular_viaje(GrafoP<tCoste>& A, GrafoP<tCoste>& B, typename GrafoP<tCoste>::vertice origen) {
    std::vector<typename GrafoP<tCoste>::vertice> P;
    GrafoP<tCoste> T(A.numVert());

    for (unsigned i = 0; i < T.numVert(); i++) {
        for (unsigned j = 0; j < T.numVert(); j++) {
            T[i][j] = std::min(A[i][j], B[i][j]);
        }
    }

    return Dijkstra(T, origen, P);
}

template <typename tCoste>
std::vector<bool> ciudades_a_visitar(GrafoP<tCoste>& C, GrafoP<tCoste>& T, GrafoP<tCoste>& A, typename GrafoP<tCoste>::vertice origen,
                                     alergias alergia, double dinero) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    std::vector<tCoste> D;
    std::vector<bool> ciudades_posibles(C.numVert(), false);

    switch (alergia) {
        case Coche:
            D = calcular_viaje(T, A, origen);
            break;
        case Tren:
            D = calcular_viaje(C, A, origen);
            break;
        case Avion:
            D = calcular_viaje(C, T, origen);
            break;
    }

    for (unsigned i = 0; i < D.size(); i++) {
        if (dinero <= D[i]) {
            ciudades_posibles[i] = true;
        }
    }

    return ciudades_posibles;
}