#include <stdio.h>
#include <math.h>

// Declaration (function prototype for fact)
int fact(int);

int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
  double rad, sin_rad;
  
  // Prompt the user
  printf("Enter x in radians: ");
  
  // Use "%d" for integers, "%lf" for double/floating point
  // Also be sure to put an '&' in front of the variable name
  scanf("%lf", &rad);

  // Do some operations
  sin_rad = rad - pow(rad, 3.0)/(double)fact(3) + pow(rad, 5.0)/(double)fact(5) - pow(rad, 7.0)/(double)fact(7);

  // Print the result to the user
  printf("Approximation of sin: %lf", sin_rad);
  
  // You're done
  return 0;
  
}


int fact(int n)
{
  int i;
  int result=1;
  for(i=1; i <= n; i++){
    result = result * i;
  }
  return result;
}

