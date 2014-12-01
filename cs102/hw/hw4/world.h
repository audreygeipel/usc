#include <iostream>
#include <vector>
#include "table.h"

#ifndef WORLD_H
#define WORLD_H

class World {
  public:
    int num_of_rows;
    int num_of_cols;
    int time;

    std::vector<Table> tables;

    void print();
    void next_generation();
    void next_generation(int);
    void old_generation();
    void old_generation(int);
    void toggle_point(int, int);
    void reset();

    World();
    ~World();
};

#endif

