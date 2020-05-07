#include <stdio.h>
#include <stdlib.h>

int main() {

	
	int len = 5;
	
	int*vec = malloc(len* sizeof(int));

	printf("Values of vec \n");

	for (int i = 0; i < 5; i++) {
		printf("value %d = %d", i, vec[i]);
	}


}