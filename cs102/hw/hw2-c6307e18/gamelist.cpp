#include <iomanip>
#include "game.h"
#include "database.h"
#include "cli.h"

using namespace std;

GameList::GameList(){

}

GameList::~GameList(){

}

// This function adds given game to game list
bool GameList::add_game(Game *game){
  if (!includes(*game)){
    games.push_back(game);
    return true;
  }
  return false;
}

// This function removes games from list
void GameList::remove_game(int game_id){
  games.erase(games.begin() + game_id);
}

// This function also removes game from database
// But this function gets game as an input
void GameList::remove_game(Game game){
  for(unsigned int i = 0; i < games.size(); i++){
    if (*games[i] == game){
      games.erase(games.begin() + i);
    }
  }
}

// This function checks list if game is already added to list
bool GameList::includes(Game game){
  for(unsigned int i = 0; i < games.size(); i++){
    if (*games[i] == game){
      return true;
    }
  }
  return false;
}

// This function prints all the games in the list
void GameList::print(){
  cout << "List: " << name << endl;
  games[0]->print_table();
  for(unsigned int i = 0; i < games.size(); i++){
    games[i]->print(i);
  }
}

