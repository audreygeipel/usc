// Basic Printf Tutorial
// Url : http://www.hscripts.com/tutorials/cpp/io-functions/printf-function.php

#include <stdio.h>
int main(){
	printf ("Characters: 			%c %c \n", 			'b', 					42);
	printf ("Decimals: 				%d %ssd\n", 		187, 					345);
	printf ("Preceding blanks:		%7d \n", 			2010					);
	printf ("Preceding zeros: 		%07d \n", 			2010					);
	printf ("Float values : 		%3.2f %+.0e %E \n", 4.316, 					4.2456, 6.1317);
	printf ("%s \n", 									"Hscripts"				);
	return 0;
}
