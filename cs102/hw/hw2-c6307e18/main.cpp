// Author : Oguz Bilgic
// Date   : 10-february-2011
// File   : main.cpp
// Project: CS 102 - Homework #2 - Extending the Video Game Database
// Desc   : Extending the Video Game Database
// Repo   : 
// Version:

#include <iostream>
#include "game.h"
#include "gamelist.h"
#include "database.h"
#include "cli.h"

using namespace std;

Database game_database;

// This function shows menu to user
// Everytime function is complated if user does not quit, This will call itself
// This function uses CLI functions to interact with user thorugh command line
void show_menu(bool show_info = false){
  bool cont = true;
  int temp, temp2;
  Game game;
  
  // Does not show the menu if this is not first run
  if(show_info){
    cout << "--------------------" << endl
         << "MENU OPTIONS" << endl
         << "--------------------" << endl
         << "1. List all video games in the database" << endl
         << "2. Add a video game to the database" << endl
         << "3. Remove a video game from the database" << endl

         << "4. Create new game list" << endl
         << "5. Remove game list" << endl

         << "6. Add a video game to the list" << endl
         << "7. Remove a video game from the list" << endl
         << "8. List all the games in list" << endl

         << "9. Export database to a file" << endl
         
         << "10. Show Menu" << endl
         << "11. Quit" << endl;
  }
  show_info = false;
  
  cout << "--------------------" << endl
       << "Enter Command (10 - menu, 11 - quit): " << endl;
  
  // Switch through menu items
  switch(CLI::get_command()) {
    case 1:
      game_database.print_games();
      break;
    case 2:
      game.name = CLI::get_name();
      game.purchased_at = CLI::get_purchased_at();
      game.price = CLI::get_price();
      game.publisher = CLI::get_publisher();
      game.platform = CLI::get_platform();
      game.category = CLI::get_category();
      game.rating = CLI::get_rating();
      
      if (game_database.add_game(game)){
        cout << "Game is succesfully added." << endl;
      } else {
        cout << "This game is duplicate." << endl;
      }
      break;
    case 3:
      if (game_database.games.size() > 0){
        game_database.print_games();
        cout << "Enter the id of the game which you want to remove from database:" << endl;
        game_database.remove_game(CLI::get_id(0, game_database.games.size()));
        cout << "Game is succesfully removed." << endl;
      } else {
        cout << "Your database is empty" << endl;
      }
      break;
    case 4:
      game_database.add_list(CLI::get_name());
      break;
    case 5:
      if (game_database.game_lists.size() > 0){
        game_database.print_lists();
        cout << "Enter the id of the list which you want to remove from database:" << endl;
        game_database.remove_list(CLI::get_id(0, game_database.game_lists.size()));
        cout << "List is succesfully removed." << endl;
      } else {
        cout << "You do not have any game list." << endl;
      }
      break;
    case 6:
      if (game_database.game_lists.size() > 0){
        game_database.print_games();
        cout << "Enter the id of the game which you want to add to list:" << endl;
        temp = CLI::get_id(0, game_database.games.size());
        game_database.print_lists();
        cout << "Enter the id of the list which you want to add the game:" << endl;
        temp2 = CLI::get_id(0, game_database.game_lists.size());
        if (game_database.add_game_to_list(temp, temp2)){
          cout << "Game is succesfully added to list." << endl;
        } else {
          cout << "Game is already added to list." << endl;
        }
      } else {
        cout << "You do not have any lists to add game, first create new list." << endl;
      }
      break;
    case 7:
      if (game_database.game_lists.size() > 0){
        game_database.print_lists();
        cout << "Enter the id of the list which you want to remove from:" << endl;
        temp = CLI::get_id(0, game_database.game_lists.size());
        game_database.print_lists_games(temp);
        cout << "Enter the id of the game which you want to remove from list:" << endl;
        temp2 = CLI::get_id(0, game_database.game_lists[temp].games.size());
        game_database.remove_game_from_list(temp2, temp);
        cout << "Game is succesfully removed from list." << endl;
      } else {
        cout << "You do not have any game list." << endl;
      }
      break;
    case 8:
      if (game_database.game_lists.size() > 0){
      game_database.print_lists();
      cout << "Enter the id of the list which you want list games:" << endl;
      game_database.print_lists_games(CLI::get_id(0, game_database.game_lists.size()));
      } else {
        cout << "You do not have any game lists" << endl;
      }
      break;
    case 9:
      game_database.export_data(CLI::get_name());
      cout << "Database is succesfully exported." << endl;
      break;
    case 10:
      show_info = true;
      break;
    case 11:
      cout << "Good bye!" << endl;
      cont = false;
      break;
  }  
  
  // If user is still here call yourselfs
  if (cont){
    show_menu(show_info);
  }
}

// This is the manin function
// This function is called when program is first executed
// This function calls show_menu function
int main(){
  show_menu(true);
  return 0;
}
