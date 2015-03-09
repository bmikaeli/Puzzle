#ifndef GAME_CLASS_H
#define GAME_CLASS_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <stdlib.h>
#include "IHeuristic.Class.hpp"

using namespace std;

class Game {
public :
    struct Node {
        short F; // F = G + H
        short G; // the movement cost from start to here
        short H; // the estimated movement cost to move from here to the end (Calculed by the heuristic)
        vector <vector<short> > parent;
    };

    Game();

    void Search();
    void PrshortPlate(vector <vector<short> >);
    pair<short, short>findMovingPart(vector<vector<short> >);
    void PrshortInfo();
    void findBestMoveInOpenList(vector<vector<short > > &retour);
    void AddToOpenList(const vector<vector<short> > &jeu, const Node &nouveauNoeud, const Node &noeudRemplace);
    void PrshortParcours();
    vector<vector<short> > getStartMap();
    vector<vector<short> > getEndMap();
    void setHeuristic(IHeuristic &);
    void storeResolvedMap();
    void Parse(string line);
    ~Game();

private:
    vector <vector<short> > PlateEnd;
    vector <vector<short> > PlateBegin;
    map <vector<vector<short> >, Node> openList;
    map <vector<vector<short> >, Node> closedlist;
    short nbLines;
    bool resolved;
    short nbRows;
    IHeuristic *heuristic;
};
#endif