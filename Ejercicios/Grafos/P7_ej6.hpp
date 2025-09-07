#include "../../Algoritmos/alg_grafoPMC.h"

template <typename tCoste>
GrafoP<tCoste> tren_y_bus(GrafoP<tCoste>& T, GrafoP<tCoste>& B, typename GrafoP<tCoste>::vertice estacion) {
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> mc_tren, mc_bus;
    matriz<vertice> m_vert;

    mc_tren = Floyd(T, m_vert);
    mc_bus = Floyd(B, m_vert);

    GrafoP<tCoste> G(T.numVert());
    for (vertice i = 0; i < T.numVert(); i++) {
        for (vertice j = 0; j < T.numVert(); j++) {
            G[i][j] = std::min(std::min(mc_tren[i][j], mc_bus[i][j]),
                               std::min(mc_bus[i][estacion] + mc_tren[estacion][j], mc_tren[i][estacion] + mc_bus[estacion][j]));
        }
    }

    return G;
}