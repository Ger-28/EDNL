#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
struct viaje {
    typename GrafoP<tCoste>::vertice origen, destino;
    float coste;
};

template <typename tCoste>
matriz<tCoste> FloydMax(const GrafoP<tCoste>& G, matriz<typename GrafoP<tCoste>::vertice>& P) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    const size_t n = G.numVert();
    matriz<tCoste> A(n);

    P = matriz<vertice>(n);
    for (vertice i = 0; i < n; i++) {
        A[i] = G[i];
        A[i][i] = 0;
        P[i] = vector<vertice>(n, i);
    }

    for (vertice k = 0; k < n; k++)
        for (vertice i = 0; i < n; i++)
            for (vertice j = 0; j < n; j++) {
                tCoste ikj = suma(A[i][k], A[k][j]);
                if (ikj > A[i][j] && ikj != GrafoP<tCoste>::INFINITO) {
                    A[i][j] = ikj;
                    P[i][j] = k;
                }
            }
    return A;
}

template <typename tCoste>
viaje<tCoste> viaje_mas_caro(const GrafoP<tCoste>& G) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<tCoste> S = G;
    matriz<vertice> m_vert;
    matriz<tCoste> m_costes = FloydMax(G, m_vert);
    viaje<tCoste> solucion;
    solucion.coste = solucion.destino = solucion.origen = 0;

    for (vertice i = 0; i < G.numVert(); i++) {
        for (vertice j = 0; j < G.numVert(); j++) {
            if (m_costes[i][j] > solucion.coste) {
                solucion.coste = m_costes[i][j];
                solucion.origen = i;
                solucion.destino = j;
            }
        }
    }

    return viaje;
}