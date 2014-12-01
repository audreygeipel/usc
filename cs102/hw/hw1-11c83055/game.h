#include <iostream>

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
  public:
    int id;
    double price;
    bool is_favorite;
    int platform;
    int category;
    int rating;
    string name;
    string publisher;
    string purchased_at;

    void print_table();
    void print();

    Game();
    ~Game();
};

#endif
