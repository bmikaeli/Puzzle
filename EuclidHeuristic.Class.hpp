#ifndef EuclidHeuristic_H
#define EuclidHeuristic_H

#include "IHeuristic.Class.hpp"

class EuclidHeuristic : public IHeuristic {

public :
    short Calculate(vector <vector<short> >, vector <vector<short> >);

    short Algo(pair<short, short> &p1, pair<short, short> &p2);

    EuclidHeuristic(void);

    ~EuclidHeuristic(void);
};

#endif