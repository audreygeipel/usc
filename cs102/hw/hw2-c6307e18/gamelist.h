#include <vector>

using namespace std;

#ifndef GAMELIST_H
#define GAMELIST_H

class GameList {
  public:
    string name;
    vector<Game *> games;
    
    bool add_game(Game *);
    void remove_game(int);
    void remove_game(Game);
    bool includes(Game);
    void print();

    GameList();
    ~GameList();
};

#endif

