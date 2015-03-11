#ifndef ManhattanHeuristic_H
#define ManhattanHeuristic_H

#include "IHeuristic.Class.hpp"

class ManhattanHeuristic : public IHeuristic {

public :
    virtual size_t Calculate(size_t n, size_t pos, vector<size_t> map, size_t size);

    ManhattanHeuristic(void);

    ~ManhattanHeuristic(void);
};

#endif