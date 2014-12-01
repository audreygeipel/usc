#include <iostream>
#include "world.h"

using namespace std;

World::World(){
  reset_gen_num();
  clear_table();
}

World::~World(){

}

//This function resets generation number
void World::reset_gen_num(){
  gen_num = 0;
}

//This function clears the table
void World::clear_table(){
  for(int y=0; y<= 11; y++){
    for(int x=0; x<=31; x++){
      table[x][y] = false;   
      next_table[x][y] = false;   
    }
  }
}

//This function toggle the given point
void World::toggle_point(int x, int y){
  if(table[x][y]){
    table[x][y] = false;
  } else {
    table[x][y] = true;
  }
}

//This function print the current generation
void World::print_table(){
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  cout << "Generation: " << gen_num << endl;
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
  for(int y=0; y<= 11; y++){
    cout << "|";
    for(int x=0; x<=31; x++){
      if (table[x][y]){
        cout << "@|";
      } else {
        cout << " |";
      }
    }
    cout << endl;
  }
  cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
}

//This function switches table to next generation
void World::next_generation(){
  gen_num++;

  for(int y=0; y<= 11; y++){
    for(int x=0; x<=31; x++){
      update_point(x, y);   
    }
  }
  
  for(int y=0; y<= 11; y++){
    for(int x=0; x<=31; x++){
      table[x][y] = next_table[x][y];   
    }
  }
}

//This function loops through next generation
void World::next_generation(int step){
  for(int i=0; i<=step; i++){
    next_generation();
    print_table();
    sleep(1);
  }
}

//This function updates the current point
void World::update_point(int x, int y){
  int alive = num_of_alive_neighbours(x, y);

  next_table[x][y] = table[x][y];

  if(table[x][y]){
    if(alive < 2 || alive > 3){
      next_table[x][y] = false;
    }
  } else {
    if (alive == 3){
      next_table[x][y] = true;
    } 
  }
}

//This function returns the number of alive neighbours of given point
int World::num_of_alive_neighbours(int x, int y){
  int num = 0;
  int x_start, x_stop, y_start, y_stop;
  
  if(x == 0) {
    x_start = 0;
    x_stop  = 1;
  } else if(x == 31) {
    x_start = 30;
    x_stop  = 31;
  } else {
    x_start = x - 1;
    x_stop  = x + 1;
  }

  if(y == 0){
    y_start = 0;
    y_stop  = 1;
  } else if(y == 11) {
    y_start = 10;
    y_stop  = 11;
  } else {
    y_start = y - 1;
    y_stop  = y + 1;
  }
  
  
  for(int yi=y_start; yi<= y_stop; yi++){
    for(int xi=x_start; xi<=x_stop; xi++){
      if (table[xi][yi] && !((x==xi) && (y==yi))){
        num++; 
      }
    }
  }

  return num;
}
