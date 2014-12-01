#include <iostream>
#include <sstream>
#include "cli.h"
#include "database.h"

using namespace std;

// Platform string dictionary 
string platform_a[] = {"Xbox", "Ps3", "Wii", "Ds"};
// Category string dictionary 
string category_a[] = {"Action", "Education", "Fighting", "Music/Party", "Puzzle/Cards", "Roleplaying", "Shooter", "Simulation", "Sports", "Strategy", "Other"};
// Rating string dictionary 
string rating_a[] = {"EC", "E", "E10+", "T", "M", "AO", "RP", "PG", "PG13", "R", "NC17"};

// Platform string vector
vector<string> CLI::platforms(platform_a, platform_a + sizeof(platform_a) / sizeof(string));
// Category string vector
vector<string> CLI::categories(category_a, category_a + sizeof(category_a) / sizeof(string));
// Rating string vector
vector<string> CLI::ratings(rating_a, rating_a + sizeof(rating_a) / sizeof(string));

// This function requests user to type valid menu optin
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
int CLI::get_command(int command){
  cin >> command;
  cin.ignore(1000, '\n');
  
  // Checks valid game id
  // Checks cin.fail
  if (command > 12 || cin.fail()){
    cin.clear();
    cout << "Menu item is invalid" << endl;
    cin.ignore(1000);
    return get_command();
  }

  return command;
}

// This function requests user to type valid game id
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
int CLI::get_id(int id, int max_id){
  cin >> id;
  cin.ignore(1000, '\n');
  
  // Checks valid game id
  // Checks cin.fail
  if (id >= max_id || cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "id is invalid" << endl;
    return get_id();
  }
  
  return id;
}

// This function requests user to type valid price
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
double CLI::get_price(string price){
  stringstream ss;
  double price_d = 0.00;
  bool valid = true;
  int pos = 0;
  
  cout << "Enter price of the game:" << endl;
  getline(cin, price);
  
  // Checks cin.fail
  if (cin.fail()){
    cin.clear();
    cout << "price is invalid" << endl;
    return get_price();
  }
  
  ss << price;
  ss >> price_d;
  
  for (unsigned int i=0; i<price.size(); i++){
    // Checks format
    if (!(isdigit(price[i]) || price[i] == '.')){
      valid = false;
    }
    
    // Checks lenght of chars after '.'
    if(price[i] == '.'){
      pos = price.find('.');
      if (((price.size() - pos) - 1) >= 3){
        valid = false;
      }
    }
  }
  
  if (!valid){
    cin.clear();
    cout << "price you entered includes bad characters (x.xx)" << endl;
    return get_price();
  }
  
  return price_d;
}

// This function requests user to type valid platform
// First it lists all the available platform options
// Then it requests user to select one of them
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
int CLI::get_platform(int platform){
  cout << "-----------" << endl;
  cout << "Platforms:" << endl;
  for (unsigned int i=0; i<platforms.size(); i++){
    cout << "(" << i << ") " << platforms[i] << endl;
  }
  cout << "Enter platform number:" << endl;
  cin >> platform;
  cin.ignore(1000, '\n');
  
  // Checks cin.fail
  if (cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Platform number is invalid" << endl;
    return get_platform();
  }
  
  // Check for valid platform
  if ((unsigned) platform >= platforms.size()){
    cout << "Platform number is invalid" << endl;
    return get_platform();
  }
  
  return platform;
}

// This function requests user to type valid category
// First it lists all the available category options
// Then it requests user to select one of them
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
int CLI::get_category(int category){
  cout << "-----------" << endl;
  cout << "Categories:" << endl;
  for (unsigned int i=0; i<categories.size(); i++){
    cout << "(" << i << ") " << categories[i] << endl;
  }
  cout << "Enter category number:" << endl;
  cin >> category;
  cin.ignore(1000, '\n');
  
  // Checks cin.fail
  if (cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Category number is invalid" << endl;
    return get_category();
  }
  
  // Check for valid category
  if ((unsigned) category >= categories.size()){
    cout << "Category number is invalid" << endl;
    return get_category();
  }
  
  return category;
}

