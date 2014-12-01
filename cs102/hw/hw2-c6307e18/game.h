#include <iostream>

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
  public:
    double price;
    int platform;
    int category;
    int rating;
    string name;
    string publisher;
    string purchased_at;

    void print_table();
    void print(int);

    bool operator==(const Game& other_game);

    Game();
    ~Game();
};

#endif
