#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[])
{
  // Declare any other variables you need here
  // and/or delete the integer declared below 
  double fah, cel;

  
  // Prompt the user
  printf("Enter a temperature in Fahrenheit: ");
  
  // Use "%d" for integers, "%lf" for double/floating point
  // Also be sure to put an '&' in front of the variable name
  scanf("%lf", &fah);

  // Do some operations
  cel = (fah - 32.0) * (5.0/9.0);

  // Print the result to the user
  printf("Temperature in Celsius is: %d \n", (int) cel);
  
  // You're done
  return 0;
}

