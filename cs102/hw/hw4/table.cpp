#include <iostream>
#include "table.h"

using namespace std;

//This function sets table options
Table::Table(int x, int y){
  size_of_y = y;
  size_of_x = x;
  this->clear();
}

//This function clears the table
void Table::clear(){
  this->table.resize(size_of_x);
  this->next_table.resize(size_of_x);
  for(int y=0; y<= (size_of_y - 1); y++){
    for(int x=0; x<=(size_of_x - 1); x++){
      table[x].push_back(false);
      next_table[x].push_back(false);
    }
  }
}

//This function toggle the given point
void Table::toggle_point(int x, int y){
  if(table[x][y]){
    table[x][y] = false;
  } else {
    table[x][y] = true;
  }
}

//This function print the current generation
void Table::print(){
  for(int y=0; y<= (size_of_y - 1); y++){
    cout << "|";
    for(int x=0; x<=(size_of_x - 1); x++){
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
void Table::forward(){
  for(int y=0; y<= (size_of_y - 1); y++){
    for(int x=0; x<=(size_of_x - 1); x++){
      update_point(x, y);   
    }
  }

  for(int y=0; y<= (size_of_y - 1); y++){
    for(int x=0; x<=(size_of_x - 1); x++){
      table[x][y] = next_table[x][y];   
    }
  }
}

//This function updates the current point
void Table::update_point(int x, int y){
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
int Table::num_of_alive_neighbours(int x, int y){
  int num = 0;
  int x_start, x_stop, y_start, y_stop;

  //This loops through regular part of table
  if(x == 0) {
    x_start = 0;
    x_stop  = 1;
  } else if(x == (size_of_x - 1)) {
    x_start = (size_of_x - 2);
    x_stop  = (size_of_x - 1);
  } else {
    x_start = x - 1;
    x_stop  = x + 1;
  }

  if(y == 0){
    y_start = 0;
    y_stop  = 1;
  } else if(y == (size_of_y - 1)) {
    y_start = (size_of_y - 2);
    y_stop  = (size_of_y - 1);
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

  //This loops through infinite part of table
  if(x == 0) {
    x_start = (size_of_x - 1);
    x_stop  = (size_of_x - 1);
  } else if(x == (size_of_x - 1)) {
    x_start = 0;
    x_stop  = 0;
  } else {
    x_start = x - 1;
    x_stop  = x + 1;
  }

  if(y == 0){
    y_start = (size_of_y - 1);
    y_stop  = (size_of_y - 1);
  } else if(y == (size_of_y - 1)) {
    y_start = 0;
    y_stop  = 0;
  } else {
    y_start = y - 1;
    y_stop  = y + 1;
  }

  if (x == 0 || x ==(size_of_x - 1) || y == 0 || y ==(size_of_y - 1) ) {
    for(int yi=y_start; yi<= y_stop; yi++){
      for(int xi=x_start; xi<=x_stop; xi++){
        if (table[xi][yi] && !((x==xi) && (y==yi))){
          num++; 
        }
      }
    }
  }

  return num;
}
