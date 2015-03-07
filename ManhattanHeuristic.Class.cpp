#include "ManhattanHeuristic.Class.hpp"

ManhattanHeuristic::~ManhattanHeuristic(void) {
}

ManhattanHeuristic::ManhattanHeuristic(void) {

}

pair<int, int> localiserPositionFinale(int value, vector <vector<int> > GameAtEnd) {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (GameAtEnd[i][j] == value) {
                return pair<int, int>(i, j);
            }
        }
    }
    return pair<int, int>(0, 0);
}

int ManhattanHeuristic::Algo(pair<int, int> &p1, pair<int, int> &p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

int ManhattanHeuristic::Calculate(vector < vector<int> > start, vector < vector<int> > end) {
    int k = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            pair<int, int> finalePos = localiserPositionFinale(start[i][j], end);
            pair<int, int> currPos = pair<int, int>(i, j);

            k += this->Algo(currPos, finalePos);
        }
    }
    return k;
}