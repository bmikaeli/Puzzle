#ifndef ManhattanHeuristic_H
#define ManhattanHeuristic_H

#include "IHeuristic.Class.hpp"

class ManhattanHeuristic : public IHeuristic {

public :
    int Calculate(vector <vector<int> >, vector <vector<int> >);

    int Algo(pair<int, int> &p1, pair<int, int> &p2);

    ManhattanHeuristic(void);

    ~ManhattanHeuristic(void);
};

#endif