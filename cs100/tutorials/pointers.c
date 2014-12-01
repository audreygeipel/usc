// Basic example for pointers (&, *)
// Url :: http://www.cplusplus.com/doc/tutorial/pointers/



#include <iostream>
using namespace std;

int main (){
  int firstvalue, secondvalue;
  int * mypointer;

  mypointer = &firstvalue;
  *mypointer = 10;
  mypointer = &secondvalue;
  *mypointer = 20;
  cout << "firstvalue is " << firstvalue << endl;
  cout << "secondvalue is " << secondvalue << endl;
  return 0;
}
