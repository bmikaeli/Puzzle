#include "EuclidHeuristic.Class.hpp"

EuclidHeuristic::~EuclidHeuristic(void) {
}

EuclidHeuristic::EuclidHeuristic(void) {

}

pair<short, short> localiserPositionFinale2(short value, vector <vector<short>> GameAtEnd) {

    for (unsigned long i = 0; i < GameAtEnd.size(); ++i) {
        for (unsigned long j = 0; j < GameAtEnd.begin()->size(); ++j) {
            if (GameAtEnd[i][j] == value) {
                return pair<short, short>(i + 1, j + 1);
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

    for (unsigned long i = 0; i < start.size() * start.begin()->size(); ++i) {
            pair<short, short> finalePos = localiserPositionFinale2(i, end);

            pair<short, short> currPos = localiserPositionFinale2(i, start);

            k += this->Algo(currPos, finalePos);
            cout << "nb : " << i <<  "    :   "<< currPos.first << " " << currPos.second << " "<< finalePos.first << " " << finalePos.second << endl;
        cout << "k : " << k << endl;
    }
    cout << "k : " << k << endl;
    cout << endl;
    return k;
}