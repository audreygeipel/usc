// Oguz and Sahil
// 08_09_2010 Lecture Example

#include <stdio.h>

int primeChecker(int n){
	
	while (n %2 == 0){
		n = n/2;
	}

	while (n %3 == 0){
		n = n/3;
	}

	if (n != 1){ 
		return 0;
	} else {
		return 1;
	}
}


int main(){
	int i;

	scanf("Enter a number : ", &i)
	if (primeChecker(i)){
		printf("Yes");
	} else {
		printf("No");
	} 	
}
