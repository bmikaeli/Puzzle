#ifndef ManhattanHeuristic_H
#define ManhattanHeuristic_H

#include "IHeuristic.Class.hpp"

class ManhattanHeuristic : public IHeuristic {

public :
    short Calculate(vector <vector<short> >, vector <vector<short> >);

    short Algo(pair<short, short> &p1, pair<short, short> &p2);

    ManhattanHeuristic(void);

    ~ManhattanHeuristic(void);
};

#endif