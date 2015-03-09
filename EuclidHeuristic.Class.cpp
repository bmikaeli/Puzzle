#include "EuclidHeuristic.Class.hpp"

EuclidHeuristic::~EuclidHeuristic(void) {
}

EuclidHeuristic::EuclidHeuristic(void) {

}

pair<short, short> localiserPositionFinale2(short value, vector <vector<short>> GameAtEnd) {

    for (unsigned long i = 0; i < GameAtEnd.size(); ++i) {
        for (unsigned long j = 0; j < GameAtEnd.begin()->size(); ++j) {
            if (GameAtEnd[i][j] == value) {
                return pair<short, short>(i, j);
            }
        }
    }
    return pair<short, short>(0, 0);
}

short EuclidHeuristic::Algo(pair<short, short> & p1, pair<short, short> & p2) {
    return (abs(sqrt(pow(p1.first - p2.first, 2) + pow(p1.first - p2.first, 2))));
}

short EuclidHeuristic::Calculate(vector < vector<short> > start, vector < vector<short> > end) {
    short k = 0;

    for (unsigned long i = 0; i < start.size(); ++i) {
        for (unsigned long j = 0; j < start.begin()->size(); ++j) {

            pair<short, short> finalePos = localiserPositionFinale2(start[i][j], end);
            pair<short, short> currPos = pair<short, short>(i, j);

            k += this->Algo(currPos, finalePos);
        }
    }
    return k;
}