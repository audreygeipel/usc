#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
  if(argc < 2){
    printf("%s expects a string to be entered on the command line\n", argv[0]);
    exit(1);
  }
  printf("Hello %s. Welcome to CS100\n", argv[1]);
  return 0;
}
