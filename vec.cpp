#include <stdio.h>
#include <stdlib.h>

int main() {

	int len = 5;
	//int mat[5][5]; statische reservierung

	int**mat=malloc(sizeof(int)*len)

	for (i = 0; i < len; i++) {
		mat[i] = malloc(len * sizeof(int));


	}
	

	printf("Values of vec \n")

		for (int j = 0; j < len; j++) { //Zeilen
			for (int i = 0; i < len; i++) { //Spalten
				printf(" %d ", 
					mat[i][j]);
			}
			printf("\n"); //Zeilenumbruch
		}







	/*int len = 5;
	
	double *vec = malloc(len* sizeof(double));

	printf("Values of vec \n");

	for (int i = 0; i < 5; i++) {
		printf("value %d = %d\n",i,vec[i]);
	}

	printf("Adresse in hex: \n");
	for (int i = 0; i < len; i++) {

		printf("mem(ptr[i])= %p\n", &vec[i]);
	}
	printf("in dezimal: \n");
	for (int i = 0; i < len; i++) printf("mem(ptr[i])= %d\n", &vec[i]);
	*/
	return 0;

}