#include "Game.Class.hpp"


inline uint distanceManhattan(const Point &p1, const Point &p2) {
}

inline uint heuristiqueManathan(const Jeu &jeu, const Jeu &etatFini) {

}

void Game::PrintPlate(vector < vector<int> > plate) {
    cout << endl;
    for (int i = 0; i < this->nbLines; ++i) {
        for (int j = 0; j < this->nbRows; ++j) {
            cout << plate[i][j] << " ";
        }
        cout << endl;
    }
}


Game::Game() {
    cout << "The Game is now starting" << endl;

    this->nbLines = 3;
    this->nbRows = 3;
    int lignes[this->nbLines][this->nbRows] = {
            {6, 3, 1},
            {8, 0, 2},
            {7, 4, 5}
    };
    cout << "Storing User's map" << endl;
    for (int i = 0; i < this->nbLines; ++i) {
        this->PlateBegin.push_back(vector<int>(this->nbRows));
        for (int j = 0; j < this->nbRows; ++j) {
            this->PlateBegin[i][j] = lignes[i][j];
        }
    }
    cout << "Storing resolve map" << endl;

    for (int i = 0; i < this->nbLines; ++i) {
        this->PlateEnd.push_back(vector<int>(this->nbRows));
        for (int j = 0; j < this->nbRows; ++j) {
            this->PlateEnd[i][j] = this->nbLines * i + j;
        }
    }
    this->PrintPlate(this->PlateBegin);
    this->PrintPlate(this->PlateEnd);

    Node node;
    node.F = 0;
    node.G = 0;
    node.H = this->heuristic->Calculate(this->PlateBegin, this->PlateEnd);
    node.parent = this->PlateBegin;
    openList[this->PlateBegin] = node;
}

Game::~Game() {
    cout << "The Game is now finished" << endl;
}


void Game::PrintInfo() {
}

void Game::PrintParcours() {
}

void Game::Search() {


}