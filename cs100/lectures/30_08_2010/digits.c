// 30/08/2010 Question 4
// Due : 01/09/2010
// Oguz Bilgic + Sahil Lavingia 

#include <stdio.h>



int main(){
	int input, d100, d10, d1;
	
	printf("Enter an integer between 0 and 999: ");
	scanf("%d", &input);
	

	d100 = input / 100;
	d10 = (input-d100*100) / 10;
	d1 = ((input-d100*100)-10*d10);

	printf("100's digit is %d \n", d100);
	printf("10's digit is %d \n", d10);
	printf("1's digit is %d \n", d1);

	return 0;
}
