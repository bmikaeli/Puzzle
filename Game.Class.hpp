#ifndef GAME_CLASS_H
#define GAME_CLASS_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include "IHeuristic.Class.hpp"

using namespace std;

class Game {
public :
    struct Node {
        int F; // F = G + H
        int G; // the movement cost from start to here
        int H; // the estimated movement cost to move from here to the end (Calculed by the heuristic)
        vector <vector<int> > parent;
    };

    Game();

    void Search();

    void PrintPlate(vector <vector<int> >);

    void PrintInfo();
    void meilleurJeuListeOuverte(vector<vector<int > > &retour);

    void PrintParcours();
    void setHeuristic(IHeuristic &);

    ~Game();

private:
    vector <vector<int> > Plate;
    vector <vector<int> > PlateEnd;
    vector <vector<int> > PlateBegin;
    map <vector<vector<int> >, Node> openList;
    map <vector<vector<int> >, Node> closedlist;
    int nbLines;
    int nbRows;
    IHeuristic *heuristic;
};
#endif