#include <iostream>
#include "Game.Class.hpp"
#include "ManhattanHeuristic.Class.hpp"
#include "EuclidHeuristic.Class.hpp"

int main(int ac, char **av) {

    (void) ac;
    ifstream infile(av[1]);

    Game *puzzle = new Game();
    ManhattanHeuristic man;
    EuclidHeuristic euclid;

    puzzle->setHeuristic(man);
//    puzzle->setHeuristic(euclid);

    short i = 0;
    cout << "Storing User's map" << endl;
    for (string line; getline(infile, line); i++) {
        try {
            puzzle->Parse(line);
        }
        catch (exception &e) {
            cout << "Line " << i << " Error : " << e.what() << endl;
            break;
        }
    }
    puzzle->PrshortPlate(puzzle->getStartMap());

    cout << "Storing resolved map" << endl;

    puzzle->storeResolvedMap();
    puzzle->PrshortPlate(puzzle->getEndMap());
    puzzle->Search();
    delete puzzle;
    return (0);
}
