#include <stdio.h>
#include <math.h>

int main() {
	int row, col,angle, max_col;
	
	printf("give me an angle :");
	scanf("%i", &angle)
	
	max_col = 30 * tan((double) angle);
	
	for (row=0; row<30; row++){
		
		int num = row/max_col;
		
		for(col=0; col<num; col++){
			printf("*");
		}
		
		printf("\n");
	}
	return 0;
}
