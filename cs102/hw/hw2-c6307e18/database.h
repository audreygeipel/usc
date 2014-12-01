#include <vector>
#include "game.h"
#include "gamelist.h"

using namespace std;

#ifndef DATABASE_H
#define DATABASE_H

class Database {
  public:
    vector<Game> games;
    vector<GameList> game_lists;
    
    bool add_game(Game);
    void remove_game(int);
    
    void add_list(string);
    void remove_list(int);

    bool add_game_to_list(int, int);
    void remove_game_from_list(int, int);

    void print_games();
    void print_lists();
    void print_lists_games(int);

    void export_data(string);
    void import_data(string);

    bool is_unique_game(Game);

    Database();
    ~Database();
};

#endif
