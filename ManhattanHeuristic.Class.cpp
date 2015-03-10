#include "ManhattanHeuristic.Class.hpp"

ManhattanHeuristic::~ManhattanHeuristic(void) {
}

ManhattanHeuristic::ManhattanHeuristic(void) {

}

pair<short, short> localiserPositionFinale(short value, vector <vector<short>> GameAtEnd) {

    for (unsigned long i = 0; i < GameAtEnd.size(); ++i) {
        for (unsigned long j = 0; j < GameAtEnd.begin()->size(); ++j) {
            if (GameAtEnd[i][j] == value) {
                return pair<short, short>(i + 1, j + 1);
            }
        }
    }
    return pair<short, short>(0, 0);
}

short ManhattanHeuristic::Algo(pair<short, short> & p1, pair<short, short> & p2) {
    return abs((p2.first - p1.first)) + abs((p2.second - p1.second));
}


short ManhattanHeuristic::Calculate(vector < vector<short> > start, vector < vector<short> > end) {
    short k = 0;

    for (unsigned long i = 0; i < start.size() * start.begin()->size(); ++i) {
        pair<short, short> finalePos = localiserPositionFinale(i, end);
        pair<short, short> currPos = localiserPositionFinale(i, start);

        k += this->Algo(currPos, finalePos);
    }
    return abs(k);
}