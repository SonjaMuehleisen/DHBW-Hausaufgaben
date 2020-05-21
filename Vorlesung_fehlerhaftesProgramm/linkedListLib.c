#include <stdio.h>
#include <stdlib.h>
#include "linkedListLib.h"

void addListElem(listElement* start) {
	listELement* new;
	new = (listELement*)malloc(sizeof(listElement)); //neues listenelement anlegen bzw speicherreservieren
	if (new == Null) {
		printf("cant reserve storage.\n");
		return;
	}

	//manage pointers Was ist mein letztes ELement und davon Pointer auf New element
	listElement* currElem = start;
	new = start;
	while (currElem -> nextElem != NULL) currElem = currElem->nextElem; //ich geh ans current element und davon an die stelle nextelem
	//jez zeigt currElem auf das letzte ELement in der Kette und innerhalb des ELements auf den nextElem pointer
	currElem->nextElem = new; //der nextElem pointer des current ELements wird auf new gesetzt
	new->nextElem = NULL;// element new an der stelle nextelem also der pointer wird auf NULL gesetzt da dieser nun letzter elementenpointer ist


	//enter data
	printf("First name:  \n");
	scanf("%s", new->firstname);
	printf("Last name:  \n");
	scanf("%s", new->lastname);
	printf("age:  \n");
	scanf("%d", &(new->age)); //in diesem fall & da beim int im gegensatz zum char direkt auf den wert zugegriffen wird und nicht auf die adresse, zum speichern wird jedoch adresse benötigt



	void printList(listElement * start) {

		if (start->nextElem == NULL) printf("\nlist is empty.\n");
		else {
			int i = 1;
			listElement* currElem = start; //start pointer muss auf anfang weiterhin zeigen um startadresse nicht zu verlieren
			printf("\n current list: \n\n");//daher neuer Pointer anlegen welcher immer weiter wander zum ausgeben
			do {
				currElem = currElem->nextElem;
				printf("%d", i); i++; 
				printf("\tFirst name: %s\n", currElem->firstName);
				printf("\tLast name: %s\n", currElem->lastName);
				printf("\tFirst name: %d\n", currElem->age); //*currElem.age ander schreibweise, geh zum pointerinhalt an die stelle age
			} while (currElem->nextElem != NULL)

				printf("\n");

			
		}
	}
}