// Author : Oguz Bilgic
// Date   : 7-march-2011
// File   : main.cpp
// Project: CS 102 - Homework #3
// Desc   : 
// Repo   : 
// Version:

#include <iostream>
#include <sstream>
#include "world.h"

World world;

using namespace std;

int get_int(){
  int command;
  cin >> command;
  cin.ignore(1000, '\n');
  return command;
}

// This function shows menu to user
// Everytime function is complated if user does not quit, This will call itself
// This function uses CLI functions to interact with user thorugh command line
void show_menu(bool show_info){
  bool cont = true;
  int x, y;
  string points;
  stringstream ss; 
  
  world.print_table();

  // Does not show the menu if this is not first run
  if(show_info){
    cout << "--------------------" << endl
         << "MENU OPTIONS" << endl
         << "--------------------" << endl
         << "1. Step one generation forward" << endl
         << "2. Step multiple generations forward" << endl
         << "3. Toggle states of grid cells (and reset the generation number)" << endl
         << "4. Clear the grid (and reset the generation number)" << endl
         << "5. Quit" << endl;
  }
  
  cout << "--------------------" << endl
       << "Enter Command : " << endl;
 

  // Switch through menu items
  switch(get_int()) {
    case 1:
      world.next_generation();
      break;
    case 2:
      cout << "Enter number of steps:" << endl;
      world.next_generation(get_int());
      break;
    case 3:
      cout << "Enter points:" << endl;
      getline(cin, points);
      while(points.length() > 4){
        points.erase(0, points.find("(")+1);
        ss.clear();
        ss << points[0];
        ss >> x;
        ss.clear();
        ss << points[2];
        ss >> y;
        world.toggle_point(x, y);
      } 
      break;
    case 4:
      world.clear_table();
      world.reset_gen_num();
      break;
   case 5:
      cout << "Good bye!" << endl;
      cont = false;
      break;
  }  
  
  // If user is still here call yourselfs
  if (cont){
    show_menu(false);
  }
}

// This is the manin function
// This function is called when program is first executed
// This function calls show_menu function
int main(){
  show_menu(true);
  return 0;
}

