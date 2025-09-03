#include "../../Algoritmos/grafoPMC.h"

template <typename tCoste>
vector<tCoste> DijkstraInv(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice destino, vector<typename GrafoP<tCoste>::vertice>& P)
// Calcula los caminos de coste mínimo entre todos los
// vértices del grafo G y un destino.
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v, w;
    const size_t n = G.numVert();
    vector<bool> S(n, false);  // Conjunto de vértices vacío.
    vector<tCoste> D;          // Costes mínimos desde origen.

    for (int i = 0; i < n; i++) {
        D[i] = G[i][destino];
    }

    D[destino] = 0;  // Coste origen-origen es 0.
    P = vector<vertice>(n, destino);

    // Calcular caminos de coste mínimo hasta cada vértice.
    S[destino] = true;  // Incluir vértice origen en S.
    for (size_t i = 1; i <= n - 2; i++) {
        // Seleccionar vértice w no incluido en S
        // con menor coste desde origen.
        tCoste costeMin = GrafoP<tCoste>::INFINITO;
        for (v = 0; v < n; v++)
            if (!S[v] && D[v] <= costeMin) {
                costeMin = D[v];
                w = v;
            }
        S[w] = true;  // Incluir vértice w en S.
        // Recalcular coste hasta cada v no incluido en S a través de w.
        for (v = 0; v < n; v++)
            if (!S[v]) {
                tCoste Owv = suma(D[w], G[v][w]);
                if (Owv < D[v]) {
                    D[v] = Owv;
                    P[v] = w;
                }
            }
    }
    return D;
}