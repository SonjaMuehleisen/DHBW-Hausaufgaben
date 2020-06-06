#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listBib.h"

//Sonja M�hleisen 
//Cedrik Holzwarth
//29-05-2020
//File Name:    HA03_main.c
//              HA03_linkedListLib.c
//              listBib.h
void addListElem(listElement *start){
    
    listElement * new;
    new = (listElement *)malloc(sizeof(listElement));
    if (new == NULL) {
        printf("can't reserve storage.\n"); 
        return;
        }

    listElement * currElem = start;
    while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
    currElem->nextElem = new; // add new to the end of list
    new->nextElem = NULL;
    
    /* fill data in new element */
    printf("Please enter last name: \n");
    scanf("%s",new->lastName);
    printf("Please enter first name: \n");
    scanf("%s",new->firstName);
    printf("Please enter age: \n");
    scanf("%d",&(new->age));
    printf("end of function\n");
}

void printList(listElement *start){
    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        int i = 0;
        listElement *currElem = start;
        printf("\n>> current list:\n\n");
            do {
                currElem = currElem->nextElem;
                printf("%d.)",i); i++;
                printf("\tlast Name: %s\n",currElem->lastName);
                printf("\tfirst Name: %s\n",currElem->firstName);
                printf("\tage : %d\n",currElem->age);
            } while (currElem->nextElem != NULL);
    printf("\n");
    }
}

void delListElem(listElement *start){

    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        int idxToDel = -1;
        listElement * currElem = start;
        listElement * delElem;

        printList(start);
        printf("please enter index of list element to delete\n");
        scanf("%d",&idxToDel);

        if (getLenOfList(start)-1 < idxToDel){
            printf("can't delete element with idx %d. list idx ends at %d\n",idxToDel,getLenOfList(start)-1);
            return;
        }

        for(int i = 0; i < idxToDel; i++) currElem = currElem->nextElem;

        delElem = currElem->nextElem; // extra pointer auf element to del --> free()
        currElem->nextElem = (currElem->nextElem)->nextElem;

        free(delElem);
    }
}

int getLenOfList(listElement *start){
    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; 
        counter++;
        }
    return counter;
}

void delList(listElement *start){

    if (start->nextElem == NULL) printf ("\n>> list is empty\n\n");
    else{
        listElement * currElem = start;
        listElement * delElem;

        while(currElem->nextElem != NULL){
            delElem = currElem->nextElem; // extra pointer auf element to del --> free()
            currElem->nextElem = (currElem->nextElem)->nextElem;
            free(delElem);
        }
    }
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
    fPtr = fopen(filename, "w");

    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        return;
    }
	
	listElement * currElem = start;
	fprintf(fPtr,"%d\n",getLenOfList(start));

	do {
		currElem = currElem->nextElem;
		fprintf(fPtr,"%s\n",currElem->lastName);
		fprintf(fPtr,"%s\n",currElem->firstName);
		fprintf(fPtr,"%d\n",currElem->age);
		} while (currElem->nextElem != NULL);
	
	printf("\n>> save process successful\n\n");
	fclose(fPtr);
}

void loadList(listElement *start){
	
	char filename[50];
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("ls *.txt"); // ls /b *.txt for windowsgnuplot
	printf("\nfilname without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");
	if(fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to load file.\n");
        return;
    }
	
	int lengthOfList = 0;
	fscanf(fPtr,"%d",&lengthOfList);

	for(int i = 0; i < lengthOfList; i++){

		listElement * new;
		new = (listElement *)malloc(sizeof(listElement));
		if (new == NULL) {
			printf("can't reserve storage.\n"); 
			return;
			}

		listElement * currElem = start;
		while (currElem->nextElem != NULL) {
			currElem = currElem->nextElem;// get last elem in list
		}
		currElem->nextElem = new; // add new to the end of list
		new->nextElem = NULL;
		
		/* fill data in new element */
		fscanf(fPtr,"%s",new->lastName);
		fscanf(fPtr,"%s",new->firstName);
		fscanf(fPtr,"%d",&(new->age));
	}
	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start);
}

