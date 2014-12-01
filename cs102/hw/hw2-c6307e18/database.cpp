#include "database.h"
#include "cli.h"
#include <iostream>
#include <fstream>

using namespace std;

Database::Database(){
  games.reserve(20);
  game_lists.reserve(20);
}

Database::~Database(){
  
}

// This function adds new game to database
bool Database::add_game(Game game){
  if (is_unique_game(game)){
    games.push_back(game);
    return true;
  }
  return false;
}

// This function removes game from database
// Also remove game from all the lists added
void Database::remove_game(int game_id){
  Game game;
  game = games[game_id];
  
  for(unsigned int j=0; j < game_lists.size(); j++){
    if (game_lists[j].includes(game)){
      game_lists[j].remove_game(game); 
    }
  }

  games.erase(games.begin() + game_id);
}

// This function creates new game list
void Database::add_list(string name){
  GameList new_list;
  new_list.name = name;
  game_lists.push_back(new_list);
}

// This function remove list from database
void Database::remove_list(int list_id){
  game_lists.erase(game_lists.begin() + list_id);
}

// This function adds game to game list
bool Database::add_game_to_list(int game_id, int list_id){
  return game_lists[list_id].add_game(&games[game_id]);
}

// This function removes game from list
void Database::remove_game_from_list(int game_id, int list_id){
  game_lists[list_id].remove_game(game_id);
}

// This function prints a table which shows all the game's of user
void Database::print_games(){
  if (games.size() > 0){
    games[0].print_table();
    for(unsigned int i = 0; i < games.size(); i++){
      games[i].print(i);
    }
  } else {
    cout << "Your game database is empty" << endl;
  }
}

// This function prints name of all the lists in database
void Database::print_lists(){
  cout << "Your game lists:" << endl;
  for(unsigned int i = 0; i < game_lists.size(); i++){
    cout << "(" << i << ") " << game_lists[i].name << endl;
  }
}

// This function prints games of selected list
void Database::print_lists_games(int list_id){
  if (game_lists[list_id].games.size() > 0){
    game_lists[list_id].print(); 
  } else {
    cout << "This game list is empty" << endl;
  }
}

// This function exports current database to a file
void Database::export_data(string file_name = "export.txt"){
	ofstream data_file(file_name.c_str(), ifstream::out);
  if (data_file.fail()){
    cout << "Not valid filename" << endl;
    return ;
  }
		
	for(unsigned int i=0; i < games.size(); i++){
		data_file << i << endl;
		data_file << "\t" << games[i].name << endl;
		data_file << "\t" << CLI::print_platform(games[i].platform) << endl;
		data_file << "\t" << CLI::print_category(games[i].category) << endl;
		data_file << "\t" << games[i].publisher << endl;
		data_file << "\t" << CLI::print_rating(games[i].rating) << endl;
		data_file << "\t" << games[i].purchased_at << endl;
		data_file << "\t" << games[i].price << endl;
		data_file << "\t" << "Lists: " << endl;

    for(unsigned int j=0; j < game_lists.size(); j++){
      if (game_lists[j].includes(games[i])){
        data_file << "\t\t" << game_lists[j].name << endl;
      }
    }
	}
}

// This function is not complate
void Database::import_data(string file_name){

}

// this function checks the database if game is already added or not 
bool Database::is_unique_game(Game game){
  for(unsigned int i = 0; i < games.size(); i++){
    if (games[i] == game){
      return false;
    }
  }
  return true;
}

