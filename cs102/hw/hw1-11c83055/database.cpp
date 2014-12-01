#include "database.h"

using namespace std;

Database::Database(){
  
}

Database::~Database(){
  
}

// This function adds new game to database
void Database::add(Game game){
  game.id = games.size();
  games.push_back(game);
}

// This function adds specified game to user's favorites list
void Database::favorite(int game_id){
  games[game_id].is_favorite = true;
}

// This function removed specified game from user's favorites list
void Database::unfavorite(int game_id){
  games[game_id].is_favorite = false;
}

// This function prints a table which shows all the game's of user
void Database::print_all(){
  if (games.size() > 0){
    games[0].print_table();
    for(unsigned int i = 0; i < games.size(); i++){
      games[i].print();
    }
  } else {
    cout << "Your game database is empty" << endl;
  }
}

// This function prints a tables which shows all favoritted game's of user
void Database::print_favorites(){
  for(unsigned int i = 0; i < games.size(); i++){
    if (games[i].is_favorite){
      games[i].print(); 
    }
  }
}
