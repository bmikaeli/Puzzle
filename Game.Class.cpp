#include "Game.Class.hpp"

vector<short> split(string input, const char *delimiter) {
    char *pch;
    char *line;
    line = const_cast<char *>(input.c_str());
    vector<short> array;
    pch = strtok(line, delimiter);
    while (pch != NULL) {
        array.push_back(atoi(pch));
        pch = strtok(NULL, delimiter);
    }
    return array;
}

void Game::PrshortPlate(vector < vector<short> > plate) {

    for (auto elem : plate) {
        cout << "| ";
        for (auto elem2 : elem) {
            cout << elem2 << " ";
        }
        cout << "|";
        cout << endl;
    }
}

void Game::setHeuristic(IHeuristic &src) {
    this->heuristic = &src;
}

void Game::storeResolvedMap() {
    for (short i = 0; i < this->nbLines; ++i) {
        this->PlateEnd.push_back(vector<short>(this->nbRows));
        for (short j = 0; j < this->nbRows; ++j) {
            this->PlateEnd[i][j] = this->nbLines * i + j + 1;
        }
    }
    this->PlateEnd[this->nbLines - 1][this->nbRows - 1] = 0;
}

void Game::Parse(string line) {
    vector<short> line_to_add;
    if (line[0] == '#')
        return;
    else {
        if (this->nbLines == 0) {
            this->nbLines = stoi(line);
        }
        else {
            line_to_add = ::split(line, " ");
            this->nbRows = line_to_add.size();
            this->PlateBegin.push_back(line_to_add);
        }
    }
}

Game::Game() {
    cout << "The Game is now starting" << endl;
}

Game::~Game() {
    cout << "The Game is now finished" << endl;
}

vector <vector<short>> Game::getStartMap() {
    return this->PlateBegin;
}

vector <vector<short>> Game::getEndMap() {
    return this->PlateEnd;
}

void Game::PrshortInfo() {
}

void Game::PrshortParcours() {
}

void Game::findBestMoveInOpenList(vector < vector<short> > &retour) {

    retour = this->openList.begin()->first;
    int smallestF = 999999999;

    for (auto item : this->openList) {
        if (item.second.F < smallestF) {
            retour = item.first;
            smallestF = item.second.F;
        }
    }
}

void Game::AddToOpenList(const vector <vector<short>> &jeu, const Node &nouveauNoeud, const Node &noeudRemplace) {
    if(jeu == this->PlateEnd)
    {
        this->resolved = true;
    }
    if (this->openList.find(jeu) == this->openList.end()) {
        this->openList[jeu] = nouveauNoeud;
    }
    else {
        if (nouveauNoeud.F < noeudRemplace.F) {
            this->openList[jeu] = nouveauNoeud;
        }
    }
}

pair<short, short> Game::findMovingPart(vector < vector<short> > jeu) {

    for (short i = 0; i < this->nbLines; ++i) {
        for (short j = 0; j < this->nbRows; ++j) {
            if (jeu[i][j] == 0) {
                return pair<short, short>(i, j);
            }
        }
    }
    return pair<short, short>(-1, -1);
}

