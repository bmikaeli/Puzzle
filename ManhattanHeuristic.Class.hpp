#include "IHeuristic.Class.hpp"

class ManhattanHeuristic : public IHeuristic {

public :
    int Calculate(vector <vector<int> >, vector <vector<int> >);

    ManhattanHeuristic(void);

    ~ManhattanHeuristic(void);
};