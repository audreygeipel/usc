// File name : datarep2.c
// Author    : Mark Redekopp
// Date      : 2010-08-23
// Purpose   : Digital Representation activity for CS 100
// Notes     : Students will examine how negative representations of
//             of integer and floating point numbers

#include <stdio.h>

int main()
{
  short int si = 1;
  long long int lli = 1212;
  double db = 9.3;
  float f = 2.5;
  int i = 4;
  char c = 'Z';


  printf("si is located at address (in hex)  0x%p\n", &si);
  printf("lli is located at address (in hex)  0x%p\n", &lli);
  printf("db is located at address (in hex)  0x%p\n", &db);
  printf("f is located at address (in hex)  0x%p\n", &f);
  printf("i is located at address (in hex)  0x%p\n", &i);
  printf("c is located at address (in hex)  0x%p\n", &c);

  return 0;
  
}
