// Author : Oguz Bilgic
// Date   : 30-january-2011
// File   : main.cpp
// Project: CS 102 - Homework #1 - Video Game Database
// Desc   : Video Game Database
// Repo   : git@gist.github.com:11c83055d21ecaae321f.git
// Version: v1.0

#include <iostream>
#include "game.h"
#include "database.h"
#include "cli.h"

using namespace std;

Database game_database;

// This function shows menu to user
// Everytime function is complated if user does not quit, This will call itself
// This function uses CLI functions to interact with user thorugh command line
void show_menu(bool show_info){
  bool cont = true;
  Game game;
  
  // Does not show the menu if this is not first run
  if(show_info){
    cout << "--------------------" << endl
         << "MENU OPTIONS" << endl
         << "--------------------" << endl
         << "1. List all video games in the database" << endl
         << "2. Add a video game to the database" << endl
         << "3. List all video games in the Favorites list" << endl
         << "4. Add a video game to the Favorites list" << endl
         << "5. Remove a video game from the Favorites list" << endl
         << "6. Quit" << endl;
  }
  
  cout << "--------------------" << endl
       << "Enter Command : " << endl;
  
  // Switch through menu items
  switch(CLI::get_command()){
    case 1:
      game_database.print_all();
      break;
    case 2:
      game.name = CLI::get_name();
      game.purchased_at = CLI::get_purchased_at();
      game.price = CLI::get_price();
      game.publisher = CLI::get_publisher();
      game.platform = CLI::get_platform();
      game.category = CLI::get_category();
      game.rating = CLI::get_rating();
      
      game_database.add(game);
      cout << "Game is succesfully added." << endl;
      break;
    case 3:
      game_database.print_favorites();
      break;
    case 4:
      game_database.print_all();
      cout << "Enter the id of the game which you want to add to favorites" << endl;
      game_database.favorite(CLI::get_id(0, game_database.games.size()));
      cout << "Game is succesfully added to your favorites." << endl;
      break;
    case 5:
      game_database.print_all();
      cout << "Enter the id of the game which you want to remove from favorites" << endl;
      game_database.unfavorite(CLI::get_id(0, game_database.games.size()));
      cout << "Game is succesfully removed from your favorites." << endl;
      break;
    case 6:
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
