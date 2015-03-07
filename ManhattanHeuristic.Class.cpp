#include "ManhattanHeuristic.Class.hpp"

ManhattanHeuristic::~ManhattanHeuristic() {
}

ManhattanHeuristic::ManhattanHeuristic() {
}

inline Point localiserPositionFinale(uchar valeur, const Jeu &etatFini) {
    for (uchar i = 0; i < nombre_de_lignes; ++i) {
        for (uchar j = 0; j < nombre_de_colonnes; ++j) {
            if (etatFini[i][j] == valeur) {
                return Point(i, j);
            }
        }
    }
    return Point(0, 0);
}

int ManhattanHeuristic::Algo(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int ManhattanHeuristic::Calculate(vector < vector<int> > start, vector < vector<int> > end) {
    int k = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            k += this->algo(i, j, localiserPositionFinale(jeu[i][j], etatFini));
        }
    }
    return k;
}