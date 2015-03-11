#ifndef IHEURISTIC_CLASS_H
#define IHEURISTIC_CLASS_H
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

class IHeuristic {
public:
    virtual size_t Calculate(size_t n, size_t pos, vector<size_t> map, size_t size) = 0;

//    IHeuristic(){};

     virtual ~IHeuristic(){};
};
#endif