void Game::Search() {

    this->resolved = false;
    Node node;
    node.F = 0;
    node.G = 0;
    node.H = this->heuristic->Calculate(this->PlateBegin, this->PlateEnd);
    node.parent = this->PlateBegin;

    this->openList[this->PlateBegin] = node;
    this->closedlist.empty();
    bool success = false;


    int nb_Try = 0;
    Node noeud;
    vector <vector<short>> jeu = this->PlateBegin;
    bool alreadyclose = true;

    while (!this->openList.empty() && !success) {

        findBestMoveInOpenList(jeu);
        if (jeu == this->PlateEnd || this->resolved == true) {
            success = true;
            break;
        }
        else {
            noeud = this->openList[jeu];
            this->closedlist[jeu] = noeud;
            this->openList.erase(jeu);
        }
            pair<int, int> MovingPart = this->findMovingPart(jeu);

            int i = MovingPart.first;
            int j = MovingPart.second;
            vector < pair < vector < vector<short> > , Node > > tmpFour;
//            this->PrshortPlate(jeu);
//            cout << "heuristic =  "<< this->heuristic->Calculate(jeu, this->PlateEnd);

//            cout << endl;

            nb_Try++;
            if (j > 0) {
                vector <vector<short>> tmpJeu = jeu;
                Node tmpNode;

                tmpJeu[i][j] = jeu[i][j - 1];
                tmpJeu[i][j - 1] = jeu[i][j];
                tmpNode.G = this->heuristic->Calculate(tmpJeu, this->PlateBegin);
                tmpNode.H = this->heuristic->Calculate(tmpJeu, this->PlateEnd);
                tmpNode.F = tmpNode.G + tmpNode.H;
                tmpNode.parent = jeu;
                alreadyclose = this->closedlist.find(tmpJeu) == this->closedlist.end() ? false : true;
                if (alreadyclose == false) {
                    AddToOpenList(tmpJeu, tmpNode, noeud);
                }
            }

            if (j < this->nbRows - 1) {
                vector <vector<short>> tmpJeu = jeu;
                Node tmpNode;

                tmpJeu[i][j] = jeu[i][j + 1];
                tmpJeu[i][j + 1] = jeu[i][j];
                tmpNode.G = this->heuristic->Calculate(tmpJeu, this->PlateBegin);
                tmpNode.H = this->heuristic->Calculate(tmpJeu, this->PlateEnd);
                tmpNode.F = tmpNode.G + tmpNode.H;
                tmpNode.parent = jeu;
                alreadyclose = this->closedlist.find(tmpJeu) == this->closedlist.end() ? false : true;
                if (alreadyclose == false) {
                    AddToOpenList(tmpJeu, tmpNode, noeud);
                }
            }

            if (i > 0) {
                vector <vector<short>> tmpJeu = jeu;
                Node tmpNode;

                tmpJeu[i][j] = jeu[i - 1][j];
                tmpJeu[i - 1][j] = jeu[i][j];
                tmpNode.G = this->heuristic->Calculate(tmpJeu, this->PlateBegin);
                tmpNode.H = this->heuristic->Calculate(tmpJeu, this->PlateEnd);
                tmpNode.F = tmpNode.G + tmpNode.H;
                tmpNode.parent = jeu;
                alreadyclose = this->closedlist.find(tmpJeu) == this->closedlist.end() ? false : true;
                if (alreadyclose == false) {
                    AddToOpenList(tmpJeu, tmpNode, noeud);
                }
            }

            if (i < this->nbLines - 1) {
                vector <vector<short>> tmpJeu = jeu;
                Node tmpNode;
                tmpJeu[i][j] = jeu[i + 1][j];
                tmpJeu[i + 1][j] = jeu[i][j];
                tmpNode.G = this->heuristic->Calculate(tmpJeu, this->PlateBegin);
                tmpNode.H = this->heuristic->Calculate(tmpJeu, this->PlateEnd);
                tmpNode.F = tmpNode.G + tmpNode.H;
                tmpNode.parent = jeu;
                alreadyclose = this->closedlist.find(tmpJeu) == this->closedlist.end() ? false : true;
                if (alreadyclose == false) {
                    AddToOpenList(tmpJeu, tmpNode, noeud);
                }
            }
    }

    if (jeu != this->PlateEnd) {
        cout << "No solutions were found" << endl;
        return;
    }
    cout << "Solution found in " << nb_Try << " tries" << endl;
    cout << "size of jeu : " << this->closedlist.size() << endl;

//    map<vector<vector<short > >, Node>::iterator ite = this->closedlist.end();


//    for (ite = this->openList.begin(); ite != this->openList.end(); ite++) {
//        for (short z = 0; z < this->nbRows; ++z) {
//            cout << " - ";
//        }
//        cout << endl;
//        cout << "|";
//        this->PrshortPlate((*ite).first);
//        cout << "|";
//        cout << (*ite).first[0][0];
//    }
//

    //    vj.push_back(jeu);

//
//  map <vector<vector<short> >, Node> it;
   cout << "Resolution Path :" << endl;
    cout << "taille de la closelist : " << this->closedlist.size() << endl;
    while (noeud.parent != this->PlateBegin) {
        this->PrshortPlate(jeu);
        cout << endl;
        jeu = noeud.parent;
        noeud = this->closedlist[jeu];
    }
//    for(auto elem : this->closedlist)
//    {
//        this->PrshortPlate(elem.first);
//        cout << endl;
//    }
//    std::cout << "solution en " << vj.size() << " coups :" << std::endl;


}
