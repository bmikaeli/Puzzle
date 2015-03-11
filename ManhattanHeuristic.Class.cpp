#include "ManhattanHeuristic.Class.hpp"

ManhattanHeuristic::~ManhattanHeuristic(void) {
}

ManhattanHeuristic::ManhattanHeuristic(void) {

}

size_t ManhattanHeuristic::Calculate(size_t n, size_t pos, vector<size_t> map, size_t size) {
    size_t						p = 0;
    size_t						i = 0;

    while (map[i] != n)
        i++;
    if ((i % size) > (pos % size))
        p += (i % size) - (pos % size);
    else
        p += (pos % size) - (i % size);
    if ((i / size) > (pos / size))
        p += (i / size) - (pos / size);
    else
        p += (pos / size) - (i / size);
    return (p);
}