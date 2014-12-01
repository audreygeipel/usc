#include <iostream>

#ifndef WORLD_H
#define WORLD_H

class World {
  public:
    int gen_num;
    bool table[32][12];
    bool next_table[32][12];

    void reset_gen_num();
    void clear_table();
    void toggle_point(int, int);
    void print_table();
    void next_generation();
    void next_generation(int);
    
    void update_point(int, int);
    int num_of_alive_neighbours(int, int);

    World();
    ~World();
};

#endif

