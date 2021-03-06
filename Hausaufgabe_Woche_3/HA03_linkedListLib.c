#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HA03_linkedListLib.h"
//Sonja M�hleisen 
//Cedrik Holzwarth
//22-05-2020
//File Name:    HA03_main.c
//              HA03_linkedListLib.c
//              HA03_linkedListLib.h

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

    printf("\n>> delListElem fcn is tbd.\n\n");

}

void delList(listElement *start){

    printf("\n>> getLenOfList fcn is tbd.\n\n");

}

int getLenOfList(listElement *start){ // we use this for save list fcn

    int counter = 0;
    listElement * currElem = start;
    while (currElem->nextElem != NULL) {// get last elem in list
        currElem = currElem->nextElem; counter++;
        }
    return counter;
}

void saveList(listElement *start){

	char filename[50];
	printf("\n >> saving data...\n\n");
	printf("filename without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
    fPtr = fopen(filename, "w");

    /* YOUR CODE HERE */
    /* ---------------- 


        1.) Check if fopen() was successful.
            Otherwise exit function with return and inform the user about the canceled task.
           




        2.) Use fprintf() to write length of list as first value to the text file.
            This will be the first information needed by the loadList function.


        3.) Use fprintf() to write every field of the structs to the text file.
            Consider to loop over the listelements for this task.
            It might be handy to use an iteration pointer on this stage :-)


        4.) The user needs to be informed about the successful saving process.
            Don't forget to close the file stream!
    */
    if (fPtr == NULL)
    {
        printf("Could not save file\n");

        //return 0 oder �-1
        //return auf exit fcn
    }
    else {
        int temp = 66;
        temp = getLenOfList(start);
        fprintf(fPtr,"%d\n", temp );  //Length of Linked list: 
       
        if (start->nextElem == NULL) printf("\n>> list is empty\n\n");
        else {
            int i = 1;
            listElement* currElem = start;
            //fprintf(fPtr,"\n>> current list:\n\n");
            do {
                currElem = currElem->nextElem;
                //fprintf(fPtr,"%d.)", i); i++;
                fprintf(fPtr,"%s\n", currElem->lastName); //last Name: 
                fprintf(fPtr,"%s\n", currElem->firstName);//\tfirst Name:
                fprintf(fPtr,"%d\n", currElem->age);        //\tage : 
            } while (currElem->nextElem != NULL);
            fprintf(fPtr, "\n"); printf("Saving successfull!\n\n");
        }
    }


    fclose(fPtr);
}

void loadList(listElement *start){
	
    int temp = 0;
	char filename[50];
	printf("\nloading data...\n\n");
	printf("availible data: \n----------------\n");
	system("dir /b *.txt"); // dir /b *.txt for windows | print availible *.txt files in current location
	printf("\nfilname without extension: ");
	scanf("%s",filename);
	strcat(filename, ".txt"); // adding .txt to file name
	
	FILE * fPtr;
	fPtr = fopen(filename, "r");

    if (fPtr == NULL)
    {
        printf("Could not load file\n");
    }
    else {

        fscanf(fPtr, "%d", &temp);
        printf("Values in file:%d\n", temp);
       // temp = 2;
        for (int i = 1; i <= temp; i++) {//Loop noch dr�ber legen
            listElement* new;
            new = (listElement*)malloc(sizeof(listElement));
            if (new == NULL) {
                printf("can't reserve storage.\n");
                return;
            }

            listElement* currElem = start;

            while (currElem->nextElem != NULL) currElem = currElem->nextElem;// get last elem in list
            currElem->nextElem = new; // add new to the end of list
            new->nextElem = NULL;


            fscanf(fPtr, "%s", new->lastName); //new->lastName
            fscanf(fPtr, "%s", new->firstName);
            fscanf(fPtr, "%d", &(new->age));
            printf("\t(%d)\n\tLast name: %s\n\tFirst name: %s\n\tAge:%d\n\n",i, new->lastName, new->firstName, new->age);
            
        }
       
    }
    

    /* YOUR CODE HERE */
    /* ---------------- 


        1.) Check if fopen() was successful.
            Otherwise exit function with return and inform the user about the canceled task.


        2.) Use fscanf() to read the first value of the text file.
            This will be the information about the length of the list to be loaded.


        3.) Use fscanf() to read every field of the structs from text file.
            Consider to loop over the listelements for this task.
            You need to create a new instance listElement every iteration. 
            It might be handy to use an iteration pointer on this stage :-)


    */
	
    
	fclose(fPtr);
	printf("loading data will be append to current list...\n");
	printList(start); // show loaded list
}

void exitFcn(listElement *start){

    printf("\n>> exitFcn fcn is tbd.\n\n");

}

void sortList(listElement *start){
	
	printf("\n>>sortList fcn is tbd.\n\n");
    
}

void stringToLower(char *string) {
	
    printf("\n>>stringToLower fcn is tbd.\n\n");

}
/*
JW-2020-05-22:
--------------
> well done (10/10) 
> how much time did you spend on this exercise? I think it was a litte to easy wasnt it? ;-)
*/




