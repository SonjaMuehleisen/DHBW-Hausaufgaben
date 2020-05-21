#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"



int main() {

	listElement* start;
	start = (listElement*)malloc(sizeof(listElement));
	if (start == NULL) {

		printf("Cant reserve storage.\n");
		return -1;
	}

	start->nextElem = NULL; //geht in start an die stelle nextElem und lässt diesen Pointer auf NULL zeigen
	int FLAGG = 1;
	while (FLAGG) {

		printf("1.....print list\n");
		printf("2.....add ELement to list\n");
		printf("3.....delete element\n");
		printf("4.....delete list\n");
		printf("5.....save list\n");
		printf("6.....load list\n");
		printf("7.....sort list\n");
		printf("0....exit\n");
		scanf("%d", &FLAGG);
		system("clear");
	}
	switch (FLAGG)
	{
	case 1:printList(start); break;
	case 2:addListElem(start); break;

	//restliche Funktionen

	case 0:FLAGG = 0;// exit fcn
	default: printf("invalid choice\n"); break;
	 }

	
	

	


	return 0;
}