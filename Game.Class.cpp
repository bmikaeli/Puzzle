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
            {5, 3, 1},
            {6, 0, 4},
            {7, 2, 8}
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
void Game::ajouterDansOpenList(const vector<vector<int> > &jeu, const Node &nouveauNoeud, const Node &noeudRemplace) {
    if (openList.find(jeu) == openList.end()) { // pas encore dans la liste ouverte, donc on l'ajoute
        openList[jeu] = nouveauNoeud;
    } else { // déjà dans la liste ouverte, avons nous trouvé un meilleur chemin ?
        if (nouveauNoeud.F < noeudRemplace.F) {
            openList[jeu] = nouveauNoeud;
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



    Node noeud;
    vector<vector<int> > jeu;

    bool okPourCeTour;
    int nombre_tentative = 0;
    while (!this->openList.empty()) {

        // recuperation du meilleur noeud
        meilleurJeuListeOuverte(jeu);
        noeud = this->openList[jeu];

        // passage dans la liste fermee
        this->closedlist[jeu] = noeud;

        // suppression de la liste ouverte
        this->openList.erase(jeu);


        if (jeu == this->PlateEnd) {
            break;
        }

        // regarder les permutations possibles
        okPourCeTour = false;
        for (int i = 0; i < 3 && !okPourCeTour; ++i) {
            for (int j = 0; j < 3 && !okPourCeTour; ++j) {

                // on cherche la case vide
                if (jeu[i][j] != 8) {
                    continue;
                }

                // on a notre case vide
                okPourCeTour = true;
                ++nombre_tentative;

                if (j > 0) {
                    vector<vector<int > > nJeu = jeu;
                    nJeu[i][j] = jeu[i][j - 1];
                    nJeu[i][j - 1] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = noeud.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, noeud);
                }

                if (j < 3 - 1) {
                    vector<vector<int > > nJeu = jeu;

                    nJeu[i][j] = jeu[i][j + 1];
                    nJeu[i][j + 1] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = noeud.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, noeud);
                }

                if (i > 0) {
                    vector<vector<int > > nJeu = jeu;

                    nJeu[i][j] = jeu[i - 1][j];
                    nJeu[i - 1][j] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = noeud.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, noeud);
                }

                if (i < 3 - 1) {
                    vector<vector<int > > nJeu = jeu;

                    nJeu[i][j] = jeu[i + 1][j];
                    nJeu[i + 1][j] = jeu[i][j];
                    Node nNoeud;
                    nNoeud.G = noeud.G + 1;
                    nNoeud.H = this->heuristic->Calculate(nJeu, this->PlateEnd);
                    nNoeud.F = nNoeud.G + nNoeud.H;
                    nNoeud.parent = jeu;
                    ajouterDansOpenList(nJeu, nNoeud, noeud);
                }
            }
        }
    }

    if (jeu != this->PlateEnd) {
        std::cout << "pas de solution" << std::endl;
        return;
    }
    cout << "solution trouvée en " << nombre_tentative << " tentatives" << endl;
    cout << this->openList.size() << endl;

    vector<vector<vector<int> > > vj;
    vj.push_back(jeu);

    map<vector<vector<int > >, Node>::iterator ite = this->closedlist.end();

    for (ite = this->openList.begin(); ite != this->openList.end(); ite++) {
            this->PrintPlate((*ite).first);
//        cout << (*ite).first[0][0];
    }

//    while (noeud.parent != this->PlateBegin) {
//            jeu = noeud.parent;
//        this->PrintPlate(jeu);
//        vj.push_back(jeu);
//        noeud = this->closedlist[jeu];
//    }
//    std::cout << "solution en " << vj.size() << " coups :" << std::endl;


}
