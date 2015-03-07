#include <iostream>

using namespace std;

class IHeuristic {
public:
    virtual int Algo(int, int, int, int);

    virtual int Calculate(vector <vector<int> >, vector <vector<int> >) = 0;
};