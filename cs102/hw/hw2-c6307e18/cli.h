#include <iostream>
#include <vector>
#include "database.h"

using namespace std;

#ifndef CLI_H
#define CLI_H

namespace CLI {
  
  int get_command(int command = 0);
  int get_id(int id = 0, int max_id = 0);
  double get_price(string price = "");
  int get_platform(int platform = 0);
  int get_category(int category = 0);
  int get_rating(int rating = 0);
  
  string get_name(string name = "");
  string get_publisher(string publisher = "");
  string get_purchased_at(string purchased_at = "");
  string print_category(int);
  string print_platform(int);
  string print_rating(int);
    
}

#endif