void exitFcn(listElement *start){
	
	int saveFLAGG = 0;
	
	// ask user to save
	printf("do you want to save the current list?\n");
	printf("[1]... yes\n");
	printf("[0]... no\n");
	scanf("%d",&saveFLAGG);
	
	if(saveFLAGG == 1) saveList(start);
	system("cls");
}

void sortList(listElement *start){
	
	int i, lenOfList, userFLAGG, swapFLAGG, SWAPPING = 0; // some locals
   
    listElement * currElem;
    listElement * prevElem;
    
    char temp1[50];
    char temp2[50];

	printf("sort current list according to ...\n");
	printf(" [1] ... last name\n [2] ... first name\n [3] ... age\n [0] ... exit\n");
	scanf("%d",&userFLAGG);
    printf("\n\n");

    // sort useres choice and get flagg if char or int
	if (userFLAGG != 0 && userFLAGG != 1 && userFLAGG != 2 && userFLAGG != 3){
        system("cls");
        printf("invalid choice. will exit function\n\n");
        return; 
    }
    else if (userFLAGG == 0){
        system("cls");
        return;
        }
    else{ // do the sorting

        lenOfList = getLenOfList(start);

        do{

            currElem = start->nextElem;
            prevElem = start;

            SWAPPING = 0; 
            for (i = 0; i < lenOfList - 1; i++){

                    swapFLAGG = 0;
                    switch (userFLAGG){
                    case 1: // last name 
                            

                        /* YOUR CODE HERE */
                        /* ---------------- 

                        Do the preprocessing:


                            1.) Save last names of strings to compare in temp1 and temp2
                                

                            2.) Use stringToLower function to cast temp1 and temp2 so lower cases


                        */
                        strcpy(temp1, currElem->lastName);
                        strcpy(temp2, (currElem->nextElem)->lastName);
                       
                        stringToLower(temp1);
                        stringToLower(temp2);
                        

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 2: // first name   


                        /* YOUR CODE HERE */
                        /* ---------------- 

                        Do the preprocessing:


                            3.) Save first names of strings to compare in temp1 and temp2
                                

                            4.) Use stringToLower function to cast temp1 and temp2 so lower cases


                        */
                        strcpy(temp1, currElem->firstName);
                        strcpy(temp2, (currElem->nextElem)->firstName);
                        
                        stringToLower(temp1);
                        stringToLower(temp2);

                        if (strcmp(temp1,temp2) > 0) swapFLAGG = 1;
                        break;
                    case 3: // age  
                        
                        
                        /* YOUR CODE HERE */
                        /* ---------------- 

                        Do the preprocessing:DONE


                            5.) Check swapFlagg to one if the relevant condition is true


                        */
                        if (currElem->age > (currElem->nextElem)->age) swapFLAGG = 1;
                       

                       
                        
                        
                        break;    
                    
                    default:
                        break;
                    }

                if (swapFLAGG){ 

                    /* YOUR CODE HERE */
                        /* ---------------- 

                        Do the processing: DONE


                            7.) Do the swapping. 
                                Hint: We need 3 steps. You might start with prevElem->nextElem = ... :-)


                            8.) Don't forget to increment only the prev pointer.


                        */
                    prevElem->nextElem = currElem->nextElem;
                    currElem->nextElem = (currElem->nextElem)->nextElem;
                    (prevElem->nextElem)->nextElem = currElem;

                    prevElem = prevElem->nextElem;


                    SWAPPING = 1;
                } else{ // increament both
                    currElem = currElem->nextElem;
                    prevElem = prevElem->nextElem;
                }

            }

            lenOfList--;
        
        }while(SWAPPING);
        
    }
	printList(start); // print sorted list.
}

void stringToLower(char *string) {
	int i;
	int len = strlen(string);
	for(i=0; i<len; i++) {
       // printf("%d",i);
		if(string[i] >= 'A' && string[i] <= 'Z') {
			string[i] += 32;
		}
	}
   // printf("\n\n");
}

/*why did you print numbers in stringtoLower-FCN. Is there a need to do that. We // it out
we needed about 3h for this. But we did somthing unnecessary because we did not see that this part was already implemented
*/
/*
JW-2020-05-29:
--------------
> well done (10/10) 
> thx for the feedback. no i really dont know why there are two printf statements in the stringToLower-fcn.
> I think there was a reason when i implemented the fcn but cant remember now :O
*/


