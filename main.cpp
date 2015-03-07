#include "Game.Class.hpp"
#include "ManhattanHeuristic.Class.hpp"

static void Parse(string line, vector<vector<int> >plate) {
    (void)line;
    (void)plate;
}

int main(int ac, char **av) {

    (void)ac;
    ifstream infile(av[1]);

    Game *puzzle = new Game();
    ManhattanHeuristic man;
    puzzle->setHeuristic(man);

    int i = 0;
    vector<vector<int> > plate;

    for (string line; getline(infile, line); i++) {
        try {
            Parse(line, plate);
        }
        catch (exception &e) {
            cout << "Line " << i << " Error : " << e.what() << endl;
            break;
        }
    }
    puzzle->Search();
    delete puzzle;
    return (0);
}
