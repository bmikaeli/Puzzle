#include "Game.Class.hpp"

void Game::PrintPlate(vector < vector<int> > plate) {
    cout << endl;
    for (int i = 0; i < this->nbLines; ++i) {
        for (int j = 0; j < this->nbRows; ++j) {
            cout << plate[i][j] << " ";
        }
        cout << endl;
    }
}

void Game::setHeuristic(IHeuristic &src) {
    this->heuristic = &src;
}

Game::Game() {
    cout << "The Game is now starting" << endl;

    this->nbLines = 3;
    this->nbRows = 3;
    int lignes[3][3] = {
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
}

Game::~Game() {
    cout << "The Game is now finished" << endl;
}


void Game::PrintInfo() {
}

void Game::PrintParcours() {
}

void Game::meilleurJeuListeOuverte(vector<vector<int > > &retour) {
    retour = this->openList.begin()->first;
    int plusBasCout = openList.begin()->second.F;

    for (map<vector<vector<int> >, Node>::iterator it = ++openList.begin(); it != openList.end(); ++it) {
        if (it->second.F < plusBasCout) {
            retour = it->first;
            plusBasCout = it->second.F;
        }
    }
}
void Game::Search() {

    Node node;
    node.F = 0;
    node.G = 0;
    node.H = this->heuristic->Calculate(this->PlateBegin, this->PlateEnd);
    node.parent = this->PlateBegin;
    this->openList[this->PlateBegin] = node;

    vector<vector<int> > jeu;


    Node currNode;
    bool okPourCeTour;
    int nombre_tentative = 0;
    int numero_case_vide = 0;
    int z = 0;
    while (!this->openList.empty()) {

        cout << "iteration : "  << z << endl;
z++;
        meilleurJeuListeOuverte(jeu);

        currNode = openList[jeu];
        this->closedlist[jeu] = currNode;
//        this->openList.erase(jeu);

        if (jeu == this->PlateEnd) {
            break;
        }

        okPourCeTour = false;
        for (int i = 0; i < 3 && !okPourCeTour; ++i) {
            for (int j = 0; j < 3 && !okPourCeTour; ++j) {

                // on cherche la case vide
                if (jeu[i][j] != numero_case_vide) {
                    continue;
                }

                // on a notre case vide
                okPourCeTour = true;
                ++nombre_tentative;

                if (j > 0) {
                    vector<vector<int> >  nJeu = jeu;
                    nJeu[i][j] = jeu[i][j - 1];
                    nJeu[i][j - 1] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = node.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, node);
                }

                if (j < 3 - 1) {
                    vector<vector<int> >  nJeu = jeu;
                    nJeu[i][j] = jeu[i][j + 1];
                    nJeu[i][j + 1] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = node.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, node);
                }

                if (i > 0) {
                    vector<vector<int> >  nJeu = jeu;
                    nJeu[i][j] = jeu[i - 1][j];
                    nJeu[i - 1][j] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = node.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, node);
                }

                if (i < 3 - 1) {
                    vector<vector<int> > nJeu = jeu;
                    nJeu[i][j] = jeu[i + 1][j];
                    nJeu[i + 1][j] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = node.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, node);
                }

            }
        }
    }
}