#include <vector>
#include "game.h"

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
  public:
    vector<Game> games;
    
    void add(Game);
    void favorite(int);
    void unfavorite(int);
    void print_all();
    void print_favorites();

    Database();
    ~Database();
};

#endif
