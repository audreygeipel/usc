// Basic usage of define
// defined constants: calculate circumference
// URL :: http://www.cplusplus.com/doc/tutorial/constants/S

#include <iostream>
using namespace std;

#define PI 3.14159
#define NEWLINE '\n'

int main (){
  double r=5.0;       
  double circle;

  circle = 2 * PI * r;
  cout << circle;
  cout << NEWLINE;

  return 0;
}
