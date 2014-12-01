// Basic usage of char array
// null-terminated sequences of characters
// Url :: http://www.cplusplus.com/doc/tutorial/ntcs/

#include <iostream>
using namespace std;

int main (){
  char question[] = "Please, enter your first name: ";
  char greeting[] = "Hello, ";
  char yourname [80];
  cout << question;
  cin >> yourname;
  cout << greeting << yourname << "!";
  return 0;
}
