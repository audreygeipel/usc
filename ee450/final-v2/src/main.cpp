#include <iostream>

#include "General.h"
#include "Major.h"
#include "Captain.h"

#define MAJOR_PORT "3746"

using namespace std;

int main (int argc, char const *argv[]) {
  Captain *captain;
  Major *major;
  General *general ;
	
  if (argc < 2) {
    cout << "Error: You need to specifiy the unit." << endl << endl;
    cout << "Commands:" << endl << endl;
    cout << "\tg     : starts general" << endl;
    cout << "\tm     : starts major" << endl;
    cout << "\tc 1   : starts the first captain" << endl;
    cout << "\tc 2   : starts the second captain" << endl;
    cout << "Usage:" << endl << endl;
    cout << "\t$ ./army c 1" << endl;
  } else { 
    switch(tolower(*argv[1])){
      case 'g':
        general = new General();
        general->start();
        break;
      case 'm':
        major = new Major((char*) MAJOR_PORT);
        major->start();
        break;
      case 'c':
        if (argc < 3){
          cout << "You need to specify Captain number, for example: c 1" << endl;
          break;
        }
        switch(tolower(*argv[2])){
          case '1':
            captain = new Captain(1, (char*) MAJOR_PORT);
            break;
          case '2':
            captain = new Captain(2, (char*) MAJOR_PORT);
            break;
        }
        captain->start();
        break;
      default:
        cout << "Can't recognize your command" << endl;
        break;
    }
  }
  return 0;
}
