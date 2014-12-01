#include <iomanip>
#include "game.h"
#include "database.h"
#include "cli.h"

using namespace std;

Game::Game(){

}

Game::~Game(){

}

// This function prints the header part of game list
void Game::print_table(){
  cout << left
       << '|' << setw(4) << "ID"
       << '|' << setw(20) << "Name"
       << '|' << setw(10) << "Platform"
       << '|' << setw(15) << "Category"
       << '|' << setw(15) << "Publisher"
       << '|' << setw(8)  << "Rating"
       << '|' << setw(15) << "Purchased at"
       << '|' << setw(6)  << "Price" << endl;
}

//This function prints one row which is filled by game's information
void Game::print(int id){
  cout << left
       << '|' << setw(4) << id
       << '|' << setw(20) << name
       << '|' << setw(10) << CLI::print_platform(platform)
       << '|' << setw(15) << CLI::print_category(category)
       << '|' << setw(15) << publisher
       << '|' << setw(8)  << CLI::print_rating(rating)
       << '|' << setw(15) << purchased_at
       << '|' << setw(6)  << setprecision(3) << price << "$" << endl;
}

// This function is overloading compare operator
// Thus function compares current object with other_game
bool Game::operator==(const Game& other_game){
  if (name == other_game.name && platform == other_game.platform && publisher == other_game.publisher){
    return true;
  }
  return false;
}
