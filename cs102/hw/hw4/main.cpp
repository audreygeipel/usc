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
int s = 300, h = 12, w = 32;


using namespace std;

//This function gets inteher from command line
int get_int(){
  int command;
  cin >> command;
  cin.ignore(1000, '\n');
  return command;
}

//This function parses optional command line arguments
void parse_cl_options(int argc, char *argv[]){
  string input;
  stringstream ss;
  int val;

  for (int i=1; i < argc; i++){
    if (argv[i][0] == '-' ){
      input = argv[i];
      ss.clear();
      input.erase(0, input.find("=")+1);
      ss << input;
      ss >> val;

      switch(argv[i][1]){
        case 'h':
          if (val > 3 && val < 60){
            h = val;
          }
          break;
        case 's':
          if (val > 10 && val < 30000){
            s = val;
          }
          break;
        case 'w':
          if (val > 4 && val < 132){
            w = val;
          }
          break;
      }
    }
  }
  
  world.num_of_rows = h;
  world.num_of_cols = w;
  world.time = s;
  world.reset();
}

// This function shows menu to user
// Everytime function is complated if user does not quit, This will call itself
// This function uses CLI functions to interact with user thorugh command line
void show_menu(bool show_info){
  bool cont = true;
  int x, y;
  string points;
  stringstream ss; 

  world.print();

  // Does not show the menu if this is not first run
  if(show_info){
    cout << "--------------------" << endl
      << "MENU OPTIONS" << endl
      << "--------------------" << endl
      << "1. Step one generation forward" << endl
      << "2. Step one generation backward" << endl
      << "3. Step multiple generations forward" << endl
      << "4. Step multiple generations backward" << endl
      << "5. Toggle states of grid cells (and reset the generation number)" << endl
      << "6. Clear the grid (and reset the generation number)" << endl
      << "7. Quit" << endl;
  }

  cout << "--------------------" << endl
    << "Enter Command : " << endl;


  // Switch through menu items
  switch(get_int()) {
    case 1:
      world.next_generation();
      break;
    case 2:
      world.old_generation();
      break;
    case 3:
      cout << "Enter number of steps:" << endl;
      world.next_generation(get_int());
      break;
    case 4:
      cout << "Enter number of steps:" << endl;
      world.old_generation(get_int());
      break;
    case 5:
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
    case 6:
      world.reset();
      break;
    case 7:
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
int main(int argc, char *argv[]){
  parse_cl_options(argc, argv);
  cout << s << " " << h << " " << w << endl;
  show_menu(true);
  return 0;
}

