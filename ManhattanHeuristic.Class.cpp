#include "ManhattanHeuristic.Class.hpp"

ManhattanHeuristic::~ManhattanHeuristic(void) {
}

ManhattanHeuristic::ManhattanHeuristic(void) {

}

pair<short, short> localiserPositionFinale(short value, vector <vector<short> > GameAtEnd) {

    for (unsigned long i = 0; i < GameAtEnd.size(); ++i) {
        for (unsigned long j = 0; j < GameAtEnd.begin()->size(); ++j) {
            if (GameAtEnd[i][j] == value) {
                return pair<short, short>(i, j);
            }
        }
    }
    return pair<short, short>(0, 0);
}

short ManhattanHeuristic::Algo(pair<short, short> &p1, pair<short, short> &p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}

short ManhattanHeuristic::Calculate(vector < vector<short> > start, vector < vector<short> > end) {
    short k = 0;

    for (unsigned long i = 0; i < start.size(); ++i) {
        for (unsigned long j = 0; j < start.begin()->size(); ++j) {

            pair<short, short> finalePos = localiserPositionFinale(start[i][j], end);
            pair<short, short> currPos = pair<short, short>(i, j);

            k += this->Algo(currPos, finalePos);
        }
    }
    return k;
}