// This function requests user to type valid rating
// First it lists all the available rating options
// Then it requests user to select one of them
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
int CLI::get_rating(int rating){
  cout << "-----------" << endl;
  cout << "Ratings:" << endl;
  for (unsigned int i=0; i<ratings.size(); i++){
    cout << "(" << i << ") " << ratings[i] << endl;
  }
  cout << "Enter rating number:" << endl;
  cin >> rating;
  cin.ignore(1000, '\n');
  
  // Checks cin.fail
  if (cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Rating number is invalid" << endl;
    return get_rating();
  }
  
  // Checks valid rating
  if ((unsigned) rating >= ratings.size()){
    cout << "Rating number is invalid" << endl;
    return get_rating();
  }
  
  return rating;
}

// This function requests user to type valid game name
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
string CLI::get_name(string name){
  bool empty = true;
  cout << "Enter the name :" << endl;
  getline(cin, name);

  // Checks cin.fail
  if (cin.fail()){
    cin.clear();
    cout << "name is invalid" << endl;
    return get_name();
  }
  
  // Checks empty string
  for (unsigned int i=0; i<name.size(); i++){
    if (!(name[i] == ' ' || name[i] == '\t')){
      empty = false;
    }
  }
  
  if (empty){
    cout << "name is empty" << endl;
    return get_name();
  }
  
  return name;
}

// This function requests user to type valid publisher name
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
string CLI::get_publisher(string publisher){
  bool empty = true;
  cout << "Enter the publisher of game:" << endl;
  getline(cin, publisher);
  
  // Checks cin.fail
  if (cin.fail()){
    cin.clear();
    cout << "publisher name is invalid" << endl;
    return get_publisher();
  }
  
  // Checks empty string
  for (unsigned int i=0; i<publisher.size(); i++){
    if (!(publisher[i] == ' ' || publisher[i] == '\t')){
      empty = false;
    }
  }
  
  if (empty){
    cout << "publisher name is empty" << endl;
    return get_publisher();
  }
  
  return publisher;
}

// This function requests user to type valid date
// It preforms some validations on user's input
// If there are any formating error in input it prints error message and calls itself again
string CLI::get_purchased_at(string purchased_at){
  bool leap_year = false;
  int month = 0, day = 0, year = 0;
  stringstream ss;
  
  cout << "Enter purchase date (MM/DD/YYYY):" << endl;
  getline(cin, purchased_at);
  
  // Check cin.fail
  // Check string lenght
  if (cin.fail() || purchased_at.size() != 10){
    cin.clear();
    cout << "Date is invalid, date format is MM/DD/YYYY" << endl;
    return get_purchased_at();
  }
  
  // Check format 00/00/000
  for (int i=0; i<10; i++){
    if(!isdigit(purchased_at[i]) && !(i ==2 || i == 5) && purchased_at[i] != '/'){
      cout << "Date is invalid, date format is MM/DD/YYYY" << endl;
      return get_purchased_at();
    }
  }
  
  // Check valid date
  ss << purchased_at.substr(0, 2);
  ss >> month;
  
  ss.clear();
  ss << purchased_at.substr(3, 2);
  ss >> day;
  
  ss.clear();
  ss << purchased_at.substr(6, 4);
  ss >> year;
  
  // Checks day interval
  if(day > 31 || day < 1){
    cout << "Day is invalid, date format is MM/DD/YYYY" << endl;
    return get_purchased_at();
  }
  
  // Checks month interval
  if(month > 12 || month < 1){
    cout << "Month is invalid, date format is MM/DD/YYYY" << endl;
    return get_purchased_at();
  }
  
  // Checks year interval
  if(year > 2011 || year < 1970){
    cout << "Year is invalid, date format is MM/DD/YYYY" << endl;
    return get_purchased_at();
  }
  
  // Checks leap year
  if (month == 2 && day == 29){
    if ((year%4) != 0)          
      leap_year = false;          
    else if ( (year%400) == 0 )  
      leap_year = true;             
    else if ( (year%100) == 0 )  
      leap_year = false;           
    else                           
      leap_year = true;
  }
  
  if(leap_year){
    cout << "Leap year is detected!" << endl;
    return get_purchased_at();
  }
  
  return purchased_at;
}

// This function gets the id of the category and returns the string form of category
string CLI::print_category(int category){
  return categories[category];
}

// This function gets the id of the platform and returns the string form of platform
string CLI::print_platform(int platform){
  return platforms[platform];
}

// This function gets the id of the rating and returns the string form of rating
string CLI::print_rating(int rating){
  return ratings[rating];
}
