// Basic scanf tutorial
// Url : http://www.hscripts.com/tutorials/cpp/io-functions/scanf-function.php
#include <stdio.h>

int main (){
	char stri [80];
    int a;
	printf ("Enter your name: ");
	scanf ("%s",stri);  
	printf ("Enter your age: ");
	scanf ("%d",&a);
	printf ("You name is %s , age is %d.\n",stri,a);
	return 0;
}
