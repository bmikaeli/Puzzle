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
    virtual short Algo(pair<short, short> &p1, pair<short, short> &p2) = 0;

    virtual short Calculate(vector <vector<short> >, vector <vector<short> >) = 0;

    virtual ~IHeuristic(){};
};
#endif