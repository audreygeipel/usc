#include <iostream>

#include "Major.h"
#include "Captain.h"

#define MAJOR_PORT "3746"

using namespace std;

int main (int argc, char const *argv[]) {
	Captain *captain1 = new Captain(1, (char*) MAJOR_PORT);
	Captain *captain2 = new Captain(2, (char*) MAJOR_PORT);
	Major *major = new Major((char*) MAJOR_PORT);
	
  if (argc < 2) {
    cout << "Error: You need to specifiy the unit." << endl << endl;
    cout << "Commands:" << endl << endl;
    cout << "Major:     ./main m" << endl;
    cout << "Captain#1: ./main c 1" << endl;
    cout << "Captain#2: ./main c 2" << endl;
  } else { 
    switch(tolower(*argv[1])){
      case 'm':
        major->start();
        break;
      case 'c':
        if (argc < 3){
          cout << "You need to specify Captain number, for example: c 1" << endl;
          break;
        }
        switch(tolower(*argv[2])){
          case '1':
            captain1->start();
            break;
          case '2':
            captain2->start();
            break;
        }
        break;
      default:
        cout << "Can't recognize your command" << endl;
        break;
    }
  }
	return 0;
}
