#ifndef IHEURISTIC_CLASS_H
#define IHEURISTIC_CLASS_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

using namespace std;

class IHeuristic {
public:
    virtual int Algo(pair<int, int> &p1, pair<int, int> &p2) = 0;

    virtual int Calculate(vector <vector<int> >, vector <vector<int> >) = 0;

    virtual ~IHeuristic(){};
};
#endif