#include <iostream>
#include "world.h"

using namespace std;

//This function sets world options and resets tables vector
World::World(){
}

World::~World(){

}

//This function pirnts the last table and generation number
void World::print(){
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  cout << "Generation: " << tables.size() << endl;
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  tables.back().print();
}

//This function moves world to the next generation
void World::next_generation(){
  tables.push_back(tables.back());
  tables.back().forward();
}

//This function loops through next generation
void World::next_generation(int step){
  for(int i=0; i<step; i++){
    next_generation();
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "Generation: " << tables.size() << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    tables.back().print();
    usleep(time);
  }
}

//This function moves world one generation back
void World::old_generation(){
  tables.pop_back();
}

//This function loops through old generation
void World::old_generation(int step){
  for(int i=0; i<step; i++){
    old_generation();
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "Generation: " << tables.size() << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    tables.back().print();
    usleep(time);
  }
}

//This functions toggles the given point
void World::toggle_point(int x, int y){
  tables.back().toggle_point(x, y);
}

//This function resets generation number
void World::reset(){
  Table new_table(num_of_cols, num_of_rows);
  new_table.clear();

  tables.clear();

  tables.push_back(new_table);
